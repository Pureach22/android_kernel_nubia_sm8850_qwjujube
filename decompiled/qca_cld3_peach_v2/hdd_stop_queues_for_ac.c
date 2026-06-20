__int64 __fastcall hdd_stop_queues_for_ac(__int64 result, int a2)
{
  int v2; // w13
  unsigned __int8 v3; // w10
  int v4; // w12
  char v5; // w11
  unsigned int v6; // w8
  unsigned int v7; // w9
  __int64 v8; // x14
  unsigned __int64 v15; // x15

  v2 = *(_DWORD *)(result + 2728);
  v3 = 4 * a2 - 3;
  if ( a2 == 4 )
    v4 = 33;
  else
    v4 = 4;
  if ( a2 == 4 )
    v5 = 13;
  else
    v5 = 4 * a2 - 3;
  v6 = 0;
  if ( v2 == 11 )
    v7 = v4;
  else
    v7 = 4;
  if ( v2 == 11 )
    v3 = v5;
  do
  {
    v8 = *(_QWORD *)(result + 24) + 384LL * v3;
    *(_QWORD *)(v8 + 328) = jiffies;
    __dmb(0xBu);
    _X14 = (unsigned __int64 *)(v8 + 336);
    __asm { PRFM            #0x11, [X14] }
    do
      v15 = __ldxr(_X14);
    while ( __stxr(v15 | 1, _X14) );
    ++v6;
    ++v3;
  }
  while ( v6 < v7 );
  return result;
}
