__int64 __fastcall wmi_unified_remove_work(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  __int64 *v4; // x0
  __int64 *v5; // x9
  __int64 v6; // x8
  unsigned __int64 v7; // x8
  __int64 v8; // x8
  __int64 *v9; // x0
  __int64 *v10; // x9
  __int64 v11; // x8

  _flush_workqueue(*(_QWORD *)(a1 + 160));
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 72);
  }
  else
  {
    raw_spin_lock_bh(a1 + 72);
    *(_QWORD *)(a1 + 80) |= 1uLL;
  }
  while ( 1 )
  {
    v4 = *(__int64 **)(a1 + 88);
    if ( !v4 )
      break;
    v5 = *(__int64 **)(a1 + 96);
    --*(_DWORD *)(a1 + 104);
    if ( v4 == v5 )
    {
      v3 = 0;
      *(_QWORD *)(a1 + 96) = 0;
    }
    else
    {
      v3 = *v4;
    }
    *(_QWORD *)(a1 + 88) = v3;
    *v4 = 0;
    _qdf_nbuf_free((__int64)v4);
  }
  v6 = *(_QWORD *)(a1 + 80);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 80) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 72);
  }
  else
  {
    raw_spin_unlock(a1 + 72);
  }
  _flush_workqueue(*(_QWORD *)(a1 + 168));
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v7 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v7 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 176);
  }
  else
  {
    raw_spin_lock_bh(a1 + 176);
    *(_QWORD *)(a1 + 184) |= 1uLL;
  }
  while ( 1 )
  {
    v9 = *(__int64 **)(a1 + 192);
    if ( !v9 )
      break;
    v10 = *(__int64 **)(a1 + 200);
    --*(_DWORD *)(a1 + 208);
    if ( v9 == v10 )
    {
      v8 = 0;
      *(_QWORD *)(a1 + 200) = 0;
    }
    else
    {
      v8 = *v9;
    }
    *(_QWORD *)(a1 + 192) = v8;
    *v9 = 0;
    _qdf_nbuf_free((__int64)v9);
  }
  v11 = *(_QWORD *)(a1 + 184);
  if ( (v11 & 1) == 0 )
    return raw_spin_unlock(a1 + 176);
  *(_QWORD *)(a1 + 184) = v11 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 176);
}
