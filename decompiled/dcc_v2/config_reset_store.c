__int64 __fastcall config_reset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w8
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8[0] = 0;
  v6 = kstrtoull(a3, 16, v8);
  result = -22;
  if ( !v6 && v8[0] <= 1u )
  {
    if ( v8[0] )
      dcc_config_reset(v5);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
