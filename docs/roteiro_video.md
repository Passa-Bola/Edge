# Roteiro de Vídeo Explicativo: Arquitetura Inicial de uma Aplicação IoT - Projeto "Passa a Bola"

**Duração Máxima:** 3 minutos

--- 

## Cena 1: Introdução (0:00 - 0:45)

**Visual:** Imagens dinâmicas de jogadoras de futebol em campo, com sobreposições de ícones de IoT (sensores, nuvem, dados). Transição para uma animação simples da chuteira inteligente.

**Áudio:** Música de fundo inspiradora e enérgica. Locutor com voz clara e entusiasmada.

**Locutor:** "Olá a todos! Bem-vindos à apresentação da Sprint 3 do projeto 'Passa a Bola'. Hoje, vamos mergulhar na arquitetura inicial de uma aplicação IoT que promete revolucionar a análise de desempenho no futebol feminino!"

### Aplicação do IoT no Projeto

**Visual:** Close-up na chuteira inteligente (animação), destacando os pontos onde os sensores estariam. Gráficos simples mostrando dados sendo coletados em tempo real (ex: número de toques).

**Locutor:** "No 'Passa a Bola', a tecnologia IoT será o nosso grande diferencial. Estamos desenvolvendo uma chuteira inteligente, equipada com sensores, que nos permitirá monitorar em tempo real a interação da jogadora com a bola. Isso agrega um valor imenso à solução, oferecendo dados precisos sobre toques, passes e a participação efetiva de cada atleta em campo. Imagine ter estatísticas avançadas para otimizar treinos e estratégias!"

### Conceitos de IoT

**Visual:** Animação simplificada de dispositivos conectados (carro, casa, agora a chuteira) enviando dados para a nuvem. Texto na tela: 'IoT: Conectando o Mundo Físico ao Digital'.

**Locutor:** "Mas o que é IoT? A Internet das Coisas é a rede de objetos físicos — como a nossa chuteira — que possuem sensores, software e outras tecnologias para se conectar e trocar dados pela internet. Ela é relevante hoje porque nos permite coletar informações valiosas do mundo real, transformando-as em insights acionáveis. No esporte, isso significa um novo nível de compreensão sobre o desempenho humano."

### Arquitetura Proposta (Diagrama)

**Visual:** Apresentação clara do diagrama de arquitetura IoT (`iot_architecture_diagram.png`). Destaque animado para cada componente enquanto o locutor fala.

**Locutor:** "Para tornar isso realidade, propomos uma arquitetura IoT robusta e eficiente. No coração, temos os **Dispositivos IoT**: nossa chuteira inteligente, com sensores de pressão/força e um microcontrolador com Wi-Fi. Esses dados são enviados via protocolo **MQTT** para um **Broker MQTT**, que os encaminha para a nossa **Plataforma de Gerenciamento IoT**, que nesta fase inicial será o **Node-RED**. Lá, os dados são processados e visualizados em um dashboard."

--- 

## Cena 2: Desenvolvimento (0:45 - 1:45)

**Visual:** Tela de computador mostrando a instalação do Node-RED e a importação do fluxo. Pode ser uma gravação de tela acelerada.

**Áudio:** Música de fundo mais técnica, mas ainda dinâmica. Locutor.

### Instalação da Plataforma IoT (Node-RED)

**Visual:** Comandos de terminal sendo executados (ex: `npm install -g node-red`, `node-red`). Interface do Node-RED sendo aberta no navegador.

**Locutor:** "Para a nossa plataforma de gerenciamento, escolhemos o Node-RED pela sua flexibilidade e facilidade de uso. A instalação é simples: basta usar o npm para instalá-lo globalmente e depois iniciá-lo com um comando. Ele roda localmente, e acessamos sua interface via navegador."

### Configuração Básica

**Visual:** Interface do Node-RED com o fluxo `node_red_flow.json` importado. Destaque para o nó 'mqtt in' configurado para o tópico `passabola/chuteira/+/eventos` e o broker HiveMQ. Destaque para o nó 'function' que processa os dados.

**Locutor:** "Uma vez no Node-RED, importamos nosso fluxo pré-configurado. Aqui, definimos como a plataforma se conecta ao nosso Broker MQTT, escutando os tópicos específicos da chuteira. Configuramos também os serviços essenciais, como o processamento dos dados recebidos para contar toques e passes, e a preparação para a visualização."

--- 

## Cena 3: Demonstração (1:45 - 3:00)

**Visual:** Tela dividida ou transições rápidas entre:
1.  Terminal executando `device_simulator.py` (mostrando mensagens de publicação MQTT).
2.  Dashboard do Node-RED (`http://localhost:1880/ui`) com os contadores de toques e passes sendo atualizados em tempo real.

**Áudio:** Música de fundo mais animada. Locutor com tom de demonstração.

### Coleta de Dados

**Visual:** Simulador Python enviando dados. Dashboard do Node-RED recebendo e atualizando os contadores.

**Locutor:** "Agora, a parte mais emocionante: a demonstração! Nosso simulador de chuteira está enviando eventos de 'toque' e 'passe' para o broker MQTT. E, como podem ver, o Node-RED está recebendo esses dados em tempo real, processando-os e atualizando instantaneamente os contadores no nosso dashboard."

### Health Check e Criação de Entidade Lógica

**Visual:** Breve visualização do log do Node-RED ou do debug panel mostrando que as mensagens estão chegando. Pode-se mostrar rapidamente o nó 'mqtt in' no Node-RED e o tópico configurado.

**Locutor:** "Podemos verificar o 'health check' da aplicação observando o fluxo de mensagens no debug do Node-RED, confirmando que a comunicação está ativa e os serviços funcionando. A criação de uma entidade lógica, como um novo dispositivo, é feita configurando o tópico MQTT e o ID da jogadora, permitindo que a plataforma identifique e categorize os dados de cada chuteira de forma única. Isso é fundamental para o projeto 'Passa a Bola', pois cada jogadora terá seus dados individualizados."

--- 

## Cena Final: Conclusão (Opcional, se houver tempo)

**Visual:** Retorno à tela inicial com o logo do projeto "Passa a Bola" e os nomes dos integrantes.

**Áudio:** Música de fundo suave, locutor com tom de encerramento.

**Locutor:** "Esta arquitetura inicial é um passo crucial para o 'Passa a Bola'. Ela nos permite coletar dados valiosos e abre caminho para análises mais profundas e um entendimento sem precedentes do desempenho em campo. Agradecemos a atenção!"

