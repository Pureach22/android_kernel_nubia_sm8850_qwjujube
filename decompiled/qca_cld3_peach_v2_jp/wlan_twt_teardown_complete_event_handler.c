__int64 __fastcall wlan_twt_teardown_complete_event_handler(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v4; // w22
  int pdev_id_from_vdev_id; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 pdev_by_id; // x0
  __int64 v15; // x19
  unsigned int opmode_from_vdev_id; // w0
  int v17; // w25
  _QWORD *peer_by_mac; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x23
  __int64 comp_private_obj; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x24
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 result; // x0
  __int64 v49; // x2
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w5
  unsigned int v59; // w8
  double inited; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int64 v68; // x8
  const char *v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  int v94; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v95; // [xsp+28h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(a1, *a2, 0x5Eu);
  if ( pdev_id_from_vdev_id == -1 )
  {
    v47 = "%s: Invalid pdev id";
LABEL_12:
    qdf_trace_msg(0x96u, 2u, v47, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_twt_teardown_complete_event_handler");
    result = 4;
LABEL_33:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, pdev_id_from_vdev_id, 0x5Eu);
  if ( !pdev_by_id )
  {
    v47 = "%s: Invalid pdev";
    goto LABEL_12;
  }
  v15 = pdev_by_id;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(pdev_by_id, v4);
  if ( !opmode_from_vdev_id )
  {
    v49 = *((unsigned int *)a2 + 3);
    v94 = 0;
    if ( (((__int64 (__fastcall *)(__int64, unsigned __int8 *, __int64, __int64, int *))wlan_twt_is_command_in_progress)(
            a1,
            a2 + 4,
            v49,
            2,
            &v94)
        & 1) != 0
      || *((_DWORD *)a2 + 3) == 255
      || (v58 = *((_DWORD *)a2 + 4), v58 <= 0xD) && ((1 << v58) & 0x2380) != 0 )
    {
      if ( (mlme_get_user_ps(a1, *(unsigned int *)a2) & 1) == 0 && !*((_DWORD *)a2 + 4) )
        *((_DWORD *)a2 + 4) = 12;
      mlme_twt_osif_teardown_complete_ind();
      v59 = *((_DWORD *)a2 + 4);
      if ( v59 <= 0xD && ((1 << v59) & 0x2300) != 0 )
        wlan_twt_set_wait_for_notify(a1, *(unsigned int *)a2, 1);
      ((void (__fastcall *)(__int64, unsigned __int8 *, _QWORD, _QWORD))wlan_twt_set_command_in_progress)(
        a1,
        a2 + 4,
        *((unsigned int *)a2 + 3),
        0);
      v68 = (unsigned int)(*((_DWORD *)a2 + 4) - 1);
      if ( (unsigned int)v68 >= 6 )
      {
        wlan_twt_set_setup_done(a1, a2 + 4, *((unsigned int *)a2 + 3), 0);
        wlan_twt_set_session_state(a1, a2 + 4, *((unsigned int *)a2 + 3), 0);
        wlan_twt_init_context(a1, a2 + 4, *((_DWORD *)a2 + 3));
      }
    }
    else
    {
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: Drop TWT Del dialog event for dialog_id:%d status:%d active_cmd:%d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "wlan_twt_handle_sta_del_dialog_event");
    }
    goto LABEL_32;
  }
  if ( opmode_from_vdev_id != 1 )
  {
    v69 = qdf_opmode_str(opmode_from_vdev_id);
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: TWT Teardown is not supported on %s",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "wlan_twt_teardown_complete_event_handler",
      v69);
LABEL_32:
    wlan_objmgr_pdev_release_ref(v15, 0x5Eu, (unsigned int *)v68, inited, v61, v62, v63, v64, v65, v66, v67);
    result = 0;
    goto LABEL_33;
  }
  mlme_twt_osif_teardown_complete_ind();
  v17 = *((_DWORD *)a2 + 3);
  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, a2 + 4, 0x5Eu);
  if ( !peer_by_mac )
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Peer object not found %02x:%02x:%02x:**:**:%02x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_twt_clear_wake_dur_and_interval",
      a2[4],
      a2[5],
      a2[6],
      a2[9]);
    goto LABEL_30;
  }
  v27 = (__int64)peer_by_mac;
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x2Cu);
  if ( !comp_private_obj )
  {
    wlan_objmgr_peer_release_ref(v27, 0x5Eu, v29, v30, v31, v32, v33, v34, v35, v36);
    qdf_trace_msg(
      0x96u,
      2u,
      "%s:  peer twt component object is NULL",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "wlan_twt_clear_wake_dur_and_interval");
    goto LABEL_30;
  }
  v37 = comp_private_obj;
  v38 = qdf_mutex_acquire(comp_private_obj);
  if ( !*(_BYTE *)(v37 + 65) )
  {
LABEL_29:
    qdf_mutex_release(v37);
    wlan_objmgr_peer_release_ref(v27, 0x5Eu, v86, v87, v88, v89, v90, v91, v92, v93);
LABEL_30:
    v68 = *((unsigned int *)a2 + 4);
    if ( (_DWORD)v68 != 7 )
    {
      wlan_twt_sap_set_command_in_progress(a1);
      inited = wlan_twt_sap_init_context(a1, *(unsigned int *)a2, a2 + 4, *((unsigned int *)a2 + 3));
    }
    goto LABEL_32;
  }
  if ( *(unsigned __int8 *)(v37 + 72) == (unsigned __int8)v17 )
  {
    *(_QWORD *)(v37 + 88) = 0;
    *(_BYTE *)(v37 + 72) = -1;
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: vdev:%d peer:%02x:%02x:%02x:**:**:%02x dialog_id:%d wake_dur:%d wake_interval:%d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "wlan_twt_clear_wake_dur_and_interval",
      v4,
      a2[4],
      a2[5],
      a2[6],
      a2[9],
      255,
      0,
      0);
    goto LABEL_29;
  }
  if ( *(_BYTE *)(v37 + 65) == 1 )
    goto LABEL_29;
  __break(0x5512u);
  return wlan_twt_sap_set_command_in_progress(v38);
}
