__int64 __fastcall adreno_prop_device_qtimer(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x9
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  __int64 v7; // [xsp+10h] [xbp-10h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 13144);
  v6 = 0;
  v7 = 0;
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = *(_QWORD *)(v2 + 24);
    v4 = *(_QWORD *)(v2 + 40);
    v6 = v3;
    v7 = v4;
  }
  result = copy_prop(a2, &v6, 16);
  _ReadStatusReg(SP_EL0);
  return result;
}
