__int64 __fastcall spss_utils_ioctl(__int64 a1, unsigned int a2, unsigned __int64 a3)
{
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x9
  size_t v8; // x22
  unsigned __int64 v9; // x1
  __int64 result; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  int v21; // w8
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x9
  unsigned __int64 v26; // x8
  int v27; // w0
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x9
  __int64 v31; // x2
  __int64 v32; // x9
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x10
  size_t v35; // x2
  __int64 v36; // x20
  __int64 v37; // x0
  __int64 v38; // x0
  int v39; // w8
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x9
  unsigned __int64 v42; // x9
  unsigned __int64 v44; // x8
  int v45; // w0
  unsigned __int64 v46; // x8
  unsigned __int64 v48; // x9
  __int64 v49; // x20
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x9
  unsigned __int64 v54; // x8
  int v55; // w0
  unsigned __int64 v56; // x8
  unsigned __int64 v58; // x9
  unsigned __int64 v59; // x10
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x8
  unsigned __int64 v64; // x9
  __int64 v65; // x19
  __int64 v66; // x2
  __int64 v67; // x2
  __int64 v68; // x2
  __int64 v69; // x0
  int v70; // w21
  void *v71; // x0
  const char *v72; // x1
  void *v73; // x0
  const char *v74; // x1
  int v75; // w19
  __int64 v76; // x0
  _QWORD s[128]; // [xsp+8h] [xbp-488h] BYREF
  __int64 v78; // [xsp+408h] [xbp-88h] BYREF
  __int64 v79; // [xsp+410h] [xbp-80h]
  __int64 v80; // [xsp+418h] [xbp-78h]
  __int64 v81; // [xsp+420h] [xbp-70h]
  __int64 v82; // [xsp+428h] [xbp-68h]
  __int64 v83; // [xsp+430h] [xbp-60h]
  __int64 v84; // [xsp+438h] [xbp-58h]
  __int64 v85; // [xsp+440h] [xbp-50h]
  __int64 v86; // [xsp+448h] [xbp-48h]
  __int64 v87; // [xsp+450h] [xbp-40h]
  __int64 v88; // [xsp+458h] [xbp-38h]
  __int64 v89; // [xsp+460h] [xbp-30h]
  __int64 v90; // [xsp+468h] [xbp-28h]
  __int64 v91; // [xsp+470h] [xbp-20h]
  __int64 v92; // [xsp+478h] [xbp-18h]
  __int64 v93; // [xsp+480h] [xbp-10h]
  __int64 v94; // [xsp+488h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a3 )
  {
    printk(&unk_92E9, "spss_utils_ioctl");
LABEL_104:
    result = -22;
    goto LABEL_105;
  }
  v5 = HIWORD(a2) & 0x3FFF;
  if ( (a2 & 0x40000000) != 0 && (_DWORD)v5 )
  {
    if ( (unsigned int)v5 >= 0x401 )
    {
      v71 = &unk_8BDC;
      v72 = "spss_utils_ioctl";
      goto LABEL_103;
    }
    _check_object_size(s, HIWORD(a2) & 0x3FFF, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v7 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v7 = a3 & ((__int64)(a3 << 8) >> 8);
    v8 = HIWORD(a2) & 0x3FFF;
    if ( 0x8000000000LL - v5 < v7 )
      goto LABEL_9;
    v11 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v11);
    v8 = _arch_copy_from_user(s, a3 & 0xFF7FFFFFFFFFFFFFLL, HIWORD(a2) & 0x3FFF);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    if ( v8 )
    {
LABEL_9:
      if ( v5 - v8 <= 0x400 )
        v9 = 1024 - (v5 - v8);
      else
        v9 = 0;
      if ( v9 < v8 )
      {
        _fortify_panic(15);
        goto LABEL_109;
      }
      memset((char *)s + v5 - v8, 0, v8);
      if ( v8 )
      {
        printk(&unk_85D5, "spss_utils_ioctl");
        result = -14;
LABEL_105:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
  }
  if ( (int)a2 <= -1072934143 )
  {
    if ( a2 != -1073196285 )
    {
      if ( a2 == -1073196284 )
      {
        if ( (_DWORD)v5 == 8 )
        {
          mutex_lock(&event_lock);
          if ( LODWORD(s[0]) < 8 )
          {
            if ( spss_events_signaled[LODWORD(s[0])] )
              v21 = 43690;
            else
              v21 = 0xFFFF;
            HIDWORD(s[0]) = v21;
            mutex_unlock(&event_lock);
            v22 = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(v22 + 70) & 0x20) != 0 || (v23 = a3, (*(_QWORD *)v22 & 0x4000000) != 0) )
              v23 = a3 & ((__int64)(a3 << 8) >> 8);
            if ( v23 > 0x7FFFFFFFF8LL )
            {
              v27 = 8;
LABEL_91:
              v75 = v27;
LABEL_100:
              printk(&unk_8EB7, "spss_utils_ioctl");
              result = v75;
              goto LABEL_105;
            }
            v24 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v26 = *(_QWORD *)(v22 + 8);
            _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v26);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v24);
            v27 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, s, 8);
            v28 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v30 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v30 - 4096);
            _WriteStatusReg(TTBR1_EL1, v30);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v28);
            if ( v27 )
              goto LABEL_91;
            goto LABEL_67;
          }
          v73 = &unk_9122;
          v74 = "spss_is_event_signaled";
          goto LABEL_94;
        }
        v71 = &unk_8741;
        v72 = "spss_utils_ioctl";
LABEL_103:
        printk(v71, v72);
        goto LABEL_104;
      }
      if ( a2 == -1073458427 )
      {
        if ( (_DWORD)v5 == 4 )
        {
          if ( is_iar_active == 1 )
          {
            is_ssr_disabled = LODWORD(s[0]) != 0;
            printk(&unk_8858, "spss_utils_ioctl");
          }
          printk(&unk_8EEF, "spss_utils_ioctl");
          result = 0;
          goto LABEL_105;
        }
        v71 = &unk_8741;
        v72 = "spss_utils_ioctl";
        goto LABEL_103;
      }
LABEL_81:
      printk(&unk_930F, "spss_utils_ioctl");
      result = -515;
      goto LABEL_105;
    }
    if ( (_DWORD)v5 != 8 )
    {
      v71 = &unk_8741;
      v72 = "spss_utils_ioctl";
      goto LABEL_103;
    }
    mutex_lock(&event_lock);
    v49 = LODWORD(s[0]);
    if ( LODWORD(s[0]) > 7 )
    {
      v73 = &unk_9122;
    }
    else
    {
      if ( spss_events_signaled[LODWORD(s[0])] != 1 )
      {
        complete_all(&spss_events[8 * LODWORD(s[0])]);
        HIDWORD(s[0]) = 43690;
        spss_events_signaled[v49] = 1;
        mutex_unlock(&event_lock);
        v50 = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(v50 + 70) & 0x20) != 0 || (v51 = a3, (*(_QWORD *)v50 & 0x4000000) != 0) )
          v51 = a3 & ((__int64)(a3 << 8) >> 8);
        if ( v51 > 0x7FFFFFFFF8LL )
        {
          v55 = 8;
        }
        else
        {
          v52 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v54 = *(_QWORD *)(v50 + 8);
          _WriteStatusReg(TTBR1_EL1, v54 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v54);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v52);
          v55 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, s, 8);
          v56 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v58 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v58 - 4096);
          _WriteStatusReg(TTBR1_EL1, v58);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v56);
          if ( !v55 )
            goto LABEL_67;
        }
        v75 = v55;
        goto LABEL_100;
      }
      v73 = &unk_88E1;
    }
    v74 = "spss_signal_event";
LABEL_94:
    printk(v73, v74);
    mutex_unlock(&event_lock);
    goto LABEL_104;
  }
  if ( a2 == -1072934142 )
  {
    if ( (_DWORD)v5 != 12 )
    {
      v71 = &unk_8741;
      v72 = "spss_utils_ioctl";
      goto LABEL_103;
    }
    v36 = LODWORD(s[0]);
    if ( LODWORD(s[0]) >= 8 )
    {
      v71 = &unk_9122;
      v72 = "spss_wait_for_event";
      goto LABEL_103;
    }
    if ( HIDWORD(s[0]) )
    {
      v37 = _msecs_to_jiffies((unsigned int)(1000 * HIDWORD(s[0])));
      v38 = wait_for_completion_interruptible_timeout(&spss_events[8 * v36], v37);
      if ( !v38 )
      {
        printk(&unk_8774, "spss_wait_for_event");
        v39 = 61153;
        goto LABEL_52;
      }
      if ( (v38 & 0x80000000) == 0 )
      {
LABEL_51:
        v39 = 43690;
LABEL_52:
        LODWORD(s[1]) = v39;
        goto LABEL_53;
      }
    }
    else
    {
      LODWORD(v38) = wait_for_completion_interruptible(&spss_events[8 * LODWORD(s[0])]);
      if ( (v38 & 0x80000000) == 0 )
        goto LABEL_51;
    }
    v70 = v38;
    printk(&unk_8450, "spss_wait_for_event");
    LODWORD(s[1]) = 61154;
    if ( v70 == -512 )
    {
      result = -512;
      goto LABEL_105;
    }
LABEL_53:
    v40 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v40 + 70) & 0x20) != 0 || (v41 = a3, (*(_QWORD *)v40 & 0x4000000) != 0) )
      v41 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v41 > 0x7FFFFFFFF4LL )
    {
      v45 = 12;
    }
    else
    {
      v42 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v44 = *(_QWORD *)(v40 + 8);
      _WriteStatusReg(TTBR1_EL1, v44 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v44);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v42);
      v45 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, s, 12);
      v46 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v48 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v48 - 4096);
      _WriteStatusReg(TTBR1_EL1, v48);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v46);
      if ( !v45 )
      {
LABEL_67:
        result = 0;
        goto LABEL_105;
      }
    }
    v75 = v45;
    goto LABEL_100;
  }
  if ( a2 != -1072671994 )
    goto LABEL_81;
  is_iar_active = 1;
  if ( !cmac_mem )
  {
    v31 = arm64_use_ng_mappings ? 0x68000000000F13LL : 0x68000000000713LL;
    cmac_mem = ioremap_prot(cmac_mem_addr, 4096, v31);
    if ( !cmac_mem )
    {
      printk(&unk_8719, "spss_utils_ioctl");
      result = -14;
      goto LABEL_105;
    }
  }
  v32 = s[0];
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  if ( LODWORD(s[1]) != 128 )
  {
    v71 = &unk_9198;
    v72 = "spss_handle_set_fw_and_apps_cmac";
    goto LABEL_103;
  }
  if ( HIDWORD(s[1]) >= 9 )
  {
    v71 = &unk_9242;
    v72 = "spss_handle_set_fw_and_apps_cmac";
    goto LABEL_103;
  }
  v33 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v33 + 70) & 0x20) != 0 || (v34 = s[0], (*(_QWORD *)v33 & 0x4000000) != 0) )
    v34 = s[0] & ((__int64)(s[0] << 8) >> 8);
  if ( v34 <= 0x7FFFFFFF80LL )
  {
    v59 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v61 = *(_QWORD *)(v33 + 8);
    _WriteStatusReg(TTBR1_EL1, v61 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v61);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v59);
    v35 = _arch_copy_from_user(&v78, v32 & 0xFF7FFFFFFFFFFFFFLL, 128);
    v62 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v64 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v64 - 4096);
    _WriteStatusReg(TTBR1_EL1, v64);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v62);
    if ( !v35 )
      goto LABEL_69;
  }
  else
  {
    v35 = 128;
  }
  if ( v35 < 0x81 )
  {
    memset((char *)&v78 - v35 + 128, 0, v35);
LABEL_69:
    v65 = cmac_mem;
    saved_fw_cmac = v78;
    qword_9798 = v79;
    qword_97F0 = v90;
    qword_97F8 = v91;
    qword_9800 = v92;
    qword_9808 = v93;
    qword_97D0 = v86;
    qword_97D8 = v87;
    qword_97E0 = v88;
    qword_97E8 = v89;
    qword_97B0 = v82;
    qword_97B8 = v83;
    qword_97C0 = v84;
    qword_97C8 = v85;
    saved_apps_cmac = v80;
    qword_97A8 = v81;
    if ( cmac_mem )
    {
      writel_relaxed((unsigned int)saved_fw_cmac, cmac_mem, v35);
      writel_relaxed(HIDWORD(saved_fw_cmac), v65 + 4, v66);
      writel_relaxed((unsigned int)qword_9798, v65 + 8, v67);
      v69 = writel_relaxed(HIDWORD(qword_9798), v65 + 12, v68);
    }
    else
    {
      v69 = printk(&unk_866E, "spss_set_saved_fw_cmac");
    }
    spss_set_saved_uefi_apps_cmac(v69);
    result = 0;
    goto LABEL_105;
  }
LABEL_109:
  v76 = _fortify_panic(15);
  return spss_set_saved_uefi_apps_cmac(v76);
}
