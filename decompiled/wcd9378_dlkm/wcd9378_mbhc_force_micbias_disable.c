__int64 __fastcall wcd9378_mbhc_force_micbias_disable(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  __int64 v6; // x9
  __int64 v7; // x9

  v5 = a2 - 1;
  if ( (unsigned int)(a2 - 1) >= 3 )
  {
    __break(0x5512u);
    return wcd9378_mbhc_zdet_ramp(a1, a2, a3, a4, a5);
  }
  else
  {
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
    if ( *(int *)(v6 + 72 + 4LL * v5) > 1 )
      *(_DWORD *)(v6 + 72 + 4LL * v5) = 1;
    v7 = v6 + 84;
    if ( *(int *)(v7 + 4LL * v5) >= 1 )
      *(_DWORD *)(v7 + 4LL * v5) = 0;
    return wcd9378_micbias_control(a1, a2, 3, 0);
  }
}
