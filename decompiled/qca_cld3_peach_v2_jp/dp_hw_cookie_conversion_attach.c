__int64 __fastcall dp_hw_cookie_conversion_attach(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v13; // w24
  unsigned int v15; // w8
  __int64 v19; // x21
  __int64 v20; // x1
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w8
  _QWORD *v40; // x9
  __int64 v41; // x10
  __int64 *v42; // x8
  __int64 v43; // t1

  v13 = a3 + 511;
  v15 = (unsigned int)(a3 + 511) >> 9;
  if ( v15 >= 0x400 )
    v19 = 1024;
  else
    v19 = v15;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: num_spt_pages needed %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "dp_hw_cookie_conversion_attach",
    (unsigned int)v19);
  if ( a4 )
    v20 = 11;
  else
    v20 = 10;
  *(_DWORD *)(a2 + 72) = v20;
  dp_desc_multi_pages_mem_alloc(a1, v20, a2 + 16, 4096, (unsigned int)v19, 0, 0);
  if ( !*(_QWORD *)(a2 + 24) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: spt ddr pages allocation failed",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dp_hw_cookie_conversion_attach");
    return 1;
  }
  v29 = _qdf_mem_malloc((unsigned int)(24 * v19), "dp_hw_cookie_conversion_attach", 592);
  *(_QWORD *)(a2 + 8) = v29;
  if ( !v29 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: spt page descs allocation failed",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_hw_cookie_conversion_attach");
LABEL_14:
    dp_desc_multi_pages_mem_free(a1, *(unsigned int *)(a2 + 72), a2 + 16, 0, 0);
    return 16;
  }
  if ( a4 == 7 )
  {
    v38 = (a5 << 7) + 3072;
  }
  else if ( a4 )
  {
    v38 = 0;
  }
  else
  {
    v38 = a5 << 9;
  }
  *(_DWORD *)a2 = v38;
  if ( v13 >= 0x200 )
  {
    v40 = (_QWORD *)(v29 + 8);
    v41 = v19;
    v42 = (__int64 *)(*(_QWORD *)(a2 + 24) + 16LL);
    while ( (*v42 & 0xFFF) == 0 )
    {
      --v41;
      *(v40 - 1) = *(v42 - 2);
      v43 = *v42;
      v42 += 3;
      *v40 = v43;
      v40 += 3;
      if ( !v41 )
        goto LABEL_21;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: non-4k aligned pages addr %pK",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_hw_cookie_conversion_attach");
    _qdf_mem_free(*(_QWORD *)(a2 + 8));
    *(_QWORD *)(a2 + 8) = 0;
    goto LABEL_14;
  }
LABEL_21:
  *(_DWORD *)(a2 + 4) = v19;
  *(_DWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  return 0;
}
