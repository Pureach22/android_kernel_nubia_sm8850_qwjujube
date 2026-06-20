__int64 __fastcall extract_roam_trigger_stats_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned __int8 a12,
        unsigned int a13)
{
  __int64 v17; // x8
  __int64 v18; // x12
  __int64 v19; // x11
  bool v20; // zf
  __int64 v21; // x8
  __int64 v22; // x10
  _DWORD *v23; // x11
  _DWORD *v24; // x8
  int v25; // w12
  __int64 v26; // x15
  _DWORD *v27; // x16
  int v28; // w13
  int v29; // w14
  char v30; // w13
  __int64 result; // x0
  int v32; // w14
  int v33; // w14
  int v34; // w14
  __int64 v35; // x15
  __int64 v36; // x14
  _DWORD *v37; // x13
  __int64 v38; // x14
  int v39; // w15
  int v40; // w14
  int v41; // w14
  __int64 v42; // x8
  _DWORD *v43; // x8
  __int64 v44; // x8
  __int64 v45; // x8
  int v46; // w8
  int v47; // w8
  __int64 v48; // x8
  __int64 v49; // x8
  int v50; // w8
  int v51; // w9
  __int64 v52; // t2
  __int64 v53; // x11
  _DWORD *v54; // x9
  int v55; // w8
  __int64 v56; // x10
  __int64 v57; // x9
  __int64 v58; // x10
  __int64 v59; // x9
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 v62; // x8
  __int64 v63; // x8
  unsigned int v64; // w9
  int v65; // w9
  __int64 v66; // x8
  __int64 v67; // x8
  __int64 v68; // x10
  int v69; // w8
  int v70; // w9
  int v71; // w10

  if ( !a10 )
  {
    qdf_trace_msg(0x31u, 2u, "%s: Param buf is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_trigger_stats_tlv");
    return 16;
  }
  if ( !*(_QWORD *)(a10 + 80) || *(_DWORD *)(a10 + 88) <= (unsigned int)a12 )
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: roam_result or idx error.%u",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_trigger_stats_tlv",
      a12);
  if ( !*(_QWORD *)(a10 + 32) || *(_DWORD *)(a10 + 40) <= (unsigned int)a12 )
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: roam_scan_info or idx error.%u",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_trigger_stats_tlv",
      a12);
  *(_BYTE *)a11 = 1;
  v17 = *(_QWORD *)(a10 + 32);
  v18 = *(_QWORD *)(a10 + 208);
  v19 = v17 + 32LL * a12;
  v20 = v17 == 0;
  v21 = *(_QWORD *)(a10 + 16);
  if ( v20 )
    v22 = 0;
  else
    v22 = v19;
  if ( v18 )
    v23 = (_DWORD *)(v18 + 20LL * a12);
  else
    v23 = nullptr;
  if ( v21 )
    v24 = (_DWORD *)(v21 + 124LL * a12);
  else
    v24 = nullptr;
  if ( v23 )
  {
    v25 = v23[2];
    v26 = 8;
    v27 = v23;
    if ( (unsigned int)(v25 - 1) >= 0x14 )
      v28 = 0;
    else
      v28 = v23[2];
    *(_DWORD *)(a11 + 4) = v28;
    if ( (unsigned int)(v23[3] - 1) >= 0xA )
      v29 = 0;
    else
      v29 = v23[3];
    v30 = 1;
LABEL_34:
    *(_DWORD *)(a11 + v26) = v29;
    v34 = v27[1];
    *(_BYTE *)(a11 + 1) = v30;
    *(_DWORD *)(a11 + 16) = v34;
    goto LABEL_35;
  }
  if ( v24 )
  {
    v25 = v24[2];
    v30 = 0;
    v27 = v24;
    if ( (unsigned int)(v25 - 1) >= 0x14 )
      v32 = 0;
    else
      v32 = v24[2];
    *(_DWORD *)(a11 + 4) = v32;
    v33 = v24[3];
    v26 = 12;
    if ( (unsigned int)(v33 - 1) >= 0xA )
      v33 = 0;
    *(_DWORD *)(a11 + 8) = v33;
    v29 = v24[4];
    goto LABEL_34;
  }
  v25 = 0;
LABEL_35:
  v35 = *(_QWORD *)(a10 + 224);
  v36 = *(_QWORD *)(a10 + 80);
  v37 = (_DWORD *)(v35 + 20LL * a12);
  if ( !v35 )
    v37 = nullptr;
  if ( !v36 )
    goto LABEL_48;
  v38 = v36 + 28LL * a12;
  if ( !v38 )
    goto LABEL_48;
  v39 = *(_DWORD *)(v38 + 8);
  *(_DWORD *)(a11 + 200) = v39;
  if ( !v39 )
    goto LABEL_48;
  if ( (unsigned int)*(unsigned __int16 *)(v38 + 12) - 1 > 0x26 )
  {
    *(_DWORD *)(a11 + 204) = 255;
    if ( !v37 )
      goto LABEL_48;
LABEL_45:
    v40 = *(_DWORD *)(v38 + 24);
    if ( (unsigned int)(v40 - 1) >= 4 )
      v40 = 0;
    *(_DWORD *)(a11 + 188) = v40;
    *(_BYTE *)(a11 + 192) = v37[2];
    *(_BYTE *)(a11 + 193) = v37[3];
    *(_BYTE *)(a11 + 194) = v37[4];
    goto LABEL_48;
  }
  *(_DWORD *)(a11 + 204) = dword_9E7024[(unsigned __int16)(*(_WORD *)(v38 + 12) - 1)];
  if ( v37 )
    goto LABEL_45;
LABEL_48:
  if ( v22 )
  {
    v41 = *(_DWORD *)(v22 + 4);
    if ( (unsigned int)(v41 - 1) >= 4 )
      v41 = 0;
    *(_DWORD *)(a11 + 196) = v41;
  }
  result = 0;
  switch ( v25 )
  {
    case 1:
      v60 = *(_QWORD *)(a10 + 352);
      result = 0;
      if ( v60 )
      {
        v61 = v60 + 8LL * a12;
        if ( v61 )
        {
          *(_BYTE *)(a11 + 21) = *(_WORD *)(v61 + 6);
          *(_BYTE *)(a11 + 20) = *(_DWORD *)(v61 + 4);
          return 0;
        }
      }
      return result;
    case 2:
      v62 = *(_QWORD *)(a10 + 288);
      result = 0;
      if ( v62 )
      {
        v63 = v62 + 8LL * a12;
        if ( v63 )
        {
          *(_DWORD *)(a11 + 20) = *(_DWORD *)(v63 + 4) & 0x7F;
          *(_DWORD *)(a11 + 24) = (*(_DWORD *)(v63 + 4) >> 7) & 0x1FFFF;
          *(_BYTE *)(a11 + 28) = *(_BYTE *)(v63 + 7) & 1;
          return 0;
        }
      }
      return result;
    case 3:
      if ( !v23 || !v37 )
        goto LABEL_103;
      *(_BYTE *)(a11 + 20) = v23[4];
      *(_BYTE *)(a11 + 21) = v37[1];
      *(_BYTE *)(a11 + 22) = v37[4];
      return 0;
    case 4:
      v66 = *(_QWORD *)(a10 + 384);
      result = 0;
      if ( v66 )
        v67 = v66 + 8LL * a12;
      else
        v67 = 0;
      if ( v23 && v67 )
      {
        *(_BYTE *)(a11 + 20) = v23[4];
        *(_BYTE *)(a11 + 21) = *(_DWORD *)(v67 + 4);
        return 0;
      }
      return result;
    case 5:
      v68 = *(_QWORD *)(a10 + 368);
      if ( v68 )
      {
        v59 = v68 + 8LL * a12;
        if ( v59 )
          goto LABEL_102;
      }
LABEL_103:
      if ( !v24 )
        return 0;
      v69 = v24[5];
      goto LABEL_105;
    case 6:
    case 7:
      v42 = *(_QWORD *)(a10 + 304);
      result = 0;
      if ( v42 )
      {
        v43 = (_DWORD *)(v42 + 16LL * a12);
        if ( v43 )
        {
          *(_DWORD *)(a11 + 20) = v43[1];
          *(_DWORD *)(a11 + 24) = v43[2];
          *(_BYTE *)(a11 + 28) = v43[3];
          return 0;
        }
      }
      return result;
    case 8:
      result = 0;
      if ( v23 && v37 )
      {
        *(_BYTE *)(a11 + 20) = v23[4];
        *(_BYTE *)(a11 + 21) = v37[2];
        *(_BYTE *)(a11 + 22) = v37[3];
        return 0;
      }
      return result;
    case 9:
    case 14:
      v44 = *(_QWORD *)(a10 + 320);
      result = 0;
      if ( v44 )
      {
        v45 = v44 + 8LL * a12;
        if ( v45 )
        {
          v46 = *(_DWORD *)(v45 + 4);
          result = 0;
          if ( v46 == 2 )
            v47 = 2;
          else
            v47 = v46 == 1;
          *(_DWORD *)(a11 + 20) = v47;
        }
      }
      return result;
    case 10:
      v53 = *(_QWORD *)(a10 + 272);
      if ( !v53 || (v54 = (_DWORD *)(v53 + 36LL * a12)) == nullptr )
      {
        if ( v24 )
        {
          *(_DWORD *)(a11 + 24) = v24[9];
          *(_DWORD *)(a11 + 28) = v24[10];
          *(_DWORD *)(a11 + 32) = v24[11];
          v70 = v24[12];
          *(_DWORD *)(a11 + 36) = v70;
          *(_DWORD *)(a11 + 40) = v24[13];
          *(_DWORD *)(a11 + 44) = v24[21];
          *(_DWORD *)(a11 + 48) = v24[22];
          *(_WORD *)(a11 + 52) = v24[27];
          if ( v22 )
          {
            v71 = (*(_DWORD *)(v22 + 28) >> 1) & 7;
            *(_BYTE *)(a11 + 185) = v71;
            if ( v71 )
              *(_BYTE *)(a11 + 184) = 1;
          }
          if ( v70 + (unsigned int)(unsigned __int8)a13 <= *(_DWORD *)(a10 + 200) )
          {
            extract_roam_11kv_candidate_info(a10, a11 + 56, a13, (unsigned int)v24[12]);
            return 0;
          }
        }
        return 0;
      }
      *(_DWORD *)(a11 + 24) = v54[1];
      *(_DWORD *)(a11 + 28) = v54[2];
      *(_DWORD *)(a11 + 32) = v54[3];
      *(_DWORD *)(a11 + 36) = v54[4];
      *(_DWORD *)(a11 + 40) = v54[5];
      *(_DWORD *)(a11 + 44) = v54[6];
      *(_DWORD *)(a11 + 48) = v54[7];
      *(_WORD *)(a11 + 52) = v54[8];
      if ( !v22 )
        return 0;
      result = 0;
      v55 = (*(_DWORD *)(v22 + 28) >> 1) & 7;
      *(_BYTE *)(a11 + 185) = (*(_DWORD *)(v22 + 28) >> 1) & 7;
      if ( v55 )
        *(_BYTE *)(a11 + 184) = 1;
      return result;
    case 12:
      v58 = *(_QWORD *)(a10 + 240);
      if ( v58 && (v59 = v58 + 8LL * a12) != 0 )
      {
LABEL_102:
        v69 = *(_DWORD *)(v59 + 4);
LABEL_105:
        *(_DWORD *)(a11 + 20) = v69;
        return 0;
      }
      else
      {
        result = 0;
        if ( v24 )
          *(_DWORD *)(a11 + 20) = v24[6];
      }
      return result;
    case 13:
      v56 = *(_QWORD *)(a10 + 256);
      if ( v56 && (v57 = v56 + 12LL * a12) != 0 )
      {
        *(_DWORD *)(a11 + 20) = *(_DWORD *)(v57 + 4);
        *(_DWORD *)(a11 + 24) = *(_DWORD *)(v57 + 8);
        return 0;
      }
      else
      {
        result = 0;
        if ( v24 )
        {
          *(_DWORD *)(a11 + 20) = v24[7];
          *(_DWORD *)(a11 + 24) = v24[8];
        }
      }
      return result;
    case 15:
      v48 = *(_QWORD *)(a10 + 336);
      result = 0;
      if ( v48 )
      {
        v49 = v48 + 12LL * a12;
        if ( v49 )
        {
          v52 = v49 + 4;
          v50 = *(_DWORD *)(v49 + 4);
          v51 = *(_DWORD *)(v52 + 4);
          result = 0;
          if ( (unsigned int)(v51 - 1) >= 6 )
            v51 = 0;
          *(_DWORD *)(a11 + 20) = v50;
          *(_DWORD *)(a11 + 24) = v51;
        }
      }
      return result;
    case 17:
      if ( !v24 )
        return 0;
      *(_DWORD *)(a11 + 20) = v24[14];
      *(_DWORD *)(a11 + 24) = v24[15];
      *(_DWORD *)(a11 + 28) = v24[16];
      *(_DWORD *)(a11 + 32) = v24[17];
      v64 = v24[18] - 1;
      if ( v64 > 2 )
        v65 = 3;
      else
        v65 = dword_A30310[v64];
      *(_DWORD *)(a11 + 36) = v65;
      *(_DWORD *)(a11 + 40) = v24[19];
      *(_DWORD *)(a11 + 44) = v24[20];
      *(_DWORD *)(a11 + 48) = v24[23];
      *(_DWORD *)(a11 + 52) = v24[24];
      *(_DWORD *)(a11 + 56) = v24[25];
      *(_DWORD *)(a11 + 60) = v24[26];
      return 0;
    default:
      return result;
  }
}
