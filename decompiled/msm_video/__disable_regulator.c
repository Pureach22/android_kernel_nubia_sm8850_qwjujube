__int64 __fastcall _disable_regulator(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x19
  unsigned __int64 v5; // x22
  void *v7; // x0
  __int64 result; // x0
  unsigned int v9; // w19
  unsigned int v10; // w19

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD *)(v2 + 32);
  v5 = v4 + 24LL * *(unsigned int *)(v2 + 40);
  if ( v4 < v5 )
  {
    while ( *(_QWORD *)v4 )
    {
      if ( !strcmp(*(const char **)(v4 + 8), s2) )
      {
        result = _acquire_regulator(v4);
        if ( (_DWORD)result )
        {
          if ( (msm_vidc_debug & 1) != 0 )
          {
            v10 = result;
            printk(&unk_91B75, "err ", 0xFFFFFFFFLL, "codec", "__disable_regulator");
            result = v10;
          }
          __break(0x800u);
        }
        else
        {
          msm_vidc_change_core_sub_state(a1, 2u, 0, (__int64)"__disable_regulator");
          result = regulator_disable(*(_QWORD *)v4);
          if ( (_DWORD)result )
          {
            if ( (msm_vidc_debug & 1) != 0 )
            {
              v9 = result;
              printk(&unk_8462E, "err ", 0xFFFFFFFFLL, "codec", "__disable_regulator");
              return v9;
            }
          }
          else
          {
            if ( (msm_vidc_debug & 2) != 0 )
              printk(&unk_93F9E, "high", 0xFFFFFFFFLL, "codec", "__disable_regulator");
            return 0;
          }
        }
        return result;
      }
      v4 += 24LL;
      if ( v4 >= v5 )
        goto LABEL_5;
    }
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v7 = &unk_83B4F;
    goto LABEL_9;
  }
LABEL_5:
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v7 = &unk_87B72;
LABEL_9:
    printk(v7, "err ", 0xFFFFFFFFLL, "codec", "__disable_regulator");
  }
  return 4294967274LL;
}
