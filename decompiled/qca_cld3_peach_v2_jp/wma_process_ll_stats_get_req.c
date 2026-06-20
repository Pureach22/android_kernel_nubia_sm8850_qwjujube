__int64 __fastcall wma_process_ll_stats_get_req(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x4
  __int64 v21; // x8
  __int64 result; // x0
  const char *v23; // x2
  const char *v24; // x2
  unsigned __int8 v25; // [xsp+8h] [xbp-18h]
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  if ( !a1 || !a2 )
  {
    v23 = "%s: input pointer is NULL";
LABEL_9:
    qdf_trace_msg(0x36u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_ll_stats_get_req");
LABEL_16:
    result = 16;
    goto LABEL_17;
  }
  if ( (wma_is_vdev_valid(*(unsigned __int8 *)(a2 + 4), a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    v20 = *(unsigned __int8 *)(a2 + 4);
    v24 = "%s: vdev:%d not created yet";
LABEL_15:
    qdf_trace_msg(0x36u, 2u, v24, v12, v13, v14, v15, v16, v17, v18, v19, "wma_process_ll_stats_get_req", v20);
    goto LABEL_16;
  }
  v20 = *(unsigned __int8 *)(a2 + 4);
  v25 = *(_BYTE *)(a2 + 4);
  v21 = *(_QWORD *)(a1[65] + 488 * v20);
  if ( !v21 )
  {
    v24 = "%s: Failed to get vdev for vdev_%d";
    goto LABEL_15;
  }
  qdf_mem_copy(v26, (const void *)(v21 + 74), 6u);
  if ( *(_BYTE *)(a2 + 20) == 1 && *(_DWORD *)(a1[65] + 488LL * v25 + 164) == 2 )
    result = wmi_process_unified_ll_stats_get_sta_cmd(*a1);
  else
    result = wmi_unified_process_ll_stats_get_cmd(*a1);
  if ( (_DWORD)result )
  {
    v23 = "%s: Failed to send get link stats request";
    goto LABEL_9;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
