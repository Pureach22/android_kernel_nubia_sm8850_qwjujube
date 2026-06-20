__int64 __fastcall _hand_off_power_domains(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x28
  int v4; // w27
  __int64 v5; // x8
  _DWORD *v6; // x8
  unsigned int v7; // w0
  unsigned int v9; // w21
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x20

  if ( is_core_sub_state(a1, 2) )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_87A64, "high", 0xFFFFFFFFLL, "codec", "__hand_off_power_domains");
    return 0;
  }
  v2 = *(_QWORD *)(a1 + 3904);
  v3 = *(_QWORD *)(v2 + 48);
  if ( v3 >= v3 + 24LL * *(unsigned int *)(v2 + 56) )
  {
LABEL_23:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8E9B9, "high", 0xFFFFFFFFLL, "codec", "__hand_off_power_domains");
    msm_vidc_change_core_sub_state(a1, 0, 2u, (__int64)"__hand_off_power_domains");
    return 0;
  }
  v4 = 0;
  while ( 1 )
  {
    if ( (*(_BYTE *)(v3 + 17) & 1) == 0 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_87AAE, "high", 0xFFFFFFFFLL, "codec", "switch_gdsc_to_hwmode");
      goto LABEL_8;
    }
    if ( *(_BYTE *)(v3 + 16) == 1 )
      break;
LABEL_8:
    v3 += 24LL;
    if ( v3 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 48LL)
             + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 56LL) )
      goto LABEL_23;
  }
  v5 = *(_QWORD *)(a1 + 6544);
  if ( v5 && (v6 = *(_DWORD **)(v5 + 64)) != nullptr )
  {
    if ( !a1 )
    {
      if ( (msm_vidc_debug & 2) == 0 )
        goto LABEL_20;
      goto LABEL_22;
    }
    if ( *(v6 - 1) != -254569353 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(__int64, _QWORD))v6)(a1, 0);
  }
  else
  {
    v7 = dev_pm_genpd_set_hwmode(*(_QWORD *)v3, 1);
  }
  if ( (v7 & 0x80000000) == 0 )
  {
    if ( (msm_vidc_debug & 2) == 0 )
    {
LABEL_20:
      ++v4;
      goto LABEL_8;
    }
LABEL_22:
    printk(&unk_971C4, "high", 0xFFFFFFFFLL, "codec", "__switch_gdsc_to_hwmode");
    goto LABEL_20;
  }
  v9 = v7;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_93F4E, "err ", 0xFFFFFFFFLL, "codec", "__switch_gdsc_to_hwmode");
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 48LL);
  v11 = v10 + 24LL * v4;
  if ( v11 >= v10 )
  {
    do
    {
      _switch_gdsc_to_swmode(a1, v11);
      v11 -= 24LL;
    }
    while ( v11 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 48LL) );
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_95BEE, "err ", 0xFFFFFFFFLL, "codec", "__hand_off_power_domains");
  return v9;
}
