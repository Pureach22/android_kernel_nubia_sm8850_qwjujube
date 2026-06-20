__int64 __fastcall qce_manage_timeout(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x24
  __int64 v9; // x21
  char v10; // w25
  __int64 v11; // x22
  __int64 v12; // x28
  __int64 v13; // x22
  __int64 v14; // x22
  __int64 v15; // x21
  __int64 v16; // x22
  unsigned int v17; // w0
  void *v18; // x0
  __int64 v19; // x2
  unsigned int v20; // w28
  unsigned int v22; // w0
  unsigned int v28; // w9
  __int64 v29; // x2
  __int64 v30; // x2
  __int64 v31; // x2
  __int64 v32; // x2
  unsigned int v35; // w10
  unsigned int v37; // w9
  unsigned int v39; // w9
  __int64 v40; // [xsp+8h] [xbp-18h] BYREF
  char v41; // [xsp+10h] [xbp-10h]
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v40 = 0;
  if ( !a1 )
  {
    printk(&unk_1624A, "qce_manage_timeout", a3);
    result = 4294967290LL;
    goto LABEL_40;
  }
  if ( a2 >= 9 )
    goto LABEL_53;
  v5 = a1 + 2624;
  _X26 = a1 + 2624 + 7432LL * a2;
  _X23 = (unsigned int *)(a1 + 69520);
  v9 = *(unsigned __int16 *)(_X26 + 7420);
  v10 = *(_BYTE *)(a1 + 70253) == 1 ? *(_BYTE *)(_X26 + 7428) : 0;
  printk(&unk_15CBE, "qce_manage_timeout", "qce_manage_timeout");
  if ( (unsigned int)v9 >= 6 )
    goto LABEL_53;
  v11 = a1 + 4 * v9;
  sps_pipe_reset(*(_QWORD *)(a1 + 392), *(unsigned int *)(v11 + 364));
  sps_pipe_reset(*(_QWORD *)(a1 + 392), *(unsigned int *)(v11 + 340));
  v12 = a1 + 1520 + 184LL * (unsigned int)v9;
  v13 = *(_QWORD *)v12;
  if ( (unsigned int)sps_disconnect(*(_QWORD *)v12) )
  {
    v18 = &unk_16147;
LABEL_17:
    v19 = v13;
    goto LABEL_18;
  }
  memset(*(void **)(v12 + 64), 0, *(unsigned int *)(v12 + 88));
  if ( (unsigned int)sps_connect(v13, v12 + 8) )
  {
    v18 = &unk_14D4C;
    goto LABEL_17;
  }
  v14 = a1 + 184LL * (unsigned int)v9;
  v15 = *(_QWORD *)(v14 + 416);
  if ( (unsigned int)sps_disconnect(v15)
    || (v16 = v14 + 416,
        memset(*(void **)(v16 + 64), 0, *(unsigned int *)(v16 + 88)),
        (unsigned int)sps_connect(v15, v16 + 8)) )
  {
    v18 = &unk_14D4C;
    v19 = v15;
LABEL_18:
    printk(v18, "qce_sps_pipe_reset", v19);
    goto LABEL_19;
  }
  v17 = sps_register_event(v15, v16 + 152);
  if ( v17 )
  {
    printk(&unk_14F76, "qce_sps_pipe_reset", v17);
LABEL_19:
    printk(&unk_14BCB, "qce_manage_timeout", "qce_manage_timeout");
  }
  qce_get_crypto_status(a1, (__int64)&v40);
  if ( (v40 & 1) == 0 )
  {
    v20 = 0;
    do
    {
      usleep_range_state(3000, 5000, 2);
      qce_get_crypto_status(a1, (__int64)&v40);
      printk(&unk_1544F, "qce_manage_timeout", "qce_manage_timeout");
      if ( (v40 & 1) != 0 )
        break;
    }
    while ( v20++ <= 0x3E6 );
  }
  __dsb(0xEu);
  if ( (*(_BYTE *)(a1 + 128) & 1) == 0 && *(_BYTE *)(a1 + 68) == 1 )
  {
    if ( *(unsigned __int16 *)(_X26 + 7420) > 5u )
      goto LABEL_53;
    v22 = sps_transfer_one(
            *(_QWORD *)(a1 + 1520 + 184LL * *(unsigned __int16 *)(_X26 + 7420)),
            *(_QWORD *)(_X26 + 7040) + *(_QWORD *)(a1 + 24) - *(_QWORD *)(a1 + 16),
            0,
            0,
            2560);
    if ( v22 )
    {
      printk(&unk_14FAC, "_qce_unlock_other_pipes", v22);
      printk(&unk_15CEF, "qce_manage_timeout", "qce_manage_timeout");
      if ( *(_DWORD *)_X26 )
        goto LABEL_30;
LABEL_51:
      printk(&unk_14AC0, "qce_manage_timeout", a2);
      result = 4294967290LL;
      goto LABEL_40;
    }
  }
  if ( !*(_DWORD *)_X26 )
    goto LABEL_51;
LABEL_30:
  *(_DWORD *)(_X26 + 8) = 5;
  __asm { PRFM            #0x11, [X26] }
  do
    v28 = __ldxr((unsigned int *)_X26);
  while ( __stlxr(0, (unsigned int *)_X26) );
  __dmb(0xBu);
  if ( v28 )
  {
    if ( a2 != 8 )
    {
      __asm { PRFM            #0x11, [X23] }
      do
        v37 = __ldxr(_X23);
      while ( __stxr(v37 - 1, _X23) );
    }
  }
  else
  {
    printk(&unk_15B49, "qce_free_req_info", a2);
  }
  if ( (v10 & 1) == 0 )
    goto LABEL_38;
  _X23[92] = 0;
  if ( (unsigned int)qce_ablk_cipher_req(a1, a1 + 69920) )
  {
    printk(&unk_15AA0, "qce_manage_timeout", v29);
LABEL_44:
    printk(&unk_15E91, "qce_manage_timeout", v30);
    v32 = _X23[144];
    if ( (unsigned int)v32 < 9 )
    {
      _X9 = (unsigned int *)(v5 + 7432LL * (unsigned int)v32);
      _X9[2] = 5;
      __asm { PRFM            #0x11, [X9] }
      do
        v35 = __ldxr(_X9);
      while ( __stlxr(0, _X9) );
      __dmb(0xBu);
      if ( v35 )
      {
        if ( (_DWORD)v32 != 8 )
        {
          __asm { PRFM            #0x11, [X23] }
          do
            v39 = __ldxr(_X23);
          while ( __stxr(v39 - 1, _X23) );
        }
      }
      else
      {
        printk(&unk_15B49, "qce_free_req_info", v32);
      }
      goto LABEL_38;
    }
LABEL_53:
    __break(0x5512u);
  }
  if ( !wait_for_completion_timeout(_X23 + 92, 13) )
    goto LABEL_44;
LABEL_38:
  qce_get_crypto_status(a1, (__int64)&v40);
  if ( (v40 & 1) != 0 )
  {
    result = 0;
  }
  else
  {
    printk(&unk_15B19, "qce_manage_timeout", v31);
    result = 1;
  }
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
