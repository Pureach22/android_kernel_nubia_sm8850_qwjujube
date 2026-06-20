__int64 __fastcall _reset_control_acquire_name(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x24
  unsigned __int64 v5; // x20
  int v7; // w19
  int v8; // w0
  char *v9; // x1
  void *v10; // x0
  __int64 v11; // x4

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD *)(v2 + 80);
  v5 = v4 + 24LL * *(unsigned int *)(v2 + 88);
  if ( v4 >= v5 )
  {
LABEL_4:
    if ( (msm_vidc_debug & 2) == 0 )
      return 0;
    v10 = &unk_8C43D;
LABEL_18:
    printk(v10, "high", 0xFFFFFFFFLL, "codec", "__reset_control_acquire_name");
    return 0;
  }
  while ( strcmp(*(const char **)(v4 + 8), s2) )
  {
    v4 += 24LL;
    if ( v4 >= v5 )
      goto LABEL_4;
  }
  if ( *(_BYTE *)(v4 + 16) == 1 )
  {
    v7 = 0;
    while ( (unsigned int)reset_control_acquire(*(_QWORD *)v4) )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8F50A, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_acquire_name");
      ++v7;
      v8 = usleep_range_state(1000, 1500, 2);
      if ( v7 == 1000 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v8 = printk(&unk_90EDB, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_acquire_name");
          if ( (msm_vidc_debug & 1) != 0 )
            v8 = printk(&unk_954C1, "err ", 0xFFFFFFFFLL, "codec", v11);
        }
        __break(0x800u);
        return _reset_control_release_name(v8, v9);
      }
    }
    if ( (msm_vidc_debug & 2) == 0 )
      return 0;
    v10 = &unk_88837;
    goto LABEL_18;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_970B4, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_acquire_name");
  return 4294967274LL;
}
