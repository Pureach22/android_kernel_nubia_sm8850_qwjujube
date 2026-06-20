unsigned __int64 __fastcall alpha_pll_huayra_recalc_rate(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  int v5; // w9
  unsigned __int64 v6; // x8
  unsigned __int64 result; // x0
  __int64 v8; // x8
  int v9; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v10; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v11; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 40);
  v11 = 0;
  v5 = *(_DWORD *)(a1 - 48);
  v9 = 0;
  v10 = 0;
  regmap_read(*(_QWORD *)(a1 + 24), v5 + (unsigned int)*(unsigned __int8 *)(v4 + 1), &v11);
  regmap_read(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
    &v9);
  if ( (v9 & 0x1000000) == 0 )
  {
    v6 = v11 * a2 + 999;
LABEL_5:
    result = 1000 * (v6 / 0x3E8);
    goto LABEL_6;
  }
  regmap_read(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
    &v10);
  if ( (v9 & 0x2000000) == 0 )
  {
    v6 = (v11 - ((v10 & 0xFFFF8000) != 0)) * a2 + (((unsigned __int64)v10 * a2) >> 16) + 999;
    goto LABEL_5;
  }
  v8 = v11 * a2;
  if ( BYTE1(v10) < 0x80u )
    result = (unsigned __int64)BYTE1(v10) * a2 / (unsigned __int8)v10 + v8;
  else
    result = v8 - (256 - (unsigned __int64)BYTE1(v10)) * a2 / (unsigned __int8)v10;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
