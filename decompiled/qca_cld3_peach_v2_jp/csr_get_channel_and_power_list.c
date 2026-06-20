__int64 __fastcall csr_get_channel_and_power_list(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  int *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w8
  __int64 v21; // x9
  int v22; // t1
  __int64 result; // x0
  unsigned __int8 v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 21560);
  v11 = (int *)(a1 + 15332);
  v24[0] = 0;
  if ( (unsigned int)wlan_reg_get_channel_list_with_power_for_freq(v10, a1 + 15332, v24, a2, a3, a4, a5, a6, a7, a8, a9)
    || (v20 = v24[0]) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: failed to get channels",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "csr_get_channel_and_power_list");
    result = 16;
  }
  else
  {
    if ( v24[0] >= 0x65u )
    {
      v20 = 100;
      v24[0] = 100;
    }
    v21 = 0;
    do
    {
      if ( v21 == 400 )
        __break(0x5512u);
      v22 = *v11;
      v11 += 3;
      *(_DWORD *)(a1 + 16536 + v21) = v22;
      v21 += 4;
    }
    while ( 4LL * v20 != v21 );
    result = 0;
    *(_BYTE *)(a1 + 16532) = v20;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
