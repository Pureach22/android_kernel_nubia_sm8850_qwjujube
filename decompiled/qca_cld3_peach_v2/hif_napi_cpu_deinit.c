__int64 __fastcall hif_napi_cpu_deinit(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 2432) )
    qdf_cpuhp_unregister((_QWORD **)(a1 + 2432));
  memset((void *)(a1 + 880), 0, 0x600u);
  return 0;
}
