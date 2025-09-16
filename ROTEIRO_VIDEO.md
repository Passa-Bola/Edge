# Roteiro do Vídeo Explicativo - Projeto Passa a Bola
**Duração Total: 3 minutos**

## Estrutura do Vídeo

### INTRODUÇÃO (0:00 - 1:00) - 60 segundos

#### Abertura (0:00 - 0:15)
**[SLIDE: Título do projeto com logo/imagem de chuteira]**
- "Olá! Sou [seu nome] e vou apresentar o projeto 'Passa a Bola' - uma chuteira inteligente com IoT."
- "Este projeto faz parte da Sprint 3 do Challenge, focando na primeira versão da arquitetura IoT."

#### Aplicação do IoT no Projeto (0:15 - 0:35)
**[SLIDE: Conceitos de IoT - sensores, conectividade, dados]**
- "Nossa solução aplica IoT no futebol através de sensores FSR integrados na chuteira."
- "O sistema coleta dados em tempo real sobre toques na bola, passes e tempo de posse."
- "Isso permite análise de performance automatizada e estatísticas avançadas dos jogadores."

#### Conceitos de IoT (0:35 - 0:50)
**[SLIDE: Diagrama IoT básico - Device → Network → Cloud → Application]**
- "IoT conecta objetos físicos à internet, permitindo coleta e análise de dados."
- "Nossa arquitetura segue o padrão: dispositivo → rede → plataforma → aplicação."

#### Arquitetura Proposta (0:50 - 1:00)
**[SLIDE: Diagrama da arquitetura do projeto]**
- "Nossa arquitetura inclui: chuteira com sensor FSR, plataforma FIWARE e dashboard web."

### DESENVOLVIMENTO (1:00 - 2:15) - 75 segundos

#### Demonstração da Instalação (1:00 - 1:30)
**[TELA: Terminal/Prompt de comando]**
- "Vou demonstrar a instalação da plataforma IoT. Primeiro, clonamos o repositório:"
- `git clone https://github.com/Passa-Bola/Edge`
- "Instalamos as dependências Python:"
- `cd Edge/simulator_chuteira`
- `pip install -r requirements.txt`
- "Isso instala Flask para o Mock IoT Agent e requests para comunicação HTTP."

#### Configuração da Plataforma (1:30 - 1:50)
**[TELA: Código do Mock FIWARE IoT Agent]**
- "Configuramos um Mock do FIWARE IoT Agent usando Flask."
- "Este servidor simula o Orion Context Broker, recebendo dados via HTTP POST."
- "O endpoint `/iot/json` processa dados dos dispositivos IoT."

#### Configuração de Dispositivos Virtuais (1:50 - 2:00)
**[TELA: Código do simulador]**
- "O simulador Python representa nossa chuteira inteligente."
- "Ele gera dados realísticos do sensor FSR e envia para a plataforma."

#### Protocolos e Serviços (2:00 - 2:15)
**[SLIDE: Protocolos - HTTP, JSON, FIWARE]**
- "Usamos HTTP para comunicação, JSON para dados e padrão FIWARE para IoT."
- "Na implementação real, usaríamos MQTT para maior eficiência."

### DEMONSTRAÇÃO (2:15 - 3:00) - 45 segundos

#### Coleta de Dados Simulada (2:15 - 2:35)
**[TELA: Execução do sistema - dois terminais]**
- "Agora vou demonstrar o sistema funcionando. Primeiro, inicio o Mock IoT Agent:"
- `python mock_fiware_iot_agent.py`
- "Em outro terminal, inicio o simulador da chuteira:"
- `python simulator.py`
- "Vemos os dados sendo enviados e recebidos em tempo real."

#### Health Check dos Serviços (2:35 - 2:45)
**[TELA: Teste com curl ou navegador]**
- "Verifico a saúde do serviço:"
- `curl http://localhost:5000/health`
- "Resposta: status UP confirma que o Mock Agent está funcionando."

#### Dashboard e Entidade Lógica (2:45 - 3:00)
**[TELA: Dashboard web aberto no navegador]**
- "O dashboard mostra as estatísticas em tempo real: toques, passes, tempo de posse."
- "Isso demonstra a criação da entidade lógica 'SmartShoe' no sistema IoT."
- "Obrigado! O projeto está funcionando e pronto para expansões futuras."

## Notas para Gravação

### Slides Necessários:
1. Título do projeto com visual de chuteira
2. Conceitos de IoT (sensores, conectividade, dados)
3. Diagrama IoT básico
4. Arquitetura do projeto (diagrama do README)
5. Protocolos utilizados

### Telas a Mostrar:
1. Terminal com comandos de instalação
2. Código do Mock FIWARE IoT Agent
3. Código do simulador
4. Execução em dois terminais
5. Teste de health check
6. Dashboard funcionando no navegador

### Dicas de Apresentação:
- Fale de forma clara e pausada
- Mantenha o ritmo para caber em 3 minutos
- Mostre o código brevemente, foque nos resultados
- Destaque os dados em tempo real no dashboard
- Termine com uma nota positiva sobre o futuro do projeto

### Cronometragem:
- Introdução: 1 minuto (conceitos e arquitetura)
- Desenvolvimento: 1 minuto e 15 segundos (instalação e configuração)
- Demonstração: 45 segundos (execução e resultados)

### Palavras-chave a Mencionar:
- IoT, FIWARE, sensores FSR, tempo real
- HTTP, JSON, Mock Agent, simulador
- Chuteira inteligente, estatísticas, performance
- Arquitetura, dispositivos virtuais, health check

