__int64 __fastcall clk_rcg2_get_duty_cycle(__int64 a1, unsigned int *a2)
{
  int v3; // w8
  int v4; // w9
  __int64 v6; // x0
  int v7; // w8
  unsigned int v8; // w9
  __int64 v9; // x11
  int v11; // [xsp+Ch] [xbp-14h] BYREF
  int v12; // [xsp+10h] [xbp-10h] BYREF
  int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(a1 - 44) )
    goto LABEL_5;
  v3 = *(_DWORD *)(a1 - 48);
  v4 = *(unsigned __int8 *)(a1 + 144);
  v6 = *(_QWORD *)(a1 + 24);
  v13 = 0;
  v11 = 0;
  v12 = 0;
  regmap_read(v6, (unsigned int)(v3 + v4 + 16), &v11);
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(a1 + 144) + 8, &v12);
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(a1 + 144) + 12, &v13);
  if ( v11 || v12 || v13 )
  {
    v9 = -1LL << *(_BYTE *)(a1 - 44);
    v8 = ((~(_DWORD)v9 & (unsigned int)~v11) + 1) >> 1;
    v7 = (v12 + ~v13) & ~(_DWORD)v9;
  }
  else
  {
LABEL_5:
    v7 = 2;
    v8 = 1;
  }
  *a2 = v8;
  _ReadStatusReg(SP_EL0);
  a2[1] = v7;
  return 0;
}
