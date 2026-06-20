__int64 __fastcall sprs_register_reset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w8
  __int64 result; // x0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v6 = kstrtouint(a3, 16, &v8);
  result = -22;
  if ( !v6 && v8 == 1 )
  {
    reset_sprs_dump_table(a1);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
