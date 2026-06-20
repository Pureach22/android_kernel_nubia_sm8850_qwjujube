__int64 __fastcall kgsl_pwrctrl_probe_gdscs(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w20
  __int64 v7; // x8
  _QWORD *v8; // x19
  unsigned int v9; // w20

  result = kgsl_pwrctrl_probe_cx_gdsc();
  if ( !(_DWORD)result )
  {
    result = kgsl_pwrctrl_probe_gx_gdsc(a1, a2);
    if ( (_DWORD)result )
    {
      v5 = *(_QWORD *)(a1 + 9024);
      if ( v5 && v5 != *(_QWORD *)(a1 + 9016) )
      {
        v6 = result;
        dev_pm_domain_detach(*(_QWORD *)(a1 + 9024), 0);
        result = v6;
      }
      v7 = *(_QWORD *)(a1 + 9016);
      v8 = (_QWORD *)(a1 + 9016);
      if ( v7 )
      {
        v9 = result;
        dev_pm_domain_detach(v7, 0);
        result = v9;
      }
      *v8 = 0;
      v8[1] = 0;
    }
  }
  return result;
}
