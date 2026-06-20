void __usercall sub_72D650(unsigned int a1@<W8>)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  unsigned int v3; // w23
  __int64 v4; // x24
  unsigned __int64 StatusReg; // x25
  __int64 v7; // x22
  __int64 v8; // x24
  void (__fastcall *v9)(__int64, __int64, _QWORD, _QWORD, _QWORD, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // t1
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v7 = v4;
    ++*(_DWORD *)(StatusReg + 16);
    v8 = qword_B361E0;
    if ( qword_B361E0 )
    {
      do
      {
        v9 = *(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD, __int64))v8;
        v10 = *(_QWORD *)(v8 + 8);
        if ( *(_DWORD *)(*(_QWORD *)v8 - 4LL) != -1556693890 )
          __break(0x8228u);
        v9(v10, v1, v3, a1, v2, v7);
        v11 = *(_QWORD *)(v8 + 24);
        v8 += 24;
      }
      while ( v11 );
    }
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      JUMPOUT(0x72D9AC);
  }
  JUMPOUT(0x72D5FC);
}
