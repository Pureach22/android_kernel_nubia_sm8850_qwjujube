__int64 __fastcall wlan_objmgr_psoc_component_obj_detach(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w20
  int v13; // w9
  __int64 v14; // x8
  int v15; // w8
  int v16; // w8
  int v17; // w8

  if ( a2 > 0x35 )
    return 38;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
  }
  if ( *(_QWORD *)(a1 + 2144 + 8LL * a2) != a3 )
  {
    *(_DWORD *)(a1 + 4LL * a2 + 2576) = 16;
    v8 = *(_QWORD *)(a1 + 2824);
    if ( (v8 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v8 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 16;
  }
  *(_QWORD *)(a1 + 2144 + 8LL * a2) = 0;
  *(_DWORD *)(a1 + 4LL * a2 + 2576) = 0;
  v9 = *(_QWORD *)(a1 + 2824);
  if ( (v9 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  if ( (*(_DWORD *)(a1 + 2792) & 0xFFFFFFFE) != 4 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v10 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v10 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
  }
  v11 = 0;
  v12 = 16;
  while ( 1 )
  {
    v13 = *(_DWORD *)(a1 + 4 * v11 + 2576);
    if ( v13 != 40 )
    {
      if ( v13 == 2 || v13 == 16 )
        goto LABEL_27;
      goto LABEL_20;
    }
    if ( !*(_QWORD *)(a1 + 8 * v11 + 2144) )
      break;
LABEL_20:
    if ( ++v11 == 54 )
    {
      v12 = 0;
      goto LABEL_27;
    }
  }
  v12 = 40;
LABEL_27:
  v14 = *(_QWORD *)(a1 + 2824);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
    if ( v12 == 16 )
      goto LABEL_39;
LABEL_29:
    if ( v12 )
      return 0;
    v15 = *(_DWORD *)(a1 + 2792);
    if ( v15 != 2 )
    {
      if ( v15 == 5 )
        goto LABEL_43;
      if ( v15 != 4 )
        return 0;
      *(_DWORD *)(a1 + 2792) = 2;
    }
    return wlan_objmgr_psoc_obj_free(a1);
  }
  raw_spin_unlock(a1 + 2816);
  if ( v12 != 16 )
    goto LABEL_29;
LABEL_39:
  v16 = *(_DWORD *)(a1 + 2792);
  if ( v16 == 5 )
  {
LABEL_43:
    v17 = 1;
LABEL_44:
    *(_DWORD *)(a1 + 2792) = v17;
    return 0;
  }
  if ( v16 == 4 )
  {
    v17 = 8;
    goto LABEL_44;
  }
  return 0;
}
