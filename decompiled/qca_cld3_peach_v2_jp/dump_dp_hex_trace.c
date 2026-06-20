__int64 __fastcall dump_dp_hex_trace(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v5; // x25
  unsigned int v6; // w26
  char *v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  _QWORD v18[27]; // [xsp+8h] [xbp-D8h] BYREF

  v18[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v18, 0, 199);
  qdf_mem_set(v18, 0xC7u, 0);
  v5 = 0;
  v6 = 0;
  v7 = (char *)v18;
  do
  {
    v6 += scnprintf(v7, (int)(199 - v6), "%02x", *(unsigned __int8 *)(a2 + v5));
    if ( v6 >= 0xC8 )
LABEL_9:
      __break(0x5512u);
    v7 = (char *)v18 + v6;
    if ( v5 && __ROR8__(0xAAAAAAAAAAAAAAABLL * v5 - 0x2AAAAAAAAAAAAAABLL, 1) <= 0x2AAAAAAAAAAAAAAAuLL )
    {
      v6 += scnprintf(v7, 199 - v6, " ");
      if ( v6 > 0xC7 )
        goto LABEL_9;
      v7 = (char *)v18 + v6;
    }
    ++v5;
  }
  while ( a2 + v5 < a2 + (unsigned __int64)a3 );
  result = qdf_trace_msg(0x38u, 8u, "%s %s", v8, v9, v10, v11, v12, v13, v14, v15, a1, v18);
  _ReadStatusReg(SP_EL0);
  return result;
}
