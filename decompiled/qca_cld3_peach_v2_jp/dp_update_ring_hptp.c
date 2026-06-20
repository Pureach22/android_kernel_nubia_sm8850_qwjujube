__int64 __fastcall dp_update_ring_hptp(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v19; // x9
  unsigned __int64 v22; // x9

  v2 = result;
  if ( (a2 & 1) != 0 )
  {
    if ( *(_BYTE *)(result + 7153) )
    {
      v3 = *(_QWORD *)(result + 6752);
      while ( 1 )
      {
        _X8 = (unsigned __int64 *)(v3 + 176);
        __asm { PRFM            #0x11, [X8] }
        do
          v6 = __ldxr(_X8);
        while ( __stxr(v6 | 2, _X8) );
        result = dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6752));
        if ( *(unsigned __int8 *)(v2 + 7153) < 2u )
          break;
        _X8 = (unsigned __int64 *)(*(_QWORD *)(v2 + 6832) + 176LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v13 = __ldxr(_X8);
        while ( __stxr(v13 | 2, _X8) );
        result = dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6832));
        if ( *(unsigned __int8 *)(v2 + 7153) < 3u )
          break;
        _X8 = (unsigned __int64 *)(*(_QWORD *)(v2 + 6912) + 176LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v16 = __ldxr(_X8);
        while ( __stxr(v16 | 2, _X8) );
        result = dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6912));
        if ( *(unsigned __int8 *)(v2 + 7153) < 4u )
          break;
        _X8 = (unsigned __int64 *)(*(_QWORD *)(v2 + 6992) + 176LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v19 = __ldxr(_X8);
        while ( __stxr(v19 | 2, _X8) );
        result = dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6992));
        if ( *(unsigned __int8 *)(v2 + 7153) < 5u )
          break;
        _X8 = (unsigned __int64 *)(*(_QWORD *)(v2 + 7072) + 176LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v22 = __ldxr(_X8);
        while ( __stxr(v22 | 2, _X8) );
        result = dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 7072));
        v3 = *(unsigned __int8 *)(v2 + 7153);
        if ( (unsigned int)v3 <= 5 )
          break;
LABEL_22:
        __break(0x5512u);
      }
    }
  }
  else
  {
    if ( *(_BYTE *)(result + 7153) )
    {
      dp_flush_ring_hptp(result, *(_QWORD *)(result + 6752));
      if ( *(unsigned __int8 *)(v2 + 7153) > 1u )
      {
        dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6832));
        if ( *(unsigned __int8 *)(v2 + 7153) >= 3u )
        {
          dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6912));
          if ( *(unsigned __int8 *)(v2 + 7153) >= 4u )
          {
            dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6992));
            if ( *(unsigned __int8 *)(v2 + 7153) >= 5u )
            {
              dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 7072));
              v3 = *(unsigned __int8 *)(v2 + 7153);
              if ( (unsigned int)v3 > 5 )
                goto LABEL_22;
            }
          }
        }
      }
    }
    return dp_flush_ring_hptp(v2, *(_QWORD *)(v2 + 6512));
  }
  return result;
}
