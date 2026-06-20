__int64 __fastcall gen7_hwsched_boot_gpu(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x9
  char v6; // w11
  __int64 v7; // x8
  int v8; // w24
  unsigned __int64 *v9; // x1
  unsigned int v10; // w0
  unsigned int v11; // w24
  _QWORD *v12; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x21
  __int64 v15; // x0
  char v16; // w9
  __int64 v17; // x8
  _QWORD *v18; // x20
  int v19; // w9
  __int64 v20; // x8
  __int64 result; // x0
  int v22; // w9
  __int64 v23; // x8
  int v24; // w9
  __int64 v25; // x8
  unsigned int v26; // w20
  unsigned int v33; // w8
  unsigned int v34; // w8
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x9
  int v41; // [xsp+4h] [xbp-9Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-98h]
  int v43; // [xsp+10h] [xbp-90h]
  int v44; // [xsp+14h] [xbp-8Ch]
  __int64 v45; // [xsp+18h] [xbp-88h] BYREF
  __int64 v46; // [xsp+20h] [xbp-80h]
  __int64 v47; // [xsp+28h] [xbp-78h]
  __int64 v48; // [xsp+30h] [xbp-70h]
  __int64 v49; // [xsp+38h] [xbp-68h]
  __int64 v50; // [xsp+40h] [xbp-60h]
  __int64 v51; // [xsp+48h] [xbp-58h]
  __int64 v52; // [xsp+50h] [xbp-50h]
  __int64 v53; // [xsp+58h] [xbp-48h]
  __int64 v54; // [xsp+60h] [xbp-40h]
  __int64 v55; // [xsp+68h] [xbp-38h]
  _QWORD v56[3]; // [xsp+70h] [xbp-30h] BYREF
  unsigned __int64 v57; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v58; // [xsp+90h] [xbp-10h]
  __int64 v59; // [xsp+98h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_gen7_gmu(a1);
  if ( *(_BYTE *)(a1 + 8284) == 1
    && (*(_QWORD *)(v2 + 1096) & 0x40) != 0
    && (*(_QWORD *)(v2 + 1096) & 0x80) != 0
    && (*(_QWORD *)(a1 + 1528) & 0x100) == 0 )
  {
    v3 = to_gen7_gmu(a1);
    v4 = to_gen7_gmu(a1);
    v5 = *(_QWORD *)(v4 + 32);
    v6 = *(_BYTE *)(a1 + 8284);
    v42 = 0x100000000LL;
    v7 = *(_QWORD *)(v5 + 40);
    v43 = *(_DWORD *)(v5 + 184);
    v44 = v7;
    if ( (v6 & 1) == 0 )
      goto LABEL_29;
    _X9 = (unsigned int *)(v4 + 44);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v33 = __ldxr(_X9);
      v34 = v33 + 1;
    }
    while ( __stlxr(v34, _X9) );
    __dmb(0xBu);
    v8 = (v34 << 20) | 0x59A;
    v45 = 0;
    v46 = 0;
    v41 = v8;
    v47 = 0;
    v48 = 0;
    v49 = 0;
    v50 = 0;
    v51 = 0;
    v52 = 0;
    v53 = 0;
    v54 = 0;
    v55 = 0;
    memset(v56, 0, sizeof(v56));
    v57 = 0;
    v58 = nullptr;
    _init_swait_queue_head(v56, "&x->wait", &init_completion___key_2);
    raw_write_lock_irq(a1 + 24556);
    v9 = *(unsigned __int64 **)(a1 + 24576);
    if ( &v57 == (unsigned __int64 *)(a1 + 24568) || &v57 == v9 || *v9 != a1 + 24568 )
    {
      _list_add_valid_or_report(&v57, v9);
    }
    else
    {
      *(_QWORD *)(a1 + 24576) = &v57;
      v57 = a1 + 24568;
      v58 = (unsigned __int64 **)v9;
      *v9 = (unsigned __int64)&v57;
    }
    raw_write_unlock_irq(a1 + 24556);
    LODWORD(v45) = v8;
    v10 = gen7_hfi_cmdq_write(a1, &v41, 0x14u);
    if ( !v10 )
      v10 = adreno_hwsched_wait_ack_completion(a1, *(_QWORD *)(a1 + 1544) + 16LL, &v45, gen7_hwsched_process_msgq);
    v11 = v10;
    raw_write_lock_irq(a1 + 24556);
    v12 = v58;
    if ( *v58 == &v57 && (v13 = v57, *(unsigned __int64 **)(v57 + 8) == &v57) )
    {
      *(_QWORD *)(v57 + 8) = v58;
      *v12 = v13;
    }
    else
    {
      _list_del_entry_valid_or_report(&v57);
    }
    v57 = 0xDEAD000000000100LL;
    v58 = (unsigned __int64 **)0xDEAD000000000122LL;
    raw_write_unlock_irq(a1 + 24556);
    if ( v11 )
    {
      _X8 = (unsigned __int64 *)(v3 + 1096);
      __asm { PRFM            #0x11, [X8] }
      do
        v37 = __ldxr(_X8);
      while ( __stxr(v37 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
      gen7_disable_gpu_irq(a1);
      result = v11;
    }
    else
    {
LABEL_29:
      result = 0;
    }
    goto LABEL_28;
  }
  v14 = to_gen7_gmu(a1);
  v15 = to_gen7_hfi(a1);
  v16 = *(_BYTE *)(a1 + 8284);
  v17 = *(_QWORD *)(v14 + 32);
  v18 = (_QWORD *)v15;
  HIDWORD(v45) = 0;
  if ( (v16 & 1) == 0
    || (v19 = *(_DWORD *)(v17 + 184),
        v20 = *(_QWORD *)(v17 + 40),
        LODWORD(v46) = 0,
        HIDWORD(v46) = v19,
        LODWORD(v47) = v20,
        LODWORD(v45) = 154,
        result = gen7_hfi_send_cmd_async(a1, (int *)&v45, 0x14u),
        !(_DWORD)result) )
  {
    result = gen7_hwsched_cp_init(a1);
    if ( !(_DWORD)result )
    {
      result = gen7_hwsched_lpac_cp_init(a1);
      if ( !(_DWORD)result )
      {
        v22 = *(unsigned __int8 *)(a1 + 8284);
        v23 = *(_QWORD *)(v14 + 32);
        HIDWORD(v45) = 0;
        if ( v22 == 1 )
        {
          v24 = *(_DWORD *)(v23 + 184);
          v25 = *(_QWORD *)(v23 + 40);
          HIDWORD(v46) = v24;
          LODWORD(v47) = v25;
          LODWORD(v46) = 2;
          LODWORD(v45) = 154;
          result = gen7_hfi_send_cmd_async(a1, (int *)&v45, 0x14u);
          if ( (_DWORD)result )
            goto LABEL_26;
          if ( (*(_BYTE *)(a1 + 8284) & 1) != 0 )
          {
            _X8 = (unsigned __int64 *)(v14 + 1096);
            __asm { PRFM            #0x11, [X8] }
            do
              v40 = __ldxr(_X8);
            while ( __stxr(v40 | 0x80, _X8) );
          }
        }
        result = 0;
      }
    }
  }
LABEL_26:
  v18[120] = 0;
  v18[119] = 0;
  v18[118] = 0;
  v18[117] = 0;
  if ( (_DWORD)result )
  {
    v26 = result;
    gen7_disable_gpu_irq(a1);
    result = v26;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
