void sub_90D8()
{
  unsigned int v0; // w19
  unsigned int v1; // w20
  unsigned int v2; // w21
  __int64 v3; // x22
  unsigned int v4; // w23
  unsigned __int64 StatusReg; // x24
  __int64 v6; // x25
  void (__fastcall *v7)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD); // x8
  __int64 v8; // x0
  __int64 v9; // t1
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = qword_B0F8;
    if ( qword_B0F8 )
    {
      do
      {
        v7 = *(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v6;
        v8 = *(_QWORD *)(v6 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v6 - 4LL) != -451664855 )
          __break(0x8228u);
        v7(v8, v3 + 4, v0, v1, v2, v4);
        v9 = *(_QWORD *)(v6 + 24);
        v6 += 24;
      }
      while ( v9 );
    }
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  JUMPOUT(0x909C);
}
