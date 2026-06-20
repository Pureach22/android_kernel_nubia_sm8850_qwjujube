__int64 __fastcall hdd_add_associated_bw(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = hdd_convert_phy_bw_to_nl_bw(*(_DWORD *)(a2 + 1532));
  result = nla_put(a1, 42, 4, &v12);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to put associated bw",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_add_associated_bw");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
