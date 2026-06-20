__int64 __fastcall _qdf_nbuf_alloc(__int64 a1, __int64 a2, int a3, int a4, __int64 a5, const char *a6, int a7)
{
  int v7; // w9
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x23
  __int64 v14; // x1
  __int64 result; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  int v18; // w9
  int v19; // w9
  __int64 v20; // x24
  unsigned int v27; // w9

  v7 = a4 - 1;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( !a4 )
    v7 = 0;
  v11 = a2 + v7;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 16) )
  {
    v14 = 2080;
  }
  else
  {
    v14 = 3264;
  }
  result = _alloc_skb((unsigned int)v11, v14, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v16 = *(_QWORD *)(result + 224);
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
      v17 = v16 % a4;
      if ( v17 )
      {
        v18 = a4 - v17;
        v16 += v18;
        *(_DWORD *)(result + 208) += v18;
      }
    }
    v19 = *(_DWORD *)(result + 208);
    *(_QWORD *)(result + 224) = v16 + a3;
    *(_DWORD *)(result + 208) = v19 + a3;
  }
  else
  {
    v20 = jiffies;
    if ( _qdf_nbuf_alloc___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 2, "NBUF alloc failed %zuB @ %s:%d", v11, a6, a7);
      _qdf_nbuf_alloc___last_ticks = v20;
    }
    _X8 = &dword_716AD0;
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr((unsigned int *)&dword_716AD0);
    while ( __stxr(v27 + 1, (unsigned int *)&dword_716AD0) );
    _ZF = (unsigned int)qdf_mc_timer_get_current_state((__int64)&alloc_track_timer) == 21;
    result = 0;
    if ( !_ZF )
    {
      qdf_mc_timer_start((__int64)&alloc_track_timer, 0x1388u);
      return 0;
    }
  }
  return result;
}
