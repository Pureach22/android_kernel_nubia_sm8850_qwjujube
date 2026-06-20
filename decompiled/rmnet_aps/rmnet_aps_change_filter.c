__int64 __fastcall rmnet_aps_change_filter(__int64 *a1, __int64 a2)
{
  __int64 *v2; // x19
  unsigned __int64 v5; // x0
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9
  int v13; // w8
  __int64 v14; // x9
  char v15; // w9
  char v16; // w8

  v2 = a1;
  do
  {
    v2 = (__int64 *)*v2;
    if ( v2 == a1 )
      return 4294967274LL;
  }
  while ( *((_DWORD *)v2 + 9) != *(_DWORD *)(a2 + 4) );
  if ( v2 == qword_10 || *(_DWORD *)a2 != 6 || v2[7] )
    return 4294967274LL;
  v5 = _kmalloc_cache_noprof(preempt_schedule_notrace, 3520, 144);
  if ( !v5 )
    return 4294967284LL;
  v6 = *(_QWORD *)(a2 + 104);
  *(_QWORD *)(v5 + 112) = *(_QWORD *)(a2 + 96);
  *(_QWORD *)(v5 + 120) = v6;
  v7 = *(_QWORD *)(a2 + 120);
  *(_QWORD *)(v5 + 128) = *(_QWORD *)(a2 + 112);
  *(_QWORD *)(v5 + 136) = v7;
  v8 = *(_QWORD *)(a2 + 72);
  *(_QWORD *)(v5 + 80) = *(_QWORD *)(a2 + 64);
  *(_QWORD *)(v5 + 88) = v8;
  v9 = *(_QWORD *)(a2 + 88);
  *(_QWORD *)(v5 + 96) = *(_QWORD *)(a2 + 80);
  *(_QWORD *)(v5 + 104) = v9;
  v10 = *(_QWORD *)(a2 + 40);
  *(_QWORD *)(v5 + 48) = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(v5 + 56) = v10;
  v11 = *(_QWORD *)(a2 + 56);
  *(_QWORD *)(v5 + 64) = *(_QWORD *)(a2 + 48);
  *(_QWORD *)(v5 + 72) = v11;
  v12 = *(_QWORD *)(a2 + 8);
  v13 = *(unsigned __int8 *)(v5 + 72);
  *(_QWORD *)(v5 + 16) = *(_QWORD *)a2;
  *(_QWORD *)(v5 + 24) = v12;
  v14 = *(_QWORD *)(a2 + 24);
  *(_QWORD *)(v5 + 32) = *(_QWORD *)(a2 + 16);
  *(_QWORD *)(v5 + 40) = v14;
  if ( v13 )
  {
    v15 = *(_BYTE *)(v5 + 73);
    if ( !v15 )
    {
      v15 = -1;
      *(_BYTE *)(v5 + 73) = -1;
    }
    *(_BYTE *)(v5 + 72) = v13 & v15;
  }
  v16 = *(_BYTE *)(v5 + 75);
  if ( (v16 & 1) != 0 && !*(_DWORD *)(v5 + 76) )
  {
    *(_QWORD *)(v5 + 76) = -1;
    *(_QWORD *)(v5 + 84) = -1;
  }
  if ( (v16 & 2) != 0 && !*(_DWORD *)(v5 + 92) )
  {
    *(_QWORD *)(v5 + 92) = -1;
    *(_QWORD *)(v5 + 100) = -1;
  }
  if ( !*(_WORD *)(v5 + 108) )
    *(_WORD *)(v5 + 108) = *(_WORD *)(v5 + 64);
  if ( !*(_WORD *)(v5 + 110) )
    *(_WORD *)(v5 + 110) = *(_WORD *)(v5 + 66);
  atomic_store(v5, (unsigned __int64 *)v2 + 7);
  return 0;
}
