__int64 __fastcall audio_ext_clk_unprepare(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 - 32);
  if ( result )
  {
    result = pinctrl_select_state(result, *(_QWORD *)(a1 - 24));
    if ( (_DWORD)result )
      return printk(&unk_8B85, "audio_ext_clk_unprepare");
  }
  if ( (unsigned int)(*(_DWORD *)(a1 - 56) - 2) <= 0x11
    && (*(_DWORD *)(a1 - 52) = 0, result = audio_prm_set_lpass_clk_cfg(a1 - 48, 0), (result & 0x80000000) != 0)
    && (result = __ratelimit(&audio_ext_clk_unprepare_rtl, "audio_ext_clk_unprepare"), (_DWORD)result)
    && (result = __ratelimit(&audio_ext_clk_unprepare__rs, "audio_ext_clk_unprepare"), (_DWORD)result) )
  {
    result = printk(&unk_8AD7, "audio_ext_clk_unprepare");
    if ( !*(_QWORD *)(a1 - 8) )
      return result;
  }
  else if ( !*(_QWORD *)(a1 - 8) )
  {
    return result;
  }
  return writel(0);
}
