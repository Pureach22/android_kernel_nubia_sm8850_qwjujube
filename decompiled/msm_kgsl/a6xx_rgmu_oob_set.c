__int64 __fastcall a6xx_rgmu_oob_set(__int64 a1, int a2)
{
  int v4; // w8
  __int64 v5; // x21
  unsigned int v6; // w0
  __int64 result; // x0
  unsigned int v8; // w21
  const char *v9; // x22
  const char *v10; // x2
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 1 )
  {
    v4 = *(_DWORD *)(a1 - 8);
    *(_DWORD *)(a1 - 8) = v4 + 1;
    if ( v4 )
      goto LABEL_5;
  }
  v5 = 1LL << ((unsigned __int8)a2 + 16);
  gmu_core_regwrite(a1, 129428, (unsigned int)v5);
  v6 = gmu_core_timed_poll_check(a1, 129426, (unsigned int)v5, 100, (unsigned int)v5);
  if ( !v6 )
  {
    gmu_core_regwrite(a1, 129425, (unsigned int)v5);
LABEL_5:
    result = 0;
    goto LABEL_6;
  }
  v8 = v6;
  v11 = 0;
  if ( a2 == 1 )
  {
    v9 = "oob_perfcntr";
    --*(_DWORD *)(a1 - 8);
  }
  else
  {
    v9 = "unknown";
  }
  gmu_core_regread(a1, 129085, &v11);
  if ( a2 )
    v10 = v9;
  else
    v10 = "oob_gpu";
  dev_err(*(_QWORD *)(a1 - 88) + 16LL, "Timed out while setting OOB req:%s status:0x%x\n", v10, v11);
  gmu_core_fault_snapshot(a1, 0);
  result = v8;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
