__int64 __fastcall wma_get_mcs_idx(
        unsigned int a1,
        unsigned int a2,
        char a3,
        _BYTE *a4,
        _BYTE *a5,
        int *a6,
        int *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  unsigned int v21; // w22
  __int64 v22; // x7
  __int16 matched; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x13
  __int64 v33; // x8
  unsigned __int16 *v34; // x12
  unsigned __int16 *v35; // x14
  __int64 v36; // x17
  __int64 v37; // x11
  unsigned __int16 *v38; // x0
  unsigned __int16 *v39; // x1
  int v40; // w2
  int v41; // w2
  int v42; // w2
  int v43; // w2
  __int64 v44; // x8
  unsigned __int16 *v45; // x12
  unsigned __int16 *v46; // x13
  int v47; // w15
  int v48; // w15
  int v49; // w15
  int v50; // w15
  int v51; // w9
  int v52; // w9
  int v53; // w9
  __int64 v54; // x8
  unsigned __int16 *v55; // x10
  unsigned __int16 *v56; // x11
  int v57; // w13
  int v58; // w13
  int v59; // w9
  int v60; // w9
  int v61; // w8
  int v62; // w23
  unsigned int v63; // w6
  int v65; // w9
  int v66; // w9
  int v67; // w9
  int v68; // w9
  unsigned __int8 v69[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+18h] [xbp-8h]

  v21 = a1;
  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = (unsigned __int8)*a4;
  v69[0] = 0;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Rates from FW:  raw_rate:%d rate_flgs: 0x%x is_he_mcs_12_13_supported: %d nss: %d",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "wma_get_mcs_idx",
    (unsigned __int16)a1,
    a2,
    a3 & 1,
    v22);
  *a7 = a2;
  matched = wma_match_eht_rate(v21, a2, a4, a5, a6, a7, v69);
  if ( matched )
    goto LABEL_204;
  if ( (a2 & 0xF00) != 0 )
  {
    v32 = 14;
    v33 = 0;
    v34 = (unsigned __int16 *)&unk_B0A58A;
    if ( (a3 & 1) == 0 )
      v32 = 12;
    v35 = (unsigned __int16 *)&unk_B0A846;
    do
    {
      if ( (unsigned __int8)v33 > 4u )
        v36 = 1;
      else
        v36 = qword_B0AD38[v33 & 7];
      v37 = 0;
      v38 = v35;
      v39 = v34;
      do
      {
        if ( (a2 & 0x800) == 0 )
          goto LABEL_23;
        if ( v39[6] == (unsigned __int16)v21 )
        {
          v40 = 0;
          goto LABEL_21;
        }
        if ( *a4 != 2 )
        {
          if ( v39[7] == (unsigned __int16)v21 )
          {
LABEL_20:
            v40 = 1;
          }
          else
          {
            if ( v39[8] != (unsigned __int16)v21 )
              goto LABEL_23;
LABEL_18:
            v40 = 2;
          }
LABEL_21:
          *a4 = 1;
          goto LABEL_22;
        }
        if ( v38[6] == (unsigned __int16)v21 )
        {
          v40 = 0;
          goto LABEL_22;
        }
        if ( v39[7] == (unsigned __int16)v21 )
          goto LABEL_20;
        if ( v38[7] == (unsigned __int16)v21 )
        {
          v40 = 1;
        }
        else
        {
          if ( v39[8] == (unsigned __int16)v21 )
            goto LABEL_18;
          if ( v38[8] != (unsigned __int16)v21 )
            goto LABEL_23;
          v40 = 2;
        }
LABEL_22:
        if ( (_WORD)v21 )
        {
          if ( v40 == 2 )
            v60 = 3;
          else
            v60 = 0;
          if ( v40 == 1 )
            v60 = 2;
          *a6 = v60;
          goto LABEL_200;
        }
LABEL_23:
        if ( (a2 & 0xC00) == 0 )
          goto LABEL_36;
        if ( *v39 == (unsigned __int16)v21 )
        {
          v41 = 0;
          goto LABEL_34;
        }
        if ( *a4 != 2 )
        {
          if ( v39[1] == (unsigned __int16)v21 )
          {
LABEL_33:
            v41 = 1;
          }
          else
          {
            if ( v39[2] != (unsigned __int16)v21 )
              goto LABEL_36;
LABEL_31:
            v41 = 2;
          }
LABEL_34:
          *a4 = 1;
          goto LABEL_35;
        }
        if ( *v38 == (unsigned __int16)v21 )
        {
          v41 = 0;
          goto LABEL_35;
        }
        if ( v39[1] == (unsigned __int16)v21 )
          goto LABEL_33;
        if ( v38[1] == (unsigned __int16)v21 )
        {
          v41 = 1;
        }
        else
        {
          if ( v39[2] == (unsigned __int16)v21 )
            goto LABEL_31;
          if ( v38[2] != (unsigned __int16)v21 )
            goto LABEL_36;
          v41 = 2;
        }
LABEL_35:
        if ( (_WORD)v21 )
        {
          if ( v41 == 2 )
            v52 = 3;
          else
            v52 = 0;
          if ( v41 == 1 )
            v52 = 2;
          *a6 = v52;
          *a7 &= ~0x800u;
          goto LABEL_200;
        }
LABEL_36:
        if ( (a2 & 0xE00) == 0 )
          goto LABEL_49;
        if ( *(v39 - 6) == (unsigned __int16)v21 )
        {
          v42 = 0;
          goto LABEL_47;
        }
        if ( *a4 != 2 )
        {
          if ( *(v39 - 5) == (unsigned __int16)v21 )
          {
LABEL_46:
            v42 = 1;
          }
          else
          {
            if ( *(v39 - 4) != (unsigned __int16)v21 )
              goto LABEL_49;
LABEL_44:
            v42 = 2;
          }
LABEL_47:
          *a4 = 1;
          goto LABEL_48;
        }
        if ( *(v38 - 6) == (unsigned __int16)v21 )
        {
          v42 = 0;
          goto LABEL_48;
        }
        if ( *(v39 - 5) == (unsigned __int16)v21 )
          goto LABEL_46;
        if ( *(v38 - 5) == (unsigned __int16)v21 )
        {
          v42 = 1;
        }
        else
        {
          if ( *(v39 - 4) == (unsigned __int16)v21 )
            goto LABEL_44;
          if ( *(v38 - 4) != (unsigned __int16)v21 )
            goto LABEL_49;
          v42 = 2;
        }
LABEL_48:
        if ( (_WORD)v21 )
        {
          if ( v42 == 2 )
            v53 = 3;
          else
            v53 = 0;
          if ( v42 == 1 )
            v53 = 2;
          *a6 = v53;
          *a7 &= 0xFFFFF3FF;
          goto LABEL_200;
        }
LABEL_49:
        if ( *(v39 - 12) == (unsigned __int16)v21 )
        {
          v43 = 0;
          goto LABEL_59;
        }
        if ( *a4 != 2 )
        {
          if ( *(v39 - 11) == (unsigned __int16)v21 )
          {
LABEL_58:
            v43 = 1;
          }
          else
          {
            if ( *(v39 - 10) != (unsigned __int16)v21 )
              goto LABEL_61;
LABEL_56:
            v43 = 2;
          }
LABEL_59:
          *a4 = 1;
          goto LABEL_60;
        }
        if ( *(v38 - 12) == (unsigned __int16)v21 )
        {
          v43 = 0;
          goto LABEL_60;
        }
        if ( *(v39 - 11) == (unsigned __int16)v21 )
          goto LABEL_58;
        if ( *(v38 - 11) == (unsigned __int16)v21 )
        {
          v43 = 1;
        }
        else
        {
          if ( *(v39 - 10) == (unsigned __int16)v21 )
            goto LABEL_56;
          if ( *(v38 - 10) != (unsigned __int16)v21 )
            goto LABEL_61;
          v43 = 2;
        }
LABEL_60:
        if ( (_WORD)v21 )
        {
          if ( v43 == 2 )
            v51 = 3;
          else
            v51 = 0;
          if ( v43 == 1 )
            v51 = 2;
          *a6 = v51;
          *a7 &= 0x100u;
LABEL_200:
          if ( (unsigned __int8)v37 == 1 )
            *a5 = 1;
          v69[0] = v33;
          goto LABEL_203;
        }
LABEL_61:
        ++v37;
        v39 += 3;
        v38 += 3;
      }
      while ( v36 != v37 );
      ++v33;
      v34 += 25;
      v35 += 25;
    }
    while ( v33 != v32 );
  }
  v44 = 0;
  v45 = (unsigned __int16 *)&unk_B0ABC8;
  v46 = (unsigned __int16 *)&unk_B0AAF0;
  do
  {
    if ( (a2 & 0x1000) == 0 )
      goto LABEL_101;
    if ( v46[3] == (unsigned __int16)v21 )
    {
      v48 = 0;
      goto LABEL_100;
    }
    if ( *a4 != 2 )
    {
      if ( v46[4] != (unsigned __int16)v21 )
        goto LABEL_101;
LABEL_99:
      v48 = 1;
LABEL_100:
      *a4 = 1;
      if ( (_WORD)v21 )
        goto LABEL_144;
      goto LABEL_101;
    }
    if ( v45[3] == (unsigned __int16)v21 )
    {
      v48 = 0;
      if ( (_WORD)v21 )
        goto LABEL_144;
      goto LABEL_101;
    }
    if ( v46[4] == (unsigned __int16)v21 )
      goto LABEL_99;
    if ( v45[4] == (unsigned __int16)v21 )
    {
      v48 = 1;
      if ( (_WORD)v21 )
      {
LABEL_144:
        v69[0] = v44;
        *a6 = v48;
        goto LABEL_205;
      }
    }
LABEL_101:
    if ( (a2 & 0x1080) == 0 )
      goto LABEL_113;
    if ( v46[1] == (unsigned __int16)v21 )
    {
      v49 = 0;
      goto LABEL_112;
    }
    if ( *a4 != 2 )
    {
      if ( v46[2] != (unsigned __int16)v21 )
        goto LABEL_113;
LABEL_111:
      v49 = 1;
LABEL_112:
      *a4 = 1;
      if ( (_WORD)v21 )
        goto LABEL_213;
      goto LABEL_113;
    }
    if ( v45[1] == (unsigned __int16)v21 )
    {
      v49 = 0;
      if ( (_WORD)v21 )
        goto LABEL_213;
      goto LABEL_113;
    }
    if ( v46[2] == (unsigned __int16)v21 )
      goto LABEL_111;
    if ( v45[2] == (unsigned __int16)v21 )
    {
      v49 = 1;
      if ( (_WORD)v21 )
      {
LABEL_213:
        *a6 = v49;
        v65 = *a7;
        v69[0] = v44;
        *a7 = v65 & 0xFFFFEFFF;
        goto LABEL_203;
      }
    }
LABEL_113:
    if ( (a2 & 0x10C0) == 0 )
      goto LABEL_125;
    if ( *(v46 - 1) == (unsigned __int16)v21 )
    {
      v50 = 0;
      goto LABEL_124;
    }
    if ( *a4 != 2 )
    {
      if ( *v46 != (unsigned __int16)v21 )
        goto LABEL_125;
LABEL_123:
      v50 = 1;
LABEL_124:
      *a4 = 1;
      if ( (_WORD)v21 )
        goto LABEL_214;
      goto LABEL_125;
    }
    if ( *(v45 - 1) == (unsigned __int16)v21 )
    {
      v50 = 0;
      if ( (_WORD)v21 )
        goto LABEL_214;
      goto LABEL_125;
    }
    if ( *v46 == (unsigned __int16)v21 )
      goto LABEL_123;
    if ( *v45 == (unsigned __int16)v21 )
    {
      v50 = 1;
      if ( (_WORD)v21 )
      {
LABEL_214:
        *a6 = v50;
        v66 = *a7;
        v69[0] = v44;
        *a7 = v66 & 0xFFFFFF7F;
        goto LABEL_203;
      }
    }
LABEL_125:
    if ( (a2 & 0x10E0) == 0 )
      goto LABEL_88;
    if ( *(v46 - 3) == (unsigned __int16)v21 )
    {
      v47 = 0;
      goto LABEL_86;
    }
    if ( *a4 != 2 )
    {
      if ( *(v46 - 2) != (unsigned __int16)v21 )
        goto LABEL_88;
LABEL_133:
      v47 = 1;
LABEL_86:
      *a4 = 1;
      goto LABEL_87;
    }
    if ( *(v45 - 3) == (unsigned __int16)v21 )
    {
      v47 = 0;
    }
    else
    {
      if ( *(v46 - 2) == (unsigned __int16)v21 )
        goto LABEL_133;
      if ( *(v45 - 2) != (unsigned __int16)v21 )
        goto LABEL_88;
      v47 = 1;
    }
LABEL_87:
    if ( (_WORD)v21 )
    {
      *a6 = v47;
      v67 = *a7;
      v69[0] = v44;
      *a7 = v67 & 0xFFFFFF3F;
      goto LABEL_203;
    }
LABEL_88:
    ++v44;
    v45 += 9;
    v46 += 9;
  }
  while ( v44 != 12 );
  v54 = 0;
  v55 = (unsigned __int16 *)&unk_B0ACA0;
  v56 = (unsigned __int16 *)&unk_B0ACF0;
  while ( 1 )
  {
    if ( (a2 & 4) == 0 )
      goto LABEL_180;
    if ( *(v55 - 1) == (unsigned __int16)v21 )
    {
      v58 = 0;
      goto LABEL_179;
    }
    if ( *a4 != 2 )
    {
      if ( *v55 != (unsigned __int16)v21 )
        goto LABEL_180;
LABEL_178:
      v58 = 1;
LABEL_179:
      *a4 = 1;
      if ( (_WORD)v21 )
        goto LABEL_193;
      goto LABEL_180;
    }
    if ( *(v56 - 1) == (unsigned __int16)v21 )
    {
      v58 = 0;
      if ( (_WORD)v21 )
        goto LABEL_193;
      goto LABEL_180;
    }
    if ( *v55 == (unsigned __int16)v21 )
      goto LABEL_178;
    if ( *v56 == (unsigned __int16)v21 )
    {
      v58 = 1;
      if ( (_WORD)v21 )
      {
LABEL_193:
        *a6 = v58;
        v59 = 4;
        goto LABEL_218;
      }
    }
LABEL_180:
    if ( (a2 & 6) == 0 )
      goto LABEL_167;
    if ( *(v55 - 3) == (unsigned __int16)v21 )
    {
      v57 = 0;
      goto LABEL_165;
    }
    if ( *a4 != 2 )
    {
      if ( *(v55 - 2) != (unsigned __int16)v21 )
        goto LABEL_167;
LABEL_188:
      v57 = 1;
LABEL_165:
      *a4 = 1;
      goto LABEL_166;
    }
    if ( *(v56 - 3) == (unsigned __int16)v21 )
    {
      v57 = 0;
    }
    else
    {
      if ( *(v55 - 2) == (unsigned __int16)v21 )
        goto LABEL_188;
      if ( *(v56 - 2) != (unsigned __int16)v21 )
        goto LABEL_167;
      v57 = 1;
    }
LABEL_166:
    if ( (_WORD)v21 )
      break;
LABEL_167:
    ++v54;
    v55 += 5;
    v56 += 5;
    if ( v54 == 8 )
    {
      v61 = *a7;
      LOWORD(v21) = 0;
      v62 = 1;
      v69[0] = 8;
      goto LABEL_208;
    }
  }
  v59 = 2;
  *a6 = v57;
LABEL_218:
  *a7 = v59;
  v68 = (unsigned __int8)*a4;
  v69[0] = v54;
  if ( v68 == 2 )
    v69[0] = v54 | 8;
LABEL_203:
  matched = v21;
LABEL_204:
  v48 = *a6;
  LOWORD(v21) = matched;
LABEL_205:
  v61 = *a7;
  if ( v48 == 1 )
  {
    v62 = 0;
    v63 = v61 | 8;
  }
  else
  {
    v62 = 0;
LABEL_208:
    v63 = v61 & 0xFFFFFFF7;
  }
  *a7 = v63;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Matched rate in table: %d index: %d mcs_rate_flag: 0x%x nss %d guard interval %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wma_get_mcs_idx",
    (unsigned __int16)v21,
    v69[0],
    *a6);
  _ReadStatusReg(SP_EL0);
  if ( v62 )
    return 0xFFFFFFFFLL;
  else
    return v69[0];
}
