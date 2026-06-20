__int64 __fastcall sysmon_callback(__int64 a1, _QWORD *a2, int a3, __int64 a4)
{
  if ( !a4 )
    return 4294967274LL;
  if ( a3 >= 8 && *a2 == 0x6B63613A727373LL )
    *(_BYTE *)(a4 + 424) = 1;
  complete(a4 + 248);
  return 0;
}
