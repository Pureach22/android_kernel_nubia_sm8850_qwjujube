__int64 __fastcall dbglog_block_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x9

  v2 = *(_QWORD *)(a1 + 696);
  if ( (*(_BYTE *)(v2 + 56) & 1) != 0 )
    return 4294967280LL;
  *(_BYTE *)(v2 + 56) = 1;
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 696);
  return 0;
}
