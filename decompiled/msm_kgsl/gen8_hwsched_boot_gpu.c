__int64 __fastcall gen8_hwsched_boot_gpu(__int64 a1)
{
  _BYTE *v2; // x23
  __int64 v3; // x0
  __int64 v4; // x24
  __int64 v5; // x20
  __int64 v6; // x27
  __int64 v7; // x0
  __int64 v8; // x9
  char v9; // w11
  __int64 v10; // x8
  int v11; // w21
  unsigned __int64 *v12; // x1
  unsigned int v13; // w21
  _QWORD *v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x22
  __int64 v17; // x0
  char v18; // w9
  __int64 v19; // x8
  _QWORD *v20; // x20
  int v21; // w9
  __int64 v22; // x8
  __int64 v23; // x1
  __int64 v24; // x2
  unsigned int v25; // w0
  int v26; // w9
  __int64 v27; // x8
  int v28; // w9
  __int64 v29; // x8
  const char *v30; // x1
  unsigned __int64 v34; // x10
  unsigned int v41; // w8
  unsigned int v42; // w8
  unsigned __int64 v45; // x9
  int v46; // [xsp+4h] [xbp-9Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-98h]
  int v48; // [xsp+10h] [xbp-90h]
  int v49; // [xsp+14h] [xbp-8Ch]
  _QWORD v50[6]; // [xsp+18h] [xbp-88h] BYREF
  __int64 v51; // [xsp+48h] [xbp-58h]
  __int64 v52; // [xsp+50h] [xbp-50h]
  __int64 v53; // [xsp+58h] [xbp-48h]
  __int64 v54; // [xsp+60h] [xbp-40h]
  __int64 v55; // [xsp+68h] [xbp-38h]
  __int64 v56; // [xsp+70h] [xbp-30h] BYREF
  __int64 v57; // [xsp+78h] [xbp-28h]
  __int64 v58; // [xsp+80h] [xbp-20h]
  unsigned __int64 v59; // [xsp+88h] [xbp-18h] BYREF
  unsigned __int64 **v60; // [xsp+90h] [xbp-10h]
  __int64 v61; // [xsp+98h] [xbp-8h]

  v2 = (_BYTE *)(a1 + 20440);
  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = to_gen8_gmu(a1);
  if ( *(_BYTE *)(a1 + 8284) == 1
    && (*(_QWORD *)(v3 + 1040) & 0x40) != 0
    && (*(_QWORD *)(v3 + 1040) & 0x80) != 0
    && (*(_QWORD *)(a1 + 1528) & 0x100) == 0 )
  {
    v4 = *(_QWORD *)(a1 + 1544);
    v5 = to_gen8_gmu(a1);
    v6 = *(_QWORD *)(a1 + 1544);
    v59 = 0;
    v60 = nullptr;
    v57 = 0;
    v58 = 0;
    v55 = 0;
    v56 = 0;
    v53 = 0;
    v54 = 0;
    v51 = 0;
    v52 = 0;
    memset(v50, 0, sizeof(v50));
    v7 = to_gen8_gmu(a1);
    v8 = *(_QWORD *)(v7 + 32);
    v9 = *(_BYTE *)(a1 + 8284);
    v47 = 0x100000000LL;
    v10 = *(_QWORD *)(v8 + 40);
    v48 = *(_DWORD *)(v8 + 184);
    v49 = v10;
    if ( (v9 & 1) != 0 )
    {
      _X9 = (unsigned int *)(v7 + 44);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v41 = __ldxr(_X9);
        v42 = v41 + 1;
      }
      while ( __stlxr(v42, _X9) );
      __dmb(0xBu);
      v11 = (v42 << 20) | 0x59A;
      memset(v50, 0, sizeof(v50));
      v46 = v11;
      v51 = 0;
      v52 = 0;
      v53 = 0;
      v54 = 0;
      v55 = 0;
      v56 = 0;
      v57 = 0;
      v58 = 0;
      v59 = 0;
      v60 = nullptr;
      _init_swait_queue_head(&v56, "&x->wait", &init_completion___key_3);
      raw_write_lock_irq(a1 + 24620);
      v12 = *(unsigned __int64 **)(a1 + 24640);
      if ( &v59 == (unsigned __int64 *)(a1 + 24632) || &v59 == v12 || *v12 != a1 + 24632 )
      {
        _list_add_valid_or_report(&v59, v12);
      }
      else
      {
        *(_QWORD *)(a1 + 24640) = &v59;
        v59 = a1 + 24632;
        v60 = (unsigned __int64 **)v12;
        *v12 = (unsigned __int64)&v59;
      }
      raw_write_unlock_irq(a1 + 24620);
      LODWORD(v50[0]) = v11;
      v13 = gen8_hfi_cmdq_write(a1, &v46, 0x14u);
      if ( !v13 )
        v13 = adreno_hwsched_wait_ack_completion(a1, v6 + 16, v50, gen8_hwsched_process_msgq);
      raw_write_lock_irq(a1 + 24620);
      v14 = v60;
      if ( *v60 == &v59 && (v15 = v59, *(unsigned __int64 **)(v59 + 8) == &v59) )
      {
        *(_QWORD *)(v59 + 8) = v60;
        *v14 = v15;
      }
      else
      {
        _list_del_entry_valid_or_report(&v59);
      }
      v59 = 0xDEAD000000000100LL;
      v60 = (unsigned __int64 **)0xDEAD000000000122LL;
      raw_write_unlock_irq(a1 + 24620);
      if ( v13 )
        goto LABEL_50;
      if ( BYTE4(v50[0]) == 154 )
      {
        if ( LODWORD(v50[2]) != 6 )
        {
          if ( !LODWORD(v50[2]) )
          {
            v13 = HIDWORD(v50[1]);
            if ( !HIDWORD(v50[1]) )
              goto LABEL_51;
            goto LABEL_28;
          }
          dev_err(
            v4 + 16,
            "HFI ACK: Req=0x%8.8X, Result=0x%8.8X Error:0x%8.8X\n",
            LODWORD(v50[1]),
            HIDWORD(v50[1]),
            LODWORD(v50[2]));
          goto LABEL_49;
        }
        if ( LOBYTE(v50[1]) == 135 )
        {
          gen8_spin_idle_debug_lpac(a1);
        }
        else
        {
          if ( LOBYTE(v50[1]) != 131 )
          {
            dev_err(
              v4 + 16,
              "HFI ACK: Req=0x%8.8X, Result=0x%8.8X Error:0x%8.8X\n",
              LODWORD(v50[1]),
              HIDWORD(v50[1]),
              6);
            goto LABEL_49;
          }
          if ( LODWORD(v50[1]) == *(_DWORD *)(v5 + 1280) )
          {
            v30 = "CP initialization failed to idle\n";
LABEL_46:
            gen8_spin_idle_debug((_QWORD *)a1, v30);
            goto LABEL_49;
          }
          if ( LODWORD(v50[1]) == *(_DWORD *)(v5 + 1284) )
          {
            v30 = "Switch to unsecure failed to idle\n";
            goto LABEL_46;
          }
        }
      }
    }
LABEL_49:
    v13 = -22;
LABEL_50:
    _X8 = (unsigned __int64 *)(v5 + 1040);
    __asm { PRFM            #0x11, [X8] }
    do
      v34 = __ldxr(_X8);
    while ( __stxr(v34 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
    gen8_disable_gpu_irq(a1);
    goto LABEL_28;
  }
  v16 = to_gen8_gmu(a1);
  v17 = to_gen8_hfi(a1);
  v18 = *(_BYTE *)(a1 + 8284);
  v19 = *(_QWORD *)(v16 + 32);
  v20 = (_QWORD *)v17;
  HIDWORD(v50[0]) = 0;
  if ( (v18 & 1) == 0
    || (v21 = *(_DWORD *)(v19 + 184),
        v22 = *(_QWORD *)(v19 + 40),
        LODWORD(v50[1]) = 0,
        HIDWORD(v50[1]) = v21,
        LODWORD(v50[2]) = v22,
        LODWORD(v50[0]) = 154,
        (v13 = gen8_hfi_send_cmd_async(a1, (int *)v50, 0x14u)) == 0) )
  {
    v13 = gen8_hwsched_cp_init(a1);
    if ( !v13 )
    {
      if ( *v2 == 1 )
      {
        memset((char *)v50 + 4, 0, 40);
        LODWORD(v50[0]) = 135;
        gen8_cp_init_cmds(a1, (__int64)v50 + 4);
        v13 = gen8_hfi_send_cmd_async(a1, (int *)v50, 0x2Cu);
        if ( v13 )
          goto LABEL_25;
        v25 = gmu_core_timed_poll_check(a1, 146224, 0, 200, 0x800000);
        if ( v25 )
        {
          v13 = v25;
          gen8_spin_idle_debug_lpac(a1);
          goto LABEL_25;
        }
      }
      v26 = *(unsigned __int8 *)(a1 + 8284);
      v27 = *(_QWORD *)(v16 + 32);
      HIDWORD(v50[0]) = 0;
      if ( v26 == 1 )
      {
        v28 = *(_DWORD *)(v27 + 184);
        v29 = *(_QWORD *)(v27 + 40);
        HIDWORD(v50[1]) = v28;
        LODWORD(v50[2]) = v29;
        LODWORD(v50[1]) = 2;
        LODWORD(v50[0]) = 154;
        v13 = gen8_hfi_send_cmd_async(a1, (int *)v50, 0x14u);
        if ( v13 )
          goto LABEL_25;
        if ( (*(_BYTE *)(a1 + 8284) & 1) != 0 )
        {
          _X8 = (unsigned __int64 *)(v16 + 1040);
          __asm { PRFM            #0x11, [X8] }
          do
            v45 = __ldxr(_X8);
          while ( __stxr(v45 | 0x80, _X8) );
        }
      }
      v13 = 0;
    }
  }
LABEL_25:
  v20[120] = 0;
  v20[119] = 0;
  v20[118] = 0;
  v20[117] = 0;
  if ( v13 )
    gen8_disable_gpu_irq(a1);
  adreno_get_bus_counters(a1, v23, v24);
  if ( !v13 )
  {
LABEL_51:
    gen8_set_gmem_protect((_QWORD *)a1);
    if ( (v2[3544] & 1) != 0 )
      goto LABEL_54;
    goto LABEL_52;
  }
LABEL_28:
  if ( (v2[3544] & 1) != 0 )
    goto LABEL_54;
LABEL_52:
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 24LL) )
  {
    gen8_patch_pwrup_reglist(a1);
    v2[3544] = 1;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v13;
}
