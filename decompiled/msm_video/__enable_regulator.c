__int64 __fastcall _enable_regulator(__int64 a1, char *s2)
{
  __int64 v2; // x8
  _QWORD *v4; // x21
  _QWORD *v5; // x22
  __int64 v6; // x20
  void *v7; // x0
  __int64 result; // x0
  unsigned int v9; // w19

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD **)(v2 + 32);
  v5 = &v4[3 * *(unsigned int *)(v2 + 40)];
  if ( v4 >= v5 )
  {
LABEL_5:
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v7 = &unk_87B72;
LABEL_9:
      printk(v7, "err ", 0xFFFFFFFFLL, "codec", "__enable_regulator");
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = *v4;
      if ( !*v4 )
      {
        if ( (msm_vidc_debug & 1) == 0 )
          return 4294967274LL;
        v7 = &unk_83B4F;
        goto LABEL_9;
      }
      if ( !strcmp((const char *)v4[1], s2) )
        break;
      v4 += 3;
      if ( v4 >= v5 )
        goto LABEL_5;
    }
    result = regulator_enable(v6);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v9 = result;
        printk(&unk_8ACE1, "err ", 0xFFFFFFFFLL, "codec", "__enable_regulator");
        return v9;
      }
      return result;
    }
    if ( (unsigned int)regulator_is_enabled(*v4) )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_97207, "high", 0xFFFFFFFFLL, "codec", "__enable_regulator");
      return 0;
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8197A, "err ", 0xFFFFFFFFLL, "codec", "__enable_regulator");
    regulator_disable(*v4);
  }
  return 4294967274LL;
}
