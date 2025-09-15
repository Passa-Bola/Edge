
import paho.mqtt.client as mqtt
import time
import json
import random

# Configurações do MQTT
MQTT_BROKER = "broker.hivemq.com"  # Usando um broker público para demonstração
MQTT_PORT = 1883
MQTT_TOPIC = "passabola/chuteira/jogadorA/eventos"
CLIENT_ID = f"python-mqtt-{random.randint(0, 1000)}"

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Conectado ao broker MQTT!")
    else:
        print(f"Falha na conexão, código de retorno {rc}\n")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, CLIENT_ID)
client.on_connect = on_connect

client.connect(MQTT_BROKER, MQTT_PORT, 60)
client.loop_start()

try:
    while True:
        # Simula um toque ou passe
        event_type = random.choice(["toque", "passe"])
        force = random.uniform(10.0, 100.0) # Simula força do impacto
        
        payload = {
            "device_id": CLIENT_ID,
            "event_type": event_type,
            "force": round(force, 2),
            "timestamp": time.time()
        }
        
        client.publish(MQTT_TOPIC, json.dumps(payload))
        print(f"Publicado no tópico {MQTT_TOPIC}: {payload}")
        
        time.sleep(random.uniform(1, 5)) # Intervalo aleatório entre eventos

except KeyboardInterrupt:
    print("Simulador encerrado.")
    client.loop_stop()
    client.disconnect()


