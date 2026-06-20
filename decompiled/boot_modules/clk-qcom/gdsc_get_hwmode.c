__int64 __fastcall gdsc_get_hwmode(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x1
  unsigned int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 1544);
  v2 = *(unsigned int *)(a1 + 1552);
  v4 = 0;
  regmap_read(v1, v2, &v4);
  _ReadStatusReg(SP_EL0);
  return (v4 >> 1) & 1;
}
