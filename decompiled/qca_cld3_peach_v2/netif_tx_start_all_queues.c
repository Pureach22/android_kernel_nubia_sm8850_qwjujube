__int64 __fastcall netif_tx_start_all_queues(__int64 result)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x9
  unsigned __int64 v9; // x12

  if ( *(_DWORD *)(result + 1096) )
  {
    v1 = 0;
    v2 = 336;
    do
    {
      _X11 = (unsigned __int64 *)(*(_QWORD *)(result + 24) + v2);
      __asm { PRFM            #0x11, [X11] }
      do
        v9 = __ldxr(_X11);
      while ( __stxr(v9 & 0xFFFFFFFFFFFFFFFELL, _X11) );
      ++v1;
      v2 += 384;
    }
    while ( v1 < *(unsigned int *)(result + 1096) );
  }
  return result;
}
