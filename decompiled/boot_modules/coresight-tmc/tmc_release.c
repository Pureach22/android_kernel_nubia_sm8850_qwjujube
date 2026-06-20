__int64 __fastcall tmc_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  int v3; // w8
  __int64 v4; // x0

  v2 = *(_QWORD *)(a2 + 32);
  v3 = *(_DWORD *)(v2 + 116);
  v4 = v2 - 24;
  switch ( v3 )
  {
    case 2:
      return tmc_read_unprepare_etb(v4);
    case 1:
      return tmc_read_unprepare_etr(v4);
    case 0:
      return tmc_read_unprepare_etb(v4);
  }
  return 4294967274LL;
}
