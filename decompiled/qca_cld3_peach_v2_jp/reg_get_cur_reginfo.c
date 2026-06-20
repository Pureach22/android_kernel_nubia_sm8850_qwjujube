__int64 __fastcall reg_get_cur_reginfo(__int64 a1, unsigned __int16 a2, unsigned __int16 a3)
{
  __int16 *v4; // x28
  unsigned int v5; // w26
  unsigned int v6; // w23
  unsigned __int8 *v7; // x22
  unsigned __int8 *v8; // x25
  unsigned int v9; // w24
  int v10; // w27
  __int16 *v12; // x19
  unsigned int v13; // w8
  unsigned int v14; // w8
  unsigned __int8 v15; // w28
  unsigned __int8 v16; // w25
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w9
  __int64 v29; // x8
  __int64 v30; // x9
  unsigned int v31; // w13
  char *v32; // x13
  __int64 v33; // x9
  unsigned int v34; // w13
  char *v35; // x13
  __int16 *v36; // x21
  unsigned int v37; // w24
  unsigned int v38; // w22
  unsigned __int8 *v39; // x26
  unsigned __int8 *v40; // x28
  unsigned int v41; // w27
  int v42; // w23
  __int64 v43; // x0
  __int64 result; // x0
  __int64 v45; // x9
  char *v46; // x21
  unsigned __int8 v47; // w25
  unsigned __int8 v48; // w26
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w9
  __int64 v61; // x8
  __int64 v62; // x9
  unsigned int v63; // w13
  char *v64; // x13
  __int64 v65; // x9
  unsigned int v66; // w13
  char *v67; // x13
  int v70; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v71; // [xsp+18h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 0xFFFF || a3 == 0xFFFF )
  {
    if ( a3 == 0xFFFF )
      goto LABEL_43;
    v36 = &g_reg_dmn_pairs_0[2 * a3];
    v37 = *((unsigned __int8 *)v36 + 3);
    v38 = *((unsigned __int8 *)v36 + 2);
    v39 = &regdomains_2g[24 * *((unsigned __int8 *)v36 + 3)];
    v40 = &regdomains_5g[24 * *((unsigned __int8 *)v36 + 2)];
    v41 = v39[13];
    v42 = v40[13];
    if ( v42 + v41 <= 0x14 )
    {
      qdf_mem_set((void *)(a1 + 18), 3u, 0);
      v43 = (unsigned __int16)*v36;
      *(_WORD *)(a1 + 16) = 0;
      v70 = 0;
      *(_WORD *)(a1 + 14) = v43;
      if ( (reg_is_world_ctry_code(v43) & 1) != 0 )
      {
        qdf_mem_copy((void *)(a1 + 18), "00", 3u);
      }
      else
      {
        reg_get_num_countries(&v70);
        if ( (_WORD)v70 )
        {
          v45 = 0;
          v46 = (char *)&unk_9E06EC;
          while ( *((unsigned __int16 *)v46 - 1) != *(unsigned __int16 *)(a1 + 14) )
          {
            ++v45;
            v46 += 14;
            if ( (unsigned __int16)v70 == v45 )
              goto LABEL_31;
          }
          if ( (unsigned __int16)v70 != (unsigned __int16)v45 )
          {
            qdf_mem_copy((void *)(a1 + 18), v46, 3u);
            *(_WORD *)(a1 + 16) = *((_WORD *)v46 - 2);
          }
        }
      }
LABEL_31:
      *(_DWORD *)(a1 + 24) = *((_DWORD *)v40 + 1);
      *(_DWORD *)(a1 + 28) = 0;
      *(_DWORD *)(a1 + 36) = *((unsigned __int16 *)v39 + 5);
      *(_DWORD *)(a1 + 44) = *((unsigned __int16 *)v40 + 5);
      *(_DWORD *)(a1 + 32) = *((unsigned __int16 *)v39 + 4);
      *(_DWORD *)(a1 + 40) = *((unsigned __int16 *)v40 + 4);
      v47 = v39[12];
      v48 = v40[12];
      *(_DWORD *)(a1 + 48) = v41;
      *(_DWORD *)(a1 + 52) = v42;
      v49 = _qdf_mem_malloc(14LL * v41, "reg_get_reginfo_from_regdmn_pair", 367);
      v50 = *(unsigned int *)(a1 + 52);
      *(_QWORD *)(a1 + 64) = v49;
      v51 = _qdf_mem_malloc(14 * v50, "reg_get_reginfo_from_regdmn_pair", 370);
      v60 = *(_DWORD *)(a1 + 48);
      v61 = *(_QWORD *)(a1 + 64);
      *(_QWORD *)(a1 + 72) = v51;
      if ( v60 )
      {
        v62 = 0;
        while ( v62 != 10 )
        {
          v63 = regdomains_2g[24 * v37 + 14 + v62++];
          v64 = (char *)&reg_rules_2g + 10 * v63;
          *(_DWORD *)v61 = *(_DWORD *)v64;
          *(_WORD *)(v61 + 4) = *((_WORD *)v64 + 2);
          *(_BYTE *)(v61 + 6) = v64[6];
          LOWORD(v64) = *((_WORD *)v64 + 4);
          *(_BYTE *)(v61 + 7) = v47;
          *(_WORD *)(v61 + 8) = (_WORD)v64;
          v61 += 14;
          if ( *(_DWORD *)(a1 + 48) <= (unsigned int)v62 )
            goto LABEL_35;
        }
      }
      else
      {
LABEL_35:
        if ( !*(_DWORD *)(a1 + 52) )
        {
LABEL_39:
          if ( v61 == *(_QWORD *)(a1 + 64) && v51 == *(_QWORD *)(a1 + 72) )
          {
            qdf_trace_msg(
              0x51u,
              2u,
              "%s: No rule for regdmn_pair = %d\n",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "reg_get_reginfo_from_regdmn_pair",
              a3);
            goto LABEL_43;
          }
LABEL_41:
          result = 0;
          goto LABEL_44;
        }
        v65 = 0;
        while ( v65 != 10 )
        {
          v66 = regdomains_5g[24 * v38 + 14 + v65++];
          v67 = (char *)&reg_rules_5g + 10 * v66;
          *(_DWORD *)v51 = *(_DWORD *)v67;
          *(_WORD *)(v51 + 4) = *((_WORD *)v67 + 2);
          *(_BYTE *)(v51 + 6) = v67[6];
          LOWORD(v67) = *((_WORD *)v67 + 4);
          *(_BYTE *)(v51 + 7) = v48;
          *(_WORD *)(v51 + 8) = (_WORD)v67;
          v51 += 14;
          if ( *(_DWORD *)(a1 + 52) <= (unsigned int)v65 )
            goto LABEL_39;
        }
      }
LABEL_45:
      __break(0x5512u);
    }
  }
  else
  {
    v4 = &g_reg_dmn_pairs_0[2 * a3];
    v5 = *((unsigned __int8 *)v4 + 3);
    v6 = *((unsigned __int8 *)v4 + 2);
    v7 = &regdomains_2g[24 * *((unsigned __int8 *)v4 + 3)];
    v8 = &regdomains_5g[24 * *((unsigned __int8 *)v4 + 2)];
    v9 = v7[13];
    v10 = v8[13];
    if ( v10 + v9 <= 0x14 )
    {
      v12 = &g_all_countries_0[7 * a2];
      qdf_mem_copy((void *)(a1 + 18), v12 + 2, 3u);
      *(_WORD *)(a1 + 16) = *v12;
      *(_WORD *)(a1 + 14) = *v4;
      *(_DWORD *)(a1 + 24) = *((_DWORD *)v8 + 1);
      *(_DWORD *)(a1 + 28) = (unsigned __int16)v12[6];
      v13 = (unsigned __int16)v12[4];
      if ( v13 >= *((unsigned __int16 *)v7 + 5) )
        v13 = *((unsigned __int16 *)v7 + 5);
      *(_DWORD *)(a1 + 36) = v13;
      v14 = (unsigned __int16)v12[5];
      if ( v14 >= *((unsigned __int16 *)v8 + 5) )
        v14 = *((unsigned __int16 *)v8 + 5);
      *(_DWORD *)(a1 + 44) = v14;
      *(_DWORD *)(a1 + 32) = *((unsigned __int16 *)v7 + 4);
      *(_DWORD *)(a1 + 40) = *((unsigned __int16 *)v8 + 4);
      v15 = v7[12];
      v16 = v8[12];
      *(_DWORD *)(a1 + 48) = v9;
      *(_DWORD *)(a1 + 52) = v10;
      v17 = _qdf_mem_malloc(14LL * v9, "reg_get_reginfo_from_country_code_and_regdmn_pair", 298);
      v18 = *(unsigned int *)(a1 + 52);
      *(_QWORD *)(a1 + 64) = v17;
      v19 = _qdf_mem_malloc(14 * v18, "reg_get_reginfo_from_country_code_and_regdmn_pair", 301);
      v28 = *(_DWORD *)(a1 + 48);
      v29 = *(_QWORD *)(a1 + 64);
      *(_QWORD *)(a1 + 72) = v19;
      if ( v28 )
      {
        v30 = 0;
        while ( v30 != 10 )
        {
          v31 = regdomains_2g[24 * v5 + 14 + v30++];
          v32 = (char *)&reg_rules_2g + 10 * v31;
          *(_DWORD *)v29 = *(_DWORD *)v32;
          *(_WORD *)(v29 + 4) = *((_WORD *)v32 + 2);
          *(_BYTE *)(v29 + 6) = v32[6];
          LOWORD(v32) = *((_WORD *)v32 + 4);
          *(_BYTE *)(v29 + 7) = v15;
          *(_WORD *)(v29 + 8) = (_WORD)v32;
          v29 += 14;
          if ( *(_DWORD *)(a1 + 48) <= (unsigned int)v30 )
            goto LABEL_12;
        }
        goto LABEL_45;
      }
LABEL_12:
      if ( *(_DWORD *)(a1 + 52) )
      {
        v33 = 0;
        while ( v33 != 10 )
        {
          v34 = regdomains_5g[24 * v6 + 14 + v33++];
          v35 = (char *)&reg_rules_5g + 10 * v34;
          *(_DWORD *)v19 = *(_DWORD *)v35;
          *(_WORD *)(v19 + 4) = *((_WORD *)v35 + 2);
          *(_BYTE *)(v19 + 6) = v35[6];
          LOWORD(v35) = *((_WORD *)v35 + 4);
          *(_BYTE *)(v19 + 7) = v16;
          *(_WORD *)(v19 + 8) = (_WORD)v35;
          v19 += 14;
          if ( *(_DWORD *)(a1 + 52) <= (unsigned int)v33 )
            goto LABEL_16;
        }
        goto LABEL_45;
      }
LABEL_16:
      if ( v29 == *(_QWORD *)(a1 + 64) && v19 == *(_QWORD *)(a1 + 72) )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: No rule for country index = %d regdmn_pair = %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "reg_get_reginfo_from_country_code_and_regdmn_pair",
          a2,
          a3);
LABEL_43:
        result = 16;
        goto LABEL_44;
      }
      goto LABEL_41;
    }
  }
  result = 2;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
