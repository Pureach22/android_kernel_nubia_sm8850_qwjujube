__int64 __fastcall dbglog_ani_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int *a6)
{
  switch ( a3 )
  {
    case 0:
      dbglog_printf(
        a4,
        a2,
        "ANI POLLING: AccumListenTime %d ListenTime %d ofdmphyerr %d cckphyerr %d",
        *a6,
        a6[1],
        a6[2],
        a6[3]);
      break;
    case 1:
      dbglog_printf(a4, a2, "ANI CONTROL ofdmlevel %d ccklevel %d\n", *a6);
      break;
    case 2:
      dbglog_printf(a4, a2, "ANI ofdm_control firstep %d cycpwr %d\n", *a6, a6[1]);
      break;
    case 3:
      dbglog_printf(a4, a2, "ANI cck_control mrc_cck %d barker_threshold %d\n", *a6, a6[1]);
      break;
    case 4:
      dbglog_printf(a4, a2, "ANI resetting resetflag %d resetCause %8x channel index %d", *a6, a6[1], a6[2]);
      break;
    case 5:
      dbglog_printf(a4, a2, "ANI Restart");
      break;
    case 6:
      dbglog_printf(
        a4,
        a2,
        "ANI UPDATE ofdm level %d firstep %d firstep_low %d cycpwr_thr %d self_corr_low %d",
        *a6,
        a6[1],
        a6[2],
        a6[3],
        a6[4]);
      break;
    case 7:
      dbglog_printf(a4, a2, "ANI  UPDATE cck level %d firstep %d firstep_low %d mrc_cck %d", *a6, a6[1], a6[2], a6[3]);
      break;
    case 8:
      dbglog_printf(a4, a2, "ANI firstep %d firstep_low %d", *a6, a6[1]);
      break;
    case 9:
      dbglog_printf(a4, a2, "ANI cypwr_thresh %d", *a6);
      break;
    case 10:
      dbglog_printf(a4, a2, "ANI mrc_cck %d", *a6);
      break;
    case 11:
      dbglog_printf(a4, a2, "ANI self_corr_low %d", *a6);
      break;
    case 12:
      dbglog_printf(a4, a2, "ANI Enable:  %d", *a6);
      break;
    case 13:
      dbglog_printf(a4, a2, "ANI CURRENT LEVEL ofdm level %d cck level %d", *a6, a6[1]);
      break;
    case 14:
      dbglog_printf(a4, a2, "ANI Configure poll period to %d", *a6);
      break;
    case 15:
      dbglog_printf(a4, a2, "ANI Configure listen period to %d", *a6);
      break;
    case 16:
      dbglog_printf(a4, a2, "ANI Configure ofdm level to %d", *a6);
      break;
    case 17:
      dbglog_printf(a4, a2, "ANI Configure cck level to %d", *a6);
      break;
    default:
      dbglog_printf(a4, a2, "ANI arg1 %d arg2 %d arg3 %d", *a6, a6[1], a6[2]);
      break;
  }
  return 1;
}
