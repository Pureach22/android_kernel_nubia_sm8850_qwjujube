__int64 __fastcall rmnet_perf_quickack_force(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x10
  __int64 v4; // x9
  __int64 v6; // x21
  __int64 v7; // x20
  __int64 v8; // x10
  __int64 v9; // x9

  v2 = *(_QWORD *)(a2 + 24);
  if ( v2 )
  {
    if ( ((1 << *(_BYTE *)(v2 + 18)) & 0xFFFFEFBF) != 0
      && *(_BYTE *)(v2 + 18) == 1
      && (*(_QWORD *)(v2 + 96) & 1) == 0
      && *(_QWORD *)(v2 + 112)
      && *(_BYTE *)(v2 + 563) != 3 )
    {
      *(_BYTE *)(v2 + 1328) |= 0x10u;
      v3 = qword_EA28 + 1;
      ++*(_DWORD *)(result + 96);
      qword_EA28 = v3;
    }
    return result;
  }
  v4 = *(_QWORD *)(a2 + 16);
  if ( *(_BYTE *)(result + 68) != 4 )
  {
    v6 = result;
    result = _inet6_lookup_established(
               *(_QWORD *)(v4 + 280),
               &tcp_hashinfo,
               result + 32,
               *(unsigned __int16 *)(result + 64),
               result + 48,
               bswap32(*(unsigned __int16 *)(result + 66)) >> 16,
               *(unsigned int *)(v4 + 224),
               0);
    v7 = result;
    if ( result )
      goto LABEL_10;
LABEL_19:
    v9 = qword_EA18;
    *(_BYTE *)(v6 + 100) = 1;
    *(_BYTE *)(a2 + 42) = 1;
    qword_EA18 = v9 + 1;
    return result;
  }
  v6 = result;
  result = _inet_lookup_established(
             *(_QWORD *)(v4 + 280),
             &tcp_hashinfo,
             *(unsigned int *)(result + 32),
             *(unsigned __int16 *)(result + 64),
             *(unsigned int *)(result + 48),
             bswap32(*(unsigned __int16 *)(result + 66)) >> 16,
             *(unsigned int *)(v4 + 224),
             0);
  v7 = result;
  if ( !result )
    goto LABEL_19;
LABEL_10:
  if ( ((1 << *(_BYTE *)(v7 + 18)) & 0xFFFFEFBF) != 0 )
  {
    raw_spin_lock(v7 + 320);
    if ( *(_BYTE *)(v7 + 18) == 1
      && (*(_QWORD *)(v7 + 96) & 1) == 0
      && *(_QWORD *)(v7 + 112)
      && *(_BYTE *)(v7 + 563) != 3 )
    {
      *(_BYTE *)(v7 + 1328) |= 0x11u;
      v8 = qword_EA20 + 1;
      ++*(_DWORD *)(v6 + 96);
      qword_EA20 = v8;
    }
    raw_spin_unlock(v7 + 320);
  }
  return sock_gen_put(v7);
}
