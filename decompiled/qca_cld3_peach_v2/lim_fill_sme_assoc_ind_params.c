_QWORD *__fastcall lim_fill_sme_assoc_ind_params(__int64 a1, unsigned __int8 *a2, __int64 a3, __int64 a4, char a5)
{
  size_t v8; // x0
  void *v9; // x0
  size_t v10; // x2
  size_t v11; // x2
  size_t v12; // x2
  int v13; // w8
  size_t v14; // x2
  _QWORD *result; // x0
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x12
  __int64 v19; // x11
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x9
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _BYTE *v31; // x8

  *(_WORD *)(a3 + 2) = 2960;
  *(_BYTE *)(a3 + 4) = *(_BYTE *)(a4 + 10);
  v8 = *((unsigned int *)a2 + 682);
  *(_DWORD *)(a3 + 2740) = v8;
  if ( (a5 & 1) != 0 && (_DWORD)v8 )
  {
    v9 = (void *)_qdf_mem_malloc(v8, "lim_fill_sme_assoc_ind_params", 790);
    *(_QWORD *)(a3 + 2744) = v9;
    qdf_mem_copy(v9, *((const void **)a2 + 342), *((unsigned int *)a2 + 682));
  }
  else
  {
    *(_QWORD *)(a3 + 2744) = *((_QWORD *)a2 + 342);
  }
  qdf_mem_copy((void *)(a3 + 5), a2, 6u);
  qdf_mem_copy((void *)(a3 + 2943), a2 + 2891, 6u);
  *(_WORD *)(a3 + 12) = *((_WORD *)a2 + 3);
  qdf_mem_copy((void *)(a3 + 14), (const void *)(a4 + 24), 6u);
  *(_DWORD *)(a3 + 24) = *((_DWORD *)a2 + 2);
  *(_DWORD *)(a3 + 28) = *((_DWORD *)a2 + 3);
  qdf_mem_copy((void *)(a3 + 32), a2 + 16, (unsigned int)a2[16] + 1);
  v10 = *((unsigned __int16 *)a2 + 25);
  *(_WORD *)(a3 + 326) = v10;
  qdf_mem_copy((void *)(a3 + 328), a2 + 52, v10);
  v11 = *((unsigned __int16 *)a2 + 155);
  *(_WORD *)(a3 + 66) = v11;
  qdf_mem_copy((void *)(a3 + 68), a2 + 312, v11);
  v12 = *((unsigned __int16 *)a2 + 285);
  *(_WORD *)(a3 + 586) = v12;
  qdf_mem_copy((void *)(a3 + 588), a2 + 572, v12);
  v13 = a2[2624];
  *(_BYTE *)(a3 + 2638) = v13;
  if ( v13 == 1 )
  {
    *(_BYTE *)(a3 + 2639) = a2[2625];
    *(_BYTE *)(a3 + 2640) = a2[2626];
    v14 = a2[2627];
    *(_BYTE *)(a3 + 2641) = v14;
    qdf_mem_copy((void *)(a3 + 2642), a2 + 2628, v14);
  }
  result = qdf_mem_copy((void *)(a3 + 2756), a2 + 2744, 0x28u);
  *(_BYTE *)(a3 + 2738) = a2[2725];
  *(_BYTE *)(a3 + 2796) = a2[2784];
  *(_BYTE *)(a3 + 2797) = a2[2785];
  *(_BYTE *)(a3 + 2798) = a2[2786];
  *(_BYTE *)(a3 + 2799) = a2[2787];
  *(_DWORD *)(a3 + 2800) = *((_DWORD *)a2 + 697);
  *(_DWORD *)(a3 + 2804) = *((_DWORD *)a2 + 698);
  *(_BYTE *)(a3 + 2808) = a2[2796];
  *(_BYTE *)(a3 + 2809) = a2[2797];
  *(_BYTE *)(a3 + 2810) = a2[2798];
  *(_BYTE *)(a3 + 2811) = a2[2799];
  *(_BYTE *)(a3 + 2812) = a2[2800];
  *(_BYTE *)(a3 + 2813) = a2[2801];
  *(_BYTE *)(a3 + 2814) = a2[2802];
  *(_DWORD *)(a3 + 2816) = *((_DWORD *)a2 + 701);
  *(_BYTE *)(a3 + 2820) = a2[2808];
  if ( a2[2812] )
  {
    v16 = *(_QWORD *)(a2 + 2828);
    v17 = *(_QWORD *)(a2 + 2812);
    v18 = *(_QWORD *)(a2 + 2820);
    *(_QWORD *)(a3 + 2848) = *(_QWORD *)(a2 + 2836);
    *(_QWORD *)(a3 + 2840) = v16;
    *(_QWORD *)(a3 + 2832) = v18;
    *(_QWORD *)(a3 + 2824) = v17;
    v19 = *(_QWORD *)(a2 + 2844);
    v20 = *(_QWORD *)(a2 + 2852);
    v21 = *(_QWORD *)(a2 + 2860);
    *(_DWORD *)(a3 + 2880) = *((_DWORD *)a2 + 717);
    *(_QWORD *)(a3 + 2856) = v19;
    *(_QWORD *)(a3 + 2872) = v21;
    *(_QWORD *)(a3 + 2864) = v20;
  }
  if ( a2[2872] )
  {
    v22 = *((_QWORD *)a2 + 360);
    *(_QWORD *)(a3 + 2884) = *((_QWORD *)a2 + 359);
    *(_QWORD *)(a3 + 2892) = v22;
  }
  *(_WORD *)(a3 + 2902) = *((_WORD *)a2 + 1311);
  *(_BYTE *)(a3 + 2900) = a2[2888];
  *(_BYTE *)(a3 + 2901) = a2[2889];
  *(_BYTE *)(a3 + 2904) = a2[2890];
  if ( !a2 || *(_DWORD *)(a4 + 88) != 1 )
  {
    v31 = *(_BYTE **)(a4 + 9976);
    if ( !v31 )
      return result;
    goto LABEL_17;
  }
  result = (_QWORD *)lim_search_pre_auth_list(*(_QWORD *)(a4 + 8608), a2);
  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x35u,
                       8u,
                       "%s: No preauth node created for %02x:%02x:%02x:**:**:%02x",
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       "lim_get_fils_info",
                       *a2,
                       a2[1],
                       a2[2],
                       a2[5]);
  v31 = (_BYTE *)result[76];
  if ( v31 )
LABEL_17:
    *(_BYTE *)(a3 + 2949) = *v31;
  return result;
}
