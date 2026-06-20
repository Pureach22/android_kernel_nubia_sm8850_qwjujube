void __fastcall sub_9950(__int64 a1)
{
  __int64 v1; // x9
  unsigned int v2; // w11
  int v3; // w14
  __int64 v4; // x19
  __int64 v5; // x22
  __int64 v6; // x29
  __int64 v7; // x26
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64, _QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x3
  __int64 v12; // t1
  __int64 v13; // x8
  unsigned int v14; // [xsp+10h] [xbp+10h]

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v5 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v5 + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v6 - 12) = v3;
    v14 = v2;
    *(_QWORD *)(v6 - 8) = v1;
    ++*(_DWORD *)(v5 + 16);
    v7 = qword_C4C0;
    if ( qword_C4C0 )
    {
      do
      {
        v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD))v7;
        v9 = *(_QWORD *)(v7 + 8);
        v10 = *(unsigned int *)(v6 - 12);
        v11 = *(_QWORD *)(v6 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != 1516842171 )
          __break(0x8228u);
        a1 = v8(v9, v10, v4, v11, v14);
        v12 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v12 );
    }
    v13 = *(_QWORD *)(v5 + 16) - 1LL;
    *(_DWORD *)(v5 + 16) = v13;
    if ( !v13 || !*(_QWORD *)(v5 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x9414);
}
