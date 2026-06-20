__int64 __fastcall reg_init_pdev_mas_chan_list(_BYTE *a1, __int64 a2)
{
  _BYTE *v4; // x21
  __int64 v5; // x22
  int v6; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 result; // x0
  const char *v18; // x2
  unsigned int v19; // w1
  _BYTE v20[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v4 = a1 + 56700;
  v5 = a2 + 28672;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_mem_copy(a1 + 7344, (const void *)(a2 + 8), 0xE58u);
  qdf_mem_copy(a1 + 11020, (const void *)(a2 + 3684), 0x870u);
  qdf_mem_copy(a1 + 19660, (const void *)(a2 + 12324), 0x870u);
  qdf_mem_copy(a1 + 21820, (const void *)(a2 + 14484), 0x870u);
  qdf_mem_copy(a1 + 13180, (const void *)(a2 + 5844), 0x870u);
  qdf_mem_copy(a1 + 23980, (const void *)(a2 + 16644), 0x870u);
  qdf_mem_copy(a1 + 26140, (const void *)(a2 + 18804), 0x870u);
  qdf_mem_copy(a1 + 15340, (const void *)(a2 + 8004), 0x870u);
  qdf_mem_copy(a1 + 28300, (const void *)(a2 + 20964), 0x870u);
  qdf_mem_copy(a1 + 30460, (const void *)(a2 + 23124), 0x870u);
  qdf_mem_copy(a1 + 17500, (const void *)(a2 + 10164), 0x870u);
  qdf_mem_copy(a1 + 32620, (const void *)(a2 + 25284), 0x870u);
  qdf_mem_copy(a1 + 34780, (const void *)(a2 + 27444), 0x870u);
  v6 = *(_DWORD *)(v5 + 1676);
  *((_DWORD *)v4 + 377) = v6;
  *((_DWORD *)v4 + 378) = v6;
  v4[1516] = *(_BYTE *)(v5 + 1680);
  v4[1517] = *(_BYTE *)(v5 + 1681);
  a1[11016] = *(_BYTE *)(a2 + 3680);
  *((_WORD *)v4 + 5) = *(_WORD *)(v5 + 948);
  *((_DWORD *)v4 + 380) = *(_DWORD *)(v5 + 1684);
  *((_DWORD *)v4 + 4) = *(_DWORD *)a2;
  *((_DWORD *)v4 + 5) = *(_DWORD *)(a2 + 4);
  *((_WORD *)v4 + 4) = *(_DWORD *)(v5 + 944);
  *((_WORD *)v4 + 6) = *(_WORD *)(v5 + 950);
  *(_WORD *)v4 = *(_DWORD *)(v5 + 944);
  *((_WORD *)v4 + 1) = *(_WORD *)(v5 + 950);
  qdf_mem_copy(a1 + 56697, (const void *)(a2 + 29604), 3u);
  qdf_mem_copy(a1 + 56704, (const void *)(a2 + 29607), 3u);
  v15 = *(_QWORD *)(v4 + 28);
  v20[0] = 0;
  v16 = *(_QWORD *)(v15 + 80);
  if ( !v16 )
  {
    v18 = "%s: psoc is NULL";
    v19 = 2;
LABEL_6:
    result = qdf_trace_msg(
               0x51u,
               v19,
               v18,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "reg_fill_c2c_supp_in_pdev_mas_chan_list");
    goto LABEL_7;
  }
  result = wlan_mlme_get_c2c_support(v16, v20);
  if ( (v20[0] & 1) == 0 )
  {
    v18 = "%s: C2C support is disabled";
    v19 = 8;
    goto LABEL_6;
  }
  v4[2309] = *(_BYTE *)(v5 + 1688);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
