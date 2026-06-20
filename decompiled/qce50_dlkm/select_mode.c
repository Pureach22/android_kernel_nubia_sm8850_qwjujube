__int64 __fastcall select_mode(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  unsigned int v10; // w8
  int v11; // w8
  unsigned int v12; // w9
  int v13; // w8
  __int64 v14; // x8
  unsigned int v17; // w8
  unsigned int v18; // w8
  int v19; // w9
  __int64 v20; // x9
  int v21; // w8
  __int64 v22; // x8
  unsigned int v25; // w9

  if ( *(_BYTE *)(result + 128) != 1 )
  {
LABEL_25:
    v21 = *(_DWORD *)(a2 + 80);
    if ( v21 )
    {
      v22 = *(_QWORD *)(a2 + 72) + 8LL * (unsigned int)(v21 - 1);
      *(_DWORD *)(v22 + 4) |= 0x80000000;
    }
    return result;
  }
  v3 = result;
  _X21 = result + 69516;
  while ( 2 )
  {
    __asm { PRFM            #0x11, [X21] }
    while ( 1 )
    {
      v10 = __ldxr((unsigned int *)_X21);
      if ( v10 )
        break;
      if ( !__stlxr(1u, (unsigned int *)_X21) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v10 )
    {
      result = _const_udelay(200);
      continue;
    }
    break;
  }
  _X9 = (unsigned int *)(_X21 + 4);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v17 = __ldxr(_X9);
    v18 = v17 + 1;
  }
  while ( __stlxr(v18, _X9) );
  __dmb(0xBu);
  if ( !*(_DWORD *)(_X21 + 676) )
  {
    if ( v18 >= 2 )
    {
      *(_DWORD *)(_X21 + 676) = 1;
      v19 = *(_DWORD *)(a2 + 80);
      if ( v19 )
      {
        v20 = *(_QWORD *)(a2 + 72) + 8LL * (unsigned int)(v19 - 1);
        *(_DWORD *)(v20 + 4) |= 0x80000000;
      }
      *(_DWORD *)(_X21 + 680) = 0;
      *(_DWORD *)(_X21 + 704) = 1;
      *(_DWORD *)(_X21 + 708) = 1;
      return mod_timer(v3 + 69528, jiffies + 5LL);
    }
    goto LABEL_25;
  }
  v11 = *(_DWORD *)(_X21 + 680);
  *(_DWORD *)(_X21 + 680) = v11 + 1;
  v12 = *(_DWORD *)(a2 + 7412) >> 7;
  if ( v12 >= 3 )
    v12 = 3;
  if ( v11 + 1 <= v12 || v11 == v12 && *(_BYTE *)(_X21 + 712) == 1 )
  {
    _X8 = (unsigned int *)(_X21 + 704);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 + 1, _X8) );
  }
  else
  {
    v13 = *(_DWORD *)(a2 + 80);
    if ( v13 )
    {
      v14 = *(_QWORD *)(a2 + 72) + 8LL * (unsigned int)(v13 - 1);
      *(_DWORD *)(v14 + 4) |= 0x80000000;
    }
    *(_DWORD *)(_X21 + 680) = 0;
    *(_DWORD *)(_X21 + 704) = 0;
    *(_DWORD *)(_X21 + 708) = 0;
    *(_BYTE *)(_X21 + 712) ^= 1u;
  }
  return result;
}
