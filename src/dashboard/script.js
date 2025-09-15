document.addEventListener('DOMContentLoaded', () => {
    const totalToquesElement = document.getElementById('total-toques');
    const totalPassesElement = document.getElementById('total-passes');

    let totalToques = 0;
    let totalPasses = 0;

    // Configuração do gráfico
    const ctx = document.getElementById('eventChart').getContext('2d');
    const eventChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['Toques', 'Passes'],
            datasets: [{
                label: 'Contagem de Eventos',
                data: [totalToques, totalPasses],
                backgroundColor: [
                    'rgba(255, 99, 132, 0.6)',
                    'rgba(54, 162, 235, 0.6)'
                ],
                borderColor: [
                    'rgba(255, 99, 132, 1)',
                    'rgba(54, 162, 235, 1)'
                ],
                borderWidth: 1
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });

    // Função para buscar dados do FIWARE
    async function fetchDataFromFIWARE() {
        try {
            // URL do Orion Context Broker para a entidade da chuteira virtual
            const response = await fetch('http://localhost:1026/v2/entities/urn:ngsi-ld:Chuteira:001?type=Chuteira', {
                headers: {
                    'fiware-service': 'passa_a_bola',
                    'fiware-servicepath': '/'
                }
            });
            const data = await response.json();

            // Atualizar contadores
            totalToques = data.contagem_toques ? data.contagem_toques.value : 0;
            totalPasses = data.contagem_passes ? data.contagem_passes.value : 0;

            totalToquesElement.textContent = totalToques;
            totalPassesElement.textContent = totalPasses;

            // Atualizar gráfico
            eventChart.data.datasets[0].data[0] = totalToques;
            eventChart.data.datasets[0].data[1] = totalPasses;
            eventChart.update();

        } catch (error) {
            console.error('Erro ao buscar dados do FIWARE:', error);
            // Pode-se adicionar uma mensagem de erro no dashboard
        }
    }

    // Atualizar dados a cada 2 segundos
    setInterval(fetchDataFromFIWARE, 2000);

    // Chamar a função uma vez ao carregar para exibir os dados iniciais
    fetchDataFromFIWARE();
});

