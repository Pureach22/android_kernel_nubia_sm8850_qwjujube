__int64 __fastcall dbglog_wal_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int *a6)
{
  __int64 result; // x0
  unsigned int v7; // w8
  const char *v8; // x8
  __int64 v9; // x8
  const char *v10; // x8
  __int64 v11; // x8
  const char *v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  const char *v15; // x8
  bool v16; // zf
  unsigned int v17; // w9
  const char *v18; // x4

  result = 0;
  switch ( a3 )
  {
    case 3:
      if ( (unsigned __int16)a5 == 3 )
      {
        v7 = *a6;
        if ( *a6 == 1 )
        {
          v8 = "NETWORK SLEEP";
        }
        else if ( v7 == 2 )
        {
          v8 = "AWAKE";
        }
        else
        {
          v16 = v7 == 3;
          v8 = "SYSTEM SLEEP";
          if ( !v16 )
            v8 = "UNKNOWN";
        }
        v17 = a6[1];
        switch ( v17 )
        {
          case 1u:
            v18 = "NETWORK SLEEP";
            break;
          case 2u:
            v18 = "AWAKE";
            break;
          case 3u:
            v18 = "SYSTEM SLEEP";
            break;
          default:
            v18 = "UNKNOWN";
            break;
        }
        dbglog_printf(a4, a2, "WAL %s => %s, req_count=%u", v8, v18, a6[2]);
      }
      return 1;
    case 4:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
      return result;
    case 5:
      if ( (unsigned __int16)a5 == 4 )
        dbglog_printf(
          a4,
          a2,
          "WAL channel change (force reset) freq=%u, flags=%u mode=%u rx_ok=%u tx_ok=%u",
          (unsigned __int16)*a6,
          HIWORD(*a6),
          a6[1],
          a6[2],
          a6[3]);
      return 1;
    case 6:
      if ( (unsigned __int16)a5 == 2 )
        dbglog_printf(
          a4,
          a2,
          "WAL channel change freq=%u, mode=%u flags=%u rx_ok=1 tx_ok=1",
          (unsigned __int16)*a6,
          HIWORD(*a6),
          a6[1]);
      return 1;
    case 7:
      if ( (unsigned __int16)a5 == 1 )
      {
        v14 = *a6;
        if ( (unsigned int)v14 > 2 )
          v15 = "UNKNOWN";
        else
          v15 = off_B2CDF0[v14];
        dbglog_printf(a4, a2, "WAL %s vdev started", v15);
      }
      return 1;
    case 8:
      v13 = *a6;
      if ( (unsigned int)v13 > 2 )
        dbglog_printf(a4, a2, "WAL %s vdev stopped", "UNKNOWN");
      else
        dbglog_printf(a4, a2, "WAL %s vdev stopped", off_B2CDF0[v13]);
      return 1;
    case 9:
      v11 = *a6;
      if ( (unsigned int)v11 > 2 )
        v12 = "UNKNOWN";
      else
        v12 = off_B2CDF0[v11];
      dbglog_printf(a4, a2, "WAL %s vdev up, count=%u", v12, a6[1]);
      return 1;
    case 10:
      v9 = *a6;
      if ( (unsigned int)v9 > 2 )
        v10 = "UNKNOWN";
      else
        v10 = off_B2CDF0[v9];
      dbglog_printf(a4, a2, "WAL %s vdev down, count=%u", v10, a6[1]);
      return 1;
    case 49:
      dbglog_printf(
        a4,
        a2,
        "WAL Tx Mgmt frame desc_id=0x%x, seq=0x%x, type=0x%x, len=0x%x islocal=0x%x",
        *a6,
        a6[1],
        a6[2],
        HIWORD(a6[3]),
        (unsigned __int16)a6[3]);
      return 1;
    case 50:
      dbglog_printf(a4, a2, "WAL Tx Data frame msdu_id=0x%x, seq=0x%x, type=0x%x, len=0x%x", *a6, a6[1], a6[2], a6[3]);
      return 1;
    case 51:
      dbglog_printf(a4, a2, "WAL Tx enqueue discard msdu_id=0x%x", *a6);
      return 1;
    case 52:
      dbglog_printf(a4, a2, "WAL Tx Mgmt frame completion desc_id=0x%x, status=0x%x, islocal=0x%x", *a6, a6[1], a6[2]);
      return 1;
    case 53:
      dbglog_printf(a4, a2, "WAL Tx Data frame completion desc_id=0x%x, status=0x%x, seq=0x%x", *a6, a6[1], a6[2]);
      return 1;
    case 54:
      dbglog_printf(a4, a2, "WAL PCU cycle counter value at reset:%x", *a6);
      return 1;
    case 60:
      dbglog_printf(a4, a2, "WAL_DBGID_SET_HW_CHAINMASK pdev=%d, txchain=0x%x, rxchain=0x%x", *a6, a6[1], a6[2]);
      return 1;
    case 61:
      dbglog_printf(a4, a2, "WAL_DBGID_SET_HW_CHAINMASK_TXRX_STOP_FAIL rxstop=%d, txstop=%d", *a6, a6[1]);
      return 1;
    case 62:
      dbglog_printf(a4, a2, "WAL_DBGID_GET_HW_CHAINMASK txchain=0x%x, rxchain=0x%x", *a6, a6[1]);
      return 1;
    case 63:
      dbglog_printf(a4, a2, "WAL_DBGID_SMPS_DISABLE");
      return 1;
    case 64:
      dbglog_printf(a4, a2, "WAL_DBGID_SMPS_ENABLE_HW_CNTRL low_pwr_mask=0x%x, high_pwr_mask=0x%x", *a6, a6[1]);
      return 1;
    case 65:
      dbglog_printf(a4, a2, "WAL_DBGID_SMPS_SWSEL_CHAINMASK low_pwr=0x%x, chain_mask=0x%x", *a6, a6[1]);
      return 1;
    default:
      if ( a3 != 1000 )
        return result;
      dbglog_sm_print(
        a4,
        a2,
        a5,
        a6,
        "TID PAUSE",
        dbglog_wal_print_handler_states,
        6,
        dbglog_wal_print_handler_events,
        8);
      return 1;
  }
}
