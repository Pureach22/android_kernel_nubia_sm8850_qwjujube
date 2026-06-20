__int64 __fastcall kgsl_mmu_log_fault_addr(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x22
  __int64 *v6; // x20
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  unsigned int v10; // w19
  unsigned __int64 v11; // x8

  raw_spin_lock(&unk_3A838);
  v5 = a2 & 0xFFFFFFFFFFFFLL;
  v6 = &qword_3A828;
  do
  {
    v6 = (__int64 *)*v6;
    if ( v6 == &qword_3A828 )
    {
      v10 = 0;
      goto LABEL_15;
    }
    v7 = (__int64)(v6 - 1);
    if ( v6 != (__int64 *)&dword_8 )
    {
      v8 = v6[11];
      if ( v8 && (v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 48)) != nullptr )
      {
        if ( *((_DWORD *)v9 - 1) != 1831526433 )
          __break(0x8228u);
        v7 = v9(v7);
      }
      else
      {
        v7 = 0;
      }
    }
  }
  while ( v7 != v5 );
  v11 = a3 & 0xFFFFFFFFFFFFF000LL;
  if ( (a3 & 0xFFFFFFFFFFFFF000LL) == v6[12] )
  {
    v10 = 1;
  }
  else
  {
    v10 = 0;
    v6[12] = v11;
  }
LABEL_15:
  raw_spin_unlock(&unk_3A838);
  return v10;
}
