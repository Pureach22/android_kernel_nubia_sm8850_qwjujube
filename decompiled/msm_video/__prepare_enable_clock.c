__int64 __fastcall _prepare_enable_clock(__int64 a1, char *s2)
{
  __int64 v2; // x8
  _QWORD *v4; // x19
  _QWORD *v5; // x23
  __int64 v7; // x21
  __int64 result; // x0
  unsigned __int64 v9; // x0
  unsigned int v10; // w0
  unsigned int v11; // w20
  unsigned int v12; // w19
  __int64 v13; // x21

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD **)(v2 + 64);
  v5 = &v4[9 * *(unsigned int *)(v2 + 72)];
  if ( v4 >= v5 )
  {
LABEL_5:
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_95C3D, "err ", 0xFFFFFFFFLL, "codec", "__prepare_enable_clock");
  }
  else
  {
    while ( 1 )
    {
      v7 = *v4;
      if ( !*v4 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_94E32, "err ", 0xFFFFFFFFLL, "codec", "__prepare_enable_clock");
        return 4294967274LL;
      }
      if ( !strcmp((const char *)v4[1], s2) )
        break;
      v4 += 9;
      if ( v4 >= v5 )
        goto LABEL_5;
    }
    if ( *((_BYTE *)v4 + 20) == 1 )
    {
      reset_residency_stats(v4);
      v9 = clk_round_rate(*v4, 0);
      _set_clk_rate(a1, v4, v9 / *(unsigned int *)(*(_QWORD *)(a1 + 3912) + 184LL));
      v7 = *v4;
    }
    result = clk_prepare(v7);
    if ( (_DWORD)result )
      goto LABEL_16;
    v10 = clk_enable(v7);
    if ( v10 )
    {
      v11 = v10;
      clk_unprepare(v7);
      result = v11;
LABEL_16:
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v12 = result;
        printk(&unk_7FDCD, "err ", 0xFFFFFFFFLL, "codec", "__prepare_enable_clock");
        return v12;
      }
      return result;
    }
    if ( (_clk_is_enabled(*v4) & 1) != 0 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_8B967, "high", 0xFFFFFFFFLL, "codec", "__prepare_enable_clock");
      return 0;
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8C4D7, "err ", 0xFFFFFFFFLL, "codec", "__prepare_enable_clock");
    v13 = *v4;
    clk_disable(*v4);
    clk_unprepare(v13);
    if ( *((_BYTE *)v4 + 20) == 1 )
      _set_clk_rate(a1, v4, 0);
  }
  return 4294967274LL;
}
