__int64 __fastcall wlan_objmgr_psoc_component_obj_attach(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned __int64 v12; // x8
  __int64 v13; // x8
  unsigned int v14; // w20
  int v15; // w9
  __int64 v16; // x8
  int v17; // w9
  __int64 v18; // x22
  __int64 v19; // x8
  _DWORD *v20; // x9
  __int64 v21; // x1

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
  if ( *(_QWORD *)(a1 + 2144 + 8LL * a2) )
  {
    v10 = *(_QWORD *)(a1 + 2824);
    if ( (v10 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v10 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 16;
  }
  *(_QWORD *)(a1 + 2144 + 8LL * a2) = a3;
  *(_DWORD *)(a1 + 4LL * a2 + 2576) = a4;
  v11 = *(_QWORD *)(a1 + 2824);
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  if ( *(_DWORD *)(a1 + 2792) != 3 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v12 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v12 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
  }
  v13 = 0;
  v14 = 16;
  while ( 1 )
  {
    v15 = *(_DWORD *)(a1 + 4 * v13 + 2576);
    if ( v15 != 40 )
    {
      if ( v15 == 2 || v15 == 16 )
        goto LABEL_27;
      goto LABEL_20;
    }
    if ( !*(_QWORD *)(a1 + 8 * v13 + 2144) )
      break;
LABEL_20:
    if ( ++v13 == 54 )
    {
      v14 = 0;
      goto LABEL_27;
    }
  }
  v14 = 40;
LABEL_27:
  v16 = *(_QWORD *)(a1 + 2824);
  if ( (v16 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
    if ( !v14 )
      goto LABEL_35;
LABEL_29:
    if ( v14 == 16 )
    {
      v17 = 7;
      goto LABEL_36;
    }
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
    if ( v14 )
      goto LABEL_29;
LABEL_35:
    v17 = 1;
LABEL_36:
    v18 = 2200;
    *(_DWORD *)(a1 + 2792) = v17;
    v19 = g_umac_glb_obj;
    do
    {
      v20 = *(_DWORD **)(v19 + v18 - 432);
      if ( v20 )
      {
        v21 = *(_QWORD *)(v19 + v18);
        if ( *(v20 - 1) != 386620652 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v20)(a1, v21, v14);
        v19 = g_umac_glb_obj;
      }
      v18 += 8;
    }
    while ( v18 != 2632 );
  }
  return 0;
}
