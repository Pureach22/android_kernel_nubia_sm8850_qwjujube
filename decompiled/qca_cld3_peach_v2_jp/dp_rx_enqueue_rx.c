__int64 __fastcall dp_rx_enqueue_rx(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x23
  __int64 v15; // x0
  _QWORD *v16; // x22
  _QWORD *v17; // x23
  __int64 v18; // x26
  __int64 v19; // x8
  __int64 v20; // x10
  __int64 v21; // x21
  __int64 v22; // x25
  __int64 v23; // x8
  __int64 v24; // x10
  unsigned __int64 StatusReg; // x8
  __int64 v26; // x8
  _QWORD *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x0
  int v39; // w21
  __int64 v40; // x26
  __int64 v41; // x8
  __int64 v42; // x10
  __int64 v43; // x0
  __int64 v44; // x26
  __int64 v45; // x8
  __int64 v46; // x10

  result = dp_peer_get_ref_by_id_1(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 8LL), *(unsigned __int16 *)(a1 + 8));
  if ( result )
  {
    v13 = result;
    v14 = jiffies;
    v15 = a2;
    if ( dp_rx_enqueue_rx___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: bufq->curr %d bufq->drops %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "dp_rx_enqueue_rx",
        *(unsigned int *)(a1 + 140),
        *(unsigned int *)(a1 + 144));
      v15 = a2;
      dp_rx_enqueue_rx___last_ticks = v14;
      if ( (*(_BYTE *)(v13 + 120) & 4) == 0 )
      {
LABEL_4:
        LODWORD(a2) = 0;
        if ( v15 )
        {
          v16 = *(_QWORD **)(*(_QWORD *)a1 + 24LL);
          v17 = v16 + 5232;
          do
          {
            v18 = *(_QWORD *)v15;
            if ( v16 )
            {
              if ( ((*(_QWORD *)(v15 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v15 + 87) & 0xFu) >= 0xA )
                goto LABEL_58;
              v19 = (__int64)&v17[684 * ((*(_QWORD *)(v15 + 72) >> 18) & 0xFLL) + 76 * (*(_BYTE *)(v15 + 87) & 0xF)];
              v20 = *(_QWORD *)(v19 + 256) - 1LL;
              ++*(_QWORD *)(v19 + 312);
              *(_QWORD *)(v19 + 256) = v20;
            }
            _qdf_nbuf_free(v15);
            LODWORD(a2) = a2 + 1;
            v15 = v18;
          }
          while ( v18 );
        }
LABEL_11:
        *(_DWORD *)(a1 + 144) = a2;
        return dp_peer_unref_delete(v13, 2u, v5, v6, v7, v8, v9, v10, v11, v12);
      }
    }
    else if ( (*(_BYTE *)(v13 + 120) & 4) == 0 )
    {
      goto LABEL_4;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 120);
    }
    else
    {
      raw_spin_lock_bh(a1 + 120);
      *(_QWORD *)(a1 + 128) |= 1uLL;
    }
    if ( *(_DWORD *)(a1 + 140) >= *(_DWORD *)(a1 + 136) )
    {
      v38 = a2;
      if ( a2 )
      {
        v39 = 0;
        v16 = *(_QWORD **)(*(_QWORD *)a1 + 24LL);
        v17 = v16 + 5232;
        while ( 1 )
        {
          v40 = *(_QWORD *)v38;
          if ( v16 )
          {
            if ( ((*(_QWORD *)(v38 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v38 + 87) & 0xFu) >= 0xA )
              goto LABEL_58;
            v41 = (__int64)&v17[684 * ((*(_QWORD *)(v38 + 72) >> 18) & 0xFLL) + 76 * (*(_BYTE *)(v38 + 87) & 0xF)];
            v42 = *(_QWORD *)(v41 + 256) - 1LL;
            ++*(_QWORD *)(v41 + 312);
            *(_QWORD *)(v41 + 256) = v42;
          }
          _qdf_nbuf_free(v38);
          ++v39;
          v38 = v40;
          if ( !v40 )
            goto LABEL_53;
        }
      }
      v39 = 0;
LABEL_53:
      v37 = *(_QWORD *)(a1 + 128);
      *(_DWORD *)(a1 + 144) = v39;
      if ( (v37 & 1) != 0 )
        goto LABEL_34;
    }
    else
    {
      v26 = *(_QWORD *)(a1 + 128);
      if ( (v26 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 128) = v26 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 120);
      }
      else
      {
        raw_spin_unlock(a1 + 120);
      }
      v17 = *(_QWORD **)(a2 + 72);
      v27 = qdf_mem_malloc_atomic_fl(0x18u, (__int64)"dp_rx_enqueue_rx", 0x924u);
      if ( !v27 )
      {
        qdf_trace_msg(0x3Fu, 2u, "Failed to allocate buf to cache rx frames", v28, v29, v30, v31, v32, v33, v34, v35);
        if ( a2 )
        {
          v43 = a2;
          LODWORD(a2) = 0;
          v16 = *(_QWORD **)(*(_QWORD *)a1 + 24LL);
          v17 = v16 + 5232;
          while ( 1 )
          {
            v44 = *(_QWORD *)v43;
            if ( v16 )
            {
              if ( ((*(_QWORD *)(v43 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v43 + 87) & 0xFu) >= 0xA )
                goto LABEL_58;
              v45 = (__int64)&v17[684 * ((*(_QWORD *)(v43 + 72) >> 18) & 0xFLL) + 76 * (*(_BYTE *)(v43 + 87) & 0xF)];
              v46 = *(_QWORD *)(v45 + 256) - 1LL;
              ++*(_QWORD *)(v45 + 312);
              *(_QWORD *)(v45 + 256) = v46;
            }
            _qdf_nbuf_free(v43);
            LODWORD(a2) = a2 + 1;
            v43 = v44;
            if ( !v44 )
              goto LABEL_11;
          }
        }
        goto LABEL_11;
      }
      LODWORD(v17) = BYTE3(v17);
      v16 = v27;
      v27[2] = a2;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v36 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v36 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 120);
      }
      else
      {
LABEL_59:
        raw_spin_lock_bh(a1 + 120);
        *(_QWORD *)(a1 + 128) |= 1uLL;
      }
      qdf_list_insert_back((_QWORD *)(a1 + 96), v16);
      v37 = *(_QWORD *)(a1 + 128);
      *(_DWORD *)(a1 + 140) += (_DWORD)v17;
      if ( (v37 & 1) != 0 )
      {
LABEL_34:
        *(_QWORD *)(a1 + 128) = v37 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 120);
        return dp_peer_unref_delete(v13, 2u, v5, v6, v7, v8, v9, v10, v11, v12);
      }
    }
    raw_spin_unlock(a1 + 120);
    return dp_peer_unref_delete(v13, 2u, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  if ( a2 )
  {
    result = a2;
    v13 = 0;
    LODWORD(v17) = 5472;
    v21 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
    v16 = (_QWORD *)(v21 + 41856);
    while ( 1 )
    {
      v22 = *(_QWORD *)result;
      if ( v21 )
      {
        if ( ((*(_QWORD *)(result + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(result + 87) & 0xFu) >= 0xA )
        {
LABEL_58:
          __break(0x5512u);
          goto LABEL_59;
        }
        v23 = (__int64)&v16[684 * ((*(_QWORD *)(result + 72) >> 18) & 0xFLL) + 76 * (*(_BYTE *)(result + 87) & 0xF)];
        v24 = *(_QWORD *)(v23 + 256) - 1LL;
        ++*(_QWORD *)(v23 + 312);
        *(_QWORD *)(v23 + 256) = v24;
      }
      _qdf_nbuf_free(result);
      v13 = (unsigned int)(v13 + 1);
      result = v22;
      if ( !v22 )
      {
        *(_DWORD *)(a1 + 144) = v13;
        return result;
      }
    }
  }
  *(_DWORD *)(a1 + 144) = 0;
  return result;
}
