__int64 __fastcall richtap_file_unlocked_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v5; // x19
  __int64 v6; // x1
  __int64 v7; // x2
  void (__fastcall *v8)(_QWORD); // x8
  unsigned __int64 v9; // x8
  __int64 v10; // x21
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  unsigned __int64 v18; // x8
  size_t v19; // x2
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  void (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x1
  void (__fastcall *v25)(__int64, __int64); // x8
  _DWORD *v26; // x8
  __int64 v27; // x1
  unsigned __int64 StatusReg; // x8
  char v29; // w9
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x9
  unsigned __int64 v33; // x8
  __int64 v34; // x0
  unsigned __int64 v35; // x8
  unsigned __int64 v37; // x9
  __int64 v38; // x1
  void (__fastcall *v39)(__int64, __int64); // x8
  __int64 result; // x0
  unsigned __int64 v41; // x8
  char v42; // w10
  unsigned __int64 v43; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8
  unsigned __int64 v49; // x9
  void (__fastcall *v50)(_QWORD); // x8
  void (__fastcall *v51)(_QWORD); // x8
  _DWORD *v52; // x8
  void (__fastcall *v53)(__int64, __int64); // x8
  __int64 v54; // x1
  void (__fastcall *v55)(__int64, __int64); // x8
  int v56; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 32);
  v56 = 0;
  printk(&unk_16B9F, "richtap_file_unlocked_ioctl", (unsigned int)a2, a3);
  if ( a2 <= 21000 )
  {
    if ( a2 != 20995 )
    {
      if ( a2 == 20997 )
      {
        if ( a3 >= 0x80 )
          v38 = 128;
        else
          v38 = a3;
        v39 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1480) + 136LL);
        if ( *((_DWORD *)v39 - 1) != 487251822 )
          __break(0x8228u);
        v39(v5, v38);
        goto LABEL_39;
      }
      if ( a2 == 20998 )
      {
LABEL_39:
        result = 0;
        goto LABEL_51;
      }
      goto LABEL_66;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    v29 = *(_BYTE *)(StatusReg + 70);
    v56 = 5;
    if ( (v29 & 0x20) != 0 || (v30 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v30 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v30 < 0x7FFFFFFFFDLL )
    {
      v31 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v33 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v31);
      v34 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v56, 4);
      v35 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v37 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v37 - 4096);
      _WriteStatusReg(TTBR1_EL1, v37);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v35);
      goto LABEL_45;
    }
LABEL_50:
    result = -14;
    goto LABEL_51;
  }
  if ( a2 <= 21008 )
  {
    if ( a2 != 21001 )
    {
      if ( a2 == 21002 )
      {
        printk(&unk_14EFB, "haptic_hv", 1497, "richtap_file_unlocked_ioctl");
        richtap_clean_buf(v5);
        mutex_lock(v5 + 752);
        v50 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1480) + 240LL);
        if ( *((_DWORD *)v50 - 1) != -2072377296 )
          __break(0x8228u);
        v50(v5);
        v51 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1480) + 56LL);
        if ( *((_DWORD *)v51 - 1) != -2072377296 )
          __break(0x8228u);
        v51(v5);
        mutex_unlock(v5 + 752);
        v52 = *(_DWORD **)(*(_QWORD *)(v5 + 1480) + 272LL);
        if ( *(v52 - 1) != 487251822 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v52)(v5, 0);
        *(_DWORD *)(v5 + 1724) = 0;
        v53 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1480) + 280LL);
        if ( *((_DWORD *)v53 - 1) != -746885483 )
          __break(0x8228u);
        v53(v5, 2);
        v54 = *(unsigned int *)(v5 + 48);
        v55 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1480) + 160LL);
        if ( *((_DWORD *)v55 - 1) != 487251822 )
          __break(0x8228u);
        v55(v5, v54);
        v6 = *(_QWORD *)(v5 + 1096);
        v7 = v5 + 1608;
        goto LABEL_6;
      }
LABEL_66:
      dev_err(*(_QWORD *)(v5 + 800), "%s, unknown cmd\n", "richtap_file_unlocked_ioctl");
      goto LABEL_39;
    }
    mutex_lock(v5 + 752);
    v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1480) + 56LL);
    if ( *((_DWORD *)v8 - 1) != -2072377296 )
      __break(0x8228u);
    v8(v5);
    mutex_unlock(v5 + 752);
    v9 = _ReadStatusReg(SP_EL0);
    v10 = *(_QWORD *)(v5 + 1544);
    if ( (*(_BYTE *)(v9 + 70) & 0x20) != 0 || (v11 = a3, (*(_QWORD *)v9 & 0x4000000) != 0) )
      v11 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v11 > 0x7FFFFFC180LL )
    {
      v19 = 16000;
    }
    else
    {
      v12 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v18 = *(_QWORD *)(v9 + 8);
      _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v18);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v12);
      v19 = _arch_copy_from_user(v10, a3 & 0xFF7FFFFFFFFFFFFFLL, 16000);
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v22 - 4096);
      _WriteStatusReg(TTBR1_EL1, v22);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      if ( !v19 )
      {
        v56 = **(_DWORD **)(v5 + 1544);
        if ( v56 >= 15997 )
        {
          dev_err(*(_QWORD *)(v5 + 800), "rtp mode date len error %d\n", v56);
          result = -22;
          goto LABEL_51;
        }
        v23 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1480) + 280LL);
        if ( *((_DWORD *)v23 - 1) != -746885483 )
          __break(0x8228u);
        v23(v5, 2);
        v24 = *(unsigned int *)(v5 + 48);
        v25 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1480) + 160LL);
        if ( *((_DWORD *)v25 - 1) != 487251822 )
          __break(0x8228u);
        v25(v5, v24);
        if ( richtap_rtp_start(v5) )
        {
          v26 = *(_DWORD **)(*(_QWORD *)(v5 + 1480) + 208LL);
          v27 = *(_QWORD *)(v5 + 1544) + 4LL;
          if ( *(v26 - 1) != -962088293 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v26)(v5, v27, (unsigned int)v56);
        }
        goto LABEL_39;
      }
    }
    memset((void *)(v10 - v19 + 16000), 0, v19);
    goto LABEL_50;
  }
  if ( a2 != 21009 )
  {
    if ( a2 == 21010 )
    {
      v6 = *(_QWORD *)(v5 + 1096);
      v7 = v5 + 1640;
LABEL_6:
      queue_work_on(32, v6, v7);
      goto LABEL_39;
    }
    if ( a2 == 21011 )
    {
      printk(&unk_14A82, "haptic_hv", 1522, "richtap_file_unlocked_ioctl");
      goto LABEL_39;
    }
    goto LABEL_66;
  }
  v41 = _ReadStatusReg(SP_EL0);
  v42 = *(_BYTE *)(v41 + 70);
  v56 = *(_DWORD *)(v5 + 96);
  if ( (v42 & 0x20) != 0 || (v43 = a3, (*(_QWORD *)v41 & 0x4000000) != 0) )
    v43 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v43 >= 0x7FFFFFFFFDLL )
    goto LABEL_50;
  v44 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v46 = *(_QWORD *)(v41 + 8);
  _WriteStatusReg(TTBR1_EL1, v46 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v46);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v44);
  v34 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v56, 4);
  v47 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v49 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v49 - 4096);
  _WriteStatusReg(TTBR1_EL1, v49);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v47);
LABEL_45:
  if ( v34 )
    result = -14;
  else
    result = 0;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
