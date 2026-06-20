__int64 __fastcall epping_cookie_cleanup(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 456);
    v3 = *(_QWORD *)(a1 + 464);
  }
  else
  {
    raw_spin_lock_bh(a1 + 456);
    v3 = *(_QWORD *)(a1 + 464) | 1LL;
    *(_QWORD *)(a1 + 464) = v3;
  }
  *(_QWORD *)(a1 + 408) = 0;
  *(_DWORD *)(a1 + 416) = 0;
  if ( (v3 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 456);
    v4 = *(_QWORD *)(a1 + 424);
    if ( !v4 )
      goto LABEL_8;
    goto LABEL_7;
  }
  *(_QWORD *)(a1 + 464) = v3 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 456);
  v4 = *(_QWORD *)(a1 + 424);
  if ( v4 )
  {
LABEL_7:
    _qdf_mem_free(v4);
    *(_QWORD *)(a1 + 424) = 0;
  }
LABEL_8:
  v5 = *(_QWORD *)(a1 + 432);
  if ( v5 )
  {
    _qdf_mem_free(v5);
    *(_QWORD *)(a1 + 432) = 0;
  }
  v6 = *(_QWORD *)(a1 + 440);
  if ( v6 )
  {
    _qdf_mem_free(v6);
    *(_QWORD *)(a1 + 440) = 0;
  }
  result = *(_QWORD *)(a1 + 448);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 448) = 0;
  }
  return result;
}
