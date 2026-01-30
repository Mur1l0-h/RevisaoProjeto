Semáforo Inteligente 🚦
Este projeto visa a redução de acidentes de trânsito e a melhoria da fluidez viária através de um sistema semafórico adaptativo. O sistema ajusta automaticamente os tempos de sinalização com base em condições climáticas e no fluxo de veículos detectado por sensores.
+4

📑 Fases do Projeto
O desenvolvimento foi dividido em quatro etapas fundamentais:

Fase 1: Levantamento de Requisitos
Definição das funcionalidades essenciais e metas de desempenho:


Controle Adaptativo: Ajuste automático dos tempos com base em sensores físicos.
+1


Modo de Segurança: Ativação automática de luz amarela intermitente em caso de falha de sensores ou comunicação.
+1


Operação Climática: Adaptação específica para condições de chuva intensa.
+1


Disponibilidade: Meta de operação de 99%, especialmente em horários de pico.

Fase 2: Modelagem do Sistema
Estruturação da arquitetura de rede e fluxo lógico:


Arquitetura de Rede: Utilização de roteadores, switches, access points e firewall para garantir comunicação rápida e segura entre os dispositivos.
+1


Servidor Local: Implementação de um servidor para gerenciar dados e softwares do sistema localmente.
+1

Fase 3: Infraestrutura e Segurança
Configuração do ambiente operacional e políticas de proteção:


Sistema Operacional: Uso do Windows Server como servidor principal devido à sua popularidade e facilidade de acesso.


Políticas de Segurança: Implementação do princípio do menor privilégio para usuários, controle rigoroso de senhas e logs de auditoria para rastreabilidade.


Continuidade: Rotinas de backup diário dos dados e procedimentos claros para manutenção em caso de falha de sensores.
+1

Fase 4: Algoritmo do MVP
Desenvolvimento da lógica central do semáforo:


Tecnologias: JavaScript, HTML5 e CSS.


Entradas: O sistema processa dados de sensores de movimento, umidade e luminosidade.


Comportamento: A lógica altera o estado do semáforo dinamicamente para aumentar a segurança e melhorar o fluxo conforme as condições do ambiente mudam.

⚙️ Funcionamento do Algoritmo
O sistema opera em um ciclo contínuo de monitoramento:


Monitoramento: Sensores detectam o fluxo de carros e a presença de chuva.


Processamento: Se o fluxo estiver alto, o tempo de sinal verde é estendido. Se houver chuva forte, os tempos são ajustados para garantir frenagens seguras.
+1


Segurança (Fail-Safe): Se o sensor falhar ou o servidor central ficar inacessível, o sistema entra em modo de segurança (amarelo piscante) ou passa a rodar localmente.
+1

👥 Equipe
Murilo Almeida 

Joel Neto 

Júlio Sena