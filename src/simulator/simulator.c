#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "MQTTClient.h"

#define ADDRESS     "tcp://localhost:1883"
#define CLIENTID    "ChuteiraSimulator"
#define TOPIC       "/4jggokgpepnvsb2uv4s40d59ov/chuteira01/iot/json"
#define PAYLOAD_TOQUE   "{\"t\": 1}"
#define PAYLOAD_PASSE   "{\"p\": 1}"
#define QOS         1
#define TIMEOUT     10000L

volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Mensagem com token %d entregue\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    printf("Mensagem recebida no tópico %s\n", topicName);
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause)
{
    printf("\nConexão perdida\n");
    printf("     causa: %s\n", cause);
}

int main(int argc, char* argv[])
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Falha ao conectar, retorno código %d\n", rc);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao broker MQTT em %s\n", ADDRESS);

    while (1)
    {
        int event_type = rand() % 2; // 0 para toque, 1 para passe
        char *payload;

        if (event_type == 0) {
            payload = PAYLOAD_TOQUE;
            printf("Enviando evento: Toque\n");
        } else {
            payload = PAYLOAD_PASSE;
            printf("Enviando evento: Passe\n");
        }

        pubmsg.payload = payload;
        pubmsg.payloadlen = (int)strlen(payload);
        pubmsg.qos = QOS;
        pubmsg.retained = 0;
        deliveredtoken = 0;

        MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
        printf("Aguardando entrega da mensagem...\n");
        while (deliveredtoken != token);

        sleep(rand() % 4 + 2); // Espera entre 2 e 5 segundos
    }

    MQTTClient_disconnect(client, 1000);
    MQTTClient_destroy(&client);
    return rc;
}
