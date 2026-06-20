__int64 __fastcall _qdf_nbuf_page_pool_alloc(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        __int64 a5,
        _DWORD *a6,
        const char *a7,
        int a8)
{
  int v8; // w8
  unsigned __int64 v15; // x23
  __int64 v16; // x0
  __int64 v17; // x26
  __int64 result; // x0
  char v19; // w8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x9
  int v22; // w9
  int v23; // w9
  __int64 v24; // x22
  __int64 v25; // x22

  v8 = a4 - 1;
  if ( !a4 )
    v8 = 0;
  *a6 = 0;
  v15 = ((a2 + v8 + 63) & 0xFFFFFFFFFFFFFFC0LL) + 384;
  v16 = _qdf_page_pool_alloc_frag(a5, a6, v15);
  if ( !v16 )
  {
    v24 = jiffies;
    if ( _qdf_nbuf_page_pool_alloc___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 2, "failed to alloc page pool buffer %zuB @ %s:%d", v15, a7, a8);
      _qdf_nbuf_page_pool_alloc___last_ticks = v24;
      return 0;
    }
    return 0;
  }
  v17 = v16;
  result = napi_build_skb(
             (((v16 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + (unsigned int)*a6,
             (unsigned int)v15);
  if ( !result )
  {
    _qdf_page_pool_put_page(a5, v17, 0);
    v25 = jiffies;
    if ( _qdf_nbuf_page_pool_alloc___last_ticks_10 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 2, "failed to build skb %zuB @ %s:%d", v15, a7, a8);
      _qdf_nbuf_page_pool_alloc___last_ticks_10 = v25;
      return 0;
    }
    return 0;
  }
  v19 = *(_BYTE *)(result + 126);
  *(_QWORD *)(result + 40) = 0;
  *(_QWORD *)(result + 48) = 0;
  *(_QWORD *)(result + 56) = 0;
  *(_QWORD *)(result + 64) = 0;
  *(_QWORD *)(result + 72) = 0;
  *(_QWORD *)(result + 80) = 0;
  *(_BYTE *)(result + 126) = v19 | 0x80;
  v20 = *(_QWORD *)(result + 224);
  *(_QWORD *)(result + 16) = 0;
  *(_BYTE *)(result + 68) = 3;
  if ( a4 )
  {
    v21 = v20 % a4;
    if ( v21 )
    {
      v22 = a4 - v21;
      v20 += v22;
      *(_DWORD *)(result + 208) += v22;
    }
  }
  v23 = *(_DWORD *)(result + 208);
  *(_QWORD *)(result + 224) = v20 + a3;
  *(_DWORD *)(result + 208) = v23 + a3;
  return result;
}
