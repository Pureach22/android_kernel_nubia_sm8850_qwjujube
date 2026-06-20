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
  __int64 rso_config_fl; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w8
  unsigned int v35; // w20
  __int64 v36; // x28
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x26
  double v47; // d0
  char v48; // w0
  char v49; // w27
  unsigned int *v50; // x8
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v67; // x4
  __int64 v68; // x5
  __int64 v69; // x6
  __int64 v70; // x7
  int v71; // w9
  int v72; // w9
  __int16 v73; // w8
  int v74; // w9
  int v75; // [xsp+10h] [xbp-20h] BYREF
  __int16 v76; // [xsp+14h] [xbp-1Ch]
  int v77; // [xsp+20h] [xbp-10h] BYREF
  __int16 v78; // [xsp+24h] [xbp-Ch]
  __int64 v79; // [xsp+28h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a2 + 104);
  v76 = 0;
  v75 = 0;
  LOBYTE(v77) = 0;
  wlan_mlme_get_roaming_offload(a1, (char *)&v77);
  v11 = (unsigned __int8)v77;
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
LABEL_4:
      result = 16;
      goto LABEL_17;
    }
  }
  v23 = _qdf_mem_malloc(0x380u, "cm_start_roam_invoke", 6554);
  if ( !v23 )
  {
    result = 2;
    goto LABEL_17;
  }
  v24 = v23;
  rso_config_fl = wlan_cm_get_rso_config_fl(a2, "cm_start_roam_invoke", 6564);
  if ( !rso_config_fl )
  {
    result = 29;
    goto LABEL_17;
  }
  if ( a5 == 4 )
  {
    v34 = *(_BYTE *)(v24 + 32);
    *(_DWORD *)(v24 + 36) = 4;
    *(_BYTE *)(v24 + 32) = v34 | 1;
LABEL_14:
    *(_DWORD *)(rso_config_fl + 948) = a5;
    goto LABEL_15;
  }
  if ( a5 == 3 )
  {
    *(_DWORD *)(v24 + 36) = 3;
    goto LABEL_15;
  }
  v36 = rso_config_fl;
  v37 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v10, 77);
  if ( v37 )
  {
    if ( *(_QWORD *)(v37 + 152) )
    {
      v46 = v37;
      v47 = dlm_is_bssid_in_reject_list(*(_QWORD *)(v37 + 152), a3);
      v49 = v48;
      wlan_objmgr_vdev_release_ref(v46, 0x4Du, v50, v47, v51, v52, v53, v54, v55, v56, v57);
      if ( (v49 & 1) != 0 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: BSSID is in reject list, aborting roam invoke",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "cm_start_roam_invoke");
LABEL_47:
        _qdf_mem_free(v24);
        goto LABEL_4;
      }
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v37, 0x4Du, nullptr, v38, v39, v40, v41, v42, v43, v44, v45);
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "cm_dlm_is_bssid_in_reject_list",
      v10);
  }
  if ( !(*(_DWORD *)a3 | *((unsigned __int16 *)a3 + 2)) )
  {
    if ( (wlan_mlme_is_data_stall_recovery_fw_supported(a1) & 1) == 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: FW does not support data stall recovery, aborting roam invoke",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "cm_start_roam_invoke");
      _qdf_mem_free(v24);
      result = 11;
      goto LABEL_17;
    }
    *(_BYTE *)(v24 + 32) |= 1u;
    if ( a5 == 19 || a5 == 1 )
    {
      a5 = 2;
      rso_config_fl = v36;
      *(_BYTE *)(v36 + 958) = 1;
      *(_DWORD *)(v24 + 36) = 2;
    }
    else
    {
      a5 = 2;
      rso_config_fl = v36;
      *(_DWORD *)(v24 + 36) = 2;
    }
    goto LABEL_14;
  }
  if ( *(_DWORD *)a3 == -1 && *((__int16 *)a3 + 2) == -1 )
  {
    v71 = *(_DWORD *)a3;
    *(_WORD *)(v24 + 44) = *((_WORD *)a3 + 2);
    *(_DWORD *)(v24 + 40) = v71;
    v72 = *(_DWORD *)a3;
    *(_WORD *)(v36 + 956) = *((_WORD *)a3 + 2);
    *(_DWORD *)(v36 + 952) = v72;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Roam only if better candidate found else stick to current AP",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "cm_start_roam_invoke");
  }
  else
  {
    wlan_vdev_get_bss_peer_mac(a2, &v75, v58, v59, v60, v61, v62, v63, v64, v65);
    if ( (qdf_is_macaddr_equal_0(a3, &v75) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Reassoc BSSID is same as currently associated AP",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "cm_start_roam_invoke");
      operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
    }
    if ( !operation_chan_freq || (v78 = 0, v77 = 0, (qdf_is_macaddr_equal_0(a3, &v77) & 1) != 0) )
    {
      if ( a3 )
      {
        v67 = *a3;
        v68 = a3[1];
        v69 = a3[2];
        v70 = a3[5];
      }
      else
      {
        v69 = 0;
        v67 = 0;
        v68 = 0;
        v70 = 0;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: bssid %02x:%02x:%02x:**:**:%02x chan_freq %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "cm_start_roam_invoke",
        v67,
        v68,
        v69,
        v70,
        operation_chan_freq);
      goto LABEL_47;
    }
    v73 = *((_WORD *)a3 + 2);
    v74 = *(_DWORD *)a3;
    *(_DWORD *)(v24 + 52) = operation_chan_freq;
    *(_WORD *)(v24 + 44) = v73;
    *(_DWORD *)(v24 + 40) = v74;
  }
  *(_DWORD *)(v24 + 36) = a5;
  if ( a5 <= 0x14 )
  {
    rso_config_fl = v36;
    if ( ((1 << a5) & 0x180006) != 0 )
      goto LABEL_14;
  }
LABEL_15:
  *(_BYTE *)(v24 + 33) = v10;
  result = cm_sm_deliver_event(a2, 0x1Du, 0x380u, v24, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( (_DWORD)result )
  {
    v35 = result;
    _qdf_mem_free(v24);
    result = v35;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
