# Roteiro de Vídeo Explicativo: Projeto "Passa a Bola" - Arquitetura IoT

**Duração Máxima:** 3 minutos

--- 

## Cena 1: Introdução e Contexto (0:00 - 0:45)

*   **Visual:** Imagens dinâmicas de jogadores de futebol, close-ups de chuteiras, gráficos simples de dados.
*   **Áudio:** Música de fundo inspiradora e narração clara.

**Narração:**

"Olá a todos! Bem-vindos ao projeto 'Passa a Bola', onde a paixão pelo futebol encontra a inovação tecnológica. Nosso objetivo é revolucionar a análise de desempenho em campo, transformando uma simples chuteira em uma ferramenta inteligente de coleta de dados."

"A Internet das Coisas, ou IoT, é a chave para isso. Ela nos permite conectar objetos do dia a dia à internet, coletando e trocando dados em tempo real. No futebol, isso significa monitorar cada toque, cada passe, e entender o desempenho de uma jogadora como nunca antes. É a IoT trazendo valor real, com monitoramento em tempo real e análises de dados que podem mudar o jogo."

"Para alcançar essa visão, propomos uma arquitetura IoT robusta e escalável. Imagine uma chuteira equipada com sensores, enviando dados para uma plataforma inteligente que os transforma em estatísticas valiosas. É isso que vamos explorar hoje."

--- 

## Cena 2: Arquitetura Proposta (0:45 - 1:30)

*   **Visual:** Diagrama de arquitetura animado, destacando cada componente conforme a narração avança.
*   **Áudio:** Narração explicativa.

**Narração:**

"Nossa arquitetura é dividida em camadas claras. No coração, temos os **Dispositivos IoT**: uma chuteira inteligente equipada com sensores FSR, que detectam toques e pressão, e um microcontrolador ESP32, que processa esses dados e os envia via Wi-Fi."

"Esses dados viajam através do protocolo **MQTT**, um padrão leve e eficiente para comunicação IoT, garantindo que cada evento chegue rapidamente à nossa **Plataforma de Gerenciamento IoT: o FIWARE**."

"O FIWARE é o cérebro do nosso sistema. Ele ingere, processa e gerencia os dados, transformando eventos brutos em estatísticas significativas. E, finalmente, temos o **Dashboard de Visualização**, onde todas essas informações são apresentadas de forma clara e em tempo real, com gráficos interativos."

--- 

## Cena 3: Desenvolvimento e Configuração (1:30 - 2:15)

*   **Visual:** Telas de terminal mostrando comandos de instalação (simulados), interface do FIWARE (capturas de tela ou animações), código do simulador em C/C++.
*   **Áudio:** Narração técnica.

**Narração:**

"Para demonstrar essa arquitetura, configuramos nossa plataforma IoT. Utilizamos o FIWARE, que pode ser instalado em uma máquina virtual local ou em um provedor de nuvem. Mostraremos a configuração básica, onde criamos entidades virtuais para representar nossas chuteiras e definimos o protocolo MQTT para a comunicação."

"A parte crucial da nossa demonstração virtual é o **simulador**. Em vez de uma chuteira física, desenvolvemos um programa em **C/C++** que emula o comportamento do sensor. Este simulador gera eventos de 'toque' e 'passe' e os publica no nosso *broker* MQTT, exatamente como faria uma chuteira real."

"Isso nos permite testar toda a cadeia de dados, desde a 'chuteira virtual' até a visualização, garantindo que nossa arquitetura funcione perfeitamente antes mesmo de termos o hardware finalizado."

--- 

## Cena 4: Demonstração e Conclusão (2:15 - 3:00)

*   **Visual:** Tela dividida mostrando o terminal com o simulador C/C++ rodando, e o dashboard em tempo real atualizando os gráficos. Close-up nos gráficos.
*   **Áudio:** Narração entusiasmada.

**Narração:**

"Agora, a demonstração! Aqui, vemos nosso simulador em C/C++ em ação, enviando eventos de toque e passe. Cada linha no terminal representa um dado sendo transmitido."

"E, em tempo real, nosso dashboard web, conectado ao FIWARE, exibe essas informações. Observem como os contadores de 'toques na bola' e 'passes' se atualizam instantaneamente. Podemos ver o status dos serviços e como cada evento é processado e refletido na interface."

"Podemos até mesmo demonstrar a criação de uma entidade lógica, cadastrando uma nova chuteira virtual na plataforma e vendo seus dados aparecerem no dashboard."

"Este é apenas o começo do 'Passa a Bola'. Com esta arquitetura inicial, abrimos caminho para estatísticas mais avançadas, análises preditivas e uma nova era na performance esportiva. Obrigado por assistir!"

---
