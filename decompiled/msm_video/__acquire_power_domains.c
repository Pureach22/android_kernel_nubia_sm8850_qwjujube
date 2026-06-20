__int64 __fastcall _acquire_power_domains(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x20

  if ( is_core_sub_state(a1, 2) )
  {
    v2 = *(_QWORD *)(a1 + 3904);
    v3 = *(_QWORD *)(v2 + 48);
    if ( v3 < v3 + 24LL * *(unsigned int *)(v2 + 56) )
    {
      do
      {
        if ( (*(_BYTE *)(v3 + 17) & 1) != 0 )
        {
          if ( *(_BYTE *)(v3 + 16) == 1 )
            _switch_gdsc_to_swmode(a1, v3);
        }
        else if ( (msm_vidc_debug & 2) != 0 )
        {
          printk(&unk_87AAE, "high", 0xFFFFFFFFLL, "codec", "switch_gdsc_to_swmode");
        }
        v3 += 24LL;
      }
      while ( v3 < *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 48LL)
                 + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 56LL) );
    }
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_826EE, "high", 0xFFFFFFFFLL, "codec", "__acquire_power_domains");
    msm_vidc_change_core_sub_state(a1, 2u, 0, (__int64)"__acquire_power_domains");
  }
  else if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_90294, "high", 0xFFFFFFFFLL, "codec", "__acquire_power_domains");
  }
  return 0;
}
