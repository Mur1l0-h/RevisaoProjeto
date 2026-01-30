
const Config = {
    tempoVerdePadrao: 5000,
    tempoVerdePico: 10000,
    tempoAmareloPadrao: 2000,
    tempoAmareloChuva: 4000,
    tempoVermelho: 5000
};

let historicoFluxo = []; 

const luzes = {
    vermelha: document.getElementById('luz-vermelha'),
    amarela: document.getElementById('luz-amarela'),
    verde: document.getElementById('luz-verde')
};

const log = document.getElementById('log');


function setLuz(corAtiva) {
    Object.values(luzes).forEach(l => l.classList.remove('ativo'));
    if (corAtiva) luzes[corAtiva].classList.add('ativo');
}

async function iniciarCiclo() {
    while (true) {
     
        const fluxo = document.getElementById('sensor-fluxo').value;
        const clima = document.getElementById('sensor-clima').value;
        const sensorOk = document.getElementById('sensor-status').value === 'ok';
        const servidorOnline = document.getElementById('status-servidor').value === 'online';

        historicoFluxo.push({ timestamp: new Date(), nivel: fluxo });
        if (historicoFluxo.length > 10) historicoFluxo.shift(); 

        if (!sensorOk) {
            log.innerHTML = "ALERTA: Falha no sensor! Modo Segurança Ativo.";
            setLuz('amarela');
            await sleep(500);
            setLuz(null);
            await sleep(500);
            continue;
        }

        const modoExecucao = servidorOnline ? "Cloud" : "Local (Edge)";

        let tempoVerde = (fluxo === 'alto') ? Config.tempoVerdePico : Config.tempoVerdePadrao;
        let tempoAmarelo = (clima === 'chuva') ? Config.tempoAmareloChuva : Config.tempoAmareloPadrao;

        log.innerHTML = `Modo: ${modoExecucao} | Verde: ${tempoVerde}ms`;
        setLuz('verde');
        await sleep(tempoVerde);

        log.innerHTML = `Modo: ${modoExecucao} | Amarelo: ${tempoAmarelo}ms`;
        setLuz('amarela');
        await sleep(tempoAmarelo);

        log.innerHTML = `Modo: ${modoExecucao} | Vermelho: ${Config.tempoVermelho}ms`;
        setLuz('vermelha');
        await sleep(Config.tempoVermelho);
    }
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

iniciarCiclo();