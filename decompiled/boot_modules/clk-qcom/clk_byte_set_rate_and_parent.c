__int64 __fastcall clk_byte_set_rate_and_parent(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x8
  char v4; // w10
  __int64 *v5; // x9
  __int64 v6; // x0
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x12
  __int64 v10; // x9
  int v11; // w8
  __int64 result; // x0
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h]
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v3 = (a2 + 2 * a3 - 1) / a2;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)(a1 - 43);
  v5 = *(__int64 **)(a1 - 8);
  v6 = a1 - 48;
  v7 = -1LL << v4;
  v9 = *v5;
  v8 = v5[1];
  v10 = v5[2];
  v13 = v9;
  v14 = v8;
  v15 = v10;
  if ( (unsigned int)v7 <= -(int)v3 )
    v11 = -(int)v3;
  else
    LOBYTE(v11) = v7;
  BYTE1(v14) = ~(_BYTE)v11;
  result = clk_rcg2_configure(v6, &v13);
  _ReadStatusReg(SP_EL0);
  return result;
}
