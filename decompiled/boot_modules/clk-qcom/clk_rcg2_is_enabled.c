__int64 __fastcall clk_rcg2_is_enabled(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x1
  __int64 result; // x0
  int v4; // w8
  _BOOL4 v5; // w8
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(unsigned int *)(a1 - 48);
  v6 = 0;
  LODWORD(result) = regmap_read(v1, v2, &v6);
  v4 = v6;
  _ReadStatusReg(SP_EL0);
  v5 = v4 >= 0;
  if ( (_DWORD)result )
    return (unsigned int)result;
  else
    return v5;
}
