__int64 __fastcall hdd_send_update_owe_info_event(
        __int64 *a1,
        const void *a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x8
  __int64 v17; // x21
  __int64 vdev_by_user; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  __int64 v28; // [xsp+0h] [xbp-30h] BYREF
  __int64 v29; // [xsp+8h] [xbp-28h]
  __int64 v30; // [xsp+10h] [xbp-20h]
  __int64 v31; // [xsp+18h] [xbp-18h]
  __int64 v32; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *a1;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v17 = *(_QWORD *)(v16 + 32);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "hdd_send_update_owe_info_event",
    v17 + 296,
    0,
    0,
    0,
    0,
    0,
    v33);
  qdf_mem_set(&v28, 0x28u, 0);
  qdf_mem_copy(&v28, a2, 6u);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 5, "hdd_ml_sap_owe_fill_ml_info");
  if ( vdev_by_user )
  {
    LODWORD(v31) = -1;
    _hdd_objmgr_put_vdev_by_user(vdev_by_user, 5, "hdd_ml_sap_owe_fill_ml_info");
  }
  v29 = a3;
  v30 = a4;
  cfg80211_update_owe_info_event(v17, &v28, 3264);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: exit",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "hdd_send_update_owe_info_event");
  _ReadStatusReg(SP_EL0);
  return result;
}
