__int64 __fastcall adreno_prepare_preib_preempt_scratch(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v5; // x8
  __int64 v6; // x9

  v3 = *(_QWORD *)(a2 + 272);
  if ( !v3 )
    return 0;
  v5 = *(_QWORD *)(v3 + 32);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 20496) + 24LL) + 8LL * *(int *)(*(_QWORD *)(a2 + 1536) + 28LL);
  *(_DWORD *)a3 = 1883045892;
  *(_QWORD *)(a3 + 4) = v6;
  *(_QWORD *)(a3 + 12) = v5;
  return 5;
}
