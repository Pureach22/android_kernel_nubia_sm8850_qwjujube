__int64 __fastcall tdls_notify_sta_disconnect(
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
  __int64 v10; // x0
  __int64 v11; // x8
  int v12; // w20
  char v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v23; // x20
  __int64 comp_private_obj; // x0
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x21
  __int64 v28; // x0
  __int64 v29; // x0
  unsigned int v30; // w20
  __int64 *v31; // x20
  __int64 *v32; // x22
  __int64 v33; // x20
  unsigned int v34; // w21
  unsigned int v35; // w0
  __int64 v36; // x20
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0, 2u, "%s: invalid param", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_notify_sta_disconnect");
    return 4;
  }
  v10 = *(_QWORD *)a1;
  if ( !v10 )
  {
    qdf_trace_msg(0, 2u, "%s: invalid param", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_notify_sta_disconnect");
    goto LABEL_11;
  }
  v11 = *(_QWORD *)(v10 + 216);
  if ( !v11 || (v11 = *(_QWORD *)(v11 + 80)) == 0 )
  {
LABEL_8:
    wlan_objmgr_vdev_release_ref(v10, 0x11u, (unsigned int *)v11, a2, a3, a4, a5, a6, a7, a8, a9);
LABEL_11:
    _qdf_mem_free(a1);
    return 4;
  }
  v12 = *(_DWORD *)(v10 + 16);
  v13 = policy_mgr_mode_specific_connection_count(v11, 0, nullptr);
  if ( v12 == 2 && v13 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: STA + P2P concurrency. No action on P2P vdev",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tdls_notify_sta_disconnect");
    v10 = *(_QWORD *)a1;
    goto LABEL_8;
  }
  v23 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)a1, 0xAu);
    if ( comp_private_obj )
    {
      v25 = *(_QWORD *)(v23 + 216);
      if ( v25 && (v26 = *(_QWORD *)(v25 + 80)) != 0 )
      {
        v27 = comp_private_obj;
        v28 = wlan_objmgr_psoc_get_comp_private_obj(v26, 0xAu);
        if ( v28 && (*(_DWORD *)(v23 + 16) & 0xFFFFFFFD) == 0 )
        {
          if ( *(_BYTE *)(a1 + 11) == 1 )
          {
            LODWORD(v29) = tdls_delete_all_tdls_peers(*(_QWORD *)a1, v28);
          }
          else
          {
            v31 = (__int64 *)v28;
            qdf_trace_msg(
              0,
              8u,
              "%s: vdev:%d Disable TDLS peer_count:%d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "tdls_process_sta_disconnect",
              *(unsigned __int8 *)(a1 + 12),
              *(unsigned __int16 *)(v28 + 202));
            v32 = v31;
            tdls_send_update_to_fw(v27, v31, 0, 0, 0, *(unsigned __int8 *)(a1 + 12));
            tdls_timers_stop(v27);
            LODWORD(v29) = 0;
            if ( (*(_BYTE *)(a1 + 10) & 1) == 0 )
            {
              v33 = *v31;
              v34 = policy_mgr_mode_specific_vdev_id(*v32, 0);
              if ( v34 == 255
                && ((v35 = policy_mgr_mode_specific_vdev_id(v33, 2), v35 == 255)
                 || (v34 = v35, (unsigned int)policy_mgr_get_connection_count_with_mlo(v33) != 1)) )
              {
                LODWORD(v29) = 0;
              }
              else
              {
                v29 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                        v33,
                        v34,
                        17);
                if ( v29 )
                {
                  v36 = v29;
                  if ( (wlan_vdev_mlme_is_mlo_vdev(v29, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
                    tdls_process_enable_disable_for_ml_vdev(v36, 1);
                  else
                    tdls_process_enable_for_vdev(v36);
                  wlan_objmgr_vdev_release_ref(v36, 0x11u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
                  LODWORD(v29) = 0;
                  *(_DWORD *)(*(_QWORD *)a1 + 60LL) &= ~0x10u;
                }
              }
            }
          }
          goto LABEL_23;
        }
      }
      else
      {
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v14, v15, v16, v17, v18, v19, v20, v21, "wlan_vdev_get_tdls_soc_obj");
      }
    }
  }
  LODWORD(v29) = 16;
LABEL_23:
  v30 = v29;
  wlan_objmgr_vdev_release_ref(*(_QWORD *)a1, 0x11u, *(unsigned int **)a1, v14, v15, v16, v17, v18, v19, v20, v21);
  _qdf_mem_free(a1);
  return v30;
}
