__int64 __fastcall pmo_core_del_wow_pattern(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  __int64 v12; // x21
  __int64 v13; // x20
  bool v14; // zf
  char StatusReg; // w8
  unsigned __int64 v16; // x8
  __int64 v17; // x8
  unsigned int v18; // w22
  __int64 v19; // x0
  unsigned __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v23; // w21
  unsigned int v24; // w0
  __int64 v25; // x22
  unsigned int v26; // w21
  char v27; // w8
  unsigned __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x0
  unsigned __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // x22
  char v35; // w8
  unsigned __int64 v36; // x8
  __int64 v37; // x8
  unsigned int v38; // w22
  __int64 v39; // x0
  unsigned __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x9
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w20
  unsigned int v53; // w0

  result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
    return result;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v12 = *(_QWORD *)comp_private_obj;
  v13 = comp_private_obj;
  v14 = *(_BYTE *)(*(_QWORD *)comp_private_obj + 955LL) == 1;
  StatusReg = _ReadStatusReg(DAIF);
  if ( v14 )
  {
    if ( StatusReg < 0
      || (v16 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v16 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
      v17 = *(_QWORD *)(v13 + 1064);
      v18 = *(unsigned __int8 *)(v13 + 1030);
      if ( (v17 & 1) == 0 )
      {
LABEL_8:
        v19 = v13 + 1056;
LABEL_15:
        raw_spin_unlock(v19);
        goto LABEL_16;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v17 = *(_QWORD *)(v13 + 1064) | 1LL;
      *(_QWORD *)(v13 + 1064) = v17;
      v18 = *(unsigned __int8 *)(v13 + 1030);
      if ( (v17 & 1) == 0 )
        goto LABEL_8;
    }
    *(_QWORD *)(v13 + 1064) = v17 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 1056);
    goto LABEL_16;
  }
  if ( StatusReg < 0
    || (v20 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v20 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v20 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v12 + 1040);
  }
  else
  {
    raw_spin_lock_bh(v12 + 1040);
    *(_QWORD *)(v12 + 1048) |= 1uLL;
  }
  v21 = *(_QWORD *)v13;
  v22 = *(_QWORD *)(*(_QWORD *)v13 + 1048LL);
  v18 = *(unsigned __int8 *)(*(_QWORD *)v13 + 944LL);
  if ( (v22 & 1) == 0 )
  {
    v19 = v21 + 1040;
    goto LABEL_15;
  }
  *(_QWORD *)(v21 + 1048) = v22 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v21 + 1040);
LABEL_16:
  if ( v18 )
  {
    v23 = 0;
    do
      v24 = pmo_tgt_del_wow_pattern(a1, v23++, 0);
    while ( v18 > (unsigned __int8)v23 );
  }
  else
  {
    v24 = 0;
  }
  v25 = *(_QWORD *)v13;
  v26 = v24;
  v14 = *(_BYTE *)(*(_QWORD *)v13 + 955LL) == 1;
  v27 = _ReadStatusReg(DAIF);
  if ( v14 )
  {
    if ( v27 < 0
      || (v28 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v28 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v28 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 1056);
      v29 = *(_QWORD *)(v13 + 1064);
      *(_BYTE *)(v13 + 1030) = 0;
      if ( (v29 & 1) == 0 )
      {
LABEL_27:
        v30 = v13 + 1056;
LABEL_34:
        raw_spin_unlock(v30);
        goto LABEL_35;
      }
    }
    else
    {
      raw_spin_lock_bh(v13 + 1056);
      v29 = *(_QWORD *)(v13 + 1064) | 1LL;
      *(_QWORD *)(v13 + 1064) = v29;
      *(_BYTE *)(v13 + 1030) = 0;
      if ( (v29 & 1) == 0 )
        goto LABEL_27;
    }
    *(_QWORD *)(v13 + 1064) = v29 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 1056);
    goto LABEL_35;
  }
  if ( v27 < 0
    || (v31 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v31 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v25 + 1040);
  }
  else
  {
    raw_spin_lock_bh(v25 + 1040);
    *(_QWORD *)(v25 + 1048) |= 1uLL;
  }
  *(_BYTE *)(*(_QWORD *)v13 + 944LL) = 0;
  v32 = *(_QWORD *)v13;
  v33 = *(_QWORD *)(*(_QWORD *)v13 + 1048LL);
  if ( (v33 & 1) == 0 )
  {
    v30 = v32 + 1040;
    goto LABEL_34;
  }
  *(_QWORD *)(v32 + 1048) = v33 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v32 + 1040);
LABEL_35:
  v34 = *(_QWORD *)v13;
  v14 = *(_BYTE *)(*(_QWORD *)v13 + 955LL) == 1;
  v35 = _ReadStatusReg(DAIF);
  if ( v14 )
  {
    if ( v35 < 0
      || (v36 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v36 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 1056);
      v37 = *(_QWORD *)(v13 + 1064);
      v38 = *(unsigned __int8 *)(v13 + 1031);
      if ( (v37 & 1) == 0 )
      {
LABEL_41:
        v39 = v13 + 1056;
        goto LABEL_48;
      }
    }
    else
    {
      raw_spin_lock_bh(v13 + 1056);
      v37 = *(_QWORD *)(v13 + 1064) | 1LL;
      *(_QWORD *)(v13 + 1064) = v37;
      v38 = *(unsigned __int8 *)(v13 + 1031);
      if ( (v37 & 1) == 0 )
        goto LABEL_41;
    }
    *(_QWORD *)(v13 + 1064) = v37 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 1056);
    goto LABEL_49;
  }
  if ( v35 < 0
    || (v40 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v40 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v40 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v34 + 1040);
  }
  else
  {
    raw_spin_lock_bh(v34 + 1040);
    *(_QWORD *)(v34 + 1048) |= 1uLL;
  }
  v41 = *(_QWORD *)v13;
  v42 = *(_QWORD *)(*(_QWORD *)v13 + 1048LL);
  v38 = *(unsigned __int8 *)(*(_QWORD *)v13 + 945LL);
  if ( (v42 & 1) != 0 )
  {
    *(_QWORD *)(v41 + 1048) = v42 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v41 + 1040);
    goto LABEL_49;
  }
  v39 = v41 + 1040;
LABEL_48:
  raw_spin_unlock(v39);
LABEL_49:
  if ( v38 )
  {
    v52 = 0;
    do
      v53 = pmo_tgt_del_wow_pattern(a1, v52++, 1);
    while ( v38 > (unsigned __int8)v52 );
    v26 = v53;
  }
  wlan_objmgr_vdev_release_ref(a1, 0xAu, v43, v44, v45, v46, v47, v48, v49, v50, v51);
  return v26;
}
