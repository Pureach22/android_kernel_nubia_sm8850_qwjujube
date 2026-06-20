void __fastcall sub_17A30(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  unsigned __int64 StatusReg; // x27
  __int64 v15; // x24
  void (__fastcall *v16)(__int64, const char *); // x8
  __int64 v17; // x0
  __int64 v18; // t1
  __int64 v19; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v15 = qword_22A60;
    if ( qword_22A60 )
    {
      do
      {
        v16 = *(void (__fastcall **)(__int64, const char *))v15;
        v17 = *(_QWORD *)(v15 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v15 - 4LL) != -110690895 )
          __break(0x8228u);
        v16(v17, "context_alloc: end");
        v18 = *(_QWORD *)(v15 + 24);
        v15 += 24;
      }
      while ( v18 );
    }
    v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v19;
    if ( !v19 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(HIDWORD(a14));
  }
  JUMPOUT(0x17714);
}
