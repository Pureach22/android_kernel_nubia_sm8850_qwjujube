__int64 __fastcall kgsl_pwrctrl_disable_cx_gdsc(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  void (__fastcall *v3)(__int64, __int64); // x9
  __int64 v4; // x19
  __int64 v5; // x0

  v1 = *(_QWORD *)(result + 9000);
  if ( v1 || *(_QWORD *)(result + 9024) )
  {
    v2 = *(_QWORD *)(result + 88);
    if ( v2 )
    {
      v3 = *(void (__fastcall **)(__int64, __int64))(v2 + 104);
      if ( v3 )
      {
        v4 = result;
        v5 = result + 56;
        if ( *((_DWORD *)v3 - 1) != -1954538307 )
          __break(0x8229u);
        v3(v5, 1);
        v1 = *(_QWORD *)(v4 + 9000);
        result = v4;
      }
    }
    *(_DWORD *)(result + 9080) = 0;
    *(_BYTE *)(result + 9112) = 1;
    if ( v1 )
      return regulator_disable(v1);
    else
      return _pm_runtime_idle(*(_QWORD *)(result + 9024), 4);
  }
  return result;
}
