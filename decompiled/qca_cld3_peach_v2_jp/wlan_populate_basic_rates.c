__int64 __fastcall wlan_populate_basic_rates(unsigned __int8 *a1, char a2, char a3)
{
  unsigned __int8 *v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v14; // x2
  __int64 v15; // x8
  unsigned __int8 *v16; // x9
  unsigned __int8 v17; // w12
  unsigned __int8 v18; // w11
  __int64 result; // x0
  int v20; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v5 = a1 + 1;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0x6C6048302418120CLL;
  v20 = 369820674;
  if ( (a2 & 1) == 0 )
  {
    *a1 = 4;
    qdf_mem_copy(a1 + 1, &v20, 4u);
    if ( (a3 & 1) == 0 )
    {
      v14 = "%s: Default CCK Rates";
      goto LABEL_8;
    }
    v16 = a1 + 2;
    v14 = "%s: Default CCK Rates";
    a1[1] |= 0x80u;
    v15 = 4;
    goto LABEL_6;
  }
  *a1 = 8;
  qdf_mem_copy(a1 + 1, v21, 8u);
  v14 = "%s: Default OFDM Rates";
  if ( (a3 & 1) != 0 )
  {
    v15 = 5;
    v16 = v5;
LABEL_6:
    v17 = a1[v15];
    v18 = a1[3] | 0x80;
    *v16 |= 0x80u;
    a1[3] = v18;
    a1[v15] = v17 | 0x80;
  }
LABEL_8:
  qdf_trace_msg(0x35u, 8u, v14, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_populate_basic_rates");
  result = ((__int64 (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(53, 8, v5, *a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
