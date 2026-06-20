__int64 __fastcall sample_interval_ms_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 result; // x0
  unsigned __int16 v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( (unsigned int)kstrtou16(a3, 0, &v7) )
  {
    result = -22;
  }
  else
  {
    LODWORD(result) = btl_set_sample_interval_ms(v5, v7);
    if ( (int)result >= 0 )
      result = a4;
    else
      result = (int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
