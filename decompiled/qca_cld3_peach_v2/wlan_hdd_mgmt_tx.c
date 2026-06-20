__int64 __fastcall wlan_hdd_mgmt_tx(__int64 a1, __int64 a2, __int64 *a3, _QWORD *a4)
{
  __int64 v7; // x0
  unsigned int v8; // w21
  __int64 v9; // x22
  unsigned __int8 *v10; // x20
  unsigned __int64 v11; // x23
  __int64 v12; // x25
  unsigned int v13; // w21
  unsigned int v14; // w26
  unsigned int v15; // w27
  unsigned int v16; // w24
  __int64 *v17; // x28
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 v27; // x26
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w8
  unsigned int v45; // w21
  unsigned int v46; // w8
  int v48; // w9
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  char *v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x19
  int updated; // w20
  unsigned __int8 sta_vdev_id; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 sta_vdev_for_p2p_dev; // x0
  unsigned int v79; // w26
  __int64 v80; // x21
  double v81; // d0
  int v82; // w0
  int v83; // w20
  unsigned int *v84; // x8
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  int v100; // w8
  __int64 v101; // [xsp+0h] [xbp-70h]
  __int64 v102; // [xsp+8h] [xbp-68h]
  unsigned int v103; // [xsp+44h] [xbp-2Ch]
  unsigned __int8 v104; // [xsp+48h] [xbp-28h]
  int v105; // [xsp+4Ch] [xbp-24h]
  unsigned int v106; // [xsp+50h] [xbp-20h]
  unsigned int v107; // [xsp+54h] [xbp-1Ch]
  __int64 v108; // [xsp+58h] [xbp-18h] BYREF
  unsigned int v109; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v110; // [xsp+68h] [xbp-8h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 32);
  v108 = 0;
  v8 = _osif_vdev_sync_op_start(v7, &v108, "wlan_hdd_mgmt_tx");
  if ( !v8 )
  {
    v9 = *(_QWORD *)(a2 + 32);
    v10 = (unsigned __int8 *)a3[2];
    v11 = a3[3];
    v12 = *a3;
    v13 = *((unsigned __int8 *)a3 + 8);
    v14 = *((_DWORD *)a3 + 3);
    v15 = *((unsigned __int8 *)a3 + 32);
    v16 = *((unsigned __int8 *)a3 + 33);
    v17 = *(__int64 **)(v9 + 2712);
    v109 = 0;
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v26 = "%s: Command not allowed in FTM mode";
LABEL_14:
      qdf_trace_msg(0x33u, 2u, v26, v18, v19, v20, v21, v22, v23, v24, v25, "__wlan_hdd_mgmt_tx");
      goto LABEL_15;
    }
    v107 = v14;
    v27 = *(_QWORD *)(v9 + 55520);
    if ( !v27 )
    {
      v26 = "%s: invalid link_info";
      goto LABEL_14;
    }
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(v27 + 8),
                         (__int64)"__wlan_hdd_mgmt_tx",
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25) )
    {
LABEL_15:
      v8 = -22;
      goto LABEL_16;
    }
    v106 = v13;
    v8 = _wlan_hdd_validate_context((__int64)v17, (__int64)"__wlan_hdd_mgmt_tx", v28, v29, v30, v31, v32, v33, v34, v35);
    if ( v8 )
    {
LABEL_16:
      _osif_vdev_sync_op_stop(v108, "wlan_hdd_mgmt_tx");
      goto LABEL_17;
    }
    v44 = *v10;
    v45 = v44 >> 4;
    v104 = *v10;
    v105 = (v44 >> 2) & 3;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev_id %d, type %d, sub_type %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "__wlan_hdd_mgmt_tx",
      *(unsigned __int8 *)(v27 + 8));
    v46 = *(_DWORD *)(v9 + 2728);
    if ( v46 >= 4 )
    {
      if ( v45 != 11 || v105 || v46 != 16 )
        goto LABEL_37;
    }
    else if ( v45 != 11 || v105 )
    {
      v103 = v45;
      if ( v46 == 1 )
      {
        if ( v105 )
          goto LABEL_40;
      }
      else if ( v105 || v46 != 3 )
      {
        goto LABEL_40;
      }
      if ( (v104 & 0xD0) != 0x10 )
        goto LABEL_40;
      if ( wlan_get_ie_ptr_from_eid(0x37u, v10 + 30, (unsigned __int16)v11 - 30) )
      {
        v58 = hdd_filter_ft_info(v10 + 30, v11, &v109);
        v8 = -22;
        if ( !v58 )
          goto LABEL_16;
        if ( !v109 )
          goto LABEL_16;
        v67 = (__int64)v58;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: get ft_info_len from Assoc rsp :%d",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "__wlan_hdd_mgmt_tx");
        updated = wlansap_update_ft_info(*(_QWORD *)(v27 + 272), v10 + 4, v67, v109, 0);
        _qdf_mem_free(v67);
        if ( updated )
          goto LABEL_16;
        v49 = 0;
        goto LABEL_27;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: No FT info in Assoc rsp, send it directly",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "__wlan_hdd_mgmt_tx");
      v46 = *(_DWORD *)(v9 + 2728);
LABEL_37:
      v103 = v45;
      if ( v46 == 7 && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*v17) & 1) != 0 )
      {
        sta_vdev_id = ucfg_p2p_psoc_priv_get_sta_vdev_id(*v17);
        sta_vdev_for_p2p_dev = wlan_hdd_get_sta_vdev_for_p2p_dev(
                                 *v17,
                                 sta_vdev_id,
                                 0x53u,
                                 v70,
                                 v71,
                                 v72,
                                 v73,
                                 v74,
                                 v75,
                                 v76,
                                 v77);
        v79 = 7;
LABEL_41:
        if ( sta_vdev_for_p2p_dev )
        {
          v80 = sta_vdev_for_p2p_dev;
          qdf_mtrace(51, 72, 0x49u, *(_BYTE *)(sta_vdev_for_p2p_dev + 168), 0);
          v81 = wlan_cfg80211_mgmt_tx(v80, v12, v106, v107, v10, (unsigned int)v11, v15, v16, a4, v79);
          v83 = v82;
          _hdd_objmgr_put_vdev_by_user(
            v80,
            0x53u,
            (__int64)"__wlan_hdd_mgmt_tx",
            v84,
            v81,
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91);
          if ( v12 )
            v100 = *(_DWORD *)(v12 + 4);
          else
            v100 = 0;
          LODWORD(v102) = v103;
          LODWORD(v101) = v105;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev:%d adapter_device_mode:%d vdev_device_mode:%d opmode:%d type:%d sub_type:%d chan:%d wait:%d offchan"
            ":%d do_not_wait_ack:%d mgmt tx, status:%d, cookie:0x%llx",
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            "__wlan_hdd_mgmt_tx",
            *(unsigned __int8 *)(v80 + 168),
            *(unsigned int *)(v9 + 2728),
            *(unsigned int *)(v80 + 16),
            v79,
            v101,
            v102,
            v100,
            v107,
            v106,
            v16,
            v83,
            *a4);
          v8 = 0;
          goto LABEL_16;
        }
        v26 = "%s: vdev is NULL";
        goto LABEL_14;
      }
LABEL_40:
      sta_vdev_for_p2p_dev = _hdd_objmgr_get_vdev_by_user(v27, 0x53u, (__int64)"__wlan_hdd_mgmt_tx");
      v79 = 0;
      goto LABEL_41;
    }
    if ( v11 >= 0x1B )
    {
      v48 = *((unsigned __int16 *)v10 + 12);
      if ( v48 == 7 )
        goto LABEL_37;
      if ( v48 == 2 && (v46 | 2) == 3 )
        *(_BYTE *)(v27 + 2639) = 0;
    }
    qdf_mtrace(51, 52, 0x49u, *(_BYTE *)(v27 + 8), 0);
    v49 = sme_send_mgmt_tx(v17[2], *(unsigned __int8 *)(v27 + 8), v10, (unsigned int)v11);
    if ( v49 )
      goto LABEL_15;
LABEL_27:
    v8 = qdf_status_to_os_return(v49);
    goto LABEL_16;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v8;
}
