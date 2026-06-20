__int64 __fastcall _hdd_close_adapter(
        __int64 *a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int16 v12; // w9
  int v13; // w10
  __int64 v14; // x19
  __int64 v15; // x1
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  __int64 v42; // x27
  __int64 v43; // x28
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x19
  __int64 v53; // x0
  __int64 v54; // x0
  int v57; // [xsp+10h] [xbp-10h] BYREF
  __int16 v58; // [xsp+14h] [xbp-Ch]
  __int64 v59; // [xsp+18h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_WORD *)(a2 + 1621);
  v13 = *(_DWORD *)(a2 + 40);
  v57 = *(_DWORD *)(a2 + 1617);
  v58 = v12;
  if ( !v13 && a2 && a2 != -52840 )
  {
    v42 = 0;
    v43 = a2 + 53800;
    do
    {
      if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v42 >> 3)) > 2 )
        break;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: cleanup he operation info",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "hdd_cleanup_he_operation_info");
      v52 = v43 + v42;
      v53 = *(_QWORD *)(v43 + v42 + 560);
      if ( v53 )
      {
        _qdf_mem_free(v53);
        *(_QWORD *)(v52 + 560) = 0;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: cleanup previous ap bcn ie",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "hdd_cleanup_prev_ap_bcn_ie");
      v54 = *(_QWORD *)(v52 + 8);
      if ( v54 )
      {
        _qdf_mem_free(v54);
        *(_QWORD *)(v52 + 8) = 0;
        *(_DWORD *)(v43 + v42) = 0;
      }
      v42 += 6088;
    }
    while ( v43 + v42 != 960 );
  }
  if ( a2 && a2 != -52840 )
  {
    v14 = 0;
    do
    {
      if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v14 >> 3)) > 2 )
        break;
      flush_work(a2 + 58848 + v14);
      v14 += 6088;
    }
    while ( a2 + 52840 + v14 );
  }
  if ( *(_DWORD *)(a2 + 41752) )
    qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", a4, a5, a6, a7, a8, a9, a10, a11, "qdf_list_destroy");
  qdf_mutex_destroy(a2 + 41760);
  ((void (__fastcall *)(__int64, _QWORD))policy_mgr_clear_concurrency_mode)(*a1, *(unsigned int *)(a2 + 40));
  qdf_event_destroy(a2 + 52408, v15);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "hdd_adapter_feature_update_work_deinit");
  if ( *(_DWORD *)(a2 + 52520) == 1 )
  {
    cancel_work_sync(a2 + 52472);
    flush_work(a2 + 52472);
    v32 = "%s: exit";
    *(_DWORD *)(a2 + 52520) = 0;
  }
  else
  {
    v32 = "%s: work not yet init";
  }
  qdf_trace_msg(0x33u, 8u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "hdd_adapter_feature_update_work_deinit");
  hdd_cleanup_adapter(a2, a3 & 1, v33, v34, v35, v36, v37, v38, v39, v40);
  result = ucfg_dp_destroy_intf(*a1, (unsigned __int8 *)&v57);
  _ReadStatusReg(SP_EL0);
  return result;
}
