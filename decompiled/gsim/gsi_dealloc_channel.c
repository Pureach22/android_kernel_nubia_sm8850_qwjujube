__int64 __fastcall gsi_dealloc_channel(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x4
  __int64 v7; // x21
  int v8; // w22
  __int64 v9; // x8
  int v10; // w5
  __int64 v11; // x8
  __int64 result; // x0
  unsigned int v20; // w10
  unsigned int v22; // w10
  _QWORD v23[2]; // [xsp+0h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  if ( !gsi_ctx )
  {
    printk(&unk_2DEB9, "gsi_dealloc_channel", 3858);
    result = 4294967288LL;
    goto LABEL_16;
  }
  if ( *(unsigned int *)(gsi_ctx + 28608) <= a1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad params chan_hdl=%lu\n", "gsi_dealloc_channel", 3863, a1);
    result = 4294967290LL;
    goto LABEL_16;
  }
  if ( a1 >= 0x25 )
    goto LABEL_21;
  v5 = gsi_ctx + 448 * a1;
  v6 = *(unsigned int *)(v5 + 304);
  if ( (_DWORD)v6 != 1 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "gsi_dealloc_channel", 3870, v6);
    result = 4294967289LL;
    goto LABEL_16;
  }
  v7 = v5 + 184;
  v8 = *(_DWORD *)(gsi_ctx + 16);
  mutex_lock(gsi_ctx + 28512, a2, a3, a4, v6);
  if ( v8 == 5 )
  {
    *(_DWORD *)(v7 + 120) = 0;
    v9 = gsi_ctx;
    goto LABEL_10;
  }
  *(_DWORD *)(v7 + 264) = 0;
  if ( a1 == 36 )
LABEL_21:
    __break(0x5512u);
  ++*(_QWORD *)(gsi_ctx + 56 * a1 + 16344);
  LODWORD(v23[0]) = 10;
  HIDWORD(v23[0]) = a1;
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *))gsihal_write_reg_n_fields)(55, *(unsigned int *)(gsi_ctx + 20), v23);
  if ( !(unsigned int)wait_for_completion_timeout(v7 + 264, 1250) )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_hdl=%lu timed out\n", "gsi_dealloc_channel", 3886, a1);
    mutex_unlock(gsi_ctx + 28512);
    result = 4294967285LL;
    goto LABEL_16;
  }
  v10 = *(_DWORD *)(v7 + 120);
  v9 = gsi_ctx;
  if ( v10 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d chan_hdl=%lu unexpected state=%u\n", "gsi_dealloc_channel", 3892, a1, v10);
    __break(0x800u);
LABEL_25:
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 - 1, _X8) );
    --*(_BYTE *)(*(_QWORD *)(v7 + 208) + 304LL);
    goto LABEL_13;
  }
LABEL_10:
  mutex_unlock(v9 + 28512);
  devm_kfree(*(_QWORD *)(gsi_ctx + 8), *(_QWORD *)(v7 + 200));
  v11 = *(_QWORD *)(v7 + 208);
  *(_BYTE *)(v7 + 296) = 0;
  if ( v11 && *(_DWORD *)v7 != 5 )
  {
    _X8 = (unsigned int *)(v11 + 308);
    goto LABEL_25;
  }
LABEL_13:
  _X8 = (unsigned int *)(gsi_ctx + 28580);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 - 1, _X8) );
  result = 0;
  if ( *(_DWORD *)v7 == 5 )
    *(_WORD *)(gsi_ctx + 28664) = 7972;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
