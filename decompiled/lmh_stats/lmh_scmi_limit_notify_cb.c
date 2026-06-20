__int64 __fastcall lmh_scmi_limit_notify_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  int v6; // w10
  __int64 v7; // x9
  int v8; // w11
  __int64 v9; // x0
  _DWORD *v10; // x8
  __int64 v11; // x10
  __int64 v12; // x10
  unsigned int v13; // w9

  if ( *(_QWORD *)(a1 + 72) )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 32) + 8LL * *(unsigned int *)(a1 + 60)) += sched_clock() - *(_QWORD *)(a1 + 72);
    v5 = sched_clock();
    v6 = *(_DWORD *)(a1 + 64);
    v7 = *(_QWORD *)(a1 + 40);
    *(_QWORD *)(a1 + 72) = v5;
    if ( !v6 )
      goto LABEL_10;
    v8 = 0;
    while ( *(_QWORD *)(a3 + 24) / 0x3E8uLL != *(_DWORD *)(v7 + 4LL * v8) )
    {
      if ( v6 == ++v8 )
        goto LABEL_10;
    }
    if ( v8 == -1 )
    {
LABEL_10:
      v11 = *(unsigned int *)(a1 + 56);
      *(_DWORD *)(a1 + 56) = v11 + 1;
      *(_DWORD *)(v7 + 4 * v11) = *(_QWORD *)(a3 + 24) / 0x3E8uLL;
      v12 = *(_QWORD *)(a1 + 48);
      v13 = *(_DWORD *)(a1 + 56) - 1;
      *(_DWORD *)(a1 + 60) = v13;
      ++*(_DWORD *)(v12 + 4LL * v13);
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)(a1 + 48) + 4LL * v8);
      *(_DWORD *)(a1 + 60) = v8;
    }
  }
  else
  {
    **(_DWORD **)(a1 + 40) = *(_QWORD *)(a3 + 24) / 0x3E8uLL;
    v9 = sched_clock();
    v10 = *(_DWORD **)(a1 + 48);
    *(_QWORD *)(a1 + 72) = v9;
    ++*v10;
    ++*(_DWORD *)(a1 + 56);
  }
  return 0;
}
