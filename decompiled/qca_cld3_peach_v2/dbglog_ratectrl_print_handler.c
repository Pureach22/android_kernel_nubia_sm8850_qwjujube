__int64 __fastcall dbglog_ratectrl_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int *a6)
{
  __int64 v6; // x4
  unsigned int v7; // w8
  __int64 v8; // x6
  unsigned int v9; // w9
  __int64 v10; // x7
  const char *v11; // x2
  unsigned int v12; // w8
  unsigned int v13; // w10

  if ( a3 <= 3 )
  {
    switch ( a3 )
    {
      case 1:
        v7 = *a6;
        v6 = a6[1];
        v9 = a6[2];
        v8 = a6[3];
        v10 = a6[4];
        v11 = "RATE: ChainMask %d, phymode %d, ni_flags 0x%08x, vht_mcs_set 0x%04x, ht_mcs_set 0x%04x";
LABEL_15:
        dbglog_printf(a4, a2, v11, v7, v6, v9, v8, v10);
        return 1;
      case 2:
        dbglog_printf(a4, a2, "RATE: NEW NSS %d\n", *a6);
        break;
      case 3:
        dbglog_printf(a4, a2, "RATE: Chainmask ERR %d %d %d\n", *a6, a6[1], a6[2]);
        break;
    }
  }
  else
  {
    if ( a3 <= 5 )
    {
      if ( a3 == 4 )
      {
        dbglog_printf(a4, a2, "RATE: WARN1: rate %d flags 0x%08x\n", *a6, a6[1]);
        return 1;
      }
      v7 = *a6;
      v6 = a6[1];
      v9 = a6[2];
      v8 = a6[3];
      v10 = a6[4];
      v11 = "ratectrl_dbgid_wal_rcquery [rix1 %d rix2 %d rix3 %d proberix %d ppduflag 0x%x] ";
      goto LABEL_15;
    }
    if ( a3 == 6 )
    {
      dbglog_printf(a4, a2, "ratectrl_dbgid_wal_rcupdate [numelems %d ppduflag 0x%x] ", *a6, a6[1]);
      return 1;
    }
    if ( a3 == 7 )
    {
      v12 = *a6;
      v13 = a6[1];
      if ( *a6 == 254 )
      {
        dbglog_printf(
          a4,
          a2,
          "gtx_cfg_addr [RTMask0@0x%x PERThreshold@0x%x gtxTPCMin@0x%x userGtxMask@0x%x] ",
          v13,
          a6[2],
          a6[3],
          a6[4]);
        return 1;
      }
      if ( v12 != 255 )
      {
        dbglog_printf(
          a4,
          a2,
          "gtx_update [act %d bw %d rix 0x%x tpc %d per %d lastrssi %d] ",
          v12,
          v13,
          a6[2],
          a6[3],
          a6[4],
          a6[5]);
        return 1;
      }
      v9 = a6[2];
      v8 = a6[3];
      v7 = v13 >> 8;
      v10 = a6[4];
      v11 = "GtxInitPwrCfg [bw[last %d|cur %d] rtcode 0x%x tpc %d tpc_init_pwr_cfg %d] ";
      v6 = (unsigned __int8)a6[1];
      goto LABEL_15;
    }
  }
  return 1;
}
