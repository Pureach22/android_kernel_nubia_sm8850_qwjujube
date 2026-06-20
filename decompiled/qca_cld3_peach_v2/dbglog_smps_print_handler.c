__int64 __fastcall dbglog_smps_print_handler(
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
  unsigned int v9; // w9
  const char *v10; // x4
  bool v11; // zf
  unsigned int v12; // w9
  const char *v13; // x4

  result = 1;
  switch ( a3 )
  {
    case 1:
      dbglog_printf(a4, a2, "STA_SMPS Create PDEV ctx %#x", *a6);
      return 1;
    case 2:
      dbglog_printf(a4, a2, "STA_SMPS Create Virtual Chan ctx %#x", *a6);
      return 1;
    case 3:
      dbglog_printf(a4, a2, "STA_SMPS Delete Virtual Chan ctx %#x", *a6);
      return 1;
    case 4:
      dbglog_printf(a4, a2, "STA_SMPS Create STA ctx %#x", *a6);
      return 1;
    case 5:
      dbglog_printf(a4, a2, "STA_SMPS Delete STA ctx %#x", *a6);
      return 1;
    case 6:
    case 7:
      return result;
    case 8:
      v9 = a6[1];
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          v10 = "STATIC";
        }
        else if ( v9 == 3 )
        {
          v10 = "DYNAMIC";
        }
        else
        {
          v10 = "UNKNOWN";
        }
      }
      else
      {
        v10 = "DISABLED";
      }
      dbglog_printf(a4, a2, "STA_SMPS STA %#x Signal SMPS mode as %s; cb_flags %#x", *a6, v10, a6[2]);
      return 1;
    case 9:
    case 10:
    case 11:
    case 12:
      goto LABEL_5;
    case 13:
      dbglog_printf(a4, a2, "STA_SMPS_DBGID_DTIM_EBT_EVENT_CHMASK_UPDATE");
      return 1;
    case 14:
      dbglog_printf(
        a4,
        a2,
        "STA_SMPS_DBGID_DTIM_CHMASK_UPDATE tx_mask %#x rx_mask %#x arb_dtim_mask %#x",
        *a6,
        a6[1],
        a6[2]);
      return 1;
    case 15:
      dbglog_printf(a4, a2, "STA_SMPS_DBGID_DTIM_BEACON_EVENT_CHMASK_UPDATE");
      return 1;
    case 16:
      v7 = *a6;
      if ( *a6 == 1 )
      {
        v8 = "SLEEP";
      }
      else if ( v7 == 2 )
      {
        v8 = "AWAKE";
      }
      else
      {
        v11 = v7 == 3;
        v8 = "FULL_SLEEP";
        if ( !v11 )
          v8 = "UNKNOWN";
      }
      v12 = a6[1];
      switch ( v12 )
      {
        case 1u:
          v13 = "SLEEP";
          break;
        case 2u:
          v13 = "AWAKE";
          break;
        case 3u:
          v13 = "FULL_SLEEP";
          break;
        default:
          v13 = "UNKNOWN";
          break;
      }
      dbglog_printf(a4, a2, "STA_SMPS_DBGID_DTIM_POWER_STATE_CHANGE cur_pwr_state %s new_pwr_state %s", v8, v13);
      return 1;
    case 17:
      dbglog_printf(
        a4,
        a2,
        "STA_SMPS_DBGID_DTIM_CHMASK_UPDATE_SLEEP tx_mask %#x rx_mask %#x orig_rx %#x dtim_rx %#x",
        *a6,
        a6[1],
        a6[2],
        a6[3]);
      return 1;
    case 18:
      dbglog_printf(
        a4,
        a2,
        "STA_SMPS_DBGID_DTIM_CHMASK_UPDATE_AWAKE tx_mask %#x rx_mask %#x orig_rx %#x",
        *a6,
        a6[1],
        a6[2]);
      return 1;
    default:
      if ( a3 == 1000 )
      {
        dbglog_sm_print(
          a4,
          a2,
          a5,
          a6,
          "STA_SMPS SM",
          dbglog_smps_print_handler_states,
          7,
          dbglog_smps_print_handler_events,
          11);
        return 1;
      }
      else
      {
LABEL_5:
        dbglog_printf(a4, a2, "STA_SMPS: UNKNOWN DBGID!");
        return 0;
      }
  }
}
