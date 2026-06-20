__int64 __fastcall reg_process_c2c_detect_evt(__int64 a1, char a2)
{
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 psoc_tx_ops; // x0
  __int64 v15; // x22
  double (__fastcall *v16)(_QWORD); // x28
  unsigned int v17; // w23
  bool v18; // zf
  unsigned int v19; // w20
  __int64 result; // x0
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w8
  _DWORD *v31; // x8
  char v32; // w1
  __int64 pdev_by_id; // x0
  __int64 v34; // x26
  __int64 pdev_obj; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x27
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  _QWORD *v53; // x25
  int v54; // w8
  int v55; // w5
  __int64 v56; // x4
  __int64 v57; // x8
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  unsigned int v68; // w1
  unsigned int *v69; // x8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-18h]
  int v79; // [xsp+10h] [xbp-10h]
  char v80[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v81; // [xsp+18h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v80[0] = 0;
  psoc_obj = reg_get_psoc_obj();
  if ( !psoc_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: psoc reg component is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "reg_process_c2c_detect_evt");
    goto LABEL_7;
  }
  v13 = psoc_obj;
  psoc_tx_ops = reg_get_psoc_tx_ops(a1);
  if ( !psoc_tx_ops )
  {
LABEL_7:
    result = 16;
    goto LABEL_48;
  }
  v79 = a2 & 1;
  v15 = psoc_tx_ops;
  v16 = nullptr;
  v17 = 0;
  v18 = *(_BYTE *)(v13 + 91095) == 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( v18 )
    v19 = 21;
  else
    v19 = 22;
  while ( 1 )
  {
    v31 = *(_DWORD **)(v15 + 136);
    if ( v31 )
    {
      if ( *(v31 - 1) != 13449260 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, char *))v31)(a1, v17, v80);
      v32 = v80[0];
    }
    else
    {
      v32 = v17;
      v80[0] = v17;
    }
    pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, v32, v19);
    if ( !pdev_by_id )
      goto LABEL_13;
    v34 = pdev_by_id;
    pdev_obj = reg_get_pdev_obj();
    if ( !pdev_obj )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg pdev priv obj is NULL",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "reg_process_c2c_detect_evt");
      wlan_objmgr_pdev_release_ref(v34, v19, v58, v59, v60, v61, v62, v63, v64, v65, v66);
      result = 16;
      goto LABEL_48;
    }
    v44 = pdev_obj;
    if ( (reg_does_country_supp_c2c(v34) & 1) == 0 )
    {
      v67 = "%s: C2C is not supported.";
      v68 = 4;
      goto LABEL_46;
    }
    v53 = (_QWORD *)(v44 + 56728);
    if ( *(unsigned __int8 *)(v44 + 59010) == v79 )
      break;
    v54 = *(unsigned __int8 *)(v44 + 56760);
    *(_BYTE *)(v44 + 59010) = v79;
    if ( v54 == 1 && *(_BYTE *)(v44 + 57610) )
    {
      v55 = 0;
    }
    else if ( (reg_does_country_supp_c2c(*v53) & 1) != 0
           && (reg_is_indoor_ap_detected(*v53) & 1) != 0
           && *(_BYTE *)(v44 + 57613) )
    {
      v55 = 3;
    }
    else if ( *(_BYTE *)(v44 + 57612) )
    {
      v55 = 2;
    }
    else
    {
      v55 = 4;
    }
    v56 = *(unsigned __int8 *)(v44 + 56760);
    *(_DWORD *)(v44 + 58204) = v55;
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: indoor_chan_enabled %d ap_pwr_type %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "reg_set_ap_pwr_type",
      v56);
    ((void (__fastcall *)(__int64))reg_compute_pdev_current_chan_list)(v44);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 93240);
      v57 = *(_QWORD *)(v13 + 93248);
    }
    else
    {
      raw_spin_lock_bh(v13 + 93240);
      v57 = *(_QWORD *)(v13 + 93248) | 1LL;
      *(_QWORD *)(v13 + 93248) = v57;
    }
    if ( *(_QWORD *)(v13 + 91672) )
      v16 = *(double (__fastcall **)(_QWORD))(v13 + 91672);
    if ( (v57 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 93248) = v57 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 93240);
      if ( v16 )
        goto LABEL_9;
    }
    else
    {
      raw_spin_unlock(v13 + 93240);
      if ( v16 )
      {
LABEL_9:
        if ( *((_DWORD *)v16 - 1) != 1588979751 )
          __break(0x823Cu);
        v22 = v16(a1);
      }
    }
    wlan_objmgr_pdev_release_ref(v34, v19, v21, v22, v23, v24, v25, v26, v27, v28, v29);
LABEL_13:
    v30 = (unsigned __int8)v17++;
    if ( v30 >= 2 )
      goto LABEL_47;
  }
  v67 = "%s: No change in is_indoor_ap_found";
  v68 = 8;
LABEL_46:
  qdf_trace_msg(0x51u, v68, v67, v45, v46, v47, v48, v49, v50, v51, v52, "reg_process_c2c_detect_evt");
  wlan_objmgr_pdev_release_ref(v34, v19, v69, v70, v71, v72, v73, v74, v75, v76, v77);
LABEL_47:
  result = 0;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
