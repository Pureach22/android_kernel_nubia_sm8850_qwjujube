__int64 __fastcall ieee80211_agg_splice_packets(__int64 result, __int64 a2, unsigned __int16 a3)
{
  __int64 v3; // x19
  unsigned int v4; // w20
  unsigned __int16 v5; // w21
  __int64 v6; // x22
  _QWORD *v8; // x21
  __int64 v9; // x0
  _QWORD *v10; // x8
  _QWORD *v11; // x11
  __int64 v12; // x9
  _QWORD *v13; // x10
  unsigned int v19; // w9
  unsigned int v20; // w9

  _X8 = ieee802_1d_to_ac[a3 & 7];
  if ( (unsigned int)_X8 >= 4 || (_X8 += result, v4 = *(unsigned __int8 *)(_X8 + 5850), v4 > 0x10) )
  {
    __break(0x5512u);
  }
  else
  {
    v6 = *(_QWORD *)(result + 1616);
    v5 = a3;
    v3 = a2;
    _X8 = v6 + 4LL * *(unsigned __int8 *)(_X8 + 5850) + 2464;
  }
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v19 = __ldxr((unsigned int *)_X8);
    v20 = v19 + 1;
  }
  while ( __stlxr(v20, (unsigned int *)_X8) );
  __dmb(0xBu);
  if ( v20 == 1 )
    result = ieee80211_stop_queue_by_reason(*(_QWORD *)(result + 1616), v4, 3, 0);
  if ( v3 )
  {
    v8 = (_QWORD *)(v3 + 96);
    if ( *(_QWORD *)(v3 + 96) != v3 + 96 )
    {
      v9 = raw_spin_lock_irqsave(v6 + 1312);
      v10 = (_QWORD *)*v8;
      if ( (_QWORD *)*v8 != v8 )
      {
        v11 = *(_QWORD **)(v3 + 104);
        v12 = v6 + 24LL * v4;
        v13 = *(_QWORD **)(v12 + 2008);
        v10[1] = v13;
        *v13 = v10;
        *v11 = v12 + 2000;
        *(_QWORD *)(v12 + 2008) = v11;
        *(_DWORD *)(v12 + 2016) += *(_DWORD *)(v3 + 112);
        *(_QWORD *)(v3 + 96) = v3 + 96;
        *(_QWORD *)(v3 + 104) = v8;
        *(_DWORD *)(v3 + 112) = 0;
      }
      return raw_spin_unlock_irqrestore(v6 + 1312, v9);
    }
  }
  else
  {
    result = _warn_printk("TID %d gone but expected when splicing aggregates from the pending queue\n", v5);
    __break(0x800u);
  }
  return result;
}
