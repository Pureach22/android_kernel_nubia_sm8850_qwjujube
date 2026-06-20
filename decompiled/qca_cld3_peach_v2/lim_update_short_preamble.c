_WORD *__fastcall lim_update_short_preamble(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _WORD *result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x8
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x25
  __int64 v39; // x23
  __int64 v40; // x24
  __int64 v41; // x8
  _BYTE *v42; // x25
  _BYTE *v43; // x23
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x8
  __int16 v61; // w8
  __int64 v62; // x6
  __int64 v63; // x7
  int v64; // w8
  int v65; // w9
  __int16 v66; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v67; // [xsp+18h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  result = (_WORD *)dph_lookup_hash_entry(a5, a6, a7, a8, a9, a10, a11, a12, a1, a2, &v66, a4 + 360);
  v25 = (_DWORD *)(a4 + 7232);
  if ( !a4 )
    v25 = (_DWORD *)(a1 + 4840);
  if ( result && *v25 == 2 && (*result & 0x10) == 0 )
  {
    if ( a2 )
    {
      v26 = *a2;
      v27 = a2[1];
      v28 = a2[2];
      v29 = a2[5];
    }
    else
    {
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v29 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Short Preamble is not enabled in Assoc Req from %02x:%02x:%02x:**:**:%02x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_update_short_preamble",
      v26,
      v27,
      v28,
      v29);
    v38 = 0;
    v39 = a4 + 452;
    v40 = a1 + 4068;
    while ( 1 )
    {
      if ( *(_DWORD *)(a4 + 88) != 1 )
        goto LABEL_41;
      if ( *(_BYTE *)(a4 + v38 + 452) )
      {
        result = (_WORD *)qdf_mem_cmp((const void *)(a4 + v38 + 453), a2, 6u);
        if ( !(_DWORD)result )
          break;
        if ( *(_DWORD *)(a4 + 88) != 1 )
        {
LABEL_41:
          if ( *(_BYTE *)(a1 + v38 + 4068) )
          {
            result = (_WORD *)qdf_mem_cmp((const void *)(a1 + v38 + 4069), a2, 6u);
            if ( !(_DWORD)result )
              break;
          }
        }
      }
      v38 += 12;
      if ( v38 == 384 )
      {
        v41 = 0;
        while ( 1 )
        {
          while ( *(_DWORD *)(a4 + 88) == 1 )
          {
            if ( !*(_BYTE *)(v39 + 12 * v41) || !*(_BYTE *)(v40 + 12 * v41) )
            {
              v42 = (_BYTE *)(a4 + 448);
              goto LABEL_29;
            }
            if ( ++v41 == 32 )
              goto LABEL_34;
          }
          if ( !*(_BYTE *)(v40 + 12 * v41) )
            break;
          if ( ++v41 == 32 )
          {
LABEL_34:
            if ( a2 )
            {
              v62 = *a2;
              v63 = a2[1];
              v64 = a2[2];
              v65 = a2[5];
            }
            else
            {
              v64 = 0;
              v62 = 0;
              v63 = 0;
              v65 = 0;
            }
            result = (_WORD *)qdf_trace_msg(
                                0x35u,
                                2u,
                                "%s: No space in Short cache active: %d sta: %d for sta %02x:%02x:%02x:**:**:%02x",
                                v30,
                                v31,
                                v32,
                                v33,
                                v34,
                                v35,
                                v36,
                                v37,
                                "lim_update_short_preamble",
                                32,
                                *(unsigned __int8 *)(a4 + 448),
                                v62,
                                v63,
                                v64,
                                v65);
            goto LABEL_38;
          }
        }
        v42 = (_BYTE *)(a1 + 4064);
        v39 = a1 + 4068;
LABEL_29:
        v43 = (_BYTE *)(v39 + 12LL * (unsigned __int16)v41);
        qdf_mem_copy(v43 + 1, a2, 6u);
        *v43 = 1;
        ++*v42;
        result = (_WORD *)qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Disabling short preamble",
                            v44,
                            v45,
                            v46,
                            v47,
                            v48,
                            v49,
                            v50,
                            v51,
                            "lim_update_short_preamble");
        v60 = *(_QWORD *)(a1 + 8);
        if ( *(_BYTE *)(v60 + 1298) == 1
          && *(_BYTE *)(v60 + 5603) == 1
          && *(_DWORD *)(a4 + 88) == 1
          && *(_BYTE *)(a4 + 7160) == 1 )
        {
          result = (_WORD *)qdf_trace_msg(
                              0x35u,
                              8u,
                              "%s: ===> Short Preamble Disabled",
                              v52,
                              v53,
                              v54,
                              v55,
                              v56,
                              v57,
                              v58,
                              v59,
                              "lim_enable_short_preamble");
          *(_BYTE *)(a4 + 7160) = 0;
          v61 = *(_WORD *)(a3 + 14);
          *(_BYTE *)(a3 + 1) = 0;
          *(_WORD *)(a3 + 14) = v61 | 2;
        }
        break;
      }
    }
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
