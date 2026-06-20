__int64 __fastcall dlm_update_ap_info(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w23
  __int64 v16; // x21
  int v17; // w9
  int v18; // w8
  unsigned int v19; // w8
  unsigned int v20; // w9
  int v21; // w9
  unsigned __int64 v22; // x6
  int v23; // w10
  unsigned int v24; // w9
  __int64 v25; // x5

  result = qdf_mc_timer_get_system_time();
  v15 = *(unsigned __int8 *)(a1 + 136);
  v16 = result;
  if ( (v15 & 4) != 0 && result - *(_QWORD *)(a1 + 88) >= (unsigned __int64)(60000LL * *a2) )
  {
    v19 = *(_DWORD *)(a1 + 140) & 0xFFFFFFBF;
    *(_BYTE *)(a1 + 136) = v15 & 0xDB | 0x20;
    *(_DWORD *)(a1 + 140) = v19;
    *(_QWORD *)(a1 + 128) = result;
    result = qdf_trace_msg(
               0x6Du,
               8u,
               "%s: Userspace avoid list timer expired, moved to monitor list",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "dlm_update_ap_info");
    v18 = *(unsigned __int8 *)(a1 + 136);
    v17 = 1;
    if ( (v18 & 8) == 0 )
      goto LABEL_8;
  }
  else
  {
    v17 = 0;
    v18 = *(unsigned __int8 *)(a1 + 136);
    if ( (v15 & 8) == 0 )
      goto LABEL_8;
  }
  if ( v16 - *(_QWORD *)(a1 + 96) >= (unsigned __int64)(60000LL * *a2) )
  {
    v20 = *(_DWORD *)(a1 + 140) & 0xFFFFFFF8;
    *(_BYTE *)(a1 + 136) = v18 & 0xD7 | 0x20;
    *(_DWORD *)(a1 + 140) = v20;
    *(_QWORD *)(a1 + 128) = v16;
    result = qdf_trace_msg(
               0x6Du,
               8u,
               "%s: Driver avoid list timer expired, moved to monitor list",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "dlm_update_ap_info");
    v18 = *(unsigned __int8 *)(a1 + 136);
    v17 = 1;
  }
LABEL_8:
  if ( (v18 & 2) != 0 && v16 - *(_QWORD *)(a1 + 112) >= (unsigned __int64)(60000LL * a2[1]) )
  {
    v21 = *(_DWORD *)(a1 + 140);
    *(_BYTE *)(a1 + 136) = v18 & 0xDD | 0x20;
    *(_DWORD *)(a1 + 140) = v21 & 0xFFFFFFF8;
    *(_QWORD *)(a1 + 128) = v16;
    result = qdf_trace_msg(
               0x6Du,
               8u,
               "%s: Driver denylist timer expired, moved to monitor list",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "dlm_update_ap_info");
    v18 = *(unsigned __int8 *)(a1 + 136);
    v17 = 1;
  }
  if ( (v18 & 0x10) != 0 )
  {
    v22 = *(unsigned int *)(a1 + 56);
    if ( (_DWORD)v22 && v16 - *(_QWORD *)(a1 + 120) >= v22 )
    {
      LOBYTE(v23) = *(_BYTE *)(a1 + 60);
    }
    else
    {
      if ( !a3 )
        goto LABEL_12;
      v23 = *(char *)(a1 + 60);
      if ( *(char *)(a3 + 60) < v23 )
        goto LABEL_12;
    }
    v24 = *(_DWORD *)(a1 + 140) & 0xFFFFF067;
    *(_BYTE *)(a1 + 136) = v18 & 0xEF;
    *(_DWORD *)(a1 + 140) = v24;
    if ( a3 )
      v25 = (unsigned int)*(char *)(a3 + 60);
    else
      v25 = 0;
    qdf_trace_msg(
      0x6Du,
      8u,
      "%s: Remove BSSID from rssi reject expected RSSI = %d, current RSSI = %d, retry delay required = %d ms, delay = %lu ms",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dlm_update_ap_info",
      (unsigned int)(char)v23,
      v25);
    v18 = *(unsigned __int8 *)(a1 + 136);
    return qdf_trace_msg(
             0x6Du,
             8u,
             "%s: %02x:%02x:%02x:**:**:%02x Old %d Updated reject ap type = %x",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "dlm_update_ap_info",
             *(unsigned __int8 *)(a1 + 16),
             *(unsigned __int8 *)(a1 + 17),
             *(unsigned __int8 *)(a1 + 18),
             *(unsigned __int8 *)(a1 + 21),
             v15,
             v18);
  }
LABEL_12:
  if ( v17 )
    return qdf_trace_msg(
             0x6Du,
             8u,
             "%s: %02x:%02x:%02x:**:**:%02x Old %d Updated reject ap type = %x",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "dlm_update_ap_info",
             *(unsigned __int8 *)(a1 + 16),
             *(unsigned __int8 *)(a1 + 17),
             *(unsigned __int8 *)(a1 + 18),
             *(unsigned __int8 *)(a1 + 21),
             v15,
             v18);
  return result;
}
