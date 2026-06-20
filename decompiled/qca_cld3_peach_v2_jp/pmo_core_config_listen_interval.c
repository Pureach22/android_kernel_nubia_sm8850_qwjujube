__int64 __fastcall pmo_core_config_listen_interval(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int ref; // w23
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 comp_private_obj; // x0
  unsigned int v32; // w20
  __int64 v33; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w23
  __int64 v63; // x0
  __int64 v64; // x22
  unsigned __int64 v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int updated; // w0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x0
  __int64 v93; // x20
  unsigned __int64 v94; // x8
  __int64 v95; // x8
  unsigned int v97; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v98; // [xsp+8h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 152);
  if ( v12 )
    v13 = *(_QWORD *)(v12 + 80);
  else
    v13 = 0;
  v97 = 0;
  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_config_listen_interval");
  ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !ref )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v32 = *(unsigned __int8 *)(a1 + 104);
    v33 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      *(_QWORD *)(v33 + 1064) |= 1uLL;
    }
    if ( *(_DWORD *)(v33 + 1044) == a2 )
    {
      v35 = *(_QWORD *)(v33 + 1064);
      if ( (v35 & 1) != 0 )
      {
        *(_QWORD *)(v33 + 1064) = v35 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v33 + 1056);
      }
      else
      {
        raw_spin_unlock(v33 + 1056);
      }
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Listen Interval(%d) already set for vdev id %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "pmo_core_config_listen_interval",
        a2,
        v32);
    }
    else
    {
      v53 = *(_QWORD *)(v33 + 1064);
      *(_DWORD *)(v33 + 1044) = a2;
      if ( (v53 & 1) != 0 )
      {
        *(_QWORD *)(v33 + 1064) = v53 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v33 + 1056);
      }
      else
      {
        raw_spin_unlock(v33 + 1056);
      }
      if ( a2 <= 1 )
        v62 = 1;
      else
        v62 = a2;
      v97 = v62;
      if ( !a2 )
      {
        v63 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL), 4u);
        if ( v63 )
        {
          v64 = v63;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v65 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v65 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v65 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v63 + 1040);
          }
          else
          {
            raw_spin_lock_bh(v63 + 1040);
            *(_QWORD *)(v64 + 1048) |= 1uLL;
          }
          if ( (unsigned int)wlan_mlme_get_listen_interval(v13, &v97) )
          {
            qdf_trace_msg(
              0x4Du,
              2u,
              "%s: Failed to get listen interval",
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              "pmo_core_config_listen_interval");
            v97 = 1;
          }
          v74 = *(_QWORD *)(v64 + 1048);
          if ( (v74 & 1) != 0 )
          {
            *(_QWORD *)(v64 + 1048) = v74 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v64 + 1040);
          }
          else
          {
            raw_spin_unlock(v64 + 1040);
          }
          v62 = v97;
        }
      }
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Set Listen Interval %d for vdevId %d",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "pmo_core_config_listen_interval",
        v62,
        v32);
      wlan_mlme_set_sap_listen_interval(v13, v97);
      if ( (unsigned int)pmo_tgt_vdev_update_param_req(a1, 0, v97) )
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: Failed to Set Listen Interval",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "pmo_core_config_listen_interval");
      updated = pmo_tgt_vdev_update_param_req(a1, 1, 2);
      if ( updated )
      {
        ref = updated;
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: Failed to set Normal DTIM for vdev id %d",
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          "pmo_core_config_listen_interval",
          v32);
LABEL_40:
        wlan_objmgr_vdev_release_ref(a1, 0xAu, v44, v45, v46, v47, v48, v49, v50, v51, v52);
        goto LABEL_41;
      }
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: Set DTIM Policy to Normal for vdev id %d",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "pmo_core_config_listen_interval",
        v32);
      v92 = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      v93 = v92;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v94 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v94 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v94 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v92 + 1056);
        v95 = *(_QWORD *)(v93 + 1064);
      }
      else
      {
        raw_spin_lock_bh(v92 + 1056);
        v95 = *(_QWORD *)(v93 + 1064) | 1LL;
        *(_QWORD *)(v93 + 1064) = v95;
      }
      *(_BYTE *)(v93 + 1048) = 1;
      if ( (v95 & 1) != 0 )
      {
        *(_QWORD *)(v93 + 1064) = v95 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v93 + 1056);
      }
      else
      {
        raw_spin_unlock(v93 + 1056);
      }
    }
    ref = 0;
    goto LABEL_40;
  }
LABEL_41:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "pmo_core_config_listen_interval");
  _ReadStatusReg(SP_EL0);
  return ref;
}
