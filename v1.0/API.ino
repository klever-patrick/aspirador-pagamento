void APIAtualizar()
{
  switch (globalEventoAPI) {
    case NADA:
      
    break;
    case LED_VERMELHO:
//      LEDVermelho();
    break;
    case LED_VERDE:
//      LEDVerde();
    break;
    case LED_AZUL:
//      LEDAzul();
    break;
    case DESTRAVAR:
      destravar();
    break;
    case BUZZER1:
      buzzer1();
    break;
    case BUZZER2:
      buzzer2();
    break;
    default:
    // statements
    break;
  }
}
