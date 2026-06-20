__int64 __fastcall dp_peer_find_hash_erase(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v10; // w8
  __int64 result; // x0
  unsigned int v14; // w9
  unsigned int v21; // w9
  __int64 v22; // x21

  v10 = 0;
  do
  {
    result = *(_QWORD *)(*(_QWORD *)(a1 + 13152) + 16LL * v10);
    if ( result )
    {
      do
      {
        v22 = *(_QWORD *)(result + 72);
        *(_DWORD *)(result + 40) = 0;
        *(_DWORD *)(result + 264) = 0;
        *(_DWORD *)(result + 268) = 0;
        *(_DWORD *)(result + 272) = 0;
        *(_DWORD *)(result + 276) = 0;
        *(_DWORD *)(result + 280) = 0;
        *(_DWORD *)(result + 284) = 0;
        *(_DWORD *)(result + 288) = 0;
        *(_DWORD *)(result + 292) = 0;
        *(_DWORD *)(result + 296) = 0;
        *(_DWORD *)(result + 300) = 0;
        *(_DWORD *)(result + 304) = 0;
        *(_DWORD *)(result + 308) = 0;
        *(_DWORD *)(result + 312) = 0;
        *(_DWORD *)(result + 316) = 0;
        *(_DWORD *)(result + 320) = 0;
        *(_DWORD *)(result + 324) = 0;
        *(_DWORD *)(result + 328) = 0;
        *(_DWORD *)(result + 332) = 0;
        *(_DWORD *)(result + 336) = 0;
        *(_DWORD *)(result + 340) = 0;
        *(_DWORD *)(result + 344) = 0;
        *(_DWORD *)(result + 348) = 0;
        *(_DWORD *)(result + 352) = 0;
        *(_DWORD *)(result + 356) = 0;
        *(_DWORD *)(result + 360) = 0;
        *(_DWORD *)(result + 364) = 0;
        *(_DWORD *)(result + 368) = 0;
        *(_DWORD *)(result + 372) = 0;
        *(_DWORD *)(result + 376) = 0;
        *(_DWORD *)(result + 380) = 0;
        *(_DWORD *)(result + 384) = 0;
        _X8 = (unsigned int *)(result + 40);
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 + 1, _X8) );
        _X8 = (unsigned int *)(result + 312);
        __asm { PRFM            #0x11, [X8] }
        do
          v21 = __ldxr(_X8);
        while ( __stxr(v21 + 1, _X8) );
        dp_peer_unref_delete(result, 0xCu, a2, a3, a4, a5, a6, a7, a8, a9);
        result = v22;
      }
      while ( v22 );
      v10 = 31;
    }
    ++v10;
  }
  while ( (unsigned int)v10 <= *(_DWORD *)(a1 + 13144) );
  return result;
}
