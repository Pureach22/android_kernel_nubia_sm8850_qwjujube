__int64 __fastcall _wcd938x_codec_enable_micbias(__int64 a1, int a2)
{
  __int64 v3; // x21
  int v5; // w1
  int v6; // w2

  v3 = *(_QWORD *)(a1 + 40);
  if ( strnstr(*(_QWORD *)(a1 + 8), "MIC BIAS1", 10) )
  {
    v5 = 1;
  }
  else if ( strnstr(*(_QWORD *)(a1 + 8), "MIC BIAS2", 10) )
  {
    v5 = 2;
  }
  else if ( strnstr(*(_QWORD *)(a1 + 8), "MIC BIAS3", 10) )
  {
    v5 = 3;
  }
  else
  {
    if ( !strnstr(*(_QWORD *)(a1 + 8), "MIC BIAS4", 10) )
      return 4294967274LL;
    v5 = 4;
  }
  switch ( a2 )
  {
    case 8:
      v6 = 3;
      goto LABEL_15;
    case 2:
      usleep_range_state(1000, 1100, 2);
      break;
    case 1:
      v6 = 2;
LABEL_15:
      wcd938x_micbias_control(v3 - 208, v5, v6, 1);
      break;
  }
  return 0;
}
