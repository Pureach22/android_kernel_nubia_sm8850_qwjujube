__int64 __fastcall _disable_power_domains(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x25
  __int64 result; // x0
  unsigned int v7; // w19
  unsigned int v8; // w19

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD *)(v2 + 48);
  if ( v4 >= v4 + 24LL * *(unsigned int *)(v2 + 56) )
  {
LABEL_9:
    if ( *(_QWORD *)(*(_QWORD *)(a1 + 3912) + 48LL) && (result = _opp_set_rate(a1, 0), (_DWORD)result) )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v7 = result;
        printk(&unk_92878, "err ", 0xFFFFFFFFLL, "codec", "__disable_power_domains");
        return v7;
      }
    }
    else
    {
      msm_vidc_change_core_sub_state(a1, 2u, 0, (__int64)"__disable_power_domains");
      return 0;
    }
    return result;
  }
  while ( strcmp(*(const char **)(v4 + 8), s2) || *(_BYTE *)(v4 + 17) != 1 )
  {
LABEL_3:
    v4 += 24LL;
    if ( v4 >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 48LL)
             + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 56LL) )
      goto LABEL_9;
  }
  result = _pm_runtime_idle(*(_QWORD *)v4, 4);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8A059, "high", 0xFFFFFFFFLL, "codec", "__disable_power_domains");
    goto LABEL_3;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v8 = result;
    printk(&unk_85272, "err ", 0xFFFFFFFFLL, "codec", "__disable_power_domains");
    return v8;
  }
  return result;
}
