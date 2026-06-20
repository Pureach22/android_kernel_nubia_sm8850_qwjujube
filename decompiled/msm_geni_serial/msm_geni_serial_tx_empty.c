bool __fastcall msm_geni_serial_tx_empty(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  int v3; // w0

  v1 = *(_QWORD *)(a1 + 264);
  if ( !v1 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v1 + 74) )
  {
    v2 = *(_QWORD *)(a1 + 344);
    if ( *(_DWORD *)(v2 + 500) )
    {
      if ( (*(_WORD *)(v2 + 488) & 7) == 0 )
        return 1;
    }
  }
  if ( *(_DWORD *)(a1 + 584) == 2 )
    v3 = *(_QWORD *)(a1 + 808) != 0;
  else
    v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 2048LL));
  return v3 == 0;
}
