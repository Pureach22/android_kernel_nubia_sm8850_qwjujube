__int64 __fastcall sg_read(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x23
  __int64 v9; // x19
  __int64 v10; // x26
  __int64 v14; // x9
  unsigned __int64 v15; // x10
  unsigned __int64 v17; // x10
  unsigned __int64 v23; // x11
  unsigned __int64 v25; // x10
  unsigned __int64 v27; // x11
  __int64 v28; // x9
  unsigned __int64 v29; // x10
  unsigned __int64 v31; // x9
  unsigned __int64 v33; // x10
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  __int64 v37; // x9
  unsigned __int64 v38; // x10
  unsigned __int64 v40; // x9
  unsigned __int64 v42; // x10
  __int64 v43; // x21
  __int64 v44; // x9
  unsigned __int64 v45; // x10
  __int64 v47; // x21
  __int64 v48; // x0
  __int64 v49; // x23
  __int64 v50; // x1
  __int64 rq_mark; // x21
  __int64 *v52; // x27
  char v53; // w8
  char v54; // w8
  __int64 v55; // x0
  char v56; // w28
  __int64 v57; // x0
  __int64 v58; // x22
  int v59; // w9
  _BOOL4 v60; // w9
  unsigned int v61; // w9
  unsigned int v62; // w9
  unsigned int v63; // w9
  __int64 v64; // x10
  unsigned int v65; // w10
  unsigned __int64 v66; // x20
  int v67; // w9
  _QWORD v68[5]; // [xsp+8h] [xbp-38h] BYREF
  char v69[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+38h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = _ReadStatusReg(SP_EL0);
  v70 = *(_QWORD *)(StatusReg + 1808);
  v5 = *(_QWORD *)(a1 + 56);
  v6 = *(_QWORD *)(v4 + 2296);
  v69[0] = 0;
  if ( v5 != v6 )
  {
    v7 = -1;
    if ( (sg_check_file_access___already_done & 1) == 0 )
    {
      sg_check_file_access___already_done = 1;
      _task_pid_nr_ns(v4, 1, 0);
      printk(&unk_B5E7, "sg_read");
    }
    goto LABEL_4;
  }
  v9 = *(_QWORD *)(a1 + 32);
  v7 = -6;
  if ( !v9 )
    goto LABEL_4;
  v10 = *(_QWORD *)(v9 + 16);
  if ( !v10 )
    goto LABEL_4;
  LODWORD(_X22) = -1;
  if ( a3 >= 0x24 && *(_BYTE *)(v9 + 4904) )
  {
    v14 = a2 + 4;
    if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v15 = a2 + 4, (*(_QWORD *)v4 & 0x4000000) != 0) )
      v15 = v14 & (v14 << 8 >> 8);
    v7 = -14;
    if ( v15 >= 0x7FFFFFFFFDLL )
      goto LABEL_4;
    _X9 = v14 & 0xFF7FFFFFFFFFFFFFLL;
    v17 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v23 = *(_QWORD *)(v4 + 8);
    _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v23);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v17);
    __asm { LDTR            W9, [X9] }
    v25 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v27 - 4096);
    _WriteStatusReg(TTBR1_EL1, v27);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v25);
    if ( (_X9 & 0x80000000) != 0 )
    {
      if ( a3 >= 0x40 && (*(_QWORD *)v4 & 0x400000) != 0 )
      {
        v37 = a2 + 36;
        if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v38 = a2 + 36, (*(_QWORD *)v4 & 0x4000000) != 0) )
          v38 = v37 & (v37 << 8 >> 8);
        v7 = -14;
        if ( v38 >= 0x7FFFFFFFFDLL )
          goto LABEL_4;
        _X8 = v37 & 0xFF7FFFFFFFFFFFFFLL;
        v40 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v42 = *(_QWORD *)(v4 + 8);
        _WriteStatusReg(TTBR1_EL1, v42 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v42);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v40);
        __asm { LDTR            W22, [X8] }
        v43 = a1;
        uaccess_ttbr0_disable(a1);
        a1 = v43;
      }
      else
      {
        LODWORD(_X22) = -1;
        if ( a3 >= 0x58 )
        {
          v44 = a2 + 48;
          if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v45 = a2 + 48, (*(_QWORD *)v4 & 0x4000000) != 0) )
            v45 = v44 & (v44 << 8 >> 8);
          v7 = -14;
          if ( v45 >= 0x7FFFFFFFFDLL )
            goto LABEL_4;
          _X22 = v44 & 0xFF7FFFFFFFFFFFFFLL;
          v47 = a1;
          v48 = uaccess_ttbr0_enable();
          __asm { LDTR            W22, [X22] }
          uaccess_ttbr0_disable(v48);
          a1 = v47;
        }
      }
    }
    else
    {
      v28 = a2 + 8;
      if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v29 = a2 + 8, (*(_QWORD *)v4 & 0x4000000) != 0) )
        v29 = v28 & (v28 << 8 >> 8);
      v7 = -14;
      if ( v29 >= 0x7FFFFFFFFDLL )
        goto LABEL_4;
      _X8 = v28 & 0xFF7FFFFFFFFFFFFFLL;
      v31 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = *(_QWORD *)(v4 + 8);
      _WriteStatusReg(TTBR1_EL1, v33 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v31);
      __asm { LDTR            W22, [X8] }
      v34 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v36 - 4096);
      _WriteStatusReg(TTBR1_EL1, v36);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v34);
    }
  }
  v49 = a1;
  v69[0] = 0;
  v50 = raw_write_lock_irqsave(v9 + 48);
  v52 = (__int64 *)(v9 + 144);
  rq_mark = *(_QWORD *)(v9 + 144);
  if ( rq_mark == v9 + 144 )
    goto LABEL_44;
  v53 = 0;
  while ( 1 )
  {
    if ( *(_BYTE *)(rq_mark + 242) || (_DWORD)_X22 != -1 && *(_DWORD *)(rq_mark + 104) != (_DWORD)_X22 )
      goto LABEL_35;
    if ( *(_BYTE *)(rq_mark + 243) )
      break;
    v53 = 1;
LABEL_35:
    rq_mark = *(_QWORD *)rq_mark;
    if ( (__int64 *)rq_mark == v52 )
    {
      v69[0] = v53;
LABEL_44:
      raw_write_unlock_irqrestore(v9 + 48, v50);
      goto LABEL_45;
    }
  }
  if ( *(_BYTE *)(rq_mark + 243) != 1 )
    goto LABEL_35;
  v69[0] = v53;
  *(_BYTE *)(rq_mark + 243) = 2;
  raw_write_unlock_irqrestore(v9 + 48, v50);
  if ( rq_mark )
    goto LABEL_47;
LABEL_45:
  v54 = *(_BYTE *)(v49 + 49);
  v7 = -11;
  if ( (v54 & 8) != 0 )
    goto LABEL_4;
  rq_mark = sg_get_rq_mark(v9, (unsigned int)_X22, v69);
  if ( rq_mark )
  {
LABEL_47:
    if ( !*(_DWORD *)(rq_mark + 56) )
      goto LABEL_67;
    goto LABEL_48;
  }
  if ( (v69[0] & 1) == 0 && *(_DWORD *)(v10 + 112) )
  {
LABEL_80:
    LODWORD(v7) = -19;
    goto LABEL_81;
  }
  memset(v68, 0, sizeof(v68));
  init_wait_entry(v68, 0);
  while ( 2 )
  {
    v7 = prepare_to_wait_event(v9 + 24, v68, 1);
    v55 = raw_write_lock_irqsave(v9 + 48);
    rq_mark = *v52;
    v56 = 0;
    if ( (__int64 *)*v52 == v52 )
    {
LABEL_53:
      v57 = raw_write_unlock_irqrestore(v9 + 48, v55);
      goto LABEL_54;
    }
    while ( 2 )
    {
      if ( *(_BYTE *)(rq_mark + 242) || (_DWORD)_X22 != -1 && *(_DWORD *)(rq_mark + 104) != (_DWORD)_X22 )
        goto LABEL_59;
      if ( !*(_BYTE *)(rq_mark + 243) )
      {
        v56 = 1;
        goto LABEL_59;
      }
      if ( *(_BYTE *)(rq_mark + 243) != 1 )
      {
LABEL_59:
        rq_mark = *(_QWORD *)rq_mark;
        if ( (__int64 *)rq_mark == v52 )
          goto LABEL_53;
        continue;
      }
      break;
    }
    *(_BYTE *)(rq_mark + 243) = 2;
    v57 = raw_write_unlock_irqrestore(v9 + 48, v55);
    if ( !rq_mark )
    {
LABEL_54:
      if ( (v56 & 1) == 0 && *(_DWORD *)(v10 + 112) )
      {
        finish_wait(v9 + 24, v68);
        goto LABEL_80;
      }
      if ( v7 )
      {
        if ( !(_DWORD)v7 )
          goto LABEL_80;
LABEL_81:
        v7 = (int)v7;
        goto LABEL_4;
      }
      schedule(v57);
      continue;
    }
    break;
  }
  v69[0] = v56;
  finish_wait(v9 + 24, v68);
  if ( *(_DWORD *)(rq_mark + 56) )
  {
LABEL_48:
    v7 = sg_new_read(v9, a2, a3, rq_mark);
    goto LABEL_4;
  }
LABEL_67:
  v58 = _kmalloc_cache_noprof(_mutex_init, 3520, 36);
  v7 = -12;
  if ( v58 )
  {
    v59 = *(_DWORD *)(rq_mark + 96);
    *(_DWORD *)v58 = v59;
    *(_DWORD *)(v58 + 4) = v59;
    *(_DWORD *)(v58 + 8) = *(_DWORD *)(rq_mark + 104);
    v60 = *(unsigned __int8 *)(rq_mark + 53) >= 0xC0u && *(unsigned __int8 *)(rq_mark + 64) == 12;
    v61 = *(_DWORD *)(v58 + 16) & 0xFFFFFFFE | v60;
    *(_DWORD *)(v58 + 16) = v61;
    v62 = v61 & 0xFFFFFFC1 | (2 * (*(_BYTE *)(rq_mark + 121) & 0x1F));
    *(_DWORD *)(v58 + 16) = v62;
    v63 = v62 & 0xFFFFC03F | ((unsigned __int8)*(_WORD *)(rq_mark + 124) << 6);
    *(_DWORD *)(v58 + 16) = v63;
    *(_DWORD *)(v58 + 16) = v63 & 0xFFC03FFF | (*(unsigned __int8 *)(rq_mark + 126) << 14);
    if ( (*(_BYTE *)(rq_mark + 121) & 1) != 0 || (~*(unsigned __int8 *)(rq_mark + 144) & 0x70) == 0 )
    {
      *(_DWORD *)(v58 + 16) = v63 & 0xFFC03FFF | 0x20000;
      v64 = *(_QWORD *)(rq_mark + 144);
      *(_QWORD *)(v58 + 28) = *(_QWORD *)(rq_mark + 152);
      *(_QWORD *)(v58 + 20) = v64;
    }
    v65 = *(unsigned __int16 *)(rq_mark + 124);
    LODWORD(v66) = 0;
    v67 = 0;
    if ( v65 > 0xB )
      goto LABEL_91;
    if ( ((1 << v65) & 0x370) != 0 )
      goto LABEL_78;
    if ( ((1 << v65) & 0xC00) == 0 )
    {
      if ( v65 == 7 )
      {
        LODWORD(v66) = -5;
        v67 = 5;
        if ( !*(_BYTE *)(rq_mark + 144) )
        {
          v67 = *(_BYTE *)(rq_mark + 121) ? 5 : 0;
          if ( !*(_BYTE *)(rq_mark + 121) )
            LODWORD(v66) = 0;
        }
        goto LABEL_94;
      }
LABEL_91:
      if ( v65 - 1 >= 3 )
      {
        if ( *(_WORD *)(rq_mark + 124) )
        {
LABEL_78:
          LODWORD(v66) = -5;
          v67 = 5;
        }
      }
      else
      {
        LODWORD(v66) = -5;
        v67 = 16;
      }
    }
LABEL_94:
    *(_DWORD *)(v58 + 12) = v67;
    if ( a3 >= 0x24
      && (inline_copy_to_user(a2, v58, 36)
       || (*(int *)(v58 + 4) >= a3 ? (v66 = a3) : (v66 = *(int *)(v58 + 4)),
           v66 >= 0x25 && (unsigned int)sg_read_oxfer(rq_mark, a2 + 36, (unsigned int)(v66 - 36)))) )
    {
      v7 = -14;
    }
    else
    {
      sg_finish_rem_req(rq_mark);
      sg_remove_request(v9, rq_mark);
      v7 = (int)v66;
    }
    kfree(v58);
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return v7;
}
