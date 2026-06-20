__int64 __fastcall a6xx_hwsched_submit_drawobj(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  __int64 v5; // x1
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w21
  unsigned int *v9; // x22
  int v10; // w8
  int v11; // w8
  __int64 v12; // x9
  __int64 v13; // x9
  unsigned int v14; // w10
  _DWORD *v15; // x8
  _QWORD *i; // x10
  __int64 v17; // x8
  unsigned int v24; // w8
  unsigned int v25; // w8
  _QWORD v26[4]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+20h] [xbp-10h]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 8);
  v27 = 0;
  v5 = v4;
  memset(v26, 0, sizeof(v26));
  if ( !a6xx_hwsched_submit_drawobj_cmdbuf )
  {
    a6xx_hwsched_submit_drawobj_cmdbuf = devm_kmalloc(*(_QWORD *)(a1 + 11168) + 16LL, 1024, 3520);
    if ( !a6xx_hwsched_submit_drawobj_cmdbuf )
    {
      result = 4294967284LL;
      goto LABEL_27;
    }
    v5 = *(_QWORD *)(a2 + 8);
  }
  result = hfi_context_register(a1, v5);
  if ( !(_DWORD)result )
  {
    v7 = *(_DWORD *)(a2 + 160);
    v8 = 32;
    if ( v7 <= 0x52 && (*(_QWORD *)(a2 + 56) & 1) == 0 )
      v8 = 12 * v7 + 32;
    v9 = (unsigned int *)a6xx_hwsched_submit_drawobj_cmdbuf;
    memset((void *)a6xx_hwsched_submit_drawobj_cmdbuf, 0, v8);
    v9[1] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL);
    v9[2] = 32;
    if ( (*(_QWORD *)(a2 + 24) & 0x100LL) != 0 )
      v10 = 288;
    else
      v10 = 32;
    v9[2] = v10;
    v9[3] = *(_DWORD *)(a2 + 20);
    if ( (*(_QWORD *)(a2 + 56) & 1) == 0 )
    {
      if ( *(_DWORD *)(a2 + 160) < 0x53u )
      {
        v15 = v9 + 8;
      }
      else
      {
        v11 = v10 | 0x200;
        if ( (*(_QWORD *)(a2 + 56) & 0x20LL) != 0 )
          v12 = 24616;
        else
          v12 = 24608;
        v13 = *(_QWORD *)(a1 + v12);
        v14 = *(_DWORD *)(v13 + 184);
        v9[2] = v11;
        v9[7] = v14;
        v15 = *(_DWORD **)(v13 + 8);
      }
      for ( i = *(_QWORD **)(a2 + 88); i != (_QWORD *)(a2 + 88); i = (_QWORD *)*i )
      {
        *(_QWORD *)v15 = i[4];
        v15[2] = i[5];
        v15 += 3;
      }
      v9[6] = *(_DWORD *)(a2 + 160);
      if ( (*(_BYTE *)(a2 + 24) & 0x10) != 0 && *(_QWORD *)(a2 + 128) )
      {
        v17 = *(_QWORD *)(a2 + 136);
        v27 = a2;
        v9[4] = v17;
        LODWORD(v17) = v9[2] | 0x10;
        v9[5] = *(_DWORD *)(a2 + 140);
        v9[2] = v17;
      }
    }
    adreno_drawobj_set_constraint(a1, a2);
    _X9 = (unsigned int *)(a1 + 22928);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v24 = __ldxr(_X9);
      v25 = v24 + 1;
    }
    while ( __stlxr(v25, _X9) );
    __dmb(0xBu);
    *v9 = (v8 << 6) & 0xFF00 | (v25 << 20) | 0x82;
    result = a6xx_hfi_dispatch_queue_write(
               a1,
               (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 8) + 292LL) + 3),
               v9,
               v8,
               a2,
               v26);
    if ( !(_DWORD)result )
    {
      gmu_core_regwrite(a1, 129428, 1LL << (*(_BYTE *)(*(_QWORD *)(a2 + 8) + 292LL) + 2));
      result = 0;
      *(_DWORD *)(v4 + 396) = *(_DWORD *)(a2 + 20);
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
