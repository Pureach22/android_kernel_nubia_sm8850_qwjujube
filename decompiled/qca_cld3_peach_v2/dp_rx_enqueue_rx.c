__int64 __fastcall dp_rx_enqueue_rx(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v13; // x21
  __int64 v14; // x0
  unsigned int v15; // w8
  unsigned int v22; // w10
  unsigned int v23; // w20
  __int64 v25; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x8
  __int64 v28; // x23
  int v29; // w24
  _QWORD *v30; // x22
  __int64 v31; // x26
  __int64 v32; // x8
  __int64 v33; // x10
  unsigned int v34; // w19
  __int64 v35; // x25
  __int64 v36; // x8
  __int64 v37; // x10
  __int64 v38; // x24
  __int64 v39; // x23
  unsigned __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x24
  _QWORD *v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned __int64 v52; // x8
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x26
  __int64 v56; // x8
  __int64 v57; // x10
  __int64 v58; // x8
  unsigned int v59; // w8
  unsigned int v62; // w10
  __int64 v63; // x0
  __int64 v64; // x26
  __int64 v65; // x8
  __int64 v66; // x10

  v13 = (unsigned __int64)(a2 + 24);
  v14 = a3;
  if ( !a1 )
  {
    v23 = *((unsigned __int16 *)a2 + 4);
    v25 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a2 + 24LL) + 8LL);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v25 + 13304);
    }
    else
    {
      raw_spin_lock_bh(v25 + 13304);
      *(_QWORD *)(v25 + 13312) |= 1uLL;
    }
    if ( *(_DWORD *)(v25 + 13324) > v23 )
    {
      a1 = *(_QWORD *)(*(_QWORD *)(v25 + 13136) + 8LL * v23);
      if ( !a1 )
      {
LABEL_19:
        v27 = *(_QWORD *)(v25 + 13312);
        if ( (v27 & 1) != 0 )
        {
          *(_QWORD *)(v25 + 13312) = v27 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v25 + 13304);
        }
        else
        {
          raw_spin_unlock(v25 + 13304);
        }
        v14 = a3;
LABEL_22:
        if ( !a1 )
          goto LABEL_33;
        v28 = jiffies;
        if ( dp_rx_enqueue_rx___last_ticks - jiffies + 125 < 0 )
        {
          v38 = v14;
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: bufq->curr %d bufq->drops %d",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "dp_rx_enqueue_rx",
            (unsigned int)a2[35],
            (unsigned int)a2[36]);
          v14 = v38;
          dp_rx_enqueue_rx___last_ticks = v28;
          if ( (*(_BYTE *)(a1 + 120) & 4) == 0 )
            goto LABEL_25;
        }
        else if ( (*(_BYTE *)(a1 + 120) & 4) == 0 )
        {
LABEL_25:
          v13 = 0;
          if ( v14 )
          {
            v29 = 5472;
            v30 = *(_QWORD **)(*(_QWORD *)a2 + 24LL);
            do
            {
              v31 = *(_QWORD *)v14;
              if ( v30 )
              {
                if ( ((*(_QWORD *)(v14 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v14 + 87) & 0xFu) >= 0xA )
                  goto LABEL_94;
                v32 = (__int64)&v30[684 * ((*(_QWORD *)(v14 + 72) >> 18) & 0xFLL)
                                  + 5335
                                  + 76 * (*(_BYTE *)(v14 + 87) & 0xF)];
                v33 = *(_QWORD *)(v32 + 256) - 1LL;
                ++*(_QWORD *)(v32 + 312);
                *(_QWORD *)(v32 + 256) = v33;
              }
              _qdf_nbuf_free(v14);
              v13 = (unsigned int)(v13 + 1);
              v14 = v31;
            }
            while ( v31 );
          }
          a2[36] = v13;
          v34 = 4;
LABEL_86:
          dp_peer_unref_delete(a1, 2u, a4, a5, a6, a7, a8, a9, a10, a11);
          return v34;
        }
        v39 = v14;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v40 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v40 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v40 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a2 + 30);
        }
        else
        {
          raw_spin_lock_bh(a2 + 30);
          *((_QWORD *)a2 + 16) |= 1uLL;
        }
        if ( a2[35] >= a2[34] )
        {
          v13 = 0;
          v54 = v39;
          if ( v39 )
          {
            v29 = 5472;
            v30 = *(_QWORD **)(*(_QWORD *)a2 + 24LL);
            do
            {
              v55 = *(_QWORD *)v54;
              if ( v30 )
              {
                if ( ((*(_QWORD *)(v54 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v54 + 87) & 0xFu) >= 0xA )
                  goto LABEL_94;
                v56 = (__int64)&v30[684 * ((*(_QWORD *)(v54 + 72) >> 18) & 0xFLL)
                                  + 5335
                                  + 76 * (*(_BYTE *)(v54 + 87) & 0xF)];
                v57 = *(_QWORD *)(v56 + 256) - 1LL;
                ++*(_QWORD *)(v56 + 312);
                *(_QWORD *)(v56 + 256) = v57;
              }
              _qdf_nbuf_free(v54);
              v13 = (unsigned int)(v13 + 1);
              v54 = v55;
            }
            while ( v55 );
          }
          v58 = *((_QWORD *)a2 + 16);
          a2[36] = v13;
          if ( (v58 & 1) != 0 )
          {
            *((_QWORD *)a2 + 16) = v58 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 30);
          }
          else
          {
            raw_spin_unlock(a2 + 30);
          }
          v34 = 1;
        }
        else
        {
          v41 = *((_QWORD *)a2 + 16);
          if ( (v41 & 1) != 0 )
          {
            *((_QWORD *)a2 + 16) = v41 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 30);
          }
          else
          {
            raw_spin_unlock(a2 + 30);
          }
          v42 = *(_QWORD *)(v39 + 72);
          v43 = qdf_mem_malloc_atomic_fl(0x18u, (__int64)"dp_rx_enqueue_rx", 0x924u);
          if ( v43 )
          {
            v29 = BYTE3(v42);
            v30 = v43;
            v43[2] = v39;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (v52 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v52 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v52 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a2 + 30);
            }
            else
            {
LABEL_95:
              raw_spin_lock_bh(a2 + 30);
              *((_QWORD *)a2 + 16) |= 1uLL;
            }
            qdf_list_insert_back((_QWORD *)v13, v30);
            v53 = *((_QWORD *)a2 + 16);
            a2[35] += v29;
            if ( (v53 & 1) != 0 )
            {
              *((_QWORD *)a2 + 16) = v53 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a2 + 30);
            }
            else
            {
              raw_spin_unlock(a2 + 30);
            }
            v34 = 0;
          }
          else
          {
            qdf_trace_msg(
              0x3Fu,
              2u,
              "Failed to allocate buf to cache rx frames",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51);
            if ( v39 )
            {
              v63 = v39;
              v13 = 0;
              v29 = 5472;
              v30 = *(_QWORD **)(*(_QWORD *)a2 + 24LL);
              while ( 1 )
              {
                v64 = *(_QWORD *)v63;
                if ( v30 )
                {
                  if ( ((*(_QWORD *)(v63 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v63 + 87) & 0xFu) >= 0xA )
                    goto LABEL_94;
                  v65 = (__int64)&v30[684 * ((*(_QWORD *)(v63 + 72) >> 18) & 0xFLL)
                                    + 5335
                                    + 76 * (*(_BYTE *)(v63 + 87) & 0xF)];
                  v66 = *(_QWORD *)(v65 + 256) - 1LL;
                  ++*(_QWORD *)(v65 + 312);
                  *(_QWORD *)(v65 + 256) = v66;
                }
                _qdf_nbuf_free(v63);
                v13 = (unsigned int)(v13 + 1);
                v63 = v64;
                if ( !v64 )
                  goto LABEL_85;
              }
            }
            LODWORD(v13) = 0;
LABEL_85:
            a2[36] = v13;
            v34 = 2;
          }
        }
        goto LABEL_86;
      }
      if ( *(unsigned __int8 *)(a1 + 388) <= 2u )
      {
        v59 = *(_DWORD *)(a1 + 40);
        while ( v59 )
        {
          _X12 = (unsigned int *)(a1 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v62 = __ldxr(_X12);
            if ( v62 != v59 )
              break;
            if ( !__stlxr(v59 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v62 == v59;
          v59 = v62;
          if ( _ZF )
            goto LABEL_19;
        }
      }
    }
    a1 = 0;
    goto LABEL_19;
  }
  v15 = *(_DWORD *)(a1 + 40);
  while ( v15 )
  {
    _X12 = (unsigned int *)(a1 + 40);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v22 = __ldxr(_X12);
      if ( v22 != v15 )
        break;
      if ( !__stlxr(v15 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v22 == v15;
    v15 = v22;
    if ( _ZF )
      goto LABEL_22;
  }
LABEL_33:
  a1 = 0;
  if ( v14 )
  {
    v29 = 608;
    v13 = *(_QWORD *)(*(_QWORD *)a2 + 24LL);
    v30 = (_QWORD *)(v13 + 42680);
    do
    {
      v35 = *(_QWORD *)v14;
      if ( v13 )
      {
        if ( ((*(_QWORD *)(v14 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v14 + 87) & 0xFu) >= 0xA )
        {
LABEL_94:
          __break(0x5512u);
          goto LABEL_95;
        }
        v36 = (__int64)&v30[684 * ((*(_QWORD *)(v14 + 72) >> 18) & 0xFLL) + 76 * (*(_BYTE *)(v14 + 87) & 0xF)];
        v37 = *(_QWORD *)(v36 + 256) - 1LL;
        ++*(_QWORD *)(v36 + 312);
        *(_QWORD *)(v36 + 256) = v37;
      }
      _qdf_nbuf_free(v14);
      a1 = (unsigned int)(a1 + 1);
      v14 = v35;
    }
    while ( v35 );
  }
  a2[36] = a1;
  return 4;
}
