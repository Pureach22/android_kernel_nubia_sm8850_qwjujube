__int64 __fastcall gen8_hwsched_dcvs_set(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  __int64 v8; // x0
  int v9; // w8
  __int64 v10; // x20
  unsigned int v11; // w9
  _BOOL4 v12; // w23
  int v14; // w8
  __int64 result; // x0
  unsigned int v16; // w21
  unsigned int v17; // w21
  __int64 v18; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v19; // [xsp+10h] [xbp-10h]
  int v20; // [xsp+14h] [xbp-Ch]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = to_gen8_gmu(a1);
  v19 = 255;
  v18 = 0x100000000LL;
  if ( (*(_QWORD *)(v8 + 1040) & 4) == 0 )
    goto LABEL_15;
  v9 = *(_DWORD *)(v8 + 1288);
  v10 = v8;
  v11 = v9 - 1;
  if ( a2 != 255 && v11 <= a2 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Invalid gpu dcvs request: %d\n", a2);
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( v11 <= a2 )
  {
    v12 = 1;
  }
  else
  {
    v19 = v9 + ~a2;
    v12 = v19 == 255;
  }
  if ( *(_DWORD *)(a1 + 10400) <= a3 || a3 <= 0 )
    a3 = 255;
  v14 = a3 | adreno_gmu_bus_ab_quantize(a1, a4);
  v20 = v14;
  if ( v12 && v14 == -65281 )
  {
LABEL_15:
    result = 0;
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  LODWORD(v18) = 30;
  result = gen8_hfi_send_cmd_async(a1, &v18, 16);
  if ( (_DWORD)result )
  {
    v16 = result;
    if ( (unsigned int)__ratelimit(&gen8_hwsched_dcvs_set__rs, "gen8_hwsched_dcvs_set") )
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to set GPU perf idx %u, bw idx %u\n", v19, v20);
    result = v16;
    if ( (*(_QWORD *)(v10 + 1040) & 2) != 0 )
    {
      gen8_hwsched_fault(a1, 32);
      result = v16;
    }
  }
  if ( v19 == 255 )
    goto LABEL_16;
  if ( v19 < 0x20 )
  {
    v17 = result;
    gmu_core_rdpm_mx_freq_update(a1, *(unsigned int *)(v10 + 12LL * v19 + 1304));
    result = v17;
    goto LABEL_16;
  }
  __break(0x5512u);
  return dcvs_tuning_show(result);
}
