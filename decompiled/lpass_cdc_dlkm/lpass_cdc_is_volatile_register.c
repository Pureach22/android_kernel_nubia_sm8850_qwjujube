__int64 __fastcall lpass_cdc_is_volatile_register(__int64 a1, int a2)
{
  __int64 result; // x0
  int v3; // w8

  result = 1;
  if ( a2 > 6167 )
  {
    if ( a2 > 8659 )
    {
      if ( a2 > 12483 )
      {
        if ( a2 > 17255 )
        {
          if ( a2 > 17815 )
          {
            if ( a2 == 17816 )
              return result;
            v3 = 17912;
          }
          else
          {
            if ( a2 == 17256 )
              return result;
            v3 = 17288;
          }
        }
        else
        {
          if ( (unsigned int)(a2 - 12484) <= 8 && ((1 << (a2 + 60)) & 0x111) != 0 )
            return result;
          v3 = 16852;
        }
      }
      else if ( a2 > 9623 )
      {
        if ( (unsigned int)(a2 - 12420) <= 0x3C && ((1LL << ((unsigned __int8)a2 + 124)) & 0x1000000000001111LL) != 0
          || a2 == 9624 )
        {
          return result;
        }
        v3 = 9720;
      }
      else
      {
        if ( a2 == 8660 || a2 == 9064 )
          return result;
        v3 = 9096;
      }
    }
    else if ( a2 <= 6827 )
    {
      if ( a2 > 6699 )
      {
        if ( a2 == 6700 )
          return result;
        v3 = 6704;
      }
      else
      {
        if ( a2 == 6168 )
          return result;
        v3 = 6264;
      }
    }
    else
    {
      switch ( a2 )
      {
        case 7440:
        case 7444:
        case 7448:
        case 7452:
        case 7456:
        case 7504:
        case 7508:
        case 7512:
        case 7516:
        case 7520:
        case 7568:
        case 7572:
        case 7576:
        case 7580:
        case 7584:
          return result;
        case 7441:
        case 7442:
        case 7443:
        case 7445:
        case 7446:
        case 7447:
        case 7449:
        case 7450:
        case 7451:
        case 7453:
        case 7454:
        case 7455:
        case 7457:
        case 7458:
        case 7459:
        case 7460:
        case 7461:
        case 7462:
        case 7463:
        case 7464:
        case 7465:
        case 7466:
        case 7467:
        case 7468:
        case 7469:
        case 7470:
        case 7471:
        case 7472:
        case 7473:
        case 7474:
        case 7475:
        case 7476:
        case 7477:
        case 7478:
        case 7479:
        case 7480:
        case 7481:
        case 7482:
        case 7483:
        case 7484:
        case 7485:
        case 7486:
        case 7487:
        case 7488:
        case 7489:
        case 7490:
        case 7491:
        case 7492:
        case 7493:
        case 7494:
        case 7495:
        case 7496:
        case 7497:
        case 7498:
        case 7499:
        case 7500:
        case 7501:
        case 7502:
        case 7503:
        case 7505:
        case 7506:
        case 7507:
        case 7509:
        case 7510:
        case 7511:
        case 7513:
        case 7514:
        case 7515:
        case 7517:
        case 7518:
        case 7519:
        case 7521:
        case 7522:
        case 7523:
        case 7524:
        case 7525:
        case 7526:
        case 7527:
        case 7528:
        case 7529:
        case 7530:
        case 7531:
        case 7532:
        case 7533:
        case 7534:
        case 7535:
        case 7536:
        case 7537:
        case 7538:
        case 7539:
        case 7540:
        case 7541:
        case 7542:
        case 7543:
        case 7544:
        case 7545:
        case 7546:
        case 7547:
        case 7548:
        case 7549:
        case 7550:
        case 7551:
        case 7552:
        case 7553:
        case 7554:
        case 7555:
        case 7556:
        case 7557:
        case 7558:
        case 7559:
        case 7560:
        case 7561:
        case 7562:
        case 7563:
        case 7564:
        case 7565:
        case 7566:
        case 7567:
        case 7569:
        case 7570:
        case 7571:
        case 7573:
        case 7574:
        case 7575:
        case 7577:
        case 7578:
        case 7579:
        case 7581:
        case 7582:
        case 7583:
          return 0;
        default:
          if ( a2 == 6828 )
            return result;
          v3 = 6832;
          break;
      }
    }
LABEL_51:
    if ( a2 == v3 )
      return result;
    return 0;
  }
  if ( a2 > 5211 )
  {
    if ( (unsigned int)(a2 - 5212) <= 0x28 && ((1LL << ((unsigned __int8)a2 - 92)) & 0x11111111101LL) != 0
      || (unsigned int)(a2 - 5404) <= 0x28 && ((1LL << ((unsigned __int8)a2 - 28)) & 0x11111111101LL) != 0 )
    {
      return result;
    }
    v3 = 5312;
    goto LABEL_51;
  }
  if ( a2 > 4215 )
  {
    if ( a2 > 4967 )
    {
      if ( a2 == 4968 || a2 == 5000 )
        return result;
      v3 = 5120;
    }
    else
    {
      if ( a2 == 4216 || a2 == 4232 )
        return result;
      v3 = 4820;
    }
    goto LABEL_51;
  }
  if ( ((unsigned int)(a2 - 4128) > 0x24 || ((1LL << ((unsigned __int8)a2 - 32)) & 0x1101111011LL) == 0)
    && ((unsigned int)(a2 - 192) > 0x14 || ((1 << (a2 + 64)) & 0x111111) == 0) )
  {
    return 0;
  }
  return result;
}
