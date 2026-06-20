__int64 __fastcall tdls_notify_sta_connect(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  unsigned int *v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  unsigned int v29; // w20
  __int64 comp_private_obj; // x0
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x21
  __int64 v34; // x0

  if ( a1 )
  {
    v10 = *a1;
    if ( v10 )
    {
      if ( (tdls_check_is_tdls_allowed(v10) & 1) == 0 )
      {
        v29 = 11;
        goto LABEL_20;
      }
      if ( (wlan_cm_is_link_switch_connection(*a1, v12, v13, v14, v15, v16, v17, v18, v19) & 1) != 0
        && (wlan_vdev_mlme_is_mlo_vdev(*a1, v20, v21, v22, v23, v24, v25, v26, v27) & 1) != 0 )
      {
        tdls_process_enable_disable_for_ml_vdev(*a1, 1);
        v28 = *a1;
        if ( !*a1 )
          goto LABEL_19;
      }
      else
      {
        tdls_process_enable_for_vdev(*a1);
        v28 = *a1;
        if ( !*a1 )
          goto LABEL_19;
      }
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v28, 0xAu);
      if ( comp_private_obj )
      {
        v31 = *(_QWORD *)(v28 + 216);
        if ( v31 )
        {
          v32 = *(_QWORD *)(v31 + 80);
          if ( v32 )
          {
            v33 = comp_private_obj;
            v34 = wlan_objmgr_psoc_get_comp_private_obj(v32, 0xAu);
            if ( !v34 || (*(_DWORD *)(v28 + 16) & 0xFFFFFFFD) != 0 )
              goto LABEL_19;
            v29 = 0;
            *(_DWORD *)(v33 + 740) = *(_DWORD *)(v34 + 116);
LABEL_20:
            wlan_objmgr_vdev_release_ref(*a1, 0x11u, v11, v12, v13, v14, v15, v16, v17, v18, v19);
            _qdf_mem_free((__int64)a1);
            return v29;
          }
        }
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_vdev_get_tdls_soc_obj");
      }
LABEL_19:
      qdf_trace_msg(
        0,
        2u,
        "%s: can't get vdev_obj & soc_obj",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "tdls_update_discovery_tries");
      v29 = 0;
      goto LABEL_20;
    }
    qdf_trace_msg(0, 2u, "%s: invalid param", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_notify_sta_connect");
    _qdf_mem_free((__int64)a1);
    return 4;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: invalid param", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_notify_sta_connect");
    return 4;
  }
}
