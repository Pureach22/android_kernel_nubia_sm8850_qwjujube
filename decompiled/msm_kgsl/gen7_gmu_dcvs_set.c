__int64 __fastcall gen7_gmu_dcvs_set(__int64 a1, unsigned int a2, int a3, unsigned int a4)
{
  _QWORD *v4; // x20
  __int64 result; // x0
  int v6; // w8
  unsigned int v7; // w9
  _BOOL4 v8; // w21
  bool v10; // cc
  int v11; // w22
  int v12; // w8
  unsigned int v13; // w20
  unsigned int v20; // w11
  __int64 v21; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v22; // [xsp+10h] [xbp-10h]
  int v23; // [xsp+14h] [xbp-Ch]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v4 = (_QWORD *)(a1 - 680);
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 255;
  v21 = 0x100000000LL;
  if ( (*(_QWORD *)(a1 - 680) & 4) == 0 )
    goto LABEL_2;
  v6 = *(_DWORD *)(a1 - 424);
  v7 = v6 - 1;
  if ( a2 != 255 && v7 <= a2 )
  {
    result = 4294967274LL;
    goto LABEL_6;
  }
  if ( v7 <= a2 )
  {
    v8 = 1;
  }
  else
  {
    v22 = v6 + ~a2;
    v8 = v22 == 255;
  }
  v10 = *(_DWORD *)(a1 + 10400) <= a3 || a3 <= 0;
  v11 = v10 ? 255 : a3;
  v12 = v11 | adreno_gmu_bus_ab_quantize(a1, a4);
  v23 = v12;
  if ( v8 && v12 == -65281 )
  {
LABEL_2:
    result = 0;
  }
  else
  {
    LODWORD(v21) = 30;
    result = gen7_hfi_send_generic_req(a1, &v21, 16);
    if ( (_DWORD)result )
    {
      v8 = result;
      if ( (unsigned int)__ratelimit(&gen7_gmu_dcvs_set__rs, "gen7_gmu_dcvs_set") )
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to set GPU perf idx %u, bw idx %u\n", v22, v23);
      result = v8;
      if ( (*v4 & 2) != 0 )
        goto LABEL_26;
    }
    while ( v22 != 255 )
    {
      if ( v22 < 0x20 )
      {
        v13 = result;
        gmu_core_rdpm_mx_freq_update(a1, *(unsigned int *)(a1 + 12LL * v22 - 408));
        result = v13;
        break;
      }
      __break(0x5512u);
LABEL_26:
      _X9 = (unsigned int *)(a1 + 24448);
      __asm { PRFM            #0x11, [X9] }
      do
        v20 = __ldxr(_X9);
      while ( __stxr(v20 | 0xA0, _X9) );
      __dmb(0xAu);
      kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
      result = v8;
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
