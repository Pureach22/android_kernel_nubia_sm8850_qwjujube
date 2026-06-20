__int64 __fastcall drv_cmd_set_fast_transition(__int64 a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
{
  unsigned int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w20
  __int64 result; // x0
  unsigned __int8 v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 1;
  v5 = kstrtou8(a3 + a4 + 1, 10, v16);
  if ( (v5 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed range [%d - %d]",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_fast_transition",
      0,
      1);
    result = 4294967274LL;
  }
  else
  {
    v14 = v5;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received Command to change ft mode = %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_fast_transition",
      v16[0]);
    ucfg_mlme_set_fast_transition_enabled(*a2, v16[0] != 0);
    result = v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
