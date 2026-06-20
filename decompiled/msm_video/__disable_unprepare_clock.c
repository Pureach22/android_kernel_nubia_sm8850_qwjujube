__int64 __fastcall _disable_unprepare_clock(__int64 a1, char *s2)
{
  __int64 v2; // x8
  __int64 *v4; // x19
  unsigned __int64 v5; // x23
  __int64 v7; // x22
  void *v8; // x0

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(__int64 **)(v2 + 64);
  v5 = (unsigned __int64)&v4[9 * *(unsigned int *)(v2 + 72)];
  if ( (unsigned __int64)v4 < v5 )
  {
    while ( 1 )
    {
      v7 = *v4;
      if ( !*v4 )
        break;
      if ( !strcmp((const char *)v4[1], s2) )
      {
        clk_disable(v7);
        clk_unprepare(v7);
        if ( *((_BYTE *)v4 + 20) == 1 )
          _set_clk_rate(a1, v4, 0);
        v4[3] = 0;
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_91B39, "high", 0xFFFFFFFFLL, "codec", "__disable_unprepare_clock");
        return 0;
      }
      v4 += 9;
      if ( (unsigned __int64)v4 >= v5 )
        goto LABEL_5;
    }
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v8 = &unk_97BAF;
    goto LABEL_9;
  }
LABEL_5:
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v8 = &unk_95C3D;
LABEL_9:
    printk(v8, "err ", 0xFFFFFFFFLL, "codec", "__disable_unprepare_clock");
  }
  return 4294967274LL;
}
