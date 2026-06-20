__int64 __fastcall cm_start_roam_invoke(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned int operation_chan_freq,
        unsigned int a5)
{
  unsigned int v10; // w20
  int v11; // w19
  unsigned __int8 rso_disabled_bitmap; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  __int64 result; // x0
  __int64 v23; // x0
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 rso_config_fl; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  char v42; // w8
  __int64 v43; // x28
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x26
  double v54; // d0
  char v55; // w0
  char v56; // w27
  unsigned int *v57; // x8
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w9
  int v82; // w9
  __int64 v83; // x4
  __int64 v84; // x5
  __int64 v85; // x6
  __int64 v86; // x7
  __int16 v87; // w8
  int v88; // w9
  unsigned int v89; // w20
  int v90; // [xsp+10h] [xbp-20h] BYREF
  __int16 v91; // [xsp+14h] [xbp-1Ch]
  int v92; // [xsp+20h] [xbp-10h] BYREF
  __int16 v93; // [xsp+24h] [xbp-Ch]
  __int64 v94; // [xsp+28h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a2 + 168);
  v91 = 0;
  v90 = 0;
  LOBYTE(v92) = 0;
  wlan_mlme_get_roaming_offload(a1, (char *)&v92);
  v11 = (unsigned __int8)v92;
  rso_disabled_bitmap = mlme_get_rso_disabled_bitmap(a1, v10);
  if ( v11 == 1 )
  {
    v21 = rso_disabled_bitmap;
    if ( rso_disabled_bitmap || !(unsigned int)mlme_get_roam_state(a1, v10) )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: ROAM: RSO Disabled internally: vdev[%d] bitmap[0x%x]",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "cm_start_roam_invoke",
        v10,
        v21);
      result = 16;
      goto LABEL_42;
    }
  }
  v23 = _qdf_mem_malloc(0x9F0u, "cm_start_roam_invoke", 6554);
  if ( !v23 )
  {
    result = 2;
    goto LABEL_42;
  }
  v24 = v23;
  if ( (wlan_vdev_mlme_get_is_mlo_link(a1, v10) & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: MLO ROAM: Invalid Roam req on link vdev %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "cm_start_roam_invoke",
      v10);
LABEL_8:
    _qdf_mem_free(v24);
    result = 16;
    goto LABEL_42;
  }
  rso_config_fl = wlan_cm_get_rso_config_fl(a2, "cm_start_roam_invoke", 6564);
  if ( !rso_config_fl )
  {
    result = 29;
    goto LABEL_42;
  }
  if ( a5 == 4 )
  {
    v42 = *(_BYTE *)(v24 + 32);
    *(_DWORD *)(v24 + 36) = 4;
    *(_BYTE *)(v24 + 32) = v42 | 1;
  }
  else
  {
    if ( a5 == 3 )
    {
      *(_DWORD *)(v24 + 36) = 3;
      goto LABEL_40;
    }
    v43 = rso_config_fl;
    v44 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v10, 77);
    if ( v44 )
    {
      if ( *(_QWORD *)(v44 + 216) )
      {
        v53 = v44;
        v54 = dlm_is_bssid_in_reject_list(*(_QWORD *)(v44 + 216), a3);
        v56 = v55;
        wlan_objmgr_vdev_release_ref(v53, 0x4Du, v57, v54, v58, v59, v60, v61, v62, v63, v64);
        if ( (v56 & 1) != 0 )
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: BSSID is in reject list, aborting roam invoke",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "cm_start_roam_invoke");
          goto LABEL_8;
        }
      }
      else
      {
        wlan_objmgr_vdev_release_ref(v44, 0x4Du, nullptr, v45, v46, v47, v48, v49, v50, v51, v52);
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL for vdev %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "cm_dlm_is_bssid_in_reject_list",
        v10);
    }
    if ( *(_DWORD *)a3 | *((unsigned __int16 *)a3 + 2) )
    {
      v93 = -1;
      v92 = -1;
      if ( (qdf_is_macaddr_equal_0(a3, &v92) & 1) != 0 )
      {
        v81 = *(_DWORD *)a3;
        *(_WORD *)(v24 + 44) = *((_WORD *)a3 + 2);
        *(_DWORD *)(v24 + 40) = v81;
        v82 = *(_DWORD *)a3;
        *(_WORD *)(v43 + 972) = *((_WORD *)a3 + 2);
        *(_DWORD *)(v43 + 968) = v82;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Roam only if better candidate found else stick to current AP",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "cm_start_roam_invoke");
      }
      else
      {
        wlan_vdev_get_bss_peer_mac(a2, &v90, v73, v74, v75, v76, v77, v78, v79, v80);
        if ( (qdf_is_macaddr_equal_0(a3, &v90) & 1) != 0 )
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Reassoc BSSID is same as currently associated AP",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "cm_start_roam_invoke");
          operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
        }
        if ( !operation_chan_freq || (v93 = 0, v92 = 0, (qdf_is_macaddr_equal_0(a3, &v92) & 1) != 0) )
        {
          if ( a3 )
          {
            v83 = *a3;
            v84 = a3[1];
            v85 = a3[2];
            v86 = a3[5];
          }
          else
          {
            v85 = 0;
            v83 = 0;
            v84 = 0;
            v86 = 0;
          }
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: bssid %02x:%02x:%02x:**:**:%02x chan_freq %d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "cm_start_roam_invoke",
            v83,
            v84,
            v85,
            v86,
            operation_chan_freq);
          goto LABEL_8;
        }
        v87 = *((_WORD *)a3 + 2);
        v88 = *(_DWORD *)a3;
        *(_DWORD *)(v24 + 52) = operation_chan_freq;
        *(_WORD *)(v24 + 44) = v87;
        *(_DWORD *)(v24 + 40) = v88;
      }
      *(_DWORD *)(v24 + 36) = a5;
      if ( a5 > 0x14 )
        goto LABEL_40;
      rso_config_fl = v43;
      if ( ((1 << a5) & 0x180006) == 0 )
        goto LABEL_40;
    }
    else
    {
      if ( (wlan_mlme_is_data_stall_recovery_fw_supported(a1) & 1) == 0 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: FW does not support data stall recovery, aborting roam invoke",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "cm_start_roam_invoke");
        _qdf_mem_free(v24);
        result = 11;
        goto LABEL_42;
      }
      *(_BYTE *)(v24 + 32) |= 1u;
      if ( a5 == 19 || a5 == 1 )
      {
        a5 = 2;
        rso_config_fl = v43;
        *(_BYTE *)(v43 + 974) = 1;
        *(_DWORD *)(v24 + 36) = 2;
      }
      else
      {
        a5 = 2;
        rso_config_fl = v43;
        *(_DWORD *)(v24 + 36) = 2;
      }
    }
  }
  *(_DWORD *)(rso_config_fl + 964) = a5;
LABEL_40:
  *(_BYTE *)(v24 + 33) = v10;
  result = cm_sm_deliver_event(a2, 0x1Du, 0x9F0u, v24, v34, v35, v36, v37, v38, v39, v40, v41);
  if ( (_DWORD)result )
  {
    v89 = result;
    _qdf_mem_free(v24);
    result = v89;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
