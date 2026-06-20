unsigned __int64 __fastcall clk_dyn_rcg_recalc_rate(__int64 a1, unsigned __int64 a2)
{
  int v4; // w21
  int v5; // w24
  __int64 v6; // x0
  __int64 v7; // x1
  bool v8; // w23
  _BOOL8 v9; // x22
  __int64 v10; // x23
  unsigned int v11; // w13
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int64 v14; // x9
  unsigned int v15; // w10
  unsigned int v17; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v18; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v19; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a1 - 42);
  v5 = *(unsigned __int8 *)(a1 - 47);
  v6 = *(_QWORD *)(a1 + 24);
  v7 = *(unsigned int *)(a1 - 64);
  v19 = 0;
  v17 = 0;
  v18 = 0;
  regmap_read(v6, v7, &v17);
  v8 = 1;
  v9 = (v17 & (unsigned int)(1LL << *(_BYTE *)(a1 - 60))) != 0;
  regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 4 * v9 - 80), &v19);
  if ( !v5 )
  {
    v13 = 0;
    v14 = 0;
    if ( !v4 )
      goto LABEL_9;
    goto LABEL_7;
  }
  v10 = a1 - v9 + 8 * v9;
  regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 4 * v9 - 72), &v18);
  v11 = v17;
  if ( *(_DWORD *)(a1 - 80) != *(_DWORD *)(a1 - 76) )
    v11 = v19;
  v12 = -1LL << *(_BYTE *)(v10 - 54);
  v13 = (v18 >> *(_BYTE *)(v10 - 55)) & ~(_DWORD)v12;
  v14 = ((~v19 >> *(_BYTE *)(v10 - 56)) & ~(_DWORD)v12) + (unsigned int)v13;
  v8 = ((v11 >> *(_BYTE *)(v10 - 57)) & 3) == 0;
  if ( v4 )
  {
LABEL_7:
    v15 = (v19 >> *(_BYTE *)(a1 - 45 + 2 * v9)) & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 45 + 2 * v9 + 1));
    if ( v15 )
      a2 /= v15 + 1;
  }
LABEL_9:
  if ( !v8 )
    a2 = a2 * v13 / v14;
  _ReadStatusReg(SP_EL0);
  return a2;
}
