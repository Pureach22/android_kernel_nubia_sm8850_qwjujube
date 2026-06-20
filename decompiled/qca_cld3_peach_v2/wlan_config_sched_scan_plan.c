__int64 __fastcall wlan_config_sched_scan_plan(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 result; // x0
  int v6; // w4
  int v7; // w8
  int v8; // w8

  result = ucfg_scan_get_user_config_sched_scan_plan();
  if ( (result & 1) == 0 )
    goto LABEL_4;
  v6 = *(_DWORD *)(a3 + 80);
  if ( v6 == 2 )
  {
    a2[5] = 1000 * **(_DWORD **)(a3 + 72);
    a2[8] = *(_DWORD *)(*(_QWORD *)(a3 + 72) + 4LL);
    v8 = *(_DWORD *)(*(_QWORD *)(a3 + 72) + 8LL);
    goto LABEL_5;
  }
  if ( v6 == 1 )
  {
LABEL_4:
    v7 = **(_DWORD **)(a3 + 72);
    a2[8] = 1;
    a2[5] = 1000 * v7;
    v8 = **(_DWORD **)(a3 + 72);
LABEL_5:
    a2[6] = 1000 * v8;
    return result;
  }
  return qdf_trace_msg(72, 2, "%s: Invalid number of scan plans %d !!", "wlan_config_sched_scan_plan", v6);
}
