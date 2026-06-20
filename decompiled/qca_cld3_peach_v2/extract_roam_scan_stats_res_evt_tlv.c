__int64 __fastcall extract_roam_scan_stats_res_evt_tlv(
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
        _DWORD *a11,
        _QWORD *a12)
{
  __int64 v12; // x19
  __int64 v13; // x21
  _DWORD *v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x9
  _QWORD *v27; // x8
  __int64 v28; // x10
  __int64 v29; // x11
  __int64 v30; // x12
  __int64 v31; // x13
  __int64 v32; // x14
  __int64 v33; // x15
  __int64 v34; // x17
  int v35; // w16
  unsigned int v36; // w4
  __int64 v37; // x16
  __int64 v38; // x17
  __int64 v39; // x1
  int v40; // w6
  unsigned int v41; // w4
  __int64 v42; // x1
  __int64 v43; // x2
  __int64 v44; // x3
  __int64 v45; // x4
  __int64 v46; // x5
  int v47; // w6
  int v48; // w7
  _DWORD *v49; // x20
  char *i; // x22
  __int64 v51; // x24
  int v52; // w25
  __int64 v53; // x25
  _DWORD *v54; // x25
  int v55; // w25
  unsigned __int64 v56; // x25
  char *v57; // x26
  __int64 v58; // x27
  int v59; // w27
  __int64 v60; // x25
  __int64 v61; // x25
  __int64 v62; // x20
  _DWORD *v63; // x21
  __int64 v64; // x20
  _DWORD *v65; // x21

  *a12 = 0;
  *a11 = 255;
  if ( !a10 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid roam scan stats event",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_scan_stats_res_evt_tlv");
    return 4;
  }
  v12 = *(unsigned int *)(*(_QWORD *)a10 + 8LL);
  *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
  if ( (unsigned int)v12 >= 6 )
  {
    v13 = jiffies;
    if ( extract_roam_scan_stats_res_evt_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: %u exceeded maximum roam scan stats: %u",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_scan_stats_res_evt_tlv",
        (unsigned int)v12,
        5);
      extract_roam_scan_stats_res_evt_tlv___last_ticks = v13;
    }
    return 4;
  }
  v17 = (_DWORD *)_qdf_mem_malloc(328LL * (unsigned int)v12 + 8, "extract_roam_scan_stats_res_evt_tlv", 19473);
  if ( !v17 )
    return 2;
  if ( !(_DWORD)v12 )
  {
    *a12 = v17;
    return 0;
  }
  v26 = *(_QWORD *)(a10 + 16);
  v27 = a12;
  if ( v26 && *(_DWORD *)(a10 + 24) != (_DWORD)v12 )
    v26 = 0;
  v28 = *(_QWORD *)(a10 + 32);
  if ( v28 && *(_DWORD *)(a10 + 40) != (_DWORD)v12 )
    v28 = 0;
  v29 = *(_QWORD *)(a10 + 80);
  if ( v29 && *(_DWORD *)(a10 + 88) != (_DWORD)v12 )
    v29 = 0;
  v30 = *(_QWORD *)(a10 + 112);
  if ( v30 && *(_DWORD *)(a10 + 120) != (_DWORD)v12 )
    v30 = 0;
  v31 = *(_QWORD *)(a10 + 96);
  if ( v31 && *(_DWORD *)(a10 + 104) != (_DWORD)v12 )
    v31 = 0;
  v32 = *(_QWORD *)(a10 + 144);
  if ( v32 && *(_DWORD *)(a10 + 152) != (_DWORD)v12 )
    v32 = 0;
  v33 = *(_QWORD *)(a10 + 48);
  if ( v33 )
  {
    if ( *(_DWORD *)(a10 + 56) == (_DWORD)v12 )
    {
      v34 = 0;
      v35 = 0;
      do
      {
        v36 = *(_DWORD *)(v33 + 4 * v34);
        if ( v36 >= 0x33 )
        {
          v62 = jiffies;
          if ( extract_roam_scan_stats_res_evt_tlv___last_ticks_493 - jiffies + 125 < 0 )
          {
            v63 = v17;
            qdf_trace_msg(
              0x31u,
              2u,
              "%s: %u exceeded max scan channels %u",
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              "extract_roam_scan_stats_res_evt_tlv");
            v17 = v63;
            extract_roam_scan_stats_res_evt_tlv___last_ticks_493 = v62;
          }
          goto LABEL_109;
        }
        ++v34;
        v35 += v36;
      }
      while ( v12 != v34 );
      if ( !*(_QWORD *)(a10 + 64) )
        goto LABEL_41;
      if ( *(_DWORD *)(a10 + 72) == v35 )
        v37 = *(_QWORD *)(a10 + 64);
      else
        v37 = 0;
      v38 = *(_QWORD *)(a10 + 128);
      if ( !v38 )
        goto LABEL_60;
      goto LABEL_42;
    }
    v33 = 0;
  }
LABEL_41:
  v37 = 0;
  v38 = *(_QWORD *)(a10 + 128);
  if ( !v38 )
    goto LABEL_60;
LABEL_42:
  if ( *(_DWORD *)(a10 + 136) != (_DWORD)v12 )
  {
    v38 = 0;
LABEL_60:
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
LABEL_61:
    v46 = 0;
    v47 = 0;
    v48 = 0;
    *v17 = v12;
    v49 = v17 + 6;
    if ( (unsigned int)v12 <= 1 )
      v12 = 1;
    else
      v12 = (unsigned int)v12;
    for ( i = (char *)v17 + 261; ; i += 328 )
    {
      v51 = (__int64)&v17[82 * v46 + 2];
      if ( v28 )
        *(_QWORD *)v51 = (unsigned int)(*(_DWORD *)(v28 + 8 * v46) | (*(_DWORD *)(v28 + 8 * v46 + 4) << 31));
      if ( v26 )
        *(_DWORD *)(v51 + 8) = *(_DWORD *)(v26 + 4 * v46);
      if ( v33 )
      {
        v52 = *(_DWORD *)(v33 + 4 * v46);
        *(_DWORD *)(v51 + 12) = v52;
        if ( v37 )
        {
          if ( v52 )
            break;
        }
      }
LABEL_77:
      if ( v31 )
        *(_DWORD *)(v51 + 216) = *(_DWORD *)(v31 + 4 * v46);
      if ( v32 )
      {
        v54 = (_DWORD *)(v32 + 8 * v46);
        *(_DWORD *)(v51 + 316) = *v54;
        *(_DWORD *)(v51 + 320) = v54[1];
      }
      if ( v38 )
      {
        v55 = *(_DWORD *)(v38 + 4 * v46);
        *(_DWORD *)(v51 + 232) = v55;
        if ( v55 )
        {
          v56 = 0;
          v57 = i;
          do
          {
            v59 = v47 + v56;
            if ( v43 )
            {
              if ( v56 > 3 )
                goto LABEL_110;
              *(_DWORD *)(v57 - 17) = *(_DWORD *)(v43 + 4LL * v59);
            }
            if ( v45 )
            {
              if ( v56 > 3 )
                goto LABEL_110;
              *(_DWORD *)(v57 - 13) = *(_DWORD *)(v45 + 4LL * v59);
            }
            if ( v44 )
            {
              if ( v56 > 3 )
                goto LABEL_110;
              *(_DWORD *)(v57 - 9) = *(_DWORD *)(v44 + 4LL * v59);
            }
            if ( v42 )
            {
              if ( v56 > 3 )
                goto LABEL_110;
              v58 = v42 + 8LL * v59;
              *(_WORD *)(v57 - 5) = *(_DWORD *)v58;
              *(v57 - 3) = *(_WORD *)(v58 + 2);
              *(v57 - 2) = *(_BYTE *)(v58 + 3);
              *(_WORD *)(v57 - 1) = *(_DWORD *)(v58 + 4);
            }
            ++v56;
            v57 += 20;
          }
          while ( v56 < *(unsigned int *)(v38 + 4 * v46) );
          v47 += v56;
        }
      }
      if ( v29 )
      {
        v60 = v29 + 8 * v46;
        *(_WORD *)(v51 + 220) = *(_DWORD *)v60;
        *(_BYTE *)(v51 + 222) = *(_WORD *)(v60 + 2);
        *(_BYTE *)(v51 + 223) = *(_BYTE *)(v60 + 3);
        *(_WORD *)(v51 + 224) = *(_DWORD *)(v60 + 4);
      }
      if ( v30 )
      {
        v61 = v30 + 8 * v46;
        *(_WORD *)(v51 + 226) = *(_DWORD *)v61;
        *(_BYTE *)(v51 + 228) = *(_WORD *)(v61 + 2);
        *(_BYTE *)(v51 + 229) = *(_BYTE *)(v61 + 3);
        *(_WORD *)(v51 + 230) = *(_DWORD *)(v61 + 4);
      }
      ++v46;
      v49 += 82;
      if ( v46 == v12 )
      {
        *v27 = v17;
        return 0;
      }
    }
    v53 = 0;
    while ( v53 != 50 )
    {
      v49[v53] = *(_DWORD *)(v37 + 4LL * (v48 + (int)v53));
      if ( ++v53 >= (unsigned __int64)*(unsigned int *)(v33 + 4 * v46) )
      {
        v48 += v53;
        goto LABEL_77;
      }
    }
LABEL_110:
    __break(0x5512u);
    return extract_offload_bcn_tx_status_evt();
  }
  v39 = 0;
  v40 = 0;
  while ( 1 )
  {
    v41 = *(_DWORD *)(v38 + 4 * v39);
    if ( v41 >= 5 )
      break;
    ++v39;
    v40 += v41;
    if ( v12 == v39 )
    {
      v42 = *(_QWORD *)(a10 + 160);
      if ( v42 && *(_DWORD *)(a10 + 168) != v40 )
        v42 = 0;
      v43 = *(_QWORD *)(a10 + 176);
      if ( v43 && *(_DWORD *)(a10 + 184) != v40 )
        v43 = 0;
      v44 = *(_QWORD *)(a10 + 192);
      if ( v44 && *(_DWORD *)(a10 + 200) != v40 )
        v44 = 0;
      v45 = *(_QWORD *)(a10 + 208);
      if ( v45 && *(_DWORD *)(a10 + 216) != v40 )
        v45 = 0;
      goto LABEL_61;
    }
  }
  v64 = jiffies;
  if ( extract_roam_scan_stats_res_evt_tlv___last_ticks_495 - jiffies + 125 < 0 )
  {
    v65 = v17;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: %u exceeded max scan cand %u",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "extract_roam_scan_stats_res_evt_tlv");
    v17 = v65;
    extract_roam_scan_stats_res_evt_tlv___last_ticks_495 = v64;
  }
LABEL_109:
  _qdf_mem_free((__int64)v17);
  return 16;
}
