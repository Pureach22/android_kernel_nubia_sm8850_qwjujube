__int64 __fastcall policy_mgr_get_pcl_for_vdev_id(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        _DWORD *a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x27
  unsigned __int8 v32; // w26
  unsigned int v33; // w21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int8 v51[4]; // [xsp+Ch] [xbp-C4h] BYREF
  _QWORD v52[22]; // [xsp+10h] [xbp-C0h] BYREF
  int v53; // [xsp+C0h] [xbp-10h]
  __int64 v54; // [xsp+C8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  memset(v52, 0, sizeof(v52));
  v51[0] = 0;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: get pcl for existing conn:%d vdev id %d",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "policy_mgr_get_pcl_for_vdev_id",
    a2,
    (unsigned __int8)a7);
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v31 = context;
    qdf_mutex_acquire(context + 56);
    *a4 = 0;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
      a1,
      (unsigned __int8)a7,
      v52,
      v51);
    v32 = v51[0];
    v33 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _DWORD *, __int64, _QWORD, _QWORD))policy_mgr_get_pcl)(
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a7);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Get PCL to FW for mode:%d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "policy_mgr_get_pcl_for_vdev_id",
      a2);
    policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v52, v32, v42, v43, v44, v45, v46, v47, v48, v49);
    qdf_mutex_release(v31 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "policy_mgr_get_pcl_for_vdev_id");
    v33 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v33;
}
