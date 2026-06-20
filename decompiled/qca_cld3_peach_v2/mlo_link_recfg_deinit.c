__int64 __fastcall mlo_link_recfg_deinit(__int64 a1)
{
  __int64 v1; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x22
  __int64 v12; // x23
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  __int64 v30; // x20
  __int64 v31; // x20
  __int64 v33; // [xsp+0h] [xbp-10h] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 3888);
  if ( !v1 )
    goto LABEL_15;
  flush_work(v1 + 4032);
  v11 = *(_QWORD *)(a1 + 3888);
  v33 = 0;
  if ( v11 )
  {
    v12 = *(_QWORD *)(v11 + 8);
    if ( v12 )
    {
      qdf_mutex_acquire(*(_QWORD *)(v12 + 3888) + 760LL);
      while ( !(unsigned int)qdf_list_remove_front((_DWORD *)(v11 + 4080), &v33) )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: flush pending recfg done data",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "mlo_link_refg_flush_recfg_done_data",
          v33,
          v34);
        mlme_cm_free_link_reconfig_done_data();
      }
      qdf_mutex_release(*(_QWORD *)(v12 + 3888) + 760LL);
      goto LABEL_10;
    }
    v29 = "%s: mlo_ctx null";
  }
  else
  {
    v29 = "%s: Invalid recfg_ctx";
  }
  qdf_trace_msg(0x8Fu, 2u, v29, v3, v4, v5, v6, v7, v8, v9, v10, "mlo_link_refg_flush_recfg_done_data", v33, v34);
LABEL_10:
  v30 = *(_QWORD *)(a1 + 3888);
  if ( *(_DWORD *)(v30 + 4096) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "qdf_list_destroy");
    v30 = *(_QWORD *)(a1 + 3888);
  }
  if ( (unsigned int)qdf_mc_timer_get_current_state(v30 + 3288) == 21 )
    qdf_mc_timer_stop(v30 + 3288);
  qdf_mc_timer_destroy(v30 + 3288);
  qdf_mutex_destroy(*(_QWORD *)(a1 + 3888) + 760LL);
  v31 = *(_QWORD *)(a1 + 3888);
  qdf_mc_timer_stop(v31 + 3032);
  qdf_mc_timer_destroy(v31 + 3032);
  wlan_sm_delete(*(_QWORD *)(v31 + 824));
  cancel_work_sync(*(_QWORD *)(a1 + 3888) + 4032LL);
  _qdf_mem_free(*(_QWORD *)(a1 + 3888));
  *(_QWORD *)(a1 + 3888) = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return 0;
}
