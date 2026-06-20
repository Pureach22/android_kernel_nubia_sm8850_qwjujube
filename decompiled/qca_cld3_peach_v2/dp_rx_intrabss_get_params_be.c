__int64 __fastcall dp_rx_intrabss_get_params_be(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x21
  unsigned int v12; // w9
  unsigned int v19; // w11
  unsigned int v22; // w9

  result = dp_find_peer_by_macaddr(a1, a5, 255, 2);
  if ( result )
  {
    if ( *(_DWORD *)(result + 408) == 1 && (v10 = *(_QWORD *)(result + 416)) != 0 )
    {
      if ( (*(_BYTE *)(v10 + 120) & 1) != 0 )
        goto LABEL_24;
    }
    else
    {
      v10 = result;
      if ( (*(_BYTE *)(result + 120) & 1) != 0 )
        goto LABEL_24;
    }
    v11 = *(_QWORD *)(v10 + 24);
    if ( v11 != a2 )
    {
      if ( !v11
        || *(_DWORD *)(a2 + 104) != *(_DWORD *)(v11 + 104)
        || *(unsigned __int16 *)(a2 + 108) != *(unsigned __int16 *)(v11 + 108) )
      {
        goto LABEL_24;
      }
LABEL_11:
      v12 = *(_DWORD *)(v11 + 43384);
      while ( v12 )
      {
        _X13 = (unsigned int *)(v11 + 43384);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v19 = __ldxr(_X13);
          if ( v19 != v12 )
            break;
          if ( !__stlxr(v12 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v19 == v12;
        v12 = v19;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v11 + 43396);
          __asm { PRFM            #0x11, [X8] }
          do
            v22 = __ldxr(_X8);
          while ( __stxr(v22 + 1, _X8) );
          break;
        }
      }
      dp_peer_unref_delete(result, 2);
      if ( v11 )
      {
        *(_QWORD *)a6 = a1;
        *(_BYTE *)(a6 + 8) = *(_BYTE *)(v11 + 59);
        dp_vdev_unref_delete(a1, v11, 2);
        return 1;
      }
      return 0;
    }
    if ( a2 )
      goto LABEL_11;
LABEL_24:
    dp_peer_unref_delete(result, 2);
    return 0;
  }
  return result;
}
