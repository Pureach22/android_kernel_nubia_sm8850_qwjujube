__int64 __fastcall _qdf_nbuf_page_frag_alloc(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        __int64 a5,
        const char *a6,
        int a7)
{
  int v9; // w9
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x24
  __int64 v15; // x2
  __int64 v16; // x0
  __int64 v17; // x4
  __int64 v18; // x25
  __int64 result; // x0
  __int64 v20; // x8
  int v21; // w10
  unsigned __int64 v22; // x9
  int v23; // w8
  unsigned __int64 v24; // x10
  int v25; // w10
  __int64 v26; // x26
  __int64 v27; // x24
  unsigned int v34; // w9

  if ( a4 )
    v9 = a4 - 1;
  else
    v9 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v14 = (a2 + v9 + 511) & 0xFFFFFFFFFFFFFFC0LL;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 16) )
  {
    v15 = 2080;
  }
  else
  {
    v15 = 3264;
  }
  v16 = _page_frag_alloc_align(a5, (unsigned int)v14, v15, 0xFFFFFFFFLL);
  if ( v16 )
  {
    v18 = v16;
    result = build_skb(v16, (unsigned int)v14);
    if ( result )
    {
      v20 = *(_QWORD *)(result + 224);
      v21 = *(_DWORD *)(result + 208);
      *(_QWORD *)(result + 40) = 0;
      *(_QWORD *)(result + 48) = 0;
      *(_QWORD *)(result + 56) = 0;
      *(_QWORD *)(result + 64) = 0;
      v22 = v20 + 64;
      v23 = v21 + 64;
      *(_QWORD *)(result + 224) = v22;
      *(_DWORD *)(result + 208) = v21 + 64;
      *(_QWORD *)(result + 72) = 0;
      *(_QWORD *)(result + 80) = 0;
      *(_QWORD *)(result + 16) = 0;
      *(_BYTE *)(result + 68) = 3;
      if ( a4 )
      {
        v24 = v22 % a4;
        if ( v24 )
        {
          v25 = a4 - v24;
          v22 += v25;
          v23 += v25;
        }
      }
      *(_DWORD *)(result + 208) = v23 + a3;
      *(_QWORD *)(result + 224) = v22 + a3;
    }
    else
    {
      page_frag_free(v18);
      v27 = jiffies;
      if ( _qdf_nbuf_page_frag_alloc___last_ticks_8 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(56, 2, "NBUF alloc failed %zuB @ %s:%d", a2 + a4 - 1, a6, a7);
        _qdf_nbuf_page_frag_alloc___last_ticks_8 = v27;
      }
      _X8 = &dword_7CF500;
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr((unsigned int *)&dword_7CF500);
      while ( __stxr(v34 + 1, (unsigned int *)&dword_7CF500) );
      if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)&alloc_track_timer) != 21 )
        qdf_mc_timer_start((__int64)&alloc_track_timer, 0x1388u);
      return 0;
    }
  }
  else
  {
    v26 = jiffies;
    if ( _qdf_nbuf_page_frag_alloc___last_ticks - jiffies + 125 < 0 )
    {
      v16 = qdf_trace_msg(56, 2, "page frag alloc failed %zuB @ %s:%d", v14, a6, a7);
      _qdf_nbuf_page_frag_alloc___last_ticks = v26;
    }
    return _qdf_nbuf_alloc(v16, a2, a3, a4, v17, a6, a7);
  }
  return result;
}
