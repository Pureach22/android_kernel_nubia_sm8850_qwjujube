__int64 __fastcall _acquire_regulators(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x20

  if ( is_core_sub_state(a1, 2) )
  {
    v2 = *(_QWORD *)(a1 + 3904);
    v3 = *(_QWORD *)(v2 + 32);
    if ( v3 < v3 + 24LL * *(unsigned int *)(v2 + 40) )
    {
      do
      {
        if ( *(_BYTE *)(v3 + 16) == 1 )
        {
          _acquire_regulator(v3);
          v2 = *(_QWORD *)(a1 + 3904);
        }
        v3 += 24LL;
      }
      while ( v3 < *(_QWORD *)(v2 + 32) + 24 * (unsigned __int64)*(unsigned int *)(v2 + 40) );
    }
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8EA3C, "high", 0xFFFFFFFFLL, "codec", "__acquire_regulators");
    msm_vidc_change_core_sub_state(a1, 2u, 0, (__int64)"__acquire_regulators");
  }
  else if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_8DD3B, "high", 0xFFFFFFFFLL, "codec", "__acquire_regulators");
  }
  return 0;
}
