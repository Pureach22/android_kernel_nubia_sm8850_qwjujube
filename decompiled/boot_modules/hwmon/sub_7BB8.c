void __usercall sub_7BB8(__int64 a1@<X8>)
{
  unsigned int v1; // w9
  __int64 v2; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v4; // x22
  void (__fastcall *v5)(__int64, _QWORD, __int64, __int64); // x8
  __int64 v6; // x0
  __int64 v7; // t1
  __int64 v8; // x8
  unsigned int v10; // [xsp+Ch] [xbp+Ch]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v10 = v1;
    ++*(_DWORD *)(StatusReg + 16);
    v4 = qword_86B0;
    if ( qword_86B0 )
    {
      do
      {
        v5 = *(void (__fastcall **)(__int64, _QWORD, __int64, __int64))v4;
        v6 = *(_QWORD *)(v4 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v4 - 4LL) != 551358637 )
          __break(0x8228u);
        v5(v6, v10, v2 + 52, a1);
        v7 = *(_QWORD *)(v4 + 24);
        v4 += 24;
      }
      while ( v7 );
    }
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0x7B70);
}
