__int64 __fastcall extract_pdev_telemetry_stats_tlv(int a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x19

  v3 = *(_QWORD *)(a2 + 144);
  if ( v3 )
  {
    qdf_mem_copy(a3, (const void *)(v3 + 8), 0x10u);
    a3[4] = *(_DWORD *)(v3 + 24);
  }
  return 0;
}
