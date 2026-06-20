__int64 __fastcall qcom_glink_early_ssr_notify(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 next; // x0
  int i; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = result;
    *(_BYTE *)(result + 249) = 1;
    _wake_up(result + 224, 3, 0, 0);
    v2 = raw_spin_lock_irqsave(v1 + 156);
    for ( i = 0; ; ++i )
    {
      next = idr_get_next(v1 + 160, &i);
      if ( !next )
        break;
      _wake_up(next + 400, 3, 1, 0);
    }
    result = raw_spin_unlock_irqrestore(v1 + 156, v2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
