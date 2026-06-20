__int64 __fastcall dsi_clk_esync_clk_enable(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x21
  unsigned __int64 v6; // x20
  int v7; // w0
  unsigned int v8; // w19

  if ( (unsigned int)a2 < 3 )
  {
    v5 = a1 + 16LL * (unsigned int)a2;
    v6 = *(_QWORD *)(v5 + 312);
    if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_24490E, a2);
      return (unsigned int)-22;
    }
    if ( (*(_BYTE *)(a1 + 440) & 1) == 0 )
    {
      v7 = clk_set_rate(*(_QWORD *)(v5 + 312), *(_QWORD *)(v5 + 320));
      if ( v7 )
      {
        v8 = v7;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: failed to set rate for esync clk, freq = %llu, rc = %d\n",
          *(_QWORD *)(v5 + 320),
          v7);
        return v8;
      }
      v6 = *(_QWORD *)(v5 + 312);
    }
    v8 = clk_prepare(v6);
    if ( !v8 )
    {
      v8 = clk_enable(v6);
      if ( !v8 )
        return v8;
      clk_unprepare(v6);
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable esync_clk, rc=%d\n", v8);
    return v8;
  }
  __break(0x5512u);
  return dsi_display_test_init(a1, a2, a3, a4, a5, *(__int16 *)(a5 + 6446));
}
