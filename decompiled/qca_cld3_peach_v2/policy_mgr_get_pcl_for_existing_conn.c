__int64 __fastcall policy_mgr_get_pcl_for_existing_conn(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        _DWORD *a4,
        __int64 a5,
        unsigned int a6,
        char a7,
        unsigned int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 context; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x26
  unsigned int v34; // w21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned __int8 v52[4]; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v53[22]; // [xsp+10h] [xbp-C0h] BYREF
  int v54; // [xsp+C0h] [xbp-10h]
  __int64 v55; // [xsp+C8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  memset(v53, 0, sizeof(v53));
  v52[0] = 0;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: get pcl for existing conn:%d",
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    a16,
    "policy_mgr_get_pcl_for_existing_conn",
    a2);
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v33 = context;
    *a4 = 0;
    qdf_mutex_acquire(context + 56);
    if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1, a2, nullptr) )
    {
      if ( (a7 & 1) != 0 )
        ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info)(
          a1,
          a2,
          1,
          v53,
          v52);
      else
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
          a1,
          (unsigned __int8)a8,
          v53,
          v52);
      v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _DWORD *, __int64, _QWORD, _QWORD))policy_mgr_get_pcl)(
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a8);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Get PCL to FW for mode:%d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "policy_mgr_get_pcl_for_existing_conn",
        a2);
      policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v53, v52[0], v43, v44, v45, v46, v47, v48, v49, v50);
    }
    else
    {
      v34 = 0;
    }
    qdf_mutex_release(v33 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "policy_mgr_get_pcl_for_existing_conn");
    v34 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v34;
}
