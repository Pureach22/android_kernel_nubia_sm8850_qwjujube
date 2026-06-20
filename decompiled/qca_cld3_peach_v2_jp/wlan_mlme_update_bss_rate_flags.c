__int64 __fastcall wlan_mlme_update_bss_rate_flags(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned __int8 a7)
{
  __int64 v7; // x29
  __int64 v8; // x30
  unsigned __int8 v14; // w20
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x19
  __int64 cmpt_obj; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x26
  int v35; // w9
  int v36; // w8
  int v37; // w21
  __int64 comp_private_obj; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v49; // x8
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w20
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // [xsp+18h] [xbp-58h]
  __int64 v71; // [xsp+28h] [xbp-48h]

  if ( !((unsigned __int8)(a5 | a4) | (unsigned __int8)(a6 | a7)) )
    return 4;
  v71 = v8;
  v14 = a2;
  v15 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 5);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev: %d vdev not found",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_mlme_update_bss_rate_flags",
      v14);
    return 4;
  }
  v24 = v15;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v15, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev: %d mlme obj not found",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_mlme_update_bss_rate_flags",
      v14);
    wlan_objmgr_vdev_release_ref(v24, 5u, v61, v62, v63, v64, v65, v66, v67, v68, v69);
    return 4;
  }
  v34 = cmpt_obj;
  *(_DWORD *)(cmpt_obj + 288) = 0;
  if ( a5 )
  {
    if ( a3 )
      v35 = 768;
    else
      v35 = 256;
    if ( a3 == 2 )
      v35 = 1792;
    if ( (unsigned int)(a3 - 3) >= 2 )
      v36 = v35;
    else
      v36 = 3840;
  }
  else if ( a6 )
  {
    if ( a3 )
    {
      if ( a3 == 2 )
      {
        v36 = 224;
      }
      else if ( (unsigned int)(a3 - 3) >= 2 )
      {
        v36 = 96;
      }
      else
      {
        v36 = 4320;
      }
    }
    else
    {
      v36 = 32;
    }
  }
  else
  {
    v36 = a7;
    if ( !a7 )
      goto LABEL_14;
    if ( a3 )
      v36 = 6;
    else
      v36 = 2;
  }
  *(_DWORD *)(cmpt_obj + 288) = v36;
LABEL_14:
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev:%d, eht:%u, he:%u, vht:%u, ht:%u, flag:%x, cw:%d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_mlme_update_bss_rate_flags",
    v14,
    a4,
    a5,
    a6,
    a7,
    v36,
    a3,
    v70,
    v7,
    v71);
  v37 = *(_DWORD *)(v34 + 288);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v24, 0x1Bu);
  if ( comp_private_obj )
  {
    v47 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 24);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 24);
      *(_QWORD *)(v47 + 32) |= 1uLL;
    }
    *(_DWORD *)(*(_QWORD *)(v47 + 8) + 4LL) = v37;
    v49 = *(_QWORD *)(v47 + 32);
    if ( (v49 & 1) != 0 )
    {
      *(_QWORD *)(v47 + 32) = v49 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v47 + 24);
    }
    else
    {
      raw_spin_unlock(v47 + 24);
    }
    v59 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev cp stats object is null",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "wlan_mlme_cp_stats_set_rate_flags");
    v59 = 29;
  }
  wlan_objmgr_vdev_release_ref(v24, 5u, v50, v51, v52, v53, v54, v55, v56, v57, v58);
  return v59;
}
