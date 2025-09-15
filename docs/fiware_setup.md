# Configuração do Ambiente FIWARE para o Projeto "Passa a Bola"

Este documento detalha os passos para configurar o ambiente FIWARE, incluindo o Orion Context Broker e o IoT Agent for MQTT, para receber e processar os dados simulados da chuteira inteligente.

## Pré-requisitos

Certifique-se de que seu ambiente Docker e Docker Compose estão configurados e que os serviços do FIWARE (Orion Context Broker, IoT Agent for MQTT e Mosquitto MQTT Broker) estão em execução, conforme especificado no `infra/docker-compose.yml`.

## 1. Provisionar um IoT Agent for MQTT

O IoT Agent é responsável por traduzir os dados do protocolo MQTT para o formato NGSI (Next Generation Service Interface) compreendido pelo Orion Context Broker.

### 1.1. Criar um Serviço e Subserviço

Primeiro, precisamos criar um serviço e um subserviço para o nosso dispositivo. Isso é feito enviando uma requisição para o IoT Agent.

```bash
curl -iX POST 'http://localhost:4041/iot/services'
-H 'Content-Type: application/json'
-H 'fiware-service: passa_a_bola'
-H 'fiware-servicepath: /'
-d '
{
  "services": [
    {
      "iot_agent": "iot-agent-json",
      "resource": "/iot/json",
      "apikey": "4jggokgpepnvsb2uv4s40d59ov",
      "cbroker": "http://orion:1026",
      "entity_type": "Chuteira",
      "trust_all_certs": true
    }
  ]
}'
```

*   `fiware-service`: Nome do serviço (ex: `passa_a_bola`).
*   `fiware-servicepath`: Caminho do serviço (ex: `/`).
*   `apikey`: Chave de API para autenticação dos dispositivos (ex: `4jggokgpepnvsb2uv4s40d59ov`).
*   `cbroker`: URL do Orion Context Broker.
*   `entity_type`: Tipo de entidade que será criada no Orion (ex: `Chuteira`).

### 1.2. Provisionar o Dispositivo (Chuteira Virtual)

Agora, vamos provisionar a nossa chuteira virtual. Isso associa um `device_id` a uma entidade no Context Broker e define como os atributos serão mapeados.

```bash
curl -iX POST 'http://localhost:4041/iot/devices'
-H 'Content-Type: application/json'
-H 'fiware-service: passa_a_bola'
-H 'fiware-servicepath: /'
-d '
{
  "devices": [
    {
      "device_id": "chuteira01",
      "entity_name": "urn:ngsi-ld:Chuteira:001",
      "entity_type": "Chuteira",
      "transport": "MQTT",
      "attributes": [
        { "object_id": "t", "name": "contagem_toques", "type": "Number" },
        { "object_id": "p", "name": "contagem_passes", "type": "Number" }
      ],
      "static_attributes": [
        { "name": "localizacao", "type": "Text", "value": "Campo A" }
      ]
    }
  ]
}'
```

*   `device_id`: ID único do dispositivo (ex: `chuteira01`). Este será o ID que o simulador usará para se identificar.
*   `entity_name`: Nome da entidade no Orion Context Broker (ex: `urn:ngsi-ld:Chuteira:001`).
*   `attributes`: Mapeamento dos dados recebidos via MQTT para os atributos da entidade.
    *   `object_id`: O nome da chave no payload JSON MQTT (ex: `t` para toques, `p` para passes).
    *   `name`: O nome do atributo correspondente na entidade NGSI-LD (ex: `contagem_toques`).

## 2. Verificar a Entidade no Orion Context Broker

Após provisionar o dispositivo, você pode verificar se a entidade foi criada corretamente no Orion Context Broker.

```bash
curl -iX GET 'http://localhost:1026/v2/entities/urn:ngsi-ld:Chuteira:001?type=Chuteira'
-H 'fiware-service: passa_a_bola'
-H 'fiware-servicepath: /'
```

Inicialmente, os valores de `contagem_toques` e `contagem_passes` devem ser 0 ou não existir até que o simulador comece a enviar dados.

## 3. Exemplo de Payload MQTT do Simulador

O simulador em C/C++ enviará mensagens MQTT para o tópico do IoT Agent. O tópico padrão para o IoT Agent JSON é `/<apikey>/<device_id>/iot/json`.

*   **Tópico:** `/4jggokgpepnvsb2uv4s40d59ov/chuteira01/iot/json`
*   **Payload para um toque:**
    ```json
    {
      "t": 1
    }
    ```
*   **Payload para um passe:**
    ```json
    {
      "p": 1
    }
    ```

O IoT Agent interpretará esses payloads e incrementará os atributos `contagem_toques` e `contagem_passes` na entidade `urn:ngsi-ld:Chuteira:001` no Orion Context Broker. Note que o IoT Agent pode ser configurado para incrementar valores automaticamente se o tipo do atributo for `Number` e o payload for um número, ou para simplesmente atualizar o valor. Para contadores, o incremento é o comportamento desejado e pode ser configurado no IoT Agent ou tratado no lado do Context Broker com regras de atualização.
