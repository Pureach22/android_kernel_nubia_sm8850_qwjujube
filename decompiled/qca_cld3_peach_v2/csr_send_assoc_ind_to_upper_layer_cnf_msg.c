__int64 __fastcall csr_send_assoc_ind_to_upper_layer_cnf_msg(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 v8; // x0
  __int64 v9; // x21
  int v10; // w8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x12
  __int64 v21; // x13
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x12
  __int64 v25; // x11
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x9
  size_t v29; // x0
  void *v30; // x0
  size_t v31; // x2
  __int64 result; // x0
  char v33; // w8
  __int16 v34; // w9
  __int64 v35; // [xsp+8h] [xbp-38h] BYREF
  __int64 v36; // [xsp+10h] [xbp-30h]
  __int64 v37; // [xsp+18h] [xbp-28h]
  __int64 v38; // [xsp+20h] [xbp-20h]
  __int64 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v8 = _qdf_mem_malloc(0xAE0u, "csr_send_assoc_ind_to_upper_layer_cnf_msg", 3901);
  if ( v8 )
  {
    v9 = v8;
    *(_BYTE *)(v8 + 4) = a4;
    *(_DWORD *)v8 = 182457382;
    if ( a3 )
      v10 = 516;
    else
      v10 = 0;
    *(_DWORD *)(v8 + 8) = v10;
    qdf_mem_copy((void *)(v8 + 12), (const void *)(a2 + 14), 6u);
    qdf_mem_copy((void *)(v9 + 18), (const void *)(a2 + 5), 6u);
    qdf_mem_copy((void *)(v9 + 2769), (const void *)(a2 + 2943), 6u);
    *(_WORD *)(v9 + 24) = *(_WORD *)(a2 + 20);
    *(_BYTE *)(v9 + 26) = *(_BYTE *)(a2 + 2738);
    memcpy((void *)(v9 + 28), (const void *)(a2 + 326), 0x104u);
    memcpy((void *)(v9 + 288), (const void *)(a2 + 66), 0x104u);
    memcpy((void *)(v9 + 548), (const void *)(a2 + 586), 0x804u);
    *(_BYTE *)(v9 + 2600) = *(_BYTE *)(a2 + 2739);
    *(_BYTE *)(v9 + 2601) = *(_BYTE *)(a2 + 2752);
    v19 = *(_QWORD *)(a2 + 2788);
    v20 = *(_QWORD *)(a2 + 2764);
    v21 = *(_QWORD *)(a2 + 2772);
    *(_QWORD *)(v9 + 2628) = *(_QWORD *)(a2 + 2780);
    *(_QWORD *)(v9 + 2636) = v19;
    *(_QWORD *)(v9 + 2612) = v20;
    *(_QWORD *)(v9 + 2620) = v21;
    *(_QWORD *)(v9 + 2604) = *(_QWORD *)(a2 + 2756);
    *(_BYTE *)(v9 + 2645) = *(_BYTE *)(a2 + 2796);
    *(_BYTE *)(v9 + 2646) = *(_BYTE *)(a2 + 2797);
    *(_BYTE *)(v9 + 2647) = *(_BYTE *)(a2 + 2798);
    *(_DWORD *)(v9 + 2648) = *(_DWORD *)(a2 + 2800);
    *(_DWORD *)(v9 + 2652) = *(_DWORD *)(a2 + 2804);
    *(_BYTE *)(v9 + 2656) = *(_BYTE *)(a2 + 2799);
    *(_BYTE *)(v9 + 2657) = *(_BYTE *)(a2 + 2808);
    *(_BYTE *)(v9 + 2658) = *(_BYTE *)(a2 + 2809);
    *(_BYTE *)(v9 + 2659) = *(_BYTE *)(a2 + 2810);
    *(_BYTE *)(v9 + 2660) = *(_BYTE *)(a2 + 2811);
    *(_BYTE *)(v9 + 2661) = *(_BYTE *)(a2 + 2812);
    *(_BYTE *)(v9 + 2662) = *(_BYTE *)(a2 + 2813);
    *(_BYTE *)(v9 + 2663) = *(_BYTE *)(a2 + 2814);
    *(_DWORD *)(v9 + 2664) = *(_DWORD *)(a2 + 2816);
    *(_BYTE *)(v9 + 2668) = *(_BYTE *)(a2 + 2820);
    if ( *(_BYTE *)(a2 + 2824) )
    {
      v22 = *(_QWORD *)(a2 + 2840);
      v23 = *(_QWORD *)(a2 + 2824);
      v24 = *(_QWORD *)(a2 + 2832);
      *(_QWORD *)(v9 + 2712) = *(_QWORD *)(a2 + 2848);
      *(_QWORD *)(v9 + 2704) = v22;
      *(_QWORD *)(v9 + 2696) = v24;
      *(_QWORD *)(v9 + 2688) = v23;
      v25 = *(_QWORD *)(a2 + 2856);
      v26 = *(_QWORD *)(a2 + 2864);
      v27 = *(_QWORD *)(a2 + 2872);
      *(_DWORD *)(v9 + 2744) = *(_DWORD *)(a2 + 2880);
      *(_QWORD *)(v9 + 2720) = v25;
      *(_QWORD *)(v9 + 2736) = v27;
      *(_QWORD *)(v9 + 2728) = v26;
    }
    if ( *(_BYTE *)(a2 + 2884) )
    {
      v28 = *(_QWORD *)(a2 + 2892);
      *(_QWORD *)(v9 + 2748) = *(_QWORD *)(a2 + 2884);
      *(_QWORD *)(v9 + 2756) = v28;
    }
    *(_WORD *)(v9 + 2764) = *(_WORD *)(a2 + 2902);
    *(_BYTE *)(v9 + 2766) = *(_BYTE *)(a2 + 2900);
    *(_BYTE *)(v9 + 2767) = *(_BYTE *)(a2 + 2901);
    if ( *(_QWORD *)(a2 + 2744) )
    {
      v29 = *(unsigned int *)(a2 + 2740);
      if ( (unsigned int)v29 > 0x7CF )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Assoc Ie length is too long",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "csr_send_assoc_ind_to_upper_layer_cnf_msg");
      }
      else
      {
        v30 = (void *)_qdf_mem_malloc(v29, "csr_send_assoc_ind_to_upper_layer_cnf_msg", 3951);
        *(_QWORD *)(v9 + 2680) = v30;
        if ( !v30 )
        {
          _qdf_mem_free(v9);
          result = 2;
          goto LABEL_16;
        }
        v31 = *(unsigned int *)(a2 + 2740);
        *(_DWORD *)(v9 + 2672) = v31;
        qdf_mem_copy(v30, *(const void **)(a2 + 2744), v31);
      }
    }
    v33 = *(_BYTE *)(a2 + 2949);
    v36 = v9;
    *(_BYTE *)(v9 + 2768) = v33;
    *(_BYTE *)(v9 + 2775) = *(_BYTE *)(a2 + 2950);
    v34 = *(_WORD *)(a2 + 2952);
    LOWORD(v35) = 5158;
    *(_WORD *)(v9 + 2776) = v34;
    sys_process_mmh_msg(v11, v12, v13, v14, v15, v16, v17, v18, a1, (unsigned __int16 *)&v35);
    result = 0;
  }
  else
  {
    result = 2;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
