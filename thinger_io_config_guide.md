# Guia de Configuração Simplificada do Thinger.io

Este guia descreve os passos para configurar um dispositivo e um dashboard no Thinger.io para receber e visualizar os dados da chuteira inteligente simulada.

## 1. Criar uma Conta no Thinger.io

1.  Acesse [https://thinger.io/](https://thinger.io/) e clique em "Sign Up" para criar uma nova conta.
2.  Siga as instruções para verificar seu e-mail e ativar sua conta.

## 2. Adicionar um Dispositivo (Chuteira Inteligente)

1.  Após fazer login, navegue até a seção "Devices" no menu lateral.
2.  Clique em "Add Device".
3.  Selecione o tipo de dispositivo "ESP32".
4.  Preencha os seguintes campos:
    *   **Device ID:** `chuteira_inteligente` (deve ser o mesmo definido no código do ESP32)
    *   **Device Name:** `Chuteira Inteligente Passa a Bola`
    *   **Device Credential:** Crie uma credencial segura (ex: `minhacredencialsecreta123`). **Anote esta credencial, pois ela será usada no código do ESP32.**
5.  Clique em "Add Device".

## 3. Configurar o Recurso de Dados

1.  No painel do dispositivo recém-criado (`chuteira_inteligente`), vá para a aba "Device Properties" ou "Resources".
2.  O Thinger.io automaticamente detectará os recursos que o ESP32 está enviando (neste caso, `dados_chuteira`). Certifique-se de que o recurso `dados_chuteira` esteja listado e ativo.

## 4. Criar um Dashboard para Visualização

1.  Navegue até a seção "Dashboards" no menu lateral.
2.  Clique em "Add Dashboard".
3.  Dê um nome ao dashboard (ex: `Estatísticas Chuteira Passa a Bola`).
4.  Adicione widgets para visualizar os dados:
    *   **Para `contagem_toques` e `contagem_passes`:** Adicione widgets do tipo "Bucket" ou "Gauge" para exibir os valores atuais.
        *   Selecione o dispositivo `chuteira_inteligente` e o recurso `dados_chuteira`.
        *   Escolha o campo `contagem_toques` ou `contagem_passes`.
    *   **Para `forca`:** Adicione um widget do tipo "Chart" (gráfico de linha) para visualizar a variação da força ao longo do tempo.
        *   Selecione o dispositivo `chuteira_inteligente` e o recurso `dados_chuteira`.
        *   Escolha o campo `forca`.
    *   **Para `usage_rate`:** Adicione um widget do tipo "Gauge" ou "Text" para exibir a taxa de uso.
        *   Selecione o dispositivo `chuteira_inteligente` e o recurso `dados_chuteira`.
        *   Escolha o campo `usage_rate`.

## 5. Atualizar o Código do ESP32

1.  No arquivo `esp32_chuteira_simulada.ino`, substitua os placeholders pelas suas credenciais:
    *   `#define USERNAME "seu_usuario_thinger"` pelo seu nome de usuário do Thinger.io.
    *   `#define DEVICE_CREDENTIAL "sua_credencial_thinger"` pela credencial que você criou.
    *   `#define WIFI_SSID "seu_ssid_wifi"` pelo nome da sua rede Wi-Fi.
    *   `#define WIFI_PASSWORD "sua_senha_wifi"` pela senha da sua rede Wi-Fi.

2.  Compile e faça o upload do código para o seu ESP32 (ou execute no Wokwi).

Com esses passos, seu dispositivo simulado estará enviando dados para o Thinger.io, e você poderá visualizar as estatísticas em tempo real no seu dashboard.


