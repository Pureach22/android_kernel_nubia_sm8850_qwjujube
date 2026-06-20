__int64 __fastcall reg_get_curr_regdomain(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x20
  __int64 psoc_obj; // x0
  int v14; // w10
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  void (__fastcall *v24)(__int64, __int64, __int64 *); // x8
  __int64 v25; // x1
  __int64 v26; // x21
  __int64 v27; // x9
  __int64 v28; // x20
  __int64 result; // x0
  unsigned __int16 v30; // w11
  __int16 *v31; // x8
  int v32; // w9
  unsigned __int8 *v33; // x10
  __int64 v34; // [xsp+0h] [xbp-10h] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 80);
  HIDWORD(v34) = 0;
  LOBYTE(v34) = 0;
  psoc_obj = reg_get_psoc_obj(v12, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !psoc_obj )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: soc reg component is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "reg_get_curr_regdomain");
    result = 4;
    goto LABEL_23;
  }
  if ( v12 )
  {
    v23 = *(_QWORD *)(v12 + 2128);
    if ( v23 )
    {
      v24 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v23 + 984);
      v25 = *(unsigned __int8 *)(a1 + 40);
      if ( v24 )
      {
        v26 = psoc_obj;
        if ( *((_DWORD *)v24 - 1) != 13449260 )
          __break(0x8228u);
        v24(v12, v25, &v34);
        LODWORD(v25) = (unsigned __int8)v34;
        psoc_obj = v26;
        if ( (unsigned __int8)v34 < 3u )
        {
LABEL_8:
          *a2 = *(_DWORD *)(psoc_obj + 30364LL * (unsigned int)v25 + 29616);
          reg_get_num_reg_dmn_pairs((_DWORD *)&v34 + 1);
          LODWORD(v24) = HIDWORD(v34);
          if ( SHIDWORD(v34) < 1 || (v14 = *a2, (unsigned __int16)g_reg_dmn_pairs_0[0] == v14) )
          {
            v27 = 0;
            if ( !HIDWORD(v34) )
            {
LABEL_11:
              v28 = jiffies;
              if ( reg_get_curr_regdomain___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x51u,
                  8u,
                  "%s: invalid regdomain",
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  "reg_get_curr_regdomain");
                reg_get_curr_regdomain___last_ticks = v28;
              }
              goto LABEL_14;
            }
LABEL_22:
            v31 = &g_reg_dmn_pairs_0[2 * v27];
            result = 0;
            v32 = *((unsigned __int8 *)v31 + 3);
            a2[1] = v32;
            LODWORD(v31) = *((unsigned __int8 *)v31 + 2);
            v33 = &regdomains_5g[24 * (unsigned int)v31];
            a2[2] = (unsigned __int16)v31;
            *((_BYTE *)a2 + 6) = regdomains_2g[24 * v32];
            *((_BYTE *)a2 + 7) = *v33;
            *((_BYTE *)a2 + 8) = *((_DWORD *)v33 + 1);
            goto LABEL_23;
          }
LABEL_18:
          v30 = 0;
          do
            v27 = ++v30;
          while ( (unsigned int)v24 > v30 && (unsigned __int16)g_reg_dmn_pairs_0[2 * v30] != v14 );
          if ( (_DWORD)v24 == v30 )
            goto LABEL_11;
          goto LABEL_22;
        }
      }
      else
      {
        LOBYTE(v34) = *(_BYTE *)(a1 + 40);
        if ( (unsigned int)v25 < 3 )
          goto LABEL_8;
      }
      __break(0x5512u);
      goto LABEL_18;
    }
  }
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: tx_ops is NULL",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "reg_get_psoc_tx_ops",
    v34,
    v35);
LABEL_14:
  result = 16;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
