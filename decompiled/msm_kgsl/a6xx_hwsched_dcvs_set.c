__int64 __fastcall a6xx_hwsched_dcvs_set(__int64 a1, unsigned int a2, int a3)
{
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x20
  unsigned int v9; // w9
  _BOOL4 v10; // w8
  _BOOL4 v11; // w9
  __int64 result; // x0
  unsigned int v13; // w21
  unsigned int v20; // w9
  __int64 v21; // [xsp+8h] [xbp-18h] BYREF
  __int64 v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = to_a6xx_gmu(a1);
  v21 = 0x100000000LL;
  v22 = 0xFF000000FFLL;
  if ( (*(_QWORD *)(v6 + 1296) & 4) == 0 )
    goto LABEL_11;
  v7 = *(_DWORD *)(v6 + 968);
  v8 = v6;
  v9 = v7 - 1;
  if ( a2 != 255 && v9 <= a2 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Invalid gpu dcvs request: %d\n", a2);
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( v9 <= a2 )
  {
    v10 = 1;
  }
  else
  {
    LODWORD(v22) = v7 + ~a2;
    v10 = v22 == 255;
  }
  v11 = 1;
  if ( a3 >= 1 && *(_DWORD *)(a1 + 10400) > a3 )
  {
    HIDWORD(v22) = a3;
    v11 = a3 == 255;
  }
  if ( !v10 || !v11 )
  {
    LODWORD(v21) = 30;
    result = a6xx_hfi_send_cmd_async(a1, &v21, 16);
    if ( (_DWORD)result )
    {
      a3 = result;
      if ( (unsigned int)__ratelimit(&a6xx_hwsched_dcvs_set__rs, "a6xx_hwsched_dcvs_set") )
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to set GPU perf idx %u, bw idx %u\n", v22, HIDWORD(v22));
      result = (unsigned int)a3;
      if ( (*(_QWORD *)(v8 + 1296) & 2) != 0 )
        goto LABEL_22;
    }
    while ( (_DWORD)v22 != 255 )
    {
      if ( (unsigned int)v22 < 0x10 )
      {
        v13 = result;
        gmu_core_rdpm_mx_freq_update(a1, *(unsigned int *)(v8 + 12LL * (unsigned int)v22 + 984));
        result = v13;
        break;
      }
      __break(0x5512u);
LABEL_22:
      _X8 = (unsigned int *)(a1 + 24448);
      __asm { PRFM            #0x11, [X8] }
      do
        v20 = __ldxr(_X8);
      while ( __stxr(v20 | 0x20, _X8) );
      __dmb(0xAu);
      kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
      result = (unsigned int)a3;
    }
  }
  else
  {
LABEL_11:
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
