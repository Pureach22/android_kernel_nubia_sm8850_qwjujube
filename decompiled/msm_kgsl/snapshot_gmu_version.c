__int64 __fastcall snapshot_gmu_version(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, _DWORD *a4)
{
  if ( a3 > 0xB )
  {
    *a2 = *a4;
    a2[1] = 1;
    a2[2] = a4[1];
    return 12;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&snapshot_gmu_version__rs, "snapshot_gmu_version") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "GMU Version");
    return 0;
  }
}
