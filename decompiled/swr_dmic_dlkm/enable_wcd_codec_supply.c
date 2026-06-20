__int64 __fastcall enable_wcd_codec_supply(__int64 a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 40);
  if ( v3 )
  {
    if ( (a2 & 1) != 0 )
      v4 = 1;
    else
      v4 = 8;
    return wcd939x_codec_force_enable_micbias_v2(v3, v4, *(unsigned int *)(a1 + 48));
  }
  else
  {
    result = __ratelimit(&enable_wcd_codec_supply__rs, "enable_wcd_codec_supply");
    if ( (_DWORD)result )
      return printk(&unk_7DE9, "enable_wcd_codec_supply");
  }
  return result;
}
