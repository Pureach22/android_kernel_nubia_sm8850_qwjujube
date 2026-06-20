__int64 __fastcall spatial_reuse_set_sr_enable_disable(
        __int64 a1,
        __int64 a2,
        char a3,
        int a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x8
  unsigned __int64 v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  __int64 v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 pdev_wmi_handle; // x0
  __int64 v44; // x21
  unsigned __int64 v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  __int64 result; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x0
  __int64 v65; // x21
  unsigned __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned __int64 StatusReg; // x8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 cmpt_obj; // x0
  __int64 v85; // x8
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  unsigned int v102; // w21
  unsigned int v103; // w20
  __int64 v104; // x0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  __int64 v113; // x19
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x8
  unsigned int v123; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v124; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v125; // [xsp+10h] [xbp-10h]
  __int64 v126; // [xsp+18h] [xbp-8h]

  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 80);
  v123 = 0;
  if ( !v13 )
  {
    result = 17;
    goto LABEL_46;
  }
  if ( (a3 & 1) == 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1344);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1344);
      *(_QWORD *)(a1 + 1352) |= 1uLL;
    }
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v76, v77, v78, v79, v80, v81, v82, v83);
    if ( cmpt_obj )
      *(_BYTE *)(cmpt_obj + 202) = 0;
    v85 = *(_QWORD *)(a1 + 1352);
    if ( (v85 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v85 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: srp param val: %x, enable: %d",
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      "spatial_reuse_set_sr_enable_disable",
      v123,
      0);
    goto LABEL_36;
  }
  wlan_mlme_update_sr_data(a1, (int *)&v123, a4, a5, 1, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v16 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v16 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1344);
    *(_QWORD *)(a1 + 1352) |= 1uLL;
  }
  v25 = wlan_vdev_mlme_get_cmpt_obj(a1, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( v25 )
    *(_BYTE *)(v25 + 202) = 1;
  v26 = *(_QWORD *)(a1 + 1352);
  if ( (v26 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1352) = v26 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1344);
  }
  else
  {
    raw_spin_unlock(a1 + 1344);
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: srp param val: %x, enable: %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "spatial_reuse_set_sr_enable_disable",
    v123,
    1);
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a2, v35, v36, v37, v38, v39, v40, v41, v42);
  if ( !pdev_wmi_handle )
    goto LABEL_39;
  v44 = pdev_wmi_handle;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v45 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v45 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1344);
    *(_QWORD *)(a1 + 1352) |= 1uLL;
  }
  if ( wlan_vdev_mlme_get_cmpt_obj(a1, v46, v47, v48, v49, v50, v51, v52, v53) )
  {
    v54 = *(_QWORD *)(a1 + 1352);
    if ( (v54 & 1) == 0 )
    {
LABEL_18:
      raw_spin_unlock(a1 + 1344);
      goto LABEL_19;
    }
  }
  else
  {
    v54 = *(_QWORD *)(a1 + 1352);
    if ( (v54 & 1) == 0 )
      goto LABEL_18;
  }
  *(_QWORD *)(a1 + 1352) = v54 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 1344);
LABEL_19:
  result = wmi_unified_send_self_srg_bss_color_bitmap_set_cmd(v44);
  if ( (_DWORD)result )
    goto LABEL_46;
  v64 = lmac_get_pdev_wmi_handle(a2, v56, v57, v58, v59, v60, v61, v62, v63);
  if ( !v64 )
    goto LABEL_39;
  v65 = v64;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v66 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v66 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v66 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1344);
    *(_QWORD *)(a1 + 1352) |= 1uLL;
  }
  wlan_vdev_mlme_get_cmpt_obj(a1, v67, v68, v69, v70, v71, v72, v73, v74);
  v122 = *(_QWORD *)(a1 + 1352);
  if ( (v122 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1352) = v122 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1344);
  }
  else
  {
    raw_spin_unlock(a1 + 1344);
  }
  result = wmi_unified_send_self_srg_partial_bssid_bitmap_set_cmd(v65);
  if ( !(_DWORD)result )
  {
LABEL_36:
    v102 = *(unsigned __int8 *)(a1 + 168);
    v103 = v123;
    v125 = 0;
    v124 = 0;
    v104 = lmac_get_pdev_wmi_handle(a2, v94, v95, v96, v97, v98, v99, v100, v101);
    if ( v104 )
    {
      v113 = v104;
      if ( (wmi_service_enabled(v104, 0xCEu, v105, v106, v107, v108, v109, v110, v111, v112) & 1) != 0 )
      {
        qdf_mem_set(&v124, 0xCu, 0);
        v124 = v102 | 0x9E00000000LL;
        v125 = v103;
        result = wmi_unified_vdev_set_param_send(v113);
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Target doesn't support SR operations",
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          "spatial_reuse_send_pd_threshold");
        result = 0;
      }
      goto LABEL_46;
    }
LABEL_39:
    result = 4;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
