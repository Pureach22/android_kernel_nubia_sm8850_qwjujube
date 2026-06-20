__int64 **__fastcall p2p_mac_clear_timeout(
        __int64 **result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x21
  __int64 **v10; // x19
  __int64 v11; // x8
  __int64 v12; // x0
  int v13; // w20
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x5
  unsigned int v24; // w20
  unsigned int v25; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // [xsp+10h] [xbp-20h] BYREF
  int v45; // [xsp+18h] [xbp-18h] BYREF
  __int16 v46; // [xsp+1Ch] [xbp-14h]
  int v47; // [xsp+20h] [xbp-10h] BYREF
  __int16 v48; // [xsp+24h] [xbp-Ch]
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v47 = 0;
  v46 = 0;
  v45 = 0;
  if ( !result || (v9 = *result, v10 = result, !*result) )
  {
    result = (__int64 **)qdf_trace_msg(
                           0x4Eu,
                           2u,
                           "%s: invalid context for mac_clear timeout",
                           a2,
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           "p2p_mac_clear_timeout");
    goto LABEL_22;
  }
  if ( *v9 )
  {
    v11 = *(_QWORD *)(*v9 + 216);
    if ( v11 )
      v12 = *(_QWORD *)(v11 + 80);
    else
      v12 = 0;
    v13 = policy_mgr_mode_specific_connection_count(v12, 3, nullptr);
    raw_spin_lock(v9 + 3);
    v14 = *(_QWORD *)(*v9 + 216);
    if ( v14 )
    {
      if ( (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*(_QWORD *)(v14 + 80)) & 1) == 0 )
      {
LABEL_15:
        v23 = *((unsigned int *)v10 + 52);
        v44 = 0;
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: Delete cookie list %pK, size %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "delete_all_action_frame_cookie",
          v10 + 24,
          v23);
        while ( !qdf_list_empty(v10 + 24) )
        {
          qdf_list_remove_front((_DWORD *)v10 + 48, &v44);
          _qdf_mem_free(v44);
        }
        v24 = *((_DWORD *)v10 + 4);
        *((_BYTE *)v10 + 8) = 0;
        qdf_mem_copy(&v47, (char *)v10 + 9, 6u);
        raw_spin_unlock(v9 + 3);
        v25 = *(unsigned __int8 *)(*v9 + 168);
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: random_mac:clear timeout vdev %d %02x:%02x:%02x:**:**:%02x freq %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "p2p_mac_clear_timeout",
          *(unsigned __int8 *)(*v9 + 168),
          (unsigned __int8)v47,
          BYTE1(v47),
          BYTE2(v47),
          HIBYTE(v48),
          v24);
        v42 = *(_QWORD *)(*v9 + 216);
        if ( v42 )
          v43 = *(_QWORD *)(v42 + 80);
        else
          v43 = 0;
        result = (__int64 **)p2p_set_mac_filter(
                               v43,
                               v25,
                               (unsigned __int8 *)&v47,
                               v24,
                               0,
                               0,
                               0,
                               v34,
                               v35,
                               v36,
                               v37,
                               v38,
                               v39,
                               v40,
                               v41);
        goto LABEL_22;
      }
    }
    else if ( (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(0) & 1) == 0 )
    {
      goto LABEL_15;
    }
    if ( v13
      && !(unsigned int)wlan_mlme_get_p2p_device_mac_addr(*v9, (__int64)&v45, v15, v16, v17, v18, v19, v20, v21, v22)
      && !(unsigned int)qdf_mem_cmp(&v45, (char *)v10 + 9, 6u) )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Skip random mac timeout as this address is used for P2P device on P2P-GO channel",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "p2p_mac_clear_timeout");
      result = (__int64 **)raw_spin_unlock(v9 + 3);
      goto LABEL_22;
    }
    goto LABEL_15;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
