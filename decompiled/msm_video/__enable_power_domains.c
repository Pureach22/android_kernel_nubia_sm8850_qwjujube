__int64 __fastcall _enable_power_domains(__int64 a1, char *s2)
{
  __int64 result; // x0
  unsigned int v5; // w19
  __int64 v6; // x8
  unsigned __int64 v7; // x25
  unsigned int v8; // w19

  if ( *(_QWORD *)(*(_QWORD *)(a1 + 3912) + 48LL) )
  {
    result = _opp_set_rate(a1, -1);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v5 = result;
        printk(&unk_92878, "err ", 0xFFFFFFFFLL, "codec", "__enable_power_domains");
        return v5;
      }
      return result;
    }
  }
  v6 = *(_QWORD *)(a1 + 3904);
  v7 = *(_QWORD *)(v6 + 48);
  if ( v7 >= v7 + 24LL * *(unsigned int *)(v6 + 56) )
  {
LABEL_13:
    msm_vidc_change_core_sub_state(a1, 0, 2u, (__int64)"__enable_power_domains");
    return 0;
  }
  while ( strcmp(*(const char **)(v7 + 8), s2) || *(_BYTE *)(v7 + 17) != 1 )
  {
LABEL_7:
    v7 += 24LL;
    if ( v7 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 48LL)
             + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 56LL) )
      goto LABEL_13;
  }
  result = _pm_runtime_resume(*(_QWORD *)v7, 4);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_90F1C, "high", 0xFFFFFFFFLL, "codec", "__enable_power_domains");
    goto LABEL_7;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v8 = result;
    printk(&unk_95BB7, "err ", 0xFFFFFFFFLL, "codec", "__enable_power_domains");
    return v8;
  }
  return result;
}
