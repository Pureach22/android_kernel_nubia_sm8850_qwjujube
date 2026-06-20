void sub_676CD8()
{
  __int64 v0; // x19
  unsigned int v1; // w20
  unsigned int v2; // w21
  unsigned int v3; // w22
  unsigned int v4; // w23
  __int64 v5; // x24
  unsigned __int64 StatusReg; // x25
  __int64 v7; // x26
  void (__fastcall *v8)(__int64, __int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // t1
  __int64 v11; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v7 = qword_A30620;
    if ( qword_A30620 )
    {
      do
      {
        v8 = *(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, __int64, _QWORD))v7;
        v9 = *(_QWORD *)(v7 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v7 - 4LL) != 566415856 )
          __break(0x8228u);
        v8(v9, v0, v4, v2, v3, v5, v1);
        v10 = *(_QWORD *)(v7 + 24);
        v7 += 24;
      }
      while ( v10 );
    }
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      JUMPOUT(0x676E40);
  }
  JUMPOUT(0x676A90);
}
