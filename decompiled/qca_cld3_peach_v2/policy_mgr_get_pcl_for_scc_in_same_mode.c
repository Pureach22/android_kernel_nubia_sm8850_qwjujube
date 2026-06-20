__int64 __fastcall policy_mgr_get_pcl_for_scc_in_same_mode(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7)
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
  __int64 v23; // x26
  unsigned int chan_by_session_id; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  unsigned int v34; // w19
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned __int8 v52[4]; // [xsp+8h] [xbp-C8h] BYREF
  int v53; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v54[22]; // [xsp+10h] [xbp-C0h] BYREF
  int v55; // [xsp+C0h] [xbp-10h]
  __int64 v56; // [xsp+C8h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  memset(v54, 0, sizeof(v54));
  v53 = 0;
  v52[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v23 = context;
    chan_by_session_id = policy_mgr_get_chan_by_session_id(a1, a7, &v53);
    if ( chan_by_session_id )
    {
      v33 = (unsigned __int8)a7;
      v34 = chan_by_session_id;
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Fail to get channel by vdev id %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "policy_mgr_get_pcl_for_scc_in_same_mode",
        v33);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: get pcl for existing conn:%d vdev id %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "policy_mgr_get_pcl_for_scc_in_same_mode",
        a2,
        (unsigned __int8)a7);
      qdf_mutex_acquire(v23 + 56);
      policy_mgr_store_and_del_conn_info_by_chan_and_mode(
        a1,
        v53,
        a2,
        (unsigned int *)v54,
        v52,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43);
      v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, _QWORD, _QWORD))policy_mgr_get_pcl)(
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7);
      if ( v52[0] )
        policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v54, v52[0], v44, v45, v46, v47, v48, v49, v50, v51);
      qdf_mutex_release(v23 + 56);
    }
    result = v34;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_get_pcl_for_scc_in_same_mode");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
