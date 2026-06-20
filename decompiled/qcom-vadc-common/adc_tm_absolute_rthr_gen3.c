__int64 __fastcall adc_tm_absolute_rthr_gen3(__int64 a1)
{
  __int64 v3; // x9

  v3 = 28900LL * *(_QWORD *)(a1 + 16) / 1875000;
  *(_QWORD *)(a1 + 8) = 28900LL * *(_QWORD *)(a1 + 8) / 1875000;
  *(_QWORD *)(a1 + 16) = v3;
  return 0;
}
