__int64 __fastcall zram_open(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 88);
  if ( (mutex_is_locked(a1 + 360) & 1) == 0 )
    __break(0x800u);
  if ( *(_BYTE *)(v1 + 233) )
    return 4294967280LL;
  else
    return 0;
}
