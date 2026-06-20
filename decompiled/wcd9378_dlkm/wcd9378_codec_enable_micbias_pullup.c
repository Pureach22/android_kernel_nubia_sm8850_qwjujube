__int64 __fastcall wcd9378_codec_enable_micbias_pullup(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x21
  unsigned int v6; // w1
  int v7; // w2

  v4 = *(_QWORD *)(a1 + 40);
  if ( strnstr(*(_QWORD *)(a1 + 8), "VA MIC BIAS1", 13) )
  {
    v6 = 1;
  }
  else if ( strnstr(*(_QWORD *)(a1 + 8), "VA MIC BIAS2", 13) )
  {
    v6 = 2;
  }
  else
  {
    if ( !strnstr(*(_QWORD *)(a1 + 8), "VA MIC BIAS3", 13) )
      return 4294967274LL;
    v6 = 3;
  }
  switch ( a3 )
  {
    case 8:
      v7 = 1;
      goto LABEL_13;
    case 2:
      usleep_range_state(1000, 1100, 2);
      break;
    case 1:
      v7 = 0;
LABEL_13:
      wcd9378_micbias_control(v4 - 208, v6, v7, 1);
      break;
  }
  return 0;
}
