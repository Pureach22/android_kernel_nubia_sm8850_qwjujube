__int64 __fastcall wlan_objmgr_trigger_psoc_comp_priv_object_creation(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x1
  unsigned __int64 v11; // x8
  __int64 v12; // x8
  int v13; // w10
  int v14; // w20
  int v15; // w9
  __int64 v16; // x8
  unsigned int v17; // w21

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
  v6 = a1 + 2144;
  v7 = *(_QWORD *)(a1 + 2824);
  if ( *(_QWORD *)(a1 + 2144 + 8LL * a2) )
  {
    if ( (v7 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v7 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 16;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  v8 = g_umac_glb_obj + 8LL * a2;
  v9 = *(__int64 (__fastcall **)(__int64, __int64))(v8 + 40);
  if ( !v9 )
    return 16;
  v10 = *(_QWORD *)(v8 + 472);
  if ( *((_DWORD *)v9 - 1) != -1796695762 )
    __break(0x8228u);
  *(_DWORD *)(a1 + 4LL * a2 + 2576) = v9(a1, v10);
  if ( *(_DWORD *)(a1 + 2792) != 1 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v11 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v11 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v11 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
  }
  v12 = 0;
  while ( 1 )
  {
    v13 = *(_DWORD *)(v6 + 4 * v12 + 432);
    if ( v13 != 40 )
    {
      v14 = 0;
      v15 = 16;
      if ( v13 == 2 || v13 == 16 )
        goto LABEL_32;
      goto LABEL_24;
    }
    if ( !*(_QWORD *)(v6 + 8 * v12) )
      break;
LABEL_24:
    if ( ++v12 == 54 )
    {
      v14 = 0;
      v15 = 0;
      goto LABEL_32;
    }
  }
  v15 = 40;
  v14 = 1;
LABEL_32:
  v16 = *(_QWORD *)(a1 + 2824);
  v17 = v15;
  if ( (v16 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
    result = v17;
    if ( v14 )
    {
LABEL_34:
      *(_DWORD *)(a1 + 2792) = 3;
      return 40;
    }
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
    result = v17;
    if ( v14 )
      goto LABEL_34;
  }
  return result;
}
