_QWORD *__fastcall dp_tx_mon_generate_cts2self_frm(_QWORD *result, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x20
  __int64 v5; // x24
  unsigned __int8 v6; // w23
  char v7; // w22
  bool v9; // zf
  _WORD *v10; // x22
  _DWORD *v11; // x21
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x8
  unsigned int v15; // w8
  int v16; // w9
  unsigned int v17; // w8
  int v18; // w9
  int v19; // w10

  if ( result )
  {
    v4 = result;
    v5 = result[11945];
    if ( v5 )
    {
      v6 = a4;
      if ( (unsigned __int8)a4 >= 3u )
      {
        __break(0x5512u);
        return (_QWORD *)dp_tx_mon_enqueue_mpdu_nbuf(result, a2, a3, a4);
      }
      v7 = a3;
      result = (_QWORD *)_qdf_nbuf_alloc(
                           *(_QWORD *)(result[1] + 24LL),
                           128,
                           0,
                           4,
                           0,
                           "dp_tx_mon_generate_cts2self_frm",
                           361);
      if ( result )
      {
        v9 = v7 == 0;
        v10 = (_WORD *)result[28];
        v11 = result;
        v12 = v5 + 2576LL * v6;
        if ( v9 )
          v13 = 328;
        else
          v13 = 408;
        qdf_mem_set(v10, 0x80u, 0);
        v14 = *(_QWORD *)(a2 + 76);
        *(_WORD *)(a2 + 140) = 196;
        *(_QWORD *)(a2 + 76) = v14 | 0x200000000000LL;
        *v10 = 196;
        v10[1] = *(_WORD *)(a2 + 138);
        qdf_mem_copy(v10 + 2, (const void *)(v12 + v13 + 39393), 6u);
        v15 = v11[28];
        if ( v15 >= 0xB )
        {
          skb_trim(v11, 10);
LABEL_18:
          result = (_QWORD *)dp_tx_mon_enqueue_mpdu_nbuf(v4, a2, 0, v11);
          *(_DWORD *)(a2 + 28) |= 0x100u;
          return result;
        }
        if ( v11[29] )
        {
          if ( v15 != 10 )
          {
            v16 = 0;
            v17 = 10 - v15;
            goto LABEL_15;
          }
        }
        else
        {
          v19 = v11[52];
          v18 = v11[53];
          v17 = 10 - v15;
          if ( v18 - v19 < v17 )
          {
            v16 = v19 - v18;
LABEL_15:
            if ( (unsigned int)pskb_expand_head(v11, 0, v16 + v17, 2080) )
              dev_kfree_skb_any_reason(v11, 1);
          }
        }
        skb_put(v11, (unsigned int)(10 - v11[28]));
        goto LABEL_18;
      }
    }
  }
  return result;
}
