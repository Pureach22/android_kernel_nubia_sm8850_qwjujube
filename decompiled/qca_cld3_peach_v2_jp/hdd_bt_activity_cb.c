__int64 __fastcall hdd_bt_activity_cb(__int64 a1, int a2)
{
  __int64 result; // x0
  char v5; // w8
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  result = _wlan_hdd_validate_context(a1, "hdd_bt_activity_cb");
  if ( !(_DWORD)result )
  {
    if ( a2 > 3 )
    {
      switch ( a2 )
      {
        case 4:
          v5 = *(_BYTE *)(a1 + 3248) & 0xFD;
          break;
        case 7:
          v5 = *(_BYTE *)(a1 + 3248) | 4;
          break;
        case 8:
          v5 = *(_BYTE *)(a1 + 3248) & 0xFB;
          break;
        default:
          return result;
      }
    }
    else
    {
      switch ( a2 )
      {
        case 1:
          v5 = *(_BYTE *)(a1 + 3248) | 1;
          break;
        case 2:
          v5 = *(_BYTE *)(a1 + 3248) & 0xFE;
          break;
        case 3:
          v5 = *(_BYTE *)(a1 + 3248) | 2;
          break;
        default:
          return result;
      }
    }
    v6 = *(_QWORD *)a1;
    *(_BYTE *)(a1 + 3248) = v5;
    ucfg_scan_set_bt_activity(v6, v5 & 1);
    ucfg_mlme_set_bt_profile_con(*(_QWORD *)a1, (*(_BYTE *)(a1 + 3248) & 4) != 0);
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: a2dp_active: %d vo_active: %d connected:%d",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "hdd_bt_activity_cb",
             *(_BYTE *)(a1 + 3248) & 1,
             (*(unsigned __int8 *)(a1 + 3248) >> 1) & 1,
             (*(unsigned __int8 *)(a1 + 3248) >> 2) & 1);
  }
  return result;
}
