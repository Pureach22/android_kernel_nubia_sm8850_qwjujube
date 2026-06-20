__int64 __fastcall sta_ps_start(__int64 result)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x20
  __int64 v4; // x19
  _DWORD *v5; // x9
  __int64 v6; // x21
  __int64 v7; // x10
  unsigned __int64 v8; // x21
  unsigned __int64 v9; // x1
  unsigned __int64 v15; // x10
  __int64 v16; // x24
  unsigned __int64 *v17; // x8
  unsigned __int64 **v18; // x10
  unsigned __int64 v20; // x10
  unsigned int v23; // w10
  unsigned __int64 v26; // x10

  v1 = *(_QWORD *)(result + 80);
  if ( (unsigned int)(*(_DWORD *)(v1 + 4720) - 3) <= 1 )
  {
    v2 = *(_QWORD *)(v1 + 1616);
    _X9 = *(unsigned __int64 **)(v1 + 2032);
    v4 = result;
    while ( 1 )
    {
      _X9 = (unsigned int *)(_X9 + 37);
      __asm { PRFM            #0x11, [X9] }
      do
        v23 = __ldxr(_X9);
      while ( __stxr(v23 + 1, _X9) );
      _X9 = (unsigned __int64 *)(v4 + 216);
      __asm { PRFM            #0x11, [X9] }
      do
        v26 = __ldxr(_X9);
      while ( __stxr(v26 | 4, _X9) );
      if ( (*(_QWORD *)(v2 + 96) & 0x100000) == 0 )
      {
        if ( v1 && *(_DWORD *)(v1 + 4720) == 4 )
          v1 = *(_QWORD *)(v1 + 2032) - 2264LL;
        if ( (*(_BYTE *)(*(_QWORD *)(v1 + 1616) + 1471LL) & 1) != 0
          || (*(_DWORD *)(v1 + 1624) & 0x20) != 0
          || (drv_sta_notify___already_done & 1) != 0 )
        {
          if ( (*(_BYTE *)(v1 + 1624) & 0x20) != 0 )
            goto LABEL_10;
        }
        else
        {
          v7 = *(_QWORD *)(v1 + 1608);
          drv_sta_notify___already_done = 1;
          v8 = v1;
          if ( v7 )
            v9 = v7 + 296;
          else
            v9 = v1 + 1640;
          _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9);
          v1 = v8;
          __break(0x800u);
          if ( (*(_BYTE *)(v8 + 1624) & 0x20) != 0 )
          {
LABEL_10:
            v5 = *(_DWORD **)(*(_QWORD *)(v2 + 464) + 280LL);
            if ( v5 )
            {
              if ( *(v5 - 1) != -1905637554 )
                __break(0x8229u);
              ((void (__fastcall *)(__int64, unsigned __int64, _QWORD, __int64))v5)(v2, v1 + 4720, 0, v4 + 2688);
            }
          }
        }
      }
      ieee80211_clear_fast_xmit(v4);
      v6 = 0;
      v2 += 308;
      while ( 1 )
      {
        v16 = *(_QWORD *)(v4 + 2736 + 8 * v6);
        v1 = *(unsigned __int8 *)(v16 + 17);
        if ( v1 >= 5 )
          break;
        raw_spin_lock(v2 + 4 * v1);
        _X9 = (unsigned __int64 *)(v16 - 48);
        v17 = *(unsigned __int64 **)(v16 - 48);
        if ( v17 != (unsigned __int64 *)(v16 - 48) )
        {
          v18 = *(unsigned __int64 ***)(v16 - 40);
          if ( *v18 == _X9 && (unsigned __int64 *)v17[1] == _X9 )
          {
            v17[1] = (unsigned __int64)v18;
            *v18 = v17;
          }
          else
          {
            _list_del_entry_valid_or_report(v16 - 48);
          }
          *(_QWORD *)(v16 - 48) = v16 - 48;
          *(_QWORD *)(v16 - 40) = _X9;
        }
        v1 = *(unsigned __int8 *)(v16 + 17);
        if ( v1 > 4 )
          break;
        result = raw_spin_unlock(v2 + 4 * v1);
        if ( *(_QWORD *)(v16 - 32) == v16 - 32 && !*(_DWORD *)(v16 - 124) )
        {
          _X9 = (unsigned __int64 *)(v4 + 432);
          __asm { PRFM            #0x11, [X9] }
          do
            v20 = __ldxr(_X9);
          while ( __stxr(v20 & ~(1LL << v6), _X9) );
        }
        else
        {
          _X9 = (unsigned __int64 *)(v4 + 432);
          __asm { PRFM            #0x11, [X9] }
          do
            v15 = __ldxr(_X9);
          while ( __stxr(v15 | (1LL << v6), _X9) );
        }
        if ( ++v6 == 16 )
          return result;
      }
      __break(0x5512u);
    }
  }
  return result;
}
