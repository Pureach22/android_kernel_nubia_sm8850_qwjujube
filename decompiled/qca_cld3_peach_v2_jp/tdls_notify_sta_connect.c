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
  __int64 v20; // x20
  __int64 comp_private_obj; // x0
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x21
  __int64 v25; // x0
  unsigned int v26; // w20

  if ( a1 )
  {
    v10 = *a1;
    if ( v10 )
    {
      if ( (tdls_check_is_tdls_allowed(v10) & 1) != 0 )
      {
        wlan_cm_is_link_switch_connection(*a1, v12, v13, v14, v15, v16, v17, v18, v19);
        tdls_process_enable_for_vdev(*a1);
        v20 = *a1;
        if ( *a1 )
        {
          comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*a1, 0xAu);
          if ( comp_private_obj )
          {
            v22 = *(_QWORD *)(v20 + 152);
            if ( v22 && (v23 = *(_QWORD *)(v22 + 80)) != 0 )
            {
              v24 = comp_private_obj;
              v25 = wlan_objmgr_psoc_get_comp_private_obj(v23, 0xAu);
              if ( v25 && (*(_DWORD *)(v20 + 16) & 0xFFFFFFFD) == 0 )
              {
                v26 = 0;
                *(_DWORD *)(v24 + 740) = *(_DWORD *)(v25 + 116);
LABEL_16:
                wlan_objmgr_vdev_release_ref(*a1, 0x11u, v11, v12, v13, v14, v15, v16, v17, v18, v19);
                _qdf_mem_free((__int64)a1);
                return v26;
              }
            }
            else
            {
              qdf_trace_msg(
                0,
                2u,
                "%s: can't get psoc",
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                "wlan_vdev_get_tdls_soc_obj");
            }
          }
        }
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
        v26 = 0;
        goto LABEL_16;
      }
      v26 = 11;
      goto LABEL_16;
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
