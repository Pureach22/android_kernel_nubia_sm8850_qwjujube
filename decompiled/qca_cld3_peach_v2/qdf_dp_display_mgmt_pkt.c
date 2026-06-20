__int64 __fastcall qdf_dp_display_mgmt_pkt(unsigned __int8 *a1, unsigned __int16 a2, __int64 a3, unsigned int a4)
{
  unsigned __int64 v7; // x8
  unsigned int v8; // w20
  const char *v9; // x21
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  _QWORD v20[12]; // [xsp+0h] [xbp-70h] BYREF
  int v21; // [xsp+60h] [xbp-10h]
  __int64 v22; // [xsp+68h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  memset(v20, 0, sizeof(v20));
  qdf_mem_set(v20, 0x64u, 0);
  qdf_dp_trace_fill_meta_str(v20, 100, a2, a4, a1);
  v7 = a1[10];
  v8 = a1[9];
  if ( v7 > 6 )
    v9 = "invalid";
  else
    v9 = off_AD0470[v7];
  v10 = qdf_dp_subtype_to_str(a1[11]);
  result = qdf_trace_msg(0x38u, 8u, "%s [%d] [%s %s]", v11, v12, v13, v14, v15, v16, v17, v18, v20, v8, v9, v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
