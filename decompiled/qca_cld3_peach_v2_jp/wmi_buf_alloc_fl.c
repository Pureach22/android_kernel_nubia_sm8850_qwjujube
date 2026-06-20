__int64 __fastcall wmi_buf_alloc_fl(__int64 a1, unsigned int a2, const char *a3, unsigned int a4)
{
  __int64 v4; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w9
  unsigned int v17; // w8
  int v18; // w9
  int v19; // w9
  int v20; // w10

  if ( ((a2 + 3) & 0xFFFFFFFC) <= *(unsigned __int16 *)(a1 + 32) )
  {
    v4 = wbuff_buff_get(*(_QWORD *)(a1 + 16), 16, a2, "wmi_buf_alloc_fl", 1816);
    if ( !v4 )
    {
      v4 = _qdf_nbuf_alloc(0, (a2 + 67) & 0xFFFFFFFC, 64, 4, 0, a3, a4);
      if ( !v4 )
      {
        qdf_trace_msg(0x31u, 2u, "%s:%d, failed to alloc len:%d", v8, v9, v10, v11, v12, v13, v14, v15, a3, a4, a2);
        return v4;
      }
    }
    qdf_mem_set(*(void **)(v4 + 224), a2, 0);
    v16 = *(_DWORD *)(v4 + 112);
    v17 = a2 - v16;
    if ( a2 < v16 )
    {
      skb_trim(v4, a2);
      return v4;
    }
    if ( *(_DWORD *)(v4 + 116) )
    {
      v17 = a2 - v16;
      if ( a2 != v16 )
      {
        v18 = 0;
        goto LABEL_12;
      }
    }
    else
    {
      v20 = *(_DWORD *)(v4 + 208);
      v19 = *(_DWORD *)(v4 + 212);
      if ( v19 - v20 < v17 )
      {
        v18 = v20 - v19;
LABEL_12:
        if ( (unsigned int)pskb_expand_head(v4, 0, v18 + v17, 2080) )
          dev_kfree_skb_any_reason(v4, 1);
      }
    }
    skb_put(v4, a2 - *(_DWORD *)(v4 + 112));
    return v4;
  }
  return 0;
}
