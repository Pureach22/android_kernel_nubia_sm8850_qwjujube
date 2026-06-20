__int64 __fastcall wma_get_mcs_idx(
        unsigned __int16 a1,
        unsigned int a2,
        char a3,
        unsigned __int8 *a4,
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
  unsigned int v17; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x13
  __int64 v31; // x8
  unsigned __int16 *v32; // x12
  unsigned __int16 *v33; // x14
  unsigned int v34; // w24
  __int64 v35; // x17
  __int64 v36; // x11
  unsigned __int16 *v37; // x0
  unsigned __int16 *v38; // x1
  int v39; // w2
  int v40; // w2
  int v41; // w2
  int v42; // w2
  __int64 v43; // x8
  unsigned __int16 *v44; // x12
  unsigned __int16 *v45; // x13
  int v46; // w15
  int v47; // w15
  int v48; // w15
  int v49; // w15
  int v50; // w8
  int v51; // w8
  int v52; // w8
  __int64 v53; // x8
  unsigned __int16 *v54; // x10
  unsigned __int16 *v55; // x11
  int v56; // w13
  int v57; // w13
  int v58; // w9
  int v59; // w8
  unsigned int v60; // w9
  int v61; // w8
  __int64 v62; // x5
  unsigned int v63; // w6

  v17 = a1;
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
    a1,
    a2,
    a3 & 1,
    *a4);
  *a7 = a2;
  if ( (a2 & 0xF00) != 0 )
  {
    v30 = 14;
    v31 = 0;
    v32 = (unsigned __int16 *)&unk_A18412;
    if ( (a3 & 1) == 0 )
      v30 = 12;
    v33 = (unsigned __int16 *)&unk_A186CE;
    do
    {
      v34 = (unsigned __int8)v31;
      if ( (unsigned __int8)v31 > 4u )
        v35 = 1;
      else
        v35 = qword_A18BC0[v31 & 7];
      v36 = 0;
      v37 = v33;
      v38 = v32;
      do
      {
        if ( (a2 & 0x800) == 0 )
          goto LABEL_22;
        if ( v38[6] == v17 )
        {
          v39 = 0;
          goto LABEL_20;
        }
        if ( *a4 != 2 )
        {
          if ( v38[7] == v17 )
          {
LABEL_19:
            v39 = 1;
          }
          else
          {
            if ( v38[8] != v17 )
              goto LABEL_22;
LABEL_17:
            v39 = 2;
          }
LABEL_20:
          *a4 = 1;
          goto LABEL_21;
        }
        if ( v37[6] == v17 )
        {
          v39 = 0;
          goto LABEL_21;
        }
        if ( v38[7] == v17 )
          goto LABEL_19;
        if ( v37[7] == v17 )
        {
          v39 = 1;
        }
        else
        {
          if ( v38[8] == v17 )
            goto LABEL_17;
          if ( v37[8] != v17 )
            goto LABEL_22;
          v39 = 2;
        }
LABEL_21:
        if ( v17 )
        {
          if ( v39 == 2 )
            v59 = 3;
          else
            v59 = 0;
          if ( v39 == 1 )
            v59 = 2;
          *a6 = v59;
          goto LABEL_199;
        }
LABEL_22:
        if ( (a2 & 0xC00) == 0 )
          goto LABEL_35;
        if ( *v38 == v17 )
        {
          v40 = 0;
          goto LABEL_33;
        }
        if ( *a4 != 2 )
        {
          if ( v38[1] == v17 )
          {
LABEL_32:
            v40 = 1;
          }
          else
          {
            if ( v38[2] != v17 )
              goto LABEL_35;
LABEL_30:
            v40 = 2;
          }
LABEL_33:
          *a4 = 1;
          goto LABEL_34;
        }
        if ( *v37 == v17 )
        {
          v40 = 0;
          goto LABEL_34;
        }
        if ( v38[1] == v17 )
          goto LABEL_32;
        if ( v37[1] == v17 )
        {
          v40 = 1;
        }
        else
        {
          if ( v38[2] == v17 )
            goto LABEL_30;
          if ( v37[2] != v17 )
            goto LABEL_35;
          v40 = 2;
        }
LABEL_34:
        if ( v17 )
        {
          if ( v40 == 2 )
            v51 = 3;
          else
            v51 = 0;
          if ( v40 == 1 )
            v51 = 2;
          *a6 = v51;
          *a7 &= ~0x800u;
          goto LABEL_199;
        }
LABEL_35:
        if ( (a2 & 0xE00) == 0 )
          goto LABEL_48;
        if ( *(v38 - 6) == v17 )
        {
          v41 = 0;
          goto LABEL_46;
        }
        if ( *a4 != 2 )
        {
          if ( *(v38 - 5) == v17 )
          {
LABEL_45:
            v41 = 1;
          }
          else
          {
            if ( *(v38 - 4) != v17 )
              goto LABEL_48;
LABEL_43:
            v41 = 2;
          }
LABEL_46:
          *a4 = 1;
          goto LABEL_47;
        }
        if ( *(v37 - 6) == v17 )
        {
          v41 = 0;
          goto LABEL_47;
        }
        if ( *(v38 - 5) == v17 )
          goto LABEL_45;
        if ( *(v37 - 5) == v17 )
        {
          v41 = 1;
        }
        else
        {
          if ( *(v38 - 4) == v17 )
            goto LABEL_43;
          if ( *(v37 - 4) != v17 )
            goto LABEL_48;
          v41 = 2;
        }
LABEL_47:
        if ( v17 )
        {
          if ( v41 == 2 )
            v52 = 3;
          else
            v52 = 0;
          if ( v41 == 1 )
            v52 = 2;
          *a6 = v52;
          *a7 &= 0xFFFFF3FF;
          goto LABEL_199;
        }
LABEL_48:
        if ( *(v38 - 12) == v17 )
        {
          v42 = 0;
          goto LABEL_58;
        }
        if ( *a4 != 2 )
        {
          if ( *(v38 - 11) == v17 )
          {
LABEL_57:
            v42 = 1;
          }
          else
          {
            if ( *(v38 - 10) != v17 )
              goto LABEL_60;
LABEL_55:
            v42 = 2;
          }
LABEL_58:
          *a4 = 1;
          goto LABEL_59;
        }
        if ( *(v37 - 12) == v17 )
        {
          v42 = 0;
          goto LABEL_59;
        }
        if ( *(v38 - 11) == v17 )
          goto LABEL_57;
        if ( *(v37 - 11) == v17 )
        {
          v42 = 1;
        }
        else
        {
          if ( *(v38 - 10) == v17 )
            goto LABEL_55;
          if ( *(v37 - 10) != v17 )
            goto LABEL_60;
          v42 = 2;
        }
LABEL_59:
        if ( v17 )
        {
          if ( v42 == 2 )
            v50 = 3;
          else
            v50 = 0;
          if ( v42 == 1 )
            v50 = 2;
          *a6 = v50;
          *a7 &= 0x100u;
LABEL_199:
          if ( (unsigned __int8)v36 == 1 )
            *a5 = 1;
          v47 = *a6;
          goto LABEL_211;
        }
LABEL_60:
        ++v36;
        v38 += 3;
        v37 += 3;
      }
      while ( v35 != v36 );
      ++v31;
      v32 += 25;
      v33 += 25;
    }
    while ( v31 != v30 );
  }
  v43 = 0;
  v44 = (unsigned __int16 *)&unk_A18A50;
  v45 = (unsigned __int16 *)&unk_A18978;
  do
  {
    if ( (a2 & 0x1000) == 0 )
      goto LABEL_100;
    if ( v45[3] == v17 )
    {
      v47 = 0;
      goto LABEL_99;
    }
    if ( *a4 != 2 )
    {
      if ( v45[4] != v17 )
        goto LABEL_100;
LABEL_98:
      v47 = 1;
LABEL_99:
      *a4 = 1;
      if ( v17 )
        goto LABEL_143;
      goto LABEL_100;
    }
    if ( v44[3] == v17 )
    {
      v47 = 0;
      if ( v17 )
        goto LABEL_143;
      goto LABEL_100;
    }
    if ( v45[4] == v17 )
      goto LABEL_98;
    if ( v44[4] == v17 )
    {
      v47 = 1;
      if ( v17 )
      {
LABEL_143:
        v34 = (unsigned __int8)v43;
        *a6 = v47;
        goto LABEL_211;
      }
    }
LABEL_100:
    if ( (a2 & 0x1080) == 0 )
      goto LABEL_112;
    if ( v45[1] == v17 )
    {
      v48 = 0;
      goto LABEL_111;
    }
    if ( *a4 != 2 )
    {
      if ( v45[2] != v17 )
        goto LABEL_112;
LABEL_110:
      v48 = 1;
LABEL_111:
      *a4 = 1;
      if ( v17 )
        goto LABEL_202;
      goto LABEL_112;
    }
    if ( v44[1] == v17 )
    {
      v48 = 0;
      if ( v17 )
        goto LABEL_202;
      goto LABEL_112;
    }
    if ( v45[2] == v17 )
      goto LABEL_110;
    if ( v44[2] == v17 )
    {
      v48 = 1;
      if ( v17 )
      {
LABEL_202:
        *a6 = v48;
        v60 = *a7 & 0xFFFFEFFF;
LABEL_205:
        *a7 = v60;
        v34 = (unsigned __int8)v43;
        v47 = *a6;
        goto LABEL_211;
      }
    }
LABEL_112:
    if ( (a2 & 0x10C0) == 0 )
      goto LABEL_124;
    if ( *(v45 - 1) == v17 )
    {
      v49 = 0;
      goto LABEL_123;
    }
    if ( *a4 != 2 )
    {
      if ( *v45 != v17 )
        goto LABEL_124;
LABEL_122:
      v49 = 1;
LABEL_123:
      *a4 = 1;
      if ( v17 )
        goto LABEL_203;
      goto LABEL_124;
    }
    if ( *(v44 - 1) == v17 )
    {
      v49 = 0;
      if ( v17 )
        goto LABEL_203;
      goto LABEL_124;
    }
    if ( *v45 == v17 )
      goto LABEL_122;
    if ( *v44 == v17 )
    {
      v49 = 1;
      if ( v17 )
      {
LABEL_203:
        *a6 = v49;
        v60 = *a7 & 0xFFFFFF7F;
        goto LABEL_205;
      }
    }
LABEL_124:
    if ( (a2 & 0x10E0) == 0 )
      goto LABEL_87;
    if ( *(v45 - 3) == v17 )
    {
      v46 = 0;
      goto LABEL_85;
    }
    if ( *a4 != 2 )
    {
      if ( *(v45 - 2) != v17 )
        goto LABEL_87;
LABEL_132:
      v46 = 1;
LABEL_85:
      *a4 = 1;
      goto LABEL_86;
    }
    if ( *(v44 - 3) == v17 )
    {
      v46 = 0;
    }
    else
    {
      if ( *(v45 - 2) == v17 )
        goto LABEL_132;
      if ( *(v44 - 2) != v17 )
        goto LABEL_87;
      v46 = 1;
    }
LABEL_86:
    if ( v17 )
    {
      *a6 = v46;
      v60 = *a7 & 0xFFFFFF3F;
      goto LABEL_205;
    }
LABEL_87:
    ++v43;
    v44 += 9;
    v45 += 9;
  }
  while ( v43 != 12 );
  v53 = 0;
  v54 = (unsigned __int16 *)&unk_A18B28;
  v55 = (unsigned __int16 *)&unk_A18B78;
  while ( 1 )
  {
    if ( (a2 & 4) == 0 )
      goto LABEL_179;
    if ( *(v54 - 1) == v17 )
    {
      v57 = 0;
      goto LABEL_178;
    }
    if ( *a4 != 2 )
    {
      if ( *v54 != v17 )
        goto LABEL_179;
LABEL_177:
      v57 = 1;
LABEL_178:
      *a4 = 1;
      if ( v17 )
        goto LABEL_192;
      goto LABEL_179;
    }
    if ( *(v55 - 1) == v17 )
    {
      v57 = 0;
      if ( v17 )
        goto LABEL_192;
      goto LABEL_179;
    }
    if ( *v54 == v17 )
      goto LABEL_177;
    if ( *v55 == v17 )
    {
      v57 = 1;
      if ( v17 )
      {
LABEL_192:
        v58 = 4;
        *a6 = v57;
        goto LABEL_208;
      }
    }
LABEL_179:
    if ( (a2 & 6) == 0 )
      goto LABEL_166;
    if ( *(v54 - 3) == v17 )
    {
      v56 = 0;
      goto LABEL_164;
    }
    if ( *a4 != 2 )
    {
      if ( *(v54 - 2) != v17 )
        goto LABEL_166;
LABEL_187:
      v56 = 1;
LABEL_164:
      *a4 = 1;
      goto LABEL_165;
    }
    if ( *(v55 - 3) == v17 )
    {
      v56 = 0;
    }
    else
    {
      if ( *(v54 - 2) == v17 )
        goto LABEL_187;
      if ( *(v55 - 2) != v17 )
        goto LABEL_166;
      v56 = 1;
    }
LABEL_165:
    if ( v17 )
      break;
LABEL_166:
    ++v53;
    v54 += 5;
    v55 += 5;
    if ( v53 == 8 )
    {
      v61 = *a7;
      v17 = 0;
      v62 = 8;
      v34 = 255;
      goto LABEL_214;
    }
  }
  *a6 = v56;
  v58 = 2;
LABEL_208:
  *a7 = v58;
  v47 = *a6;
  if ( *a4 == 2 )
    v34 = (unsigned __int8)v53 | 8;
  else
    v34 = (unsigned __int8)v53;
LABEL_211:
  v61 = *a7;
  if ( v47 == 1 )
  {
    v63 = v61 | 8;
    v62 = v34;
  }
  else
  {
    v62 = v34;
LABEL_214:
    v63 = v61 & 0xFFFFFFF7;
  }
  *a7 = v63;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Matched rate in table: %d index: %d mcs_rate_flag: 0x%x nss %d guard interval %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wma_get_mcs_idx",
    v17,
    v62,
    *a6);
  return v34;
}
