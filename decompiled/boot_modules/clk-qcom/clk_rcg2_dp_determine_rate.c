__int64 __fastcall clk_rcg2_dp_determine_rate(__int64 a1, __int64 a2)
{
  char v3; // w8
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_BYTE *)(a1 - 44);
  v4 = *(_QWORD *)(a2 + 32);
  v5 = *(_QWORD *)(a2 + 8);
  v7 = 0;
  v8[0] = 0;
  rational_best_approximation(v4, v5, 0xFFFFFFFFFFFFFFFFLL >> -v3, 0xFFFFFFFFFFFFFFFFLL >> -v3, &v7, v8);
  result = 4294967274LL;
  if ( v8[0] && v7 )
  {
    result = 0;
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a2 + 32) * v8[0] / (unsigned __int64)(unsigned int)v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
