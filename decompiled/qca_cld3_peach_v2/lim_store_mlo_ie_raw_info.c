__int64 __fastcall lim_store_mlo_ie_raw_info(unsigned __int8 *a1, __int16 a2, unsigned int a3, __int64 a4)
{
  size_t v8; // x2
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x9
  unsigned int v19; // w8
  int v20; // w6
  unsigned __int8 *v21; // x10
  unsigned __int8 *v22; // x10
  __int64 v23; // x25
  unsigned __int64 v24; // x20
  _BYTE *v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  unsigned int v35; // w12
  int v36; // w10
  unsigned int v37; // kr00_4
  bool v38; // zf
  int v39; // w13
  unsigned __int8 v40; // w14
  __int64 v41; // x21
  _BYTE *v42; // x8
  __int16 v43; // w8
  int v44; // w5
  __int64 v45; // x10
  __int64 v46; // x11
  unsigned int v47; // w14
  char v48; // w15
  __int64 v49; // x10
  int v50; // w10
  _BYTE *v51; // x24
  __int64 v52; // x19
  __int64 v53; // x4
  __int64 v54; // x25
  _BYTE *v55; // x26
  _BYTE *v56; // x8
  int v57; // w5
  __int64 v58; // x9
  __int64 v59; // x10
  unsigned int v60; // w13
  char v61; // w14
  int v62; // w9
  __int64 v63; // x23
  _BYTE *v64; // x20
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7

  if ( !a1 )
    return 4;
  qdf_mem_set((void *)a4, 0x92Cu, 0);
  v8 = (unsigned __int16)(a2 - (_WORD)a1);
  *(_WORD *)(a4 + 2088) = a2 - (_WORD)a1;
  if ( (unsigned int)v8 >= 0x102 )
  {
    *(_WORD *)(a4 + 2088) = 0;
    return 4;
  }
  qdf_mem_copy((void *)(a4 + 2090), a1, v8);
  v18 = a1[1];
  v19 = v18 + 2;
  if ( (int)v18 + 2 >= a3 )
  {
    v20 = 0;
  }
  else
  {
    v20 = 0;
    v21 = a1;
    do
    {
      v22 = &v21[v18];
      ++v20;
      v18 = v22[3];
      v21 = v22 + 2;
      v19 += v18 + 2;
    }
    while ( v19 < a3 );
  }
  v23 = jiffies;
  v24 = a3 - 2 * v20;
  if ( lim_store_mlo_ie_raw_info___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: ml_ie_len: %d, total_len: %d, frag_num: %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "lim_store_mlo_ie_raw_info",
      (unsigned int)v24,
      a3);
    lim_store_mlo_ie_raw_info___last_ticks = v23;
  }
  v25 = (_BYTE *)_qdf_mem_malloc(a3, "lim_store_mlo_ie_raw_info", 1274);
  if ( !v25 )
    return 2;
  *v25 = *a1;
  v25[1] = a1[1];
  if ( (_DWORD)v24 != 2 )
  {
    v25[2] = a1[2];
    if ( (_DWORD)v24 != 3 )
    {
      v34 = 0;
      v35 = 3;
      v36 = 1;
      do
      {
        v37 = v36++;
        v38 = ~(v37 / 0xFF) + ((v37 / 0xFF) << 8) == v34;
        v39 = v34 + 3;
        ++v34;
        if ( v38 )
          v35 += 2;
        v40 = a1[v35++];
        v25[v39] = v40;
      }
      while ( (_DWORD)v24 - 3 != v34 );
    }
  }
  v41 = *(unsigned __int16 *)(a4 + 2088);
  if ( (unsigned int)v24 > (unsigned int)v41 )
  {
    v42 = &v25[v41];
    if ( !v25[v41] )
    {
      v44 = 2;
      *(_BYTE *)(a4 + 26) = v25[v41];
      *(_BYTE *)(a4 + 27) = v25[(unsigned int)v41 + 1];
      while ( 1 )
      {
        if ( v44 + (unsigned int)(unsigned __int8)v42[1] > 0x202 )
          goto LABEL_60;
        v45 = (unsigned int)(v41 + 2);
        if ( v42[1] )
          break;
        LODWORD(v41) = v41 + 2;
LABEL_34:
        *(_WORD *)(a4 + 24) = v44;
        v49 = (unsigned __int8)v42[1];
        if ( (unsigned int)v41 >= (unsigned int)v24 || (_DWORD)v49 != 255 )
        {
          v51 = &v42[v49 + 2];
LABEL_41:
          v54 = jiffies;
          if ( lim_store_mlo_ie_raw_info___last_ticks_36 - jiffies + 125 < 0 )
          {
            v55 = v25;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: sta index: %d, sta_data len: %d, copied: %d",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "lim_store_mlo_ie_raw_info",
              0);
            v25 = v55;
            lim_store_mlo_ie_raw_info___last_ticks_36 = v54;
          }
          if ( (unsigned int)v41 >= (unsigned int)v24 || *v51 )
          {
            v43 = 1;
            goto LABEL_23;
          }
          v56 = &v25[(unsigned int)v41];
          v57 = 2;
          *(_BYTE *)(a4 + 542) = *v56;
          *(_BYTE *)(a4 + 543) = v56[1];
          while ( v57 + (unsigned int)(unsigned __int8)v51[1] <= 0x202 )
          {
            v58 = (unsigned int)(v41 + 2);
            if ( v51[1] )
            {
              v59 = 0;
              while ( v58 + v59 < v24 )
              {
                v60 = v57 + v59;
                v61 = v25[v58 + v59++];
                *(_BYTE *)(a4 + 542 + v60) = v61;
                if ( (unsigned int)v59 >= (unsigned __int8)v51[1] )
                {
                  LODWORD(v41) = v58 + v59;
                  v57 += v59;
                  goto LABEL_54;
                }
              }
              v52 = (__int64)v25;
              v53 = (unsigned int)(v41 + 2) + v59;
              goto LABEL_39;
            }
            LODWORD(v41) = v41 + 2;
LABEL_54:
            *(_WORD *)(a4 + 540) = v57;
            if ( (unsigned int)v41 < (unsigned int)v24 && (unsigned __int8)v51[1] == 255 )
            {
              v62 = (unsigned __int8)v51[257];
              v51 += 257;
              if ( v62 == 254 )
                continue;
            }
            v63 = jiffies;
            v64 = v25;
            if ( lim_store_mlo_ie_raw_info___last_ticks_36 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: sta index: %d, sta_data len: %d, copied: %d",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "lim_store_mlo_ie_raw_info",
                1);
              lim_store_mlo_ie_raw_info___last_ticks_36 = v63;
            }
            v43 = 2;
            v25 = v64;
            goto LABEL_23;
          }
LABEL_60:
          _qdf_mem_free((__int64)v25);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: no enough buf to store sta prof",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "lim_store_mlo_ie_raw_info");
          return 4;
        }
        v50 = (unsigned __int8)v42[257];
        v51 = v42 + 257;
        v42 += 257;
        if ( v50 != 254 )
          goto LABEL_41;
      }
      v46 = 0;
      while ( v45 + v46 < v24 )
      {
        v47 = v44 + v46;
        v48 = v25[v45 + v46++];
        *(_BYTE *)(a4 + 26 + v47) = v48;
        if ( (unsigned int)v46 >= (unsigned __int8)v42[1] )
        {
          LODWORD(v41) = v45 + v46;
          v44 += v46;
          goto LABEL_34;
        }
      }
      v52 = (__int64)v25;
      v53 = (unsigned int)(v41 + 2) + v46;
LABEL_39:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Buf length exceeded, copied %d ml_ie_len %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_store_mlo_ie_raw_info",
        v53,
        (unsigned int)v24);
      _qdf_mem_free(v52);
      return 4;
    }
  }
  v43 = 0;
LABEL_23:
  *(_WORD *)(a4 + 22) = v43;
  _qdf_mem_free((__int64)v25);
  return 0;
}
