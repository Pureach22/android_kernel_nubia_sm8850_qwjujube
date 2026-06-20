__int64 __fastcall qcom_smd_create_ept(__int64 a1, __int64 a2, __int64 a3, const char *a4)
{
  __int64 v8; // x27
  _QWORD *v9; // x28
  __int64 v10; // x20
  _QWORD *v11; // x24
  _QWORD *v12; // x26
  __int64 i; // x20
  __int64 v14; // x24
  __int64 v15; // x25
  _QWORD *v16; // x26
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x19
  int v22; // w8
  __int64 v23; // x21
  __int64 v24; // x0
  __int64 v25; // x23
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  _DWORD *v30; // x8
  __int64 v31; // x8
  __int64 v32; // x22
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x22
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  _DWORD *v39; // x8
  __int64 v40; // x8
  unsigned int v41; // w8
  __int64 v43; // x22
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x22
  int v47; // w8
  bool v48; // zf
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x8
  _DWORD *v52; // x8
  __int64 v53; // x8
  __int64 v54; // x21
  __int64 v55; // x0
  int v59; // w8
  __int64 v61; // [xsp+0h] [xbp-30h] BYREF
  __int64 v62; // [xsp+8h] [xbp-28h]
  __int64 v63; // [xsp+10h] [xbp-20h]
  __int64 v64; // [xsp+18h] [xbp-18h]
  __int64 v65; // [xsp+20h] [xbp-10h]
  __int64 v66; // [xsp+28h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 992);
  v9 = (_QWORD *)(v8 + 1024);
  v10 = raw_spin_lock_irqsave(v8 + 1040);
  v11 = (_QWORD *)(v8 + 1024);
  while ( 1 )
  {
    v11 = (_QWORD *)*v11;
    if ( v11 == v9 )
      break;
    if ( !strcmp((const char *)*(v11 - 17), a4) )
    {
      v12 = v11 - 20;
      raw_spin_unlock_irqrestore(v8 + 1040, v10);
      if ( v11 == &off_A0 )
        goto LABEL_7;
      goto LABEL_25;
    }
  }
  raw_spin_unlock_irqrestore(v8 + 1040, v10);
LABEL_7:
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v61 = 0;
  init_wait_entry(&v61, 0);
  for ( i = 250; ; i = schedule_timeout(v18) )
  {
    v14 = prepare_to_wait_event(v8 + 1072, &v61, 1);
    v15 = raw_spin_lock_irqsave(v8 + 1040);
    v16 = (_QWORD *)(v8 + 1024);
    while ( 1 )
    {
      v16 = (_QWORD *)*v16;
      if ( v16 == v9 )
        break;
      if ( !strcmp((const char *)*(v16 - 17), a4) )
      {
        v12 = v16 - 20;
        goto LABEL_13;
      }
    }
    v12 = nullptr;
LABEL_13:
    raw_spin_unlock_irqrestore(v8 + 1040, v15);
    _ZF = i || v12 == nullptr;
    v18 = _ZF ? i : 1LL;
    if ( v12 || !v18 )
      break;
    if ( v14 )
      goto LABEL_24;
  }
  LODWORD(v14) = v18;
  finish_wait(v8 + 1072, &v61);
LABEL_24:
  if ( !(_DWORD)v14 )
  {
LABEL_116:
    v20 = 0;
    goto LABEL_117;
  }
LABEL_25:
  if ( *((_DWORD *)v12 + 8) )
  {
    dev_err(a1, "channel %s is busy\n", (const char *)v12[3]);
    goto LABEL_116;
  }
  v19 = _kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 112);
  v20 = v19;
  if ( !v19 )
    goto LABEL_117;
  *(_DWORD *)(v19 + 8) = 1;
  _X20 = (unsigned int *)(v19 + 8);
  *(_QWORD *)v19 = a1;
  *(_QWORD *)(v19 + 16) = a2;
  *(_QWORD *)(v19 + 88) = a3;
  *(_QWORD *)(v19 + 96) = qcom_smd_endpoint_ops;
  v12[1] = v19;
  *(_QWORD *)(v19 + 104) = v12;
  v22 = *((_DWORD *)v12 + 32);
  v23 = *v12;
  if ( v22 >= 4096 )
    v22 = 4096;
  v24 = _kmalloc_noprof(v22, 3264);
  v12[17] = v24;
  if ( !v24 )
    goto LABEL_110;
  v25 = v12[1];
  v26 = raw_spin_lock_irqsave(v12 + 18);
  *(_QWORD *)(v25 + 16) = a2;
  raw_spin_unlock_irqrestore(v12 + 18, v26);
  if ( *((_DWORD *)v12 + 8) != 1 )
  {
    v27 = v12[9];
    if ( v27 )
    {
      *(_DWORD *)(v27 + 4) = 0;
      v28 = v12[9];
      if ( v28 )
        goto LABEL_33;
    }
    else
    {
      *(_BYTE *)(v12[8] + 4LL) = 0;
      v28 = v12[9];
      if ( v28 )
      {
LABEL_33:
        *(_DWORD *)(v28 + 8) = 0;
        v29 = v12[9];
        if ( v29 )
          goto LABEL_34;
        goto LABEL_40;
      }
    }
    *(_BYTE *)(v12[8] + 5LL) = 0;
    v29 = v12[9];
    if ( v29 )
    {
LABEL_34:
      *(_DWORD *)(v29 + 12) = 0;
      v30 = (_DWORD *)v12[9];
      if ( v30 )
      {
LABEL_36:
        *v30 = 1;
        v31 = v12[9];
        if ( v31 )
          *(_DWORD *)(v31 + 28) = 1;
        else
          *(_BYTE *)(v12[8] + 10LL) = 1;
        v32 = *v12;
        *((_DWORD *)v12 + 8) = 1;
        v33 = *(_QWORD *)(v32 + 1016);
        if ( v33 )
        {
          mbox_send_message(v33, 0);
          mbox_client_txdone(*(_QWORD *)(v32 + 1016), 0);
        }
        else
        {
          regmap_write(*(_QWORD *)(v32 + 944), *(unsigned int *)(v32 + 952), 1LL << *(_DWORD *)(v32 + 956));
        }
        goto LABEL_46;
      }
LABEL_35:
      v30 = (_DWORD *)v12[8];
      goto LABEL_36;
    }
LABEL_40:
    *(_BYTE *)(v12[8] + 6LL) = 0;
    v30 = (_DWORD *)v12[9];
    if ( v30 )
      goto LABEL_36;
    goto LABEL_35;
  }
LABEL_46:
  if ( (unsigned int)(*((_DWORD *)v12 + 9) - 1) >= 2 )
  {
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v61 = 0;
    init_wait_entry(&v61, 0);
    v34 = prepare_to_wait_event(v12 + 5, &v61, 1);
    v35 = 250;
    if ( (unsigned int)(*((_DWORD *)v12 + 9) - 1) >= 2 )
    {
      while ( !v34 )
      {
        v35 = schedule_timeout(v35);
        v34 = prepare_to_wait_event(v12 + 5, &v61, 1);
        v41 = *((_DWORD *)v12 + 9) - 1;
        if ( v35 )
          _CF = 1;
        else
          _CF = v41 >= 2;
        if ( !_CF )
          v35 = 1;
        if ( !v35 || v41 <= 1 )
          goto LABEL_48;
      }
    }
    else
    {
LABEL_48:
      finish_wait(v12 + 5, &v61);
      LODWORD(v34) = v35;
    }
    if ( !(_DWORD)v34 )
    {
      dev_err(v23, "remote side did not enter opening state\n");
LABEL_92:
      if ( *((_DWORD *)v12 + 8) )
      {
        v49 = v12[9];
        if ( v49 )
          *(_DWORD *)(v49 + 4) = 0;
        else
          *(_BYTE *)(v12[8] + 4LL) = 0;
        v50 = v12[9];
        if ( v50 )
          *(_DWORD *)(v50 + 8) = 0;
        else
          *(_BYTE *)(v12[8] + 5LL) = 0;
        v51 = v12[9];
        if ( v51 )
          *(_DWORD *)(v51 + 12) = 0;
        else
          *(_BYTE *)(v12[8] + 6LL) = 0;
        v52 = (_DWORD *)v12[9];
        if ( !v52 )
          v52 = (_DWORD *)v12[8];
        *v52 = 0;
        v53 = v12[9];
        if ( v53 )
          *(_DWORD *)(v53 + 28) = 1;
        else
          *(_BYTE *)(v12[8] + 10LL) = 1;
        v54 = *v12;
        *((_DWORD *)v12 + 8) = 0;
        v55 = *(_QWORD *)(v54 + 1016);
        if ( v55 )
        {
          mbox_send_message(v55, 0);
          mbox_client_txdone(*(_QWORD *)(v54 + 1016), 0);
        }
        else
        {
          regmap_write(*(_QWORD *)(v54 + 944), *(unsigned int *)(v54 + 952), 1LL << *(_DWORD *)(v54 + 956));
        }
      }
LABEL_110:
      v12[1] = 0;
      __asm { PRFM            #0x11, [X20] }
      do
        v59 = __ldxr(_X20);
      while ( __stlxr(v59 - 1, _X20) );
      if ( v59 == 1 )
      {
        __dmb(9u);
        kfree(v20);
      }
      else if ( v59 <= 0 )
      {
        refcount_warn_saturate(v20 + 8, 3);
      }
      goto LABEL_116;
    }
  }
  if ( *((_DWORD *)v12 + 8) != 2 )
  {
    v36 = v12[9];
    if ( v36 )
    {
      *(_DWORD *)(v36 + 4) = 1;
      v37 = v12[9];
      if ( v37 )
        goto LABEL_53;
    }
    else
    {
      *(_BYTE *)(v12[8] + 4LL) = 1;
      v37 = v12[9];
      if ( v37 )
      {
LABEL_53:
        *(_DWORD *)(v37 + 8) = 1;
        v38 = v12[9];
        if ( v38 )
          goto LABEL_54;
        goto LABEL_69;
      }
    }
    *(_BYTE *)(v12[8] + 5LL) = 1;
    v38 = v12[9];
    if ( v38 )
    {
LABEL_54:
      *(_DWORD *)(v38 + 12) = 1;
      v39 = (_DWORD *)v12[9];
      if ( v39 )
      {
LABEL_56:
        *v39 = 2;
        v40 = v12[9];
        if ( v40 )
          *(_DWORD *)(v40 + 28) = 1;
        else
          *(_BYTE *)(v12[8] + 10LL) = 1;
        v43 = *v12;
        *((_DWORD *)v12 + 8) = 2;
        v44 = *(_QWORD *)(v43 + 1016);
        if ( v44 )
        {
          mbox_send_message(v44, 0);
          mbox_client_txdone(*(_QWORD *)(v43 + 1016), 0);
        }
        else
        {
          regmap_write(*(_QWORD *)(v43 + 944), *(unsigned int *)(v43 + 952), 1LL << *(_DWORD *)(v43 + 956));
        }
        goto LABEL_75;
      }
LABEL_55:
      v39 = (_DWORD *)v12[8];
      goto LABEL_56;
    }
LABEL_69:
    *(_BYTE *)(v12[8] + 6LL) = 1;
    v39 = (_DWORD *)v12[9];
    if ( v39 )
      goto LABEL_56;
    goto LABEL_55;
  }
LABEL_75:
  if ( *((_DWORD *)v12 + 9) != 2 )
  {
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v61 = 0;
    init_wait_entry(&v61, 0);
    v45 = prepare_to_wait_event(v12 + 5, &v61, 1);
    v46 = 250;
    if ( *((_DWORD *)v12 + 9) == 2 )
    {
LABEL_77:
      finish_wait(v12 + 5, &v61);
      LODWORD(v45) = v46;
    }
    else
    {
      while ( !v45 )
      {
        v46 = schedule_timeout(v46);
        v45 = prepare_to_wait_event(v12 + 5, &v61, 1);
        v47 = *((_DWORD *)v12 + 9);
        if ( v46 )
          v48 = 0;
        else
          v48 = v47 == 2;
        if ( v48 )
          v46 = 1;
        if ( v47 == 2 || !v46 )
          goto LABEL_77;
      }
    }
    if ( !(_DWORD)v45 )
    {
      dev_err(v23, "remote side did not enter open state\n");
      goto LABEL_92;
    }
  }
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return v20;
}
