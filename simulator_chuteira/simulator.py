
import time
import json
import random
import requests

# Configurações do Mock FIWARE IoT Agent
MOCK_FIWARE_URL = "http://localhost:5000/iot/json"
DEVICE_ID = "chuteira001"

# Função para simular dados do sensor FSR
def simulate_fsr_data():
    # Simula um toque na bola (valor alto) ou repouso (valor baixo)
    if random.random() < 0.3:  # 30% de chance de um toque/passe
        return random.randint(500, 1023)  # Valor alto para toque/pressão
    else:
        return random.randint(0, 100)    # Valor baixo para repouso

def main():
    print(f"Simulador da Chuteira Inteligente ({DEVICE_ID}) iniciado.")
    print(f"Enviando dados para o Mock FIWARE IoT Agent em: {MOCK_FIWARE_URL}")

    toques_bola = 0
    passes = 0
    tempo_posse = 0 # Simplificado, pode ser melhorado
    last_touch_time = None

    while True:
        fsr_value = simulate_fsr_data()
        
        if fsr_value > 400: # Limiar para considerar um toque/passe
            toques_bola += 1
            if last_touch_time is not None and (time.time() - last_touch_time) < 2: # Se o toque for rápido, pode ser um passe
                passes += 1
            last_touch_time = time.time()
            tempo_posse += random.uniform(0.1, 0.5) # Simula tempo de posse

        payload = {
            "id": DEVICE_ID,
            "type": "SmartShoe",
            "pressure_sensor": fsr_value,
            "total_touches": toques_bola,
            "total_passes": passes,
            "possession_time": round(tempo_posse, 2)
        }

        try:
            response = requests.post(MOCK_FIWARE_URL, json=payload)
            response.raise_for_status() # Levanta um erro para códigos de status HTTP ruins (4xx ou 5xx)
            print(f"Publicado: {json.dumps(payload)} - Resposta: {response.status_code}")
        except requests.exceptions.ConnectionError:
            print(f"Erro de conexão: Certifique-se de que o Mock FIWARE IoT Agent está rodando em {MOCK_FIWARE_URL}")
        except requests.exceptions.RequestException as e:
            print(f"Erro ao enviar dados: {e}")

        time.sleep(random.uniform(1, 3)) # Envia dados a cada 1-3 segundos

if __name__ == "__main__":
    main()


