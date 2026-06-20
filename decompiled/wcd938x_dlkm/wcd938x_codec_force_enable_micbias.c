__int64 __fastcall wcd938x_codec_force_enable_micbias(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x20
  unsigned int v6; // w19

  if ( a3 == 8 || a3 == 1 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) - 184LL) + 152LL);
    wcd938x_wakeup(v5, 1);
    v6 = _wcd938x_codec_enable_micbias(a1, a3);
    wcd938x_wakeup(v5, 0);
  }
  else
  {
    return 0;
  }
  return v6;
}
