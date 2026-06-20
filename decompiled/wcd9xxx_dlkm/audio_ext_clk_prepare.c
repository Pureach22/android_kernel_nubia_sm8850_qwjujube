__int64 __fastcall audio_ext_clk_prepare(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v4; // w0
  unsigned int v5; // w19

  if ( (unsigned int)(*(_DWORD *)(a1 - 56) - 2) > 0x11 || *(_DWORD *)(a1 - 52) )
  {
    v2 = *(_QWORD *)(a1 - 32);
    if ( v2 )
      goto LABEL_4;
    goto LABEL_5;
  }
  v4 = audio_prm_set_lpass_clk_cfg(a1 - 48, 1);
  if ( (v4 & 0x80000000) == 0 )
  {
    *(_DWORD *)(a1 - 52) = 1;
    v2 = *(_QWORD *)(a1 - 32);
    if ( v2 )
    {
LABEL_4:
      if ( (unsigned int)pinctrl_select_state(v2, *(_QWORD *)(a1 - 16)) )
      {
        printk(&unk_8B85, "audio_ext_clk_prepare");
        return 4294967291LL;
      }
    }
LABEL_5:
    if ( *(_QWORD *)(a1 - 8) )
      writel(1);
    return 0;
  }
  v5 = v4;
  if ( !(unsigned int)__ratelimit(&audio_ext_clk_prepare_rtl, "audio_ext_clk_prepare")
    || !(unsigned int)__ratelimit(&audio_ext_clk_prepare__rs, "audio_ext_clk_prepare") )
  {
    return v5;
  }
  printk(&unk_8D0A, "audio_ext_clk_prepare");
  return v5;
}
