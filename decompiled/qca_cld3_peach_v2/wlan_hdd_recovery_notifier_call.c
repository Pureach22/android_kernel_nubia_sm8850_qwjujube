__int64 __fastcall wlan_hdd_recovery_notifier_call(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned __int64 StatusReg; // x8
  unsigned int *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x1
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  __int64 v28; // x8
  unsigned __int64 v29; // x23
  __int64 vdev_by_user; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *v39; // x8
  char *v40; // x8
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 result; // x0
  __int64 v77; // [xsp+8h] [xbp-18h] BYREF
  __int64 v78[2]; // [xsp+10h] [xbp-10h] BYREF

  v78[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  if ( !a3 )
    goto LABEL_35;
  v3 = *(_QWORD *)(a1 + 24);
  if ( !v3 )
    goto LABEL_35;
  v78[0] = 0;
  if ( a2 == 5 )
  {
    v5 = *(unsigned int *)(a3 + 8);
    if ( (unsigned int)(v5 - 180) < 0xFFFFFF3C )
      goto LABEL_35;
    v6 = *(_QWORD *)a3 + v5;
    *(_WORD *)v6 = 526;
    *(_BYTE *)(v6 + 2) = *(_BYTE *)(v3 + 1803);
    *(_DWORD *)(v6 + 3) = *(_DWORD *)(v3 + 1804);
    *(_BYTE *)(v6 + 15) = *(_BYTE *)(v3 + 1816);
    *(_DWORD *)(a3 + 8) += 16;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v3 + 32);
  }
  else
  {
    raw_spin_lock_bh(v3 + 32);
    *(_QWORD *)(v3 + 40) |= 1uLL;
  }
  hdd_get_front_adapter_no_lock(v3, v78);
  if ( v78[0] )
  {
    hdd_adapter_dev_hold_debug(v78[0], 4u, v8, v9, v10, v11, v12, v13, v14, v15, v16);
    v17 = v78[0];
  }
  else
  {
    v17 = 0;
  }
  hdd_get_next_adapter_no_lock(v3, v17, &v77);
  if ( v77 )
    hdd_adapter_dev_hold_debug(v77, 4u, v18, v19, v20, v21, v22, v23, v24, v25, v26);
  v27 = *(_QWORD *)(v3 + 40);
  if ( (v27 & 1) != 0 )
  {
    *(_QWORD *)(v3 + 40) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v3 + 32);
    v28 = v78[0];
    if ( v78[0] )
      goto LABEL_17;
LABEL_37:
    result = 1;
    goto LABEL_38;
  }
  raw_spin_unlock(v3 + 32);
  v28 = v78[0];
  if ( !v78[0] )
    goto LABEL_37;
LABEL_17:
  v29 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                     *(_QWORD *)(v28 + 52832),
                     6u,
                     (__int64)"wlan_hdd_recovery_notifier_call");
    if ( !vdev_by_user )
      goto LABEL_21;
    v39 = (unsigned int *)*(unsigned int *)(a3 + 8);
    if ( (unsigned int)((_DWORD)v39 - 190) <= 0xFFFFFF3B )
      break;
    v40 = (char *)v39 + *(_QWORD *)a3;
    *(_WORD *)v40 = 260;
    v40[2] = *(_BYTE *)(vdev_by_user + 168);
    v40[3] = *(_DWORD *)(vdev_by_user + 16);
    v40[4] = *(_DWORD *)(vdev_by_user + 20);
    v40[5] = *(_DWORD *)(vdev_by_user + 24);
    v41 = (unsigned int *)(unsigned int)(*(_DWORD *)(a3 + 8) + 6);
    *(_DWORD *)(a3 + 8) = (_DWORD)v41;
    _hdd_objmgr_put_vdev_by_user(
      vdev_by_user,
      6u,
      (__int64)"wlan_hdd_recovery_notifier_call",
      v41,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38);
LABEL_21:
    hdd_adapter_dev_put_debug(v78[0], 4u, v31, v32, v33, v34, v35, v36, v37, v38);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v29 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v3 + 32);
    }
    else
    {
      raw_spin_lock_bh(v3 + 32);
      *(_QWORD *)(v3 + 40) |= 1uLL;
    }
    v78[0] = v77;
    hdd_get_next_adapter_no_lock(v3, v77, &v77);
    hdd_validate_next_adapter(v78, &v77, 4u, v42, v43, v44, v45, v46, v47, v48, v49);
    if ( v77 )
      hdd_adapter_dev_hold_debug(v77, 4u, v50, v51, v52, v53, v54, v55, v56, v57, v58);
    v59 = *(_QWORD *)(v3 + 40);
    if ( (v59 & 1) != 0 )
    {
      *(_QWORD *)(v3 + 40) = v59 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v3 + 32);
      v28 = v78[0];
      if ( !v78[0] )
        goto LABEL_37;
    }
    else
    {
      raw_spin_unlock(v3 + 32);
      v28 = v78[0];
      if ( !v78[0] )
        goto LABEL_37;
    }
  }
  _hdd_objmgr_put_vdev_by_user(
    vdev_by_user,
    6u,
    (__int64)"wlan_hdd_recovery_notifier_call",
    v39,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38);
  hdd_adapter_dev_put_debug(v78[0], 4u, v60, v61, v62, v63, v64, v65, v66, v67);
  if ( v77 )
    hdd_adapter_dev_put_debug(v77, 4u, v68, v69, v70, v71, v72, v73, v74, v75);
LABEL_35:
  result = 0x8000;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
