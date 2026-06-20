__int64 __fastcall adreno_prop_device_shadow(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x9
  __int64 result; // x0
  __int64 v5; // [xsp+0h] [xbp-20h] BYREF
  __int64 v6; // [xsp+8h] [xbp-18h]
  __int64 v7; // [xsp+10h] [xbp-10h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 40);
  v6 = 0;
  v7 = 0;
  v5 = 0;
  if ( *(_QWORD *)(v2 + 8) )
  {
    v3 = *(_QWORD *)(v2 + 40);
    v5 = 4026527744LL;
    v6 = v3;
    LODWORD(v7) = 516;
  }
  result = copy_prop(a2, &v5, 24);
  _ReadStatusReg(SP_EL0);
  return result;
}
