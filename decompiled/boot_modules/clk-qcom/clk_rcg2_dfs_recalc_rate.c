unsigned __int64 __fastcall clk_rcg2_dfs_recalc_rate(__int64 a1, unsigned __int64 a2)
{
  int v4; // w8
  __int64 v5; // x0
  __int64 v6; // x9
  unsigned __int64 v7; // x8
  unsigned __int64 result; // x0
  unsigned int v9; // w22
  int v10; // w21
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  int v17; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 - 48);
  v5 = *(_QWORD *)(a1 + 24);
  v18 = 0;
  v17 = 0;
  v16 = 0;
  regmap_read(v5, (unsigned int)(v4 + 20), &v18);
  v6 = *(_QWORD *)(a1 - 8);
  v7 = ((unsigned __int64)v18 >> 1) & 0xF;
  v18 = (v18 >> 1) & 0xF;
  if ( v6 )
  {
    result = *(_QWORD *)(v6 + 24LL * (unsigned int)v7);
  }
  else
  {
    regmap_read(*(_QWORD *)(a1 + 24), (unsigned int)(*(_DWORD *)(a1 - 48) + 4 * v7 + 28), &v17);
    if ( (v17 & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 43))) <= 1 )
      v9 = 1;
    else
      v9 = v17 & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 43));
    v10 = v17 & 0x3000;
    if ( (v17 & 0x3000) != 0 )
    {
      v11 = -1LL << *(_BYTE *)(a1 - 44);
      regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + 4 * v18 + 92, (char *)&v16 + 4);
      v12 = *(_QWORD *)(a1 + 24);
      v13 = *(_DWORD *)(a1 - 48) + 4 * v18 + 156;
      HIDWORD(v16) &= ~(_DWORD)v11;
      regmap_read(v12, v13, &v16);
      v14 = HIDWORD(v16);
      v15 = HIDWORD(v16) + (~(_DWORD)v16 & (unsigned int)~(_DWORD)v11);
    }
    else
    {
      v14 = 0;
      v15 = 0;
    }
    result = 2 * (a2 % (v9 + 1)) / (v9 + 1) + 2 * (a2 / (v9 + 1));
    if ( v10 )
      result = result % v15 * v14 / v15 + result / v15 * v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
