__int64 __fastcall adreno_snapshot_gmu_mem(_QWORD *a1, __int64 a2, unsigned __int64 a3, _DWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x9

  if ( !a4 )
    return 0;
  if ( !*(_QWORD *)(*(_QWORD *)a4 + 8LL) )
    return 0;
  if ( *(_QWORD *)(*(_QWORD *)a4 + 40LL) + 28LL > a3 )
  {
    dev_err(*a1, "snapshot: Not enough memory for the gmu section %d\n", a4[2]);
    return 0;
  }
  else
  {
    *(_DWORD *)a2 = a4[2];
    *(_QWORD *)(a2 + 4) = *(_QWORD *)(*(_QWORD *)a4 + 8LL);
    v4 = *(unsigned int *)(*(_QWORD *)a4 + 184LL);
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = v4;
    v5 = *(_QWORD *)a4;
    if ( a4[2] == 7 )
      _memcpy_fromio(a2 + 28, *(_QWORD *)(v5 + 8), *(_QWORD *)(v5 + 40));
    else
      memcpy((void *)(a2 + 28), *(const void **)(*(_QWORD *)a4 + 8LL), *(_QWORD *)(v5 + 40));
    return *(_QWORD *)(*(_QWORD *)a4 + 40LL) + 28LL;
  }
}
