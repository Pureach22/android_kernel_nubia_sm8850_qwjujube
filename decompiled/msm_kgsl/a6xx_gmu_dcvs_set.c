__int64 __fastcall a6xx_gmu_dcvs_set(__int64 a1, unsigned int a2, int a3)
{
  __int64 v3; // x20
  _QWORD *v4; // x21
  __int64 result; // x0
  int v6; // w8
  unsigned int v7; // w9
  int v8; // w22
  int v9; // w23
  char v11; // w8
  unsigned int v12; // w8
  __int64 v13; // x0
  unsigned int v14; // w19
  unsigned int v21; // w10
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+8h] [xbp-18h]
  unsigned int v24; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v4 = (_QWORD *)(a1 - 352);
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0x100000000LL;
  v23 = 0xFF000000FFLL;
  if ( (*(_QWORD *)(a1 - 352) & 4) == 0 )
    goto LABEL_2;
  v6 = *(_DWORD *)(a1 - 680);
  v7 = v6 - 1;
  if ( a2 != 255 && v7 <= a2 )
  {
    result = 4294967274LL;
    goto LABEL_6;
  }
  if ( v7 <= a2 )
  {
    v8 = 255;
  }
  else
  {
    v8 = v6 + ~a2;
    LODWORD(v23) = v8;
  }
  v9 = 255;
  if ( a3 >= 1 && *(_DWORD *)(a1 + 10400) > a3 )
  {
    v9 = a3;
    HIDWORD(v23) = a3;
  }
  if ( v8 == 255 && v9 == 255 )
  {
LABEL_2:
    result = 0;
  }
  else
  {
    v11 = *(_BYTE *)(a1 + 20656);
    LODWORD(v22) = 30;
    if ( (v11 & 0x20) != 0 )
    {
      v3 = a1;
      gmu_core_regwrite(a1, 117756, 0);
      gmu_core_regwrite(v3, 117757, (unsigned __int8)v8 | 0x30000000u);
      gmu_core_regwrite(v3, 117758, v9 & 0xFFF | ((unsigned __int16)(v9 & 0xFFF) << 12));
      v24 = a6xx_gmu_oob_set(v3, 7u);
      if ( !v24 )
        gmu_core_regread(a1, 117759, &v24);
      a6xx_gmu_oob_clear(a1, 7u);
      v12 = v24;
      v13 = a1;
      if ( !v24 )
        goto LABEL_24;
    }
    else
    {
      v12 = a6xx_hfi_send_generic_req(a1, &v22, 16);
      v13 = a1;
      if ( !v12 )
        goto LABEL_24;
    }
    LODWORD(v3) = v12;
    if ( (unsigned int)__ratelimit(&a6xx_gmu_dcvs_set__rs, "a6xx_gmu_dcvs_set") )
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to set GPU perf idx %u, bw idx %u\n", v23, HIDWORD(v23));
    v13 = a1;
    v12 = v3;
    if ( (*v4 & 2) != 0 )
      goto LABEL_29;
    while ( 1 )
    {
LABEL_24:
      if ( (_DWORD)v23 == 255 )
      {
        result = v12;
        goto LABEL_6;
      }
      if ( (unsigned int)v23 < 0x10 )
        break;
      __break(0x5512u);
LABEL_29:
      _X8 = (unsigned int *)(v13 + 24448);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 | 0xA0, _X8) );
      __dmb(0xAu);
      kthread_queue_work(*(_QWORD *)(v13 + 24400), v13 + 24408);
      v13 = a1;
      v12 = v3;
    }
    v14 = v12;
    gmu_core_rdpm_mx_freq_update(v13, *(unsigned int *)(v13 + 12LL * (unsigned int)v23 - 664));
    result = v14;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
