unsigned __int64 __fastcall clk_rcg_recalc_rate(__int64 a1, unsigned __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  unsigned int v6; // w21
  unsigned int v7; // w8
  __int64 v8; // x1
  __int64 v9; // x10
  __int64 v10; // x22
  unsigned __int64 v11; // x23
  bool v12; // w8
  unsigned int v14; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v15; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = *(unsigned int *)(a1 - 48);
  v16 = 0;
  v14 = 0;
  v15 = 0;
  regmap_read(v4, v5, &v16);
  v6 = (v16 >> *(_BYTE *)(a1 - 33)) & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 32));
  if ( *(_BYTE *)(a1 - 35) )
  {
    regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 44), &v15);
    v7 = v16;
    v8 = *(unsigned int *)(a1 + 32);
    v9 = -1LL << *(_BYTE *)(a1 - 35);
    v10 = (v15 >> *(_BYTE *)(a1 - 36)) & ~(_DWORD)v9;
    v11 = ((~v16 >> *(_BYTE *)(a1 - 37)) & ~(_DWORD)v9) + (unsigned int)v10;
    if ( (_DWORD)v8 != *(_DWORD *)(a1 - 48) )
    {
      regmap_read(*(_QWORD *)(a1 + 24), v8, &v14);
      v7 = v14;
    }
    v12 = ((v7 >> *(_BYTE *)(a1 - 38)) & 3) == 0;
    if ( v6 )
      goto LABEL_5;
  }
  else
  {
    v10 = 0;
    v11 = 0;
    v12 = 1;
    if ( v6 )
LABEL_5:
      a2 /= v6 + 1;
  }
  if ( !v12 )
    a2 = a2 * v10 / v11;
  _ReadStatusReg(SP_EL0);
  return a2;
}
