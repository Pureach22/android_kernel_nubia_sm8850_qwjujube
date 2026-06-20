__int64 __fastcall policy_mgr_allow_concurrency_csa(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        char a6,
        int a7)
{
  __int64 context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x24
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
  __int64 v41; // x25
  unsigned int *v42; // x8
  char v43; // w20
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 result; // x0
  int v53; // [xsp+8h] [xbp-C8h] BYREF
  unsigned __int8 v54[4]; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v55[22]; // [xsp+10h] [xbp-C0h] BYREF
  int v56; // [xsp+C0h] [xbp-10h]
  __int64 v57; // [xsp+C8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  memset(v55, 0, sizeof(v55));
  v54[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v32 = "%s: Invalid Context";
LABEL_17:
    qdf_trace_msg(0x4Fu, 2u, v32, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_allow_concurrency_csa");
    goto LABEL_18;
  }
  v23 = context;
  v53 = 0;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: check concurrency_csa vdev:%d ch %d bw %d, forced %d, reason %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "policy_mgr_allow_concurrency_csa",
    a5,
    a3,
    a4,
    a6 & 1,
    a7);
  if ( (unsigned int)policy_mgr_get_chan_by_session_id(a1, a5, &v53) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to get channel for vdev:%d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "policy_mgr_allow_concurrency_csa",
      a5);
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  qdf_mem_set(v55, 0xB4u, 0);
  qdf_mutex_acquire(v23 + 56);
  if ( (a6 & 1) != 0 && (a7 == 10 || a7 == 6) )
    policy_mgr_store_and_del_conn_info_by_chan_and_mode(
      a1,
      v53,
      a2,
      (unsigned int *)v55,
      v54,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40);
  else
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
      a1,
      a5,
      v55,
      v54);
  v41 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a5, 24);
  v43 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
          a1,
          a2,
          a3,
          a4,
          0,
          a5);
  if ( v41 )
    wlan_objmgr_vdev_release_ref(v41, 0x18u, v42, v44, v45, v46, v47, v48, v49, v50, v51);
  if ( v54[0] )
    policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v55, v54[0], v44, v45, v46, v47, v48, v49, v50, v51);
  qdf_mutex_release(v23 + 56);
  if ( (v43 & 1) == 0 )
  {
    v32 = "%s: CSA concurrency check failed";
    goto LABEL_17;
  }
  result = 1;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
