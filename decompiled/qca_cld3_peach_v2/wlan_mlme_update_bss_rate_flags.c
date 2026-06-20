__int64 __fastcall wlan_mlme_update_bss_rate_flags(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned __int8 a7)
{
  int v7; // w19
  int v8; // w26
  int v9; // w28
  int v10; // w27
  unsigned __int8 v16; // w20
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w20
  __int64 v27; // x24
  __int64 cmpt_obj; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int8 v37; // w10
  int v38; // w8
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w9
  bool v50; // zf
  int v51; // w9
  __int64 v52; // x19
  int v53; // w21
  __int64 comp_private_obj; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v65; // x8
  unsigned int *v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v75; // w19
  unsigned __int8 v76; // [xsp+2Ch] [xbp-4h]

  v7 = a5;
  v8 = a4;
  v9 = a6;
  v10 = a7;
  if ( !(a5 | a4 | a6 | a7) )
    return 4;
  v16 = a2;
  v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 5);
  if ( !v17 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev: %d vdev not found",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_mlme_update_bss_rate_flags",
      v16);
    return 4;
  }
  v76 = v16;
  v26 = a3;
  v27 = v17;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v17, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev: %d mlme obj not found",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_mlme_update_bss_rate_flags",
      v76);
    wlan_objmgr_vdev_release_ref(v27, 5u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
    return 4;
  }
  *(_DWORD *)(cmpt_obj + 304) = 0;
  if ( !v8 )
  {
    if ( v7 )
    {
      if ( v26 )
        v49 = 768;
      else
        v49 = 256;
      if ( v26 == 2 )
        v49 = 1792;
      v37 = v76;
      if ( (unsigned int)(v26 - 3) >= 2 )
        v38 = v49;
      else
        v38 = 3840;
      goto LABEL_27;
    }
    v37 = v76;
    if ( v9 )
    {
      if ( v26 )
      {
        if ( v26 == 2 )
        {
          v38 = 224;
        }
        else if ( (unsigned int)(v26 - 3) >= 2 )
        {
          v38 = 96;
        }
        else
        {
          v38 = 4320;
        }
      }
      else
      {
        v38 = 32;
      }
      goto LABEL_27;
    }
    if ( !v10 )
    {
      v38 = 0;
      goto LABEL_28;
    }
    v50 = v26 == 0;
    v38 = 6;
    v51 = 2;
    goto LABEL_25;
  }
  if ( v26 != 7 )
  {
    v37 = v76;
    if ( (unsigned int)(v26 - 3) < 2 )
    {
      v38 = 122880;
      goto LABEL_27;
    }
    if ( v26 )
      v38 = 24576;
    else
      v38 = 0x2000;
    v50 = v26 == 2;
    v51 = 57344;
LABEL_25:
    if ( v50 )
      v38 = v51;
    goto LABEL_27;
  }
  v37 = v76;
  v38 = 253952;
LABEL_27:
  *(_DWORD *)(cmpt_obj + 304) = v38;
LABEL_28:
  v52 = cmpt_obj;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev:%d, eht:%u, he:%u, vht:%u, ht:%u, flag:%x, cw:%d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "wlan_mlme_update_bss_rate_flags",
    v37,
    a4,
    a5,
    a6,
    a7,
    v38,
    v26);
  v53 = *(_DWORD *)(v52 + 304);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v27, 0x1Bu);
  if ( comp_private_obj )
  {
    v63 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 24);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 24);
      *(_QWORD *)(v63 + 32) |= 1uLL;
    }
    *(_DWORD *)(*(_QWORD *)(v63 + 8) + 4LL) = v53;
    v65 = *(_QWORD *)(v63 + 32);
    if ( (v65 & 1) != 0 )
    {
      *(_QWORD *)(v63 + 32) = v65 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v63 + 24);
    }
    else
    {
      raw_spin_unlock(v63 + 24);
    }
    v75 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev cp stats object is null",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "wlan_mlme_cp_stats_set_rate_flags");
    v75 = 29;
  }
  wlan_objmgr_vdev_release_ref(v27, 5u, v66, v67, v68, v69, v70, v71, v72, v73, v74);
  return v75;
}
