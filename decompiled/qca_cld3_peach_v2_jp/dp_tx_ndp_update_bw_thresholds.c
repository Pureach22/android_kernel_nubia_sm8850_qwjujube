__int64 *__fastcall dp_tx_ndp_update_bw_thresholds(
        __int64 *result,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x23
  unsigned __int64 StatusReg; // x8
  _BOOL4 v25; // w8
  __int64 v26; // x10
  __int16 v27; // w8
  __int16 v28; // w9
  bool v29; // w8
  __int64 v30; // x9
  int v31; // w10
  unsigned __int16 *v32; // x19
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w8
  int v42; // w9
  unsigned int v43; // w14
  __int64 v44; // x8
  unsigned int v45; // w24
  __int16 v46; // w15
  __int64 v47; // x20
  _DWORD *v48; // x27
  unsigned int v49; // w25
  unsigned __int16 v50; // w16
  unsigned int v51; // w26
  __int64 v52; // x5
  __int64 v53; // x6
  unsigned int v54; // t1
  __int16 v55; // w11
  int v56; // w9
  int v57; // w10
  int v58; // w11
  int v59; // w12
  int v60; // w15
  int v61; // w9
  int v62; // w11
  int v63; // w14
  int v64; // w9
  int v65; // w11
  int v66; // w13
  int v67; // w9
  int v68; // w10
  int v69; // w14
  int v70; // w12
  int v71; // w15
  __int64 v72; // x8

  v11 = *result;
  if ( *result )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Update bandwidth based tx desc thresholds for NDP old_bw:%u new_bw:%u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_tx_ndp_update_bw_thresholds",
      a2,
      a3);
    v22 = *(_QWORD *)(v11 + 42432);
    if ( !v22 )
      return (__int64 *)qdf_trace_msg(
                          0x45u,
                          5u,
                          "%s: Pool not attached yet to vdev",
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          "dp_tx_ndp_update_bw_thresholds");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v22 + 256);
    }
    else
    {
      raw_spin_lock_bh(v22 + 256);
      *(_QWORD *)(v22 + 264) |= 1uLL;
    }
    v25 = a2 > 4 && a3 > 4;
    if ( a2 == a3 || v25 )
      goto LABEL_37;
    if ( a2 > 4 )
    {
      if ( a3 > 4 )
        goto LABEL_37;
      v29 = 0;
    }
    else
    {
      v26 = v22 + 2LL * a2;
      v27 = *(_WORD *)(v26 + 152);
      v28 = v27 - 1;
      *(_WORD *)(v26 + 152) = v27 - 1;
      v29 = v27 == 1;
      if ( a3 >= 5 )
      {
        if ( !v28 )
          goto LABEL_24;
        goto LABEL_37;
      }
    }
    v30 = v22 + 2LL * a3;
    v31 = *(unsigned __int16 *)(v30 + 152);
    *(_WORD *)(v30 + 152) = v31 + 1;
    if ( !v31 || v29 )
    {
LABEL_24:
      qdf_mem_copy((void *)(v22 + 164), (const void *)(v22 + 184), 0x14u);
      qdf_mem_set((void *)(v22 + 184), 0x14u, 0);
      qdf_mem_set((void *)(v22 + 224), 0xAu, 0);
      v32 = (unsigned __int16 *)(v22 + 234);
      qdf_mem_set((void *)(v22 + 234), 0xAu, 0);
      v41 = *(unsigned __int16 *)(v22 + 154);
      v42 = (*(_WORD *)(v22 + 152) != 0)
          | (2 * (v41 != 0))
          | (4 * (*(_WORD *)(v22 + 156) != 0))
          | (8 * (*(_WORD *)(v22 + 158) != 0))
          | (16 * (*(_WORD *)(v22 + 160) != 0));
      if ( v42 )
      {
        v43 = (unsigned __int16)((*(_WORD *)(v22 + 152) != 0)
                               | (unsigned __int16)(2 * (v41 != 0))
                               | (4 * (*(_WORD *)(v22 + 156) != 0))
                               | (8 * (*(_WORD *)(v22 + 158) != 0))
                               | (16 * (*(_WORD *)(v22 + 160) != 0)));
        v44 = v41 != 0;
        if ( *(_WORD *)(v22 + 156) )
          v44 = 2;
        v45 = *(unsigned __int16 *)(v22 + 72) / v43;
        v46 = *(_WORD *)(v22 + 56);
        if ( *(_WORD *)(v22 + 158) )
          v44 = 3;
        if ( *(_WORD *)(v22 + 160) )
          v44 = 4;
        v47 = 0;
        v48 = (_DWORD *)(v22 + 204);
        v49 = *(unsigned __int16 *)(v22 + 56) / v43;
        v50 = *(_WORD *)(v22 + 80);
        *(_WORD *)(v22 + 224 + 2 * v44) = *(_WORD *)(v22 + 72) - v45 * v42;
        v51 = v50 / v43;
        *(_DWORD *)(v22 + 184 + 4 * v44) = (unsigned __int16)(v46 - v49 * v42);
        v32[v44] = v50 - v51 * v42;
        do
        {
          if ( *(v32 - 41) )
          {
            *(v48 - 5) += v49 << v47;
            v55 = *v32;
            *(v32 - 5) += (_WORD)v45 << v47;
            *v32 = v55 + (v51 << v47);
          }
          else
          {
            *(v32 - 5) = -1;
            *v32 = -1;
          }
          v52 = (unsigned int)*(v48 - 5);
          *v48 += v52 - *(v48 - 10);
          ++v48;
          v53 = *(v32 - 5);
          v54 = *v32++;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Adjusted BE/BK tx descriptors for BW-%u: %u stop_thresh:%u start thresh:%u",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "dp_tx_ndp_update_weighted_bw_thresh",
            (unsigned int)v47++,
            v52,
            v53,
            v54);
        }
        while ( v47 != 5 );
      }
      else
      {
        v56 = *(_DWORD *)(v22 + 184);
        v57 = *(_DWORD *)(v22 + 188);
        v58 = *(_DWORD *)(v22 + 164);
        v59 = *(_DWORD *)(v22 + 168);
        v60 = *(_DWORD *)(v22 + 192);
        *(_WORD *)(v22 + 224) = -1;
        v61 = v56 - v58;
        *(_WORD *)(v22 + 234) = -1;
        v63 = *(_DWORD *)(v22 + 204);
        v62 = *(_DWORD *)(v22 + 208);
        *(_WORD *)(v22 + 230) = -1;
        *(_WORD *)(v22 + 240) = -1;
        *(_WORD *)(v22 + 232) = -1;
        *(_DWORD *)(v22 + 204) = v61 + v63;
        *(_DWORD *)(v22 + 208) = v57 - v59 + v62;
        v64 = *(_DWORD *)(v22 + 172);
        v65 = *(_DWORD *)(v22 + 176);
        v66 = *(_DWORD *)(v22 + 180);
        *(_DWORD *)(v22 + 226) = -1;
        v67 = v60 - v64;
        *(_DWORD *)(v22 + 236) = -1;
        v69 = *(_DWORD *)(v22 + 196);
        v68 = *(_DWORD *)(v22 + 200);
        v70 = *(_DWORD *)(v22 + 212);
        v71 = *(_DWORD *)(v22 + 216);
        *(_WORD *)(v22 + 242) = -1;
        *(_DWORD *)(v22 + 212) = v67 + v70;
        *(_DWORD *)(v22 + 216) = v69 - v65 + v71;
        *(_DWORD *)(v22 + 220) += v68 - v66;
      }
    }
LABEL_37:
    v72 = *(_QWORD *)(v22 + 264);
    if ( (v72 & 1) != 0 )
    {
      *(_QWORD *)(v22 + 264) = v72 & 0xFFFFFFFFFFFFFFFELL;
      return (__int64 *)raw_spin_unlock_bh(v22 + 256);
    }
    else
    {
      return (__int64 *)raw_spin_unlock(v22 + 256);
    }
  }
  return result;
}
