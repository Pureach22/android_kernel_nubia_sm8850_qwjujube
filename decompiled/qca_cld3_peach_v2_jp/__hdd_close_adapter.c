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
  _DWORD *v12; // x26
  __int16 v13; // w9
  int v14; // w10
  __int64 v15; // x9
  __int64 v16; // x1
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  __int64 v43; // x9
  __int64 v44; // x28
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x0
  __int64 v54; // x0
  int v57; // [xsp+10h] [xbp-10h] BYREF
  __int16 v58; // [xsp+14h] [xbp-Ch]
  __int64 v59; // [xsp+18h] [xbp-8h]

  v12 = (_DWORD *)(a2 + 52520);
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_WORD *)(a2 + 1621);
  v14 = *(_DWORD *)(a2 + 40);
  v57 = *(_DWORD *)(a2 + 1617);
  v58 = v13;
  if ( !v14 )
  {
    v43 = a2 ? a2 + 52832 : 0LL;
    if ( v43 && v43 == a2 + 52832 )
    {
      v44 = a2 + 53784;
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
      v53 = *(_QWORD *)(v44 + 544);
      if ( v53 )
      {
        _qdf_mem_free(v53);
        *(_QWORD *)(v44 + 544) = 0;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: cleanup previous ap bcn ie",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "hdd_cleanup_prev_ap_bcn_ie");
      v54 = *(_QWORD *)(v44 + 8);
      if ( v54 )
      {
        _qdf_mem_free(v54);
        *(_QWORD *)(v44 + 8) = 0;
        *(_DWORD *)v44 = 0;
      }
    }
  }
  if ( a2 )
    v15 = a2 + 52832;
  else
    v15 = 0;
  if ( v15 && v15 == a2 + 52832 )
    flush_work(a2 + 57280);
  if ( *(_DWORD *)(a2 + 41752) )
    qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", a4, a5, a6, a7, a8, a9, a10, a11, "qdf_list_destroy");
  qdf_mutex_destroy(a2 + 41760);
  ((void (__fastcall *)(__int64, _QWORD))policy_mgr_clear_concurrency_mode)(*a1, *(unsigned int *)(a2 + 40));
  qdf_event_destroy(a2 + 52408, v16);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "hdd_adapter_feature_update_work_deinit");
  if ( *v12 == 1 )
  {
    cancel_work_sync(a2 + 52472);
    flush_work(a2 + 52472);
    v33 = "%s: exit";
    *v12 = 0;
  }
  else
  {
    v33 = "%s: work not yet init";
  }
  qdf_trace_msg(0x33u, 8u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "hdd_adapter_feature_update_work_deinit");
  hdd_cleanup_adapter(a2, a3 & 1, v34, v35, v36, v37, v38, v39, v40, v41);
  result = ucfg_dp_destroy_intf(*a1, (unsigned __int8 *)&v57);
  _ReadStatusReg(SP_EL0);
  return result;
}
