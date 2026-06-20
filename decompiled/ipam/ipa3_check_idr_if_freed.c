bool __fastcall ipa3_check_idr_if_freed(__int64 a1)
{
  __int64 next; // x0
  _BOOL4 v3; // w20
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock(ipa3_ctx + 34232);
  v5 = 0;
  next = idr_get_next(ipa3_ctx + 34184, &v5);
  if ( next )
  {
    do
    {
      v3 = next != a1;
      if ( next == a1 )
        break;
      ++v5;
      next = idr_get_next(ipa3_ctx + 34184, &v5);
    }
    while ( next );
  }
  else
  {
    v3 = 1;
  }
  raw_spin_unlock(ipa3_ctx + 34232);
  _ReadStatusReg(SP_EL0);
  return v3;
}
