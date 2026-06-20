__int64 __fastcall pmo_core_add_wow_user_pattern(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int ref; // w21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 comp_private_obj; // x21
  unsigned int v22; // w22
  unsigned __int64 StatusReg; // x23
  __int64 v24; // x24
  __int64 v25; // x8
  unsigned int v26; // w24
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x22
  unsigned __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x0
  unsigned __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x3
  unsigned __int64 v46; // x8
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v57; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v58; // [xsp+8h] [xbp-98h]
  __int64 v59; // [xsp+10h] [xbp-90h]
  __int64 v60; // [xsp+18h] [xbp-88h]
  __int64 v61; // [xsp+20h] [xbp-80h]
  __int64 v62; // [xsp+28h] [xbp-78h]
  __int64 v63; // [xsp+30h] [xbp-70h]
  __int64 v64; // [xsp+38h] [xbp-68h]
  __int64 v65; // [xsp+40h] [xbp-60h]
  __int64 v66; // [xsp+48h] [xbp-58h]
  __int64 v67; // [xsp+50h] [xbp-50h]
  __int64 v68; // [xsp+58h] [xbp-48h]
  __int64 v69; // [xsp+60h] [xbp-40h]
  __int64 v70; // [xsp+68h] [xbp-38h]
  __int64 v71; // [xsp+70h] [xbp-30h]
  __int64 v72; // [xsp+78h] [xbp-28h]
  __int64 v73; // [xsp+80h] [xbp-20h]
  __int64 v74; // [xsp+88h] [xbp-18h]
  __int64 v75; // [xsp+90h] [xbp-10h]
  __int64 v76; // [xsp+98h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOWORD(v75) = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( ref )
    goto LABEL_45;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v22 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v24 = *(_QWORD *)comp_private_obj;
    if ( *(_BYTE *)(*(_QWORD *)comp_private_obj + 955LL) == 1 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1056);
        v25 = *(_QWORD *)(comp_private_obj + 1064);
        v26 = *(unsigned __int8 *)(comp_private_obj + 1030);
        if ( (v25 & 1) == 0 )
          goto LABEL_8;
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1056);
        v25 = *(_QWORD *)(comp_private_obj + 1064) | 1LL;
        *(_QWORD *)(comp_private_obj + 1064) = v25;
        v26 = *(unsigned __int8 *)(comp_private_obj + 1030);
        if ( (v25 & 1) == 0 )
        {
LABEL_8:
          v27 = comp_private_obj + 1056;
LABEL_15:
          raw_spin_unlock(v27);
          goto LABEL_16;
        }
      }
      *(_QWORD *)(comp_private_obj + 1064) = v25 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(comp_private_obj + 1056);
    }
    else
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v24 + 1040);
      }
      else
      {
        raw_spin_lock_bh(v24 + 1040);
        *(_QWORD *)(v24 + 1048) |= 1uLL;
      }
      v28 = *(_QWORD *)comp_private_obj;
      v29 = *(_QWORD *)(*(_QWORD *)comp_private_obj + 1048LL);
      v26 = *(unsigned __int8 *)(*(_QWORD *)comp_private_obj + 944LL);
      if ( (v29 & 1) == 0 )
      {
        v27 = v28 + 1040;
        goto LABEL_15;
      }
      *(_QWORD *)(v28 + 1048) = v29 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v28 + 1040);
    }
LABEL_16:
    if ( v26 <= (unsigned __int8)v22 )
      break;
    pmo_tgt_del_wow_pattern(a1, v22++, 0);
  }
  v30 = *(_QWORD *)comp_private_obj;
  if ( *(_BYTE *)(*(_QWORD *)comp_private_obj + 955LL) != 1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v34 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v34 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v30 + 1040);
    }
    else
    {
      raw_spin_lock_bh(v30 + 1040);
      *(_QWORD *)(v30 + 1048) |= 1uLL;
    }
    *(_BYTE *)(*(_QWORD *)comp_private_obj + 944LL) = 0;
    v35 = *(_QWORD *)comp_private_obj;
    v36 = *(_QWORD *)(*(_QWORD *)comp_private_obj + 1048LL);
    if ( (v36 & 1) != 0 )
    {
      *(_QWORD *)(v35 + 1048) = v36 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v35 + 1040);
      goto LABEL_35;
    }
    v33 = v35 + 1040;
LABEL_34:
    raw_spin_unlock(v33);
    goto LABEL_35;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    v31 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v31 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v31 + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v32 = *(_QWORD *)(comp_private_obj + 1064) | 1LL;
      *(_QWORD *)(comp_private_obj + 1064) = v32;
      *(_BYTE *)(comp_private_obj + 1030) = 0;
      if ( (v32 & 1) != 0 )
        goto LABEL_48;
LABEL_27:
      v33 = comp_private_obj + 1056;
      goto LABEL_34;
    }
  }
  raw_spin_lock(comp_private_obj + 1056);
  v32 = *(_QWORD *)(comp_private_obj + 1064);
  *(_BYTE *)(comp_private_obj + 1030) = 0;
  if ( (v32 & 1) == 0 )
    goto LABEL_27;
LABEL_48:
  *(_QWORD *)(comp_private_obj + 1064) = v32 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(comp_private_obj + 1056);
LABEL_35:
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: Add user passed wow pattern id %d vdev id %d",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "pmo_core_add_wow_user_pattern",
    *a2,
    *(unsigned __int8 *)(a1 + 168),
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76);
  qdf_mem_set(&v57, 0x92u, 0);
  v45 = a2[2];
  if ( !a2[2] )
    goto LABEL_42;
  v46 = 0;
  while ( 2 )
  {
    if ( ((a2[((unsigned __int8)v46 >> 3) + 150] >> (~(_BYTE)v46 & 7)) & 1) == 0 )
    {
LABEL_38:
      if ( v45 == ++v46 )
        goto LABEL_42;
      continue;
    }
    break;
  }
  if ( v46 <= 0x91 )
  {
    *((_BYTE *)&v57 + v46) = -1;
    goto LABEL_38;
  }
  __break(0x5512u);
LABEL_42:
  ref = pmo_tgt_send_wow_patterns_to_fw(a1, *a2, a2 + 3, v45, a2[1], &v57, (unsigned int)v45, 1);
  if ( ref )
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to add wow pattern %d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "pmo_core_add_wow_user_pattern",
      *a2);
  wlan_objmgr_vdev_release_ref(a1, 0xAu, v47, v48, v49, v50, v51, v52, v53, v54, v55);
LABEL_45:
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: exit",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "pmo_core_add_wow_user_pattern",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75);
  _ReadStatusReg(SP_EL0);
  return ref;
}
