__int64 __fastcall _qdf_nbuf_frag_alloc(__int64 a1, __int64 a2, int a3, int a4, __int64 a5, const char *a6, int a7)
{
  int v7; // w9
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x23
  int v14; // w25
  unsigned int v15; // w24
  __int64 result; // x0
  __int64 v17; // x1
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x9
  int v20; // w9
  int v21; // w9
  __int64 v22; // x20
  unsigned int v29; // w9

  v7 = a4 - 1;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( !a4 )
    v7 = 0;
  v11 = a2 + v7;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 16) )
  {
    v14 = 0;
    v15 = 32;
  }
  else
  {
    v15 = 2240;
    v14 = 1;
  }
  result = _netdev_alloc_skb(0, (unsigned int)v11, v15);
  if ( result
    || (!v14 ? (v17 = v15) : (v17 = v15 | 0x400), (result = _alloc_skb((unsigned int)v11, v17, 0, 0xFFFFFFFFLL)) != 0) )
  {
    v18 = *(_QWORD *)(result + 224);
    *(_QWORD *)(result + 72) = 0;
    *(_QWORD *)(result + 80) = 0;
    *(_QWORD *)(result + 56) = 0;
    *(_QWORD *)(result + 64) = 0;
    *(_QWORD *)(result + 40) = 0;
    *(_QWORD *)(result + 48) = 0;
    *(_QWORD *)(result + 16) = 0;
    *(_BYTE *)(result + 68) = 3;
    if ( a4 )
    {
      v19 = v18 % a4;
      if ( v19 )
      {
        v20 = a4 - v19;
        v18 += v20;
        *(_DWORD *)(result + 208) += v20;
      }
    }
    v21 = *(_DWORD *)(result + 208);
    *(_QWORD *)(result + 224) = v18 + a3;
    *(_DWORD *)(result + 208) = v21 + a3;
  }
  else
  {
    v22 = jiffies;
    if ( _qdf_nbuf_frag_alloc___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 2, "NBUF alloc failed %zuB @ %s:%d", v11, a6, a7);
      _qdf_nbuf_frag_alloc___last_ticks = v22;
    }
    _X8 = &dword_716AD0;
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr((unsigned int *)&dword_716AD0);
    while ( __stxr(v29 + 1, (unsigned int *)&dword_716AD0) );
    if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)&alloc_track_timer) != 21 )
      qdf_mc_timer_start((__int64)&alloc_track_timer, 0x1388u);
    return 0;
  }
  return result;
}
