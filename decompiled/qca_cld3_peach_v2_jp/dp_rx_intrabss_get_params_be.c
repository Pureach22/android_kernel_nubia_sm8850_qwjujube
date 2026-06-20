__int64 __fastcall dp_rx_intrabss_get_params_be(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  __int64 v10; // x21
  unsigned int v11; // w9
  unsigned int v18; // w11
  unsigned int v21; // w9

  result = dp_find_peer_by_macaddr(a1, a5, 255, 2);
  if ( result )
  {
    if ( (*(_BYTE *)(result + 120) & 1) == 0 && (v10 = *(_QWORD *)(result + 24), v10 == a2) && v10 )
    {
      v11 = *(_DWORD *)(v10 + 42560);
      while ( v11 )
      {
        _X13 = (unsigned int *)(v10 + 42560);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v18 = __ldxr(_X13);
          if ( v18 != v11 )
            break;
          if ( !__stlxr(v11 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v18 == v11;
        v11 = v18;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v10 + 42572);
          __asm { PRFM            #0x11, [X8] }
          do
            v21 = __ldxr(_X8);
          while ( __stxr(v21 + 1, _X8) );
          break;
        }
      }
      dp_peer_unref_delete(result, 2);
      *(_QWORD *)a6 = a1;
      *(_BYTE *)(a6 + 8) = *(_BYTE *)(v10 + 59);
      dp_vdev_unref_delete(a1, v10, 2);
      return 1;
    }
    else
    {
      dp_peer_unref_delete(result, 2);
      return 0;
    }
  }
  return result;
}
