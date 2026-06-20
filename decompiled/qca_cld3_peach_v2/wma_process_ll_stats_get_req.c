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
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w8
  __int64 v31; // x4
  int v32; // w10
  __int64 v33; // x11
  __int64 v34; // x9
  __int64 result; // x0
  const char *v36; // x2
  const char *v37; // x2
  unsigned __int8 v38; // [xsp+Ch] [xbp-24h]
  __int64 v39; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v40; // [xsp+1Ch] [xbp-14h] BYREF
  int v41; // [xsp+24h] [xbp-Ch]
  __int64 v42; // [xsp+28h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v40 = 0;
  v39 = 0;
  if ( !a1 || !a2 )
  {
    v36 = "%s: input pointer is NULL";
LABEL_13:
    qdf_trace_msg(0x36u, 2u, v36, a3, a4, a5, a6, a7, a8, a9, a10, "wma_process_ll_stats_get_req");
LABEL_17:
    result = 16;
    goto LABEL_18;
  }
  if ( (wma_is_vdev_valid(*(unsigned __int8 *)(a2 + 4), a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
  {
    v20 = *(unsigned __int8 *)(a2 + 4);
    v37 = "%s: vdev:%d not created yet";
LABEL_16:
    qdf_trace_msg(0x36u, 2u, v37, v12, v13, v14, v15, v16, v17, v18, v19, "wma_process_ll_stats_get_req", v20);
    goto LABEL_17;
  }
  v20 = *(unsigned __int8 *)(a2 + 4);
  v38 = *(_BYTE *)(a2 + 4);
  v21 = *(_QWORD *)(a1[65] + 488 * v20);
  if ( !v21 )
  {
    v37 = "%s: Failed to get vdev for vdev_%d";
    goto LABEL_16;
  }
  qdf_mem_copy(&v39, (const void *)(v21 + 74), 6u);
  v30 = *(_DWORD *)(a2 + 16);
  if ( v30 )
  {
    v31 = *(unsigned __int8 *)(a2 + 4);
    v32 = *(unsigned __int8 *)(a2 + 12);
    v33 = a1[65];
    BYTE6(v39) = *(_BYTE *)(a2 + 12);
    v34 = *(_QWORD *)(v33 + 488 * v31);
    if ( !v34 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get vdev for vdev_%d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_update_params_for_mlo_stats",
        v31);
      v36 = "%s: Failed to update params for mlo_stats";
      goto LABEL_13;
    }
    if ( v32 )
    {
      LODWORD(v40) = v30;
      qdf_mem_copy((char *)&v40 + 4, (const void *)(v34 + 80), 6u);
    }
  }
  if ( *(_BYTE *)(a2 + 20) == 1 && *(_DWORD *)(a1[65] + 488LL * v38 + 164) == 2 )
    result = wmi_process_unified_ll_stats_get_sta_cmd(*a1);
  else
    result = wmi_unified_process_ll_stats_get_cmd(*a1);
  if ( (_DWORD)result )
  {
    v36 = "%s: Failed to send get link stats request";
    goto LABEL_13;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
