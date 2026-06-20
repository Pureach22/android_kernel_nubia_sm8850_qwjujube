void __usercall sub_E074(
        __int64 a1@<X0>,
        unsigned int a2@<W8>,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x21
  __int64 v8; // x22
  unsigned int v9; // w23
  unsigned int v10; // w24
  __int64 v11; // x25
  __int64 v12; // x19
  __int64 (__fastcall *v13)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD); // x8
  __int64 v14; // x0
  __int64 v15; // t1
  __int64 v16; // x8

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v11 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v11 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v11 + 16);
    v12 = qword_11098;
    if ( qword_11098 )
    {
      do
      {
        v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v12;
        v14 = *(_QWORD *)(v12 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v12 - 4LL) != -90469204 )
          __break(0x8228u);
        a1 = v13(v14, a4, v7, v8, v10, v9, a2);
        v15 = *(_QWORD *)(v12 + 24);
        v12 += 24;
      }
      while ( v15 );
    }
    v16 = *(_QWORD *)(a7 + 16) - 1LL;
    *(_DWORD *)(a7 + 16) = v16;
    if ( !v16 || !*(_QWORD *)(a7 + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0xDE84);
}
