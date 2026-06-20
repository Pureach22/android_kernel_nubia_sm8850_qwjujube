void __fastcall lpm_reflect(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  void (__fastcall *v3)(_QWORD); // x9

  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( a2 )
  {
    if ( cluster_gov_ops )
    {
      v3 = *(void (__fastcall **)(_QWORD))(cluster_gov_ops + 24);
      if ( v3 )
      {
        if ( *((_DWORD *)v3 - 1) != 1795193624 )
          __break(0x8229u);
        v3(&lpm_cpu_data[StatusReg]);
      }
    }
  }
}
