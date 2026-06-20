__int64 __fastcall target_if_spectral_get_macaddr(__int64 *a1, void *a2)
{
  __int64 v2; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  const void *v6; // x1

  v2 = *a1;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 1248);
    v5 = *(_QWORD *)(v2 + 1256);
    if ( (v5 & 1) == 0 )
    {
LABEL_5:
      raw_spin_unlock(v2 + 1248);
      goto LABEL_6;
    }
  }
  else
  {
    raw_spin_lock_bh(v2 + 1248);
    v5 = *(_QWORD *)(v2 + 1256) | 1LL;
    *(_QWORD *)(v2 + 1256) = v5;
    if ( (v5 & 1) == 0 )
      goto LABEL_5;
  }
  *(_QWORD *)(v2 + 1256) = v5 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v2 + 1248);
LABEL_6:
  if ( v2 )
    v6 = (const void *)(v2 + 32);
  else
    v6 = nullptr;
  qdf_mem_copy(a2, v6, 6u);
  return 0;
}
