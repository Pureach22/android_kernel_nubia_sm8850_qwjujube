unsigned __int64 __fastcall cpucp_pmu_init(__int64 a1)
{
  __int64 v1; // x9
  unsigned __int64 result; // x0
  __int64 (__fastcall *v4)(__int64, __int64, __int64 *); // x9
  char v5; // w10
  int v6; // w0
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x10
  bool v9; // zf
  __int64 (__fastcall *v10)(__int64, int *, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  unsigned __int64 v12; // x19
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 928);
    result = 4294967274LL;
    if ( v1 && pmu_base )
    {
      v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(v1 + 24);
      if ( *((_DWORD *)v4 - 1) != -1171826031 )
        __break(0x8229u);
      result = v4(a1, 128, &ph);
      ops = result;
      if ( result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_22;
      v5 = 0;
      v6 = _cpu_possible_mask;
      do
      {
        v7 = (unsigned int)(-1LL << v5) & v6;
        if ( !(_DWORD)v7 )
          break;
        v8 = __clz(__rbit64(v7));
        if ( v8 > 0x1F )
          __break(1u);
        v9 = v8 == 31;
        phys_cpu[v8] = v8;
        v5 = v8 + 1;
      }
      while ( !v9 );
      result = configure_cpucp_map();
      if ( (result & 0x80000000) != 0 )
        goto LABEL_22;
      v13 = 1;
      if ( qcom_pmu_inited != 1 )
      {
        result = 4294966779LL;
        goto LABEL_22;
      }
      result = 0;
      if ( ops && pmu_base )
      {
        v10 = *(__int64 (__fastcall **)(__int64, int *, __int64, __int64, __int64))ops;
        v11 = ph;
        if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
          __break(0x8228u);
        result = v10(v11, &v13, 0x504D554D4150LL, 13, 4);
        if ( (result & 0x80000000) != 0 )
        {
          v12 = result;
          printk(&unk_8F4A);
          result = v12;
LABEL_22:
          ops = 0;
        }
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
