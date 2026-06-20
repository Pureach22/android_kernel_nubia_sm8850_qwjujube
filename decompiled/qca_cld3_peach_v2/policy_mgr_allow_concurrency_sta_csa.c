__int64 __fastcall policy_mgr_allow_concurrency_sta_csa(
        __int64 a1,
        unsigned __int8 a2,
        signed int a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char is_concurrency_allowed; // w20
  int bw; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int8 v39[4]; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v40[22]; // [xsp+10h] [xbp-C0h] BYREF
  int v41; // [xsp+C0h] [xbp-10h]
  __int64 v42; // [xsp+C8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  memset(v40, 0, sizeof(v40));
  v39[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_allow_concurrency_sta_csa");
    is_concurrency_allowed = 0;
    goto LABEL_18;
  }
  v19 = context;
  qdf_mutex_acquire(context + 56);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    a1,
    a2,
    v40,
    v39);
  if ( a3 <= 1 )
  {
    if ( !a3 )
      goto LABEL_15;
    if ( a3 == 1 )
    {
      if ( (policy_mgr_is_vdev_ll_lt_sap(a1, a2) & 1) != 0 )
        a3 = 6;
      else
        a3 = 1;
      goto LABEL_15;
    }
    goto LABEL_13;
  }
  if ( (unsigned int)(a3 - 2) >= 2 )
  {
    if ( a3 == 11 )
    {
      a3 = 4;
      goto LABEL_15;
    }
    if ( a3 == 16 )
    {
      a3 = 5;
      goto LABEL_15;
    }
LABEL_13:
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Unsupported mode (%d)",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "policy_mgr_qdf_opmode_to_pm_con_mode",
      (unsigned int)a3);
    a3 = 7;
  }
LABEL_15:
  bw = policy_mgr_get_bw(a5, v20, v21, v22, v23, v24, v25, v26, v27);
  is_concurrency_allowed = policy_mgr_is_concurrency_allowed(a1, a3, a4, bw, 0, 0);
  if ( v39[0] )
    policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v40, v39[0], v30, v31, v32, v33, v34, v35, v36, v37);
  qdf_mutex_release(v19 + 56);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return is_concurrency_allowed & 1;
}
