void __fastcall sub_153AC(__int64 a1)
{
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24
  __int64 (__fastcall *v3)(__int64, const char *); // x8
  __int64 v4; // x0
  __int64 v5; // t1
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v2 = qword_22A60;
    if ( qword_22A60 )
    {
      do
      {
        v3 = *(__int64 (__fastcall **)(__int64, const char *))v2;
        v4 = *(_QWORD *)(v2 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v2 - 4LL) != -110690895 )
          __break(0x8228u);
        a1 = v3(v4, "wakeup_task: begin");
        v5 = *(_QWORD *)(v2 + 24);
        v2 += 24;
      }
      while ( v5 );
    }
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x14D28);
}
