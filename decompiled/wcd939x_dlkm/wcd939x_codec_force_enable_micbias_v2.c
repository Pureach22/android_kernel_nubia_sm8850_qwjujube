__int64 __fastcall wcd939x_codec_force_enable_micbias_v2(__int64 a1, int a2, unsigned int a3)
{
  void *v3; // x0
  __int64 v5; // x19
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  unsigned int v10; // w8
  int v11; // w10
  bool v12; // vf
  int v13; // w10

  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_codec_force_enable_micbias_v2__rs, "wcd939x_codec_force_enable_micbias_v2") )
    {
      printk(&unk_19447, "wcd939x_codec_force_enable_micbias_v2");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( a2 != 1 && a2 != 8 )
  {
    if ( (unsigned int)__ratelimit(
                         &wcd939x_codec_force_enable_micbias_v2__rs_11,
                         "wcd939x_codec_force_enable_micbias_v2") )
    {
      v3 = &unk_1A5DD;
      goto LABEL_20;
    }
    return 4294967274LL;
  }
  if ( a3 - 5 <= 0xFFFFFFFB )
  {
    if ( (unsigned int)__ratelimit(
                         &wcd939x_codec_force_enable_micbias_v2__rs_13,
                         "wcd939x_codec_force_enable_micbias_v2") )
    {
      v3 = &unk_19318;
LABEL_20:
      printk(v3, "wcd939x_codec_force_enable_micbias_v2");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( (*(_BYTE *)(v5 + 3216) & 1) != 0
    || (v10 = a3 - 1, a2 != 8)
    || (v11 = *(_DWORD *)(v5 + 72 + 4LL * v10), v12 = __OFSUB__(v11, 1), v13 = v11 - 1, (v13 < 0) ^ v12) )
  {
    if ( a2 == 8 )
    {
      wcd939x_wakeup(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL), 1);
      v7 = v5;
      v8 = a3;
      v9 = 1;
    }
    else
    {
      wcd939x_wakeup(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL), 1);
      v7 = v5;
      v8 = a3;
      v9 = 0;
    }
    wcd939x_enable_micbias(v7, v8, v9);
    wcd939x_wakeup(v5, 0);
    return 0;
  }
  else
  {
    *(_DWORD *)(v5 + 72 + 4LL * v10) = v13;
    return 4294967277LL;
  }
}
