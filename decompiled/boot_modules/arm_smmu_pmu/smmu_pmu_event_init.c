__int64 __fastcall smmu_pmu_event_init(__int64 a1)
{
  __int64 v1; // x8
  int v3; // w9
  __int64 v4; // x10
  __int64 v5; // x10
  __int64 *i; // x12

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(a1 + 216) != *(_DWORD *)(v1 + 64) )
    return 4294967294LL;
  if ( *(_QWORD *)(a1 + 496) )
    return 4294967201LL;
  v3 = *(_DWORD *)(a1 + 668);
  if ( v3 < 0 || (*(_BYTE *)(a1 + 256) & 0xF0) != 0 )
    return 4294967201LL;
  v4 = *(_QWORD *)(a1 + 224);
  if ( (unsigned __int16)v4 <= 0x100u && ((*(_QWORD *)(v1 + 8LL * ((unsigned __int16)v4 >> 6) - 56) >> v4) & 1) != 0 )
  {
    v5 = *(_QWORD *)(a1 + 144);
    if ( *(_QWORD *)(v5 + 152) != v1 && (*(_BYTE *)(v5 + 132) & 1) == 0 )
      return 4294967274LL;
    for ( i = *(__int64 **)(v5 + 16); i != (__int64 *)(v5 + 16); i = (__int64 *)*i )
    {
      if ( i[17] != v1 && (*((_BYTE *)i + 116) & 1) == 0 )
        return 4294967274LL;
    }
    if ( v5 == a1 || v3 == *(_DWORD *)(v5 + 668) )
    {
      *(_DWORD *)(a1 + 396) = -1;
      *(_DWORD *)(a1 + 668) = *(_DWORD *)(v1 - 8);
      return 0;
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(v1 + 320) + 16LL, "Invalid event %d for this PMU\n", (unsigned __int16)v4);
    return 4294967274LL;
  }
}
