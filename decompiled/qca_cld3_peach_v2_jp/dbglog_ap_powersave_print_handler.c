__int64 __fastcall dbglog_ap_powersave_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        __int16 a5,
        unsigned int *a6)
{
  unsigned int v6; // w8
  const char *v7; // x10
  const char *v8; // x2
  bool v9; // zf
  const char *v10; // x9
  const char *v11; // x6
  const char *v12; // x7
  unsigned int v13; // w11
  __int64 v14; // x4
  unsigned int v15; // w8
  const char *v16; // x5
  const char *v17; // x6
  unsigned int v18; // w8
  const char *v19; // x4
  const char *v20; // x5
  const char *v21; // x4
  const char *v22; // x9
  __int64 result; // x0
  unsigned int v24; // w11
  const char *v25; // x4
  unsigned int v26; // w8
  const char *v27; // x5
  const char *v28; // x6

  switch ( a3 )
  {
    case 1:
      if ( a5 != 2 )
        goto LABEL_62;
      v6 = *a6;
      v7 = "set";
      v8 = "AP PS: TIM update AID=%u %s";
      v9 = a6[1] == 0;
      v10 = "clear";
      goto LABEL_46;
    case 2:
      if ( a5 == 2 )
      {
        v6 = *a6;
        v7 = "enabled";
        v8 = "AP PS: AID=%u power save %s";
        v9 = a6[1] == 0;
        v10 = "disabled";
LABEL_46:
        if ( v9 )
          v21 = v10;
        else
          v21 = v7;
        dbglog_printf(a4, a2, v8, v6, v21);
      }
      goto LABEL_62;
    case 3:
      if ( a5 == 3 )
        dbglog_printf(a4, a2, "AP PS: AID=%u pspoll response tid=%u flags=%x", *a6, a6[1], a6[2]);
      goto LABEL_62;
    case 4:
      if ( a5 == 1 )
        dbglog_printf(a4, a2, "AP PS: create peer AID=%u", *a6);
      goto LABEL_62;
    case 5:
      if ( a5 == 1 )
        dbglog_printf(a4, a2, "AP PS: delete peer AID=%u", *a6);
      goto LABEL_62;
    case 6:
      dbglog_printf(a4, a2, "AP PS: vdev create");
      goto LABEL_62;
    case 7:
      dbglog_printf(a4, a2, "AP PS: vdev delete");
      goto LABEL_62;
    case 8:
      if ( a5 == 3 )
        dbglog_printf(a4, a2, "AP PS: AID=%u advertised=%#x buffered=%#x", *a6, a6[1], a6[2]);
      goto LABEL_62;
    case 9:
      if ( a5 == 4 )
      {
        v24 = a6[3];
        if ( a6[1] )
          v25 = "(usp active) ";
        else
          v25 = (const char *)&unk_8B9E43;
        v26 = *a6;
        if ( a6[2] )
          v27 = "(pending usp) ";
        else
          v27 = (const char *)&unk_8B9E43;
        if ( v24 )
          v28 = "(pending poll response)";
        else
          v28 = (const char *)&unk_8B9E43;
        dbglog_printf(a4, a2, "AP PS: AID=%u select next response %s%s%s", v26, v25, v27, v28);
      }
      goto LABEL_62;
    case 10:
      if ( a5 == 3 )
        dbglog_printf(a4, a2, "AP PS: AID=%u START SP tsf=%#x (%u)", *a6, a6[1], a6[2]);
      goto LABEL_62;
    case 11:
      if ( a5 == 3 )
        dbglog_printf(a4, a2, "AP PS: AID=%u EOSP eosp_tsf=%#x trigger_tsf=%#x", *a6, a6[1], a6[2]);
      goto LABEL_62;
    case 12:
      if ( a5 == 4 )
      {
        v13 = a6[3];
        v15 = *a6;
        v14 = a6[1];
        if ( a6[2] )
          v16 = "(usp active) ";
        else
          v16 = (const char *)&unk_8B9E43;
        if ( v13 )
          v17 = "(send_n in progress)";
        else
          v17 = (const char *)&unk_8B9E43;
        dbglog_printf(a4, a2, "AP PS: AID=%u TRIGGER tsf=%#x %s%s", v15, v14, v16, v17);
      }
      goto LABEL_62;
    case 13:
      if ( a5 == 4 )
        dbglog_printf(a4, a2, "AP PS: AID=%u DUP TRIGGER tsf=%#x seq=%u ac=%u", *a6, a6[1], a6[2], a6[3]);
      goto LABEL_62;
    case 14:
      if ( a5 == 5 )
        dbglog_printf(
          a4,
          a2,
          "AP PS: AID=%u UAPSD response tid=%u, n_mpdu=%u flags=%#x max_sp=%u current_sp=%u",
          *a6,
          a6[1],
          a6[2],
          a6[3],
          HIWORD(a6[4]),
          (unsigned __int16)a6[4]);
      goto LABEL_62;
    case 15:
      if ( a5 == 5 )
      {
        if ( a6[3] )
          v11 = "(usp active) ";
        else
          v11 = (const char *)&unk_8B9E43;
        if ( a6[4] )
          v12 = "(pending poll response)";
        else
          v12 = (const char *)&unk_8B9E43;
        dbglog_printf(a4, a2, "AP PS: AID=%u SEND_COMPLETE fc=%#x qos=%#x %s%s", *a6, a6[1], a6[2], v11, v12);
      }
      goto LABEL_62;
    case 16:
      if ( a5 == 3 )
      {
        v18 = *a6;
        if ( a6[1] )
          v19 = "(usp active) ";
        else
          v19 = (const char *)&unk_8B9E43;
        if ( a6[2] )
          v20 = "(pending poll response)";
        else
          v20 = (const char *)&unk_8B9E43;
        dbglog_printf(a4, a2, "AP PS: AID=%u SEND_N_COMPLETE %s%s", v18, v19, v20);
      }
      goto LABEL_62;
    case 17:
      if ( a5 == 4 )
        dbglog_printf(
          a4,
          a2,
          "AP PS: AID=%u detected out-of-sync now=%u tx_waiting=%u txq_depth=%u",
          *a6,
          a6[1],
          a6[2],
          a6[3]);
      goto LABEL_62;
    case 18:
      if ( a5 == 4 )
      {
        v22 = "DATA";
        if ( *a6 == 17 )
          v22 = "MGMT";
        dbglog_printf(a4, a2, "AP PS: CAB %s n_mpdus=%u, flags=%x, extra=%u", v22, a6[1], a6[2], a6[3]);
      }
LABEL_62:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
