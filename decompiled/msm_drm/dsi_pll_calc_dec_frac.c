__int64 __fastcall dsi_pll_calc_dec_frac(__int64 result, __int64 a2)
{
  __int64 v2; // x9
  unsigned __int64 v3; // x10
  char v4; // w11
  int v5; // w8
  int v6; // w12
  unsigned __int64 v7; // x9
  int v8; // w10
  unsigned __int64 v9; // x8
  int v10; // w11

  v3 = *(_QWORD *)(a2 + 32);
  v2 = *(_QWORD *)(a2 + 40);
  v4 = *(_BYTE *)(result + 21);
  v5 = *(_DWORD *)(result + 28);
  if ( v3 <= 0x9B72EBF )
    goto LABEL_2;
  if ( v3 <= 0xA6E49BF )
  {
LABEL_4:
    v6 = 32;
    goto LABEL_5;
  }
  if ( v3 <= 0x135F1B3F )
    goto LABEL_2;
  if ( v3 <= 0x14DC937F )
    goto LABEL_4;
  if ( v3 <= 0x26BE367F )
    goto LABEL_2;
  if ( v3 <= 0x29B926FF )
    goto LABEL_4;
  if ( v3 <= 0x4D7C6CFF )
  {
LABEL_2:
    v6 = 160;
    goto LABEL_5;
  }
  if ( v3 <= 0x9502F8FF )
    goto LABEL_4;
  if ( v3 <= 0xEE6B27FF )
  {
    *(_DWORD *)(result + 80) = 0;
    goto LABEL_6;
  }
  v6 = 64;
LABEL_5:
  *(_DWORD *)(result + 80) = v6;
LABEL_6:
  v7 = v3 * (int)(1LL << v5) / (unsigned int)(v2 << (v4 ^ 1u));
  v8 = (1LL << v5) - 1;
  v9 = v7 >> v5;
  LODWORD(v7) = v7 & v8;
  v10 = BYTE1(v7);
  *(_DWORD *)(result + 64) = v9;
  *(_DWORD *)(result + 68) = (unsigned __int8)v7;
  LODWORD(v9) = WORD1(v7) & 3;
  LODWORD(v7) = *(_DWORD *)(result + 32);
  *(_DWORD *)(result + 72) = v10;
  *(_DWORD *)(result + 76) = v9;
  *(_DWORD *)(result + 56) = 10;
  *(_DWORD *)(result + 60) = v7;
  return result;
}
