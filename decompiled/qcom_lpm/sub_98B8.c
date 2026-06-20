void __usercall sub_98B8(__int64 a1@<X0>, __int64 a2@<X8>)
{
  int v2; // w10
  unsigned int v3; // w19
  __int64 v4; // x20
  __int64 v5; // x29
  __int64 v6; // x21
  __int64 (__fastcall *v7)(__int64, __int64, __int64, _QWORD); // x8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // t1
  __int64 v12; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v4 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v4 + 40))
      & 1) != 0 )
  {
    *(_DWORD *)(v5 - 12) = v2;
    *(_QWORD *)(v5 - 8) = a2;
    ++*(_DWORD *)(v4 + 16);
    v6 = qword_C560;
    if ( qword_C560 )
    {
      do
      {
        v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD))v6;
        v8 = *(_QWORD *)(v6 + 8);
        v9 = *(unsigned int *)(v5 - 12);
        v10 = *(_QWORD *)(v5 - 8);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != -295030581 )
          __break(0x8228u);
        a1 = v7(v8, v9, v10, v3);
        v11 = *(_QWORD *)(v6 + 24);
        v6 += 24;
      }
      while ( v11 );
    }
    v12 = *(_QWORD *)(v4 + 16) - 1LL;
    *(_DWORD *)(v4 + 16) = v12;
    if ( !v12 || !*(_QWORD *)(v4 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x92C4);
}
