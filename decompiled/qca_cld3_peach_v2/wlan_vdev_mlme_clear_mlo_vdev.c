__int64 __fastcall wlan_vdev_mlme_clear_mlo_vdev(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  int v11; // w8
  const char *v13; // x2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  unsigned int v29; // w10

  if ( !a1 )
  {
    v13 = "%s: vdev is NULL";
    return qdf_trace_msg(0x57u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_clear_mlo_vdev");
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 )
  {
    v13 = "%s: pdev is NULL";
    return qdf_trace_msg(0x57u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_clear_mlo_vdev");
  }
  qdf_mutex_acquire(a1 + 96);
  v11 = *(_DWORD *)(a1 + 60);
  if ( (v11 & 1) == 0 )
    return qdf_mutex_release(a1 + 96);
  *(_DWORD *)(a1 + 60) = v11 & 0xFFFFFFFC;
  if ( !*(_DWORD *)(v9 + 528) )
  {
    v22 = printk(
            &unk_AAA255,
            "qdf_atomic_read(&pdev->pdev_objmgr.wlan_mlo_vdev_count)",
            "wlan_pdev_dec_mlo_vdev_count",
            "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/umac/cmn_services/obj_mgr/inc/wlan_objmgr_pdev_obj.h");
    dump_stack(v22);
  }
  _X8 = (unsigned int *)(v9 + 528);
  __asm { PRFM            #0x11, [X8] }
  do
    v29 = __ldxr(_X8);
  while ( __stxr(v29 - 1, _X8) );
  qdf_mutex_release(a1 + 96);
  return qdf_trace_msg(
           0x57u,
           8u,
           "%s: Clear MLO flag: vdev_id: %d",
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           "wlan_vdev_mlme_clear_mlo_vdev",
           *(unsigned __int8 *)(a1 + 168));
}
