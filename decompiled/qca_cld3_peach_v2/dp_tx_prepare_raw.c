__int64 __fastcall dp_tx_prepare_raw(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char *v12; // x8
  __int64 v14; // x19
  __int64 v15; // x20
  int v17; // w9
  char v18; // w9
  __int64 v19; // x24
  __int16 v20; // w25
  _WORD *v21; // x26
  __int64 v22; // x23
  __int16 v23; // w8
  int v24; // w9
  __int64 v25; // x8
  __int64 v26; // x8
  __int16 v27; // w8
  int v28; // w9
  __int64 v29; // x24
  int v30; // w25
  __int64 v31; // x21
  __int64 v32; // x26
  __int64 v33; // x21
  __int64 v34; // x22
  __int64 v35; // x0
  __int64 v36; // x23
  __int64 v37; // x23
  int v38; // w8

  v12 = *(char **)(a2 + 224);
  v14 = a2;
  v15 = a1;
  if ( !a1 )
  {
    v18 = *v12;
    if ( (*v12 & 0xC) == 8 )
    {
LABEL_8:
      if ( v18 < 0 && (*(_BYTE *)(a1 + 43272) & 1) != 0 && v12[24] < 0 )
      {
        v12[1] |= 0x40u;
        if ( a2 )
        {
LABEL_12:
          v19 = 0;
          v20 = 0;
          v21 = (_WORD *)(a3 + 30);
          v22 = a2;
          while ( 1 )
          {
            if ( v19 == -6 )
            {
              v37 = jiffies;
              if ( dp_tx_prepare_raw___last_ticks - jiffies + 125 < 0 )
              {
                a1 = qdf_trace_msg(
                       0x45u,
                       2u,
                       "%s: nbuf cnt exceeds the max number of segs",
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11,
                       a12,
                       "dp_tx_prepare_raw");
                dp_tx_prepare_raw___last_ticks = v37;
              }
              if ( v15 )
              {
                if ( *(_BYTE *)(a4 + 94) )
                  goto LABEL_56;
                LODWORD(v29) = 6;
                ++*(_DWORD *)(v15 + 560);
              }
              else
              {
                LODWORD(v29) = 6;
              }
              goto LABEL_28;
            }
            a1 = qdf_nbuf_map_nbytes_single(*(_QWORD *)(v15 + 16), v22, *(unsigned int *)(v22 + 112));
            if ( (_DWORD)a1 )
              break;
            if ( (*(_BYTE *)(v22 + 68) & 4) != 0 )
              v25 = 80;
            else
              v25 = 40;
            v26 = *(_QWORD *)(v22 + v25);
            *(_DWORD *)(v21 - 3) = v26;
            *(v21 - 1) = WORD2(v26);
            if ( (*(_BYTE *)(v22 + 68) & 4) != 0 )
              v27 = *(_WORD *)(v22 + 66);
            else
              v27 = 0;
            v28 = *(_DWORD *)(v22 + 112);
            *(_QWORD *)(v21 - 7) = v22;
            *v21 = v28 + v27;
            if ( (*(_BYTE *)(v22 + 68) & 4) != 0 )
              v23 = *(_WORD *)(v22 + 66);
            else
              v23 = 0;
            v24 = *(_DWORD *)(v22 + 112);
            v22 = *(_QWORD *)v22;
            --v19;
            v21 += 8;
            v20 += v23 + v24;
            if ( !v22 )
            {
              v38 = -(int)v19;
              goto LABEL_51;
            }
          }
          a1 = qdf_trace_msg(
                 0x7Du,
                 2u,
                 "%s: %s dma map error ",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "dp_tx_prepare_raw",
                 "dp_tx_prepare_raw");
          v29 = -v19;
          if ( !v15 )
            goto LABEL_28;
          if ( !*(_BYTE *)(a4 + 94) )
          {
            ++*(_DWORD *)(v15 + 552);
            goto LABEL_28;
          }
          goto LABEL_56;
        }
      }
      else if ( a2 )
      {
        goto LABEL_12;
      }
      v20 = 0;
      LOWORD(v38) = 0;
LABEL_51:
      *(_WORD *)(a3 + 8) = v38;
      *(_WORD *)(a3 + 10) = v20;
      *(_QWORD *)(a3 + 112) = 0;
      *(_DWORD *)a4 = 5;
      *(_QWORD *)(a4 + 24) = a3;
      *(_DWORD *)(a4 + 8) = 1;
      return v14;
    }
LABEL_27:
    qdf_trace_msg(
      0x7Du,
      8u,
      "%s: Pkt. recd is of not data type",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dp_tx_prepare_raw");
    LODWORD(v29) = 0;
LABEL_28:
    if ( v14 )
    {
      v30 = 0;
      do
      {
        if ( v30 < (int)v29 )
        {
          v32 = *(_QWORD *)(v15 + 16);
          v33 = *(int *)(v14 + 112);
          v34 = *(_QWORD *)(v14 + 40);
          if ( *(_BYTE *)(v32 + 624) == 1 && (_qdf_is_pp_nbuf(v14) & 1) != 0 && *(_QWORD *)(v14 + 40) )
          {
            v35 = *(_QWORD *)(v32 + 40);
            if ( (*(_BYTE *)(v35 + 844) & 0x40) == 0 )
              _dma_sync_single_for_cpu(v35, v34);
          }
          else if ( v34 )
          {
            v36 = *(int *)(v14 + 212);
            qdf_mem_dp_tx_skb_cnt_dec();
            qdf_mem_dp_tx_skb_dec(v36);
            qdf_mem_skb_total_dec(v36);
            dma_unmap_page_attrs(*(_QWORD *)(v32 + 40), v34, v33, 1, 0);
          }
          ++v30;
        }
        v31 = *(_QWORD *)v14;
        _qdf_nbuf_free(v14);
        v14 = v31;
      }
      while ( v31 );
    }
    return v14;
  }
  if ( !*(_BYTE *)(a4 + 94) )
  {
    ++*(_QWORD *)(a1 + 536);
    v17 = (*(_BYTE *)(a2 + 68) & 4) != 0 ? *(unsigned __int16 *)(a2 + 66) : 0;
    if ( !*(_BYTE *)(a4 + 94) )
    {
      *(_QWORD *)(a1 + 544) += (unsigned int)(*(_DWORD *)(a2 + 112) + v17);
      v18 = *v12;
      if ( (*v12 & 0xC) == 8 )
        goto LABEL_8;
      if ( !*(_BYTE *)(a4 + 94) )
      {
        ++*(_DWORD *)(a1 + 556);
        goto LABEL_27;
      }
    }
  }
LABEL_56:
  __break(0x5512u);
  return dp_tx_raw_prepare_unset(a1, a2);
}
