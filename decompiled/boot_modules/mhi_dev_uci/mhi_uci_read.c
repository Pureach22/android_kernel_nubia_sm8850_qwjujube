unsigned __int64 __fastcall mhi_uci_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x23
  __int64 v6; // x19
  _QWORD *v7; // x24
  unsigned __int64 v8; // x8
  __int64 v9; // x22
  unsigned __int64 v10; // x25
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v12; // x9
  int v13; // w0
  unsigned __int64 v14; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  int v24; // w22
  unsigned __int64 v25; // x8
  int v26; // w8
  int v27; // w0
  _QWORD *v29; // x22
  _QWORD *v30; // x9
  _QWORD *v31; // x8
  __int64 v32; // x10
  __int64 v33; // x0
  __int64 v34; // x0
  _QWORD v35[6]; // [xsp+0h] [xbp-30h] BYREF

  v35[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    a3 = -22;
    goto LABEL_31;
  }
  v3 = *(_QWORD *)(a1 + 32);
  v6 = *(_QWORD *)(v3 + 32);
  if ( *(_QWORD *)(v3 + 352) && !*(_DWORD *)(v3 + 360) )
    ipc_log_string();
  mutex_lock(v3 + 272);
  raw_spin_lock_bh(v3 + 232);
  if ( (*(_BYTE *)(v3 + 340) & 1) == 0 )
  {
    raw_spin_unlock_bh(v3 + 232);
LABEL_29:
    v24 = -512;
    goto LABEL_30;
  }
  v7 = *(_QWORD **)(v3 + 256);
  if ( !v7 )
  {
    v29 = (_QWORD *)(v3 + 240);
    if ( *(_QWORD *)(v3 + 240) != v3 + 240 )
      goto LABEL_33;
    if ( *(_QWORD *)(v3 + 352) && !*(_DWORD *)(v3 + 360) )
      ipc_log_string();
    raw_spin_unlock_bh(v3 + 232);
    if ( *(_BYTE *)(v3 + 340) == 1 && (_QWORD *)*v29 == v29 )
    {
      memset(v35, 0, 40);
      init_wait_entry(v35, 0);
      v34 = prepare_to_wait_event(v3 + 208, v35, 1);
      if ( *(_BYTE *)(v3 + 340) == 1 )
      {
        while ( (_QWORD *)*v29 == v29 )
        {
          if ( v34 )
          {
            if ( (_DWORD)v34 != -512 )
              goto LABEL_51;
            if ( *(_QWORD *)(v3 + 352) && *(_DWORD *)(v3 + 360) <= 1u )
              ipc_log_string();
            goto LABEL_29;
          }
          schedule();
          v34 = prepare_to_wait_event(v3 + 208, v35, 1);
          if ( (*(_BYTE *)(v3 + 340) & 1) == 0 )
            break;
        }
      }
      finish_wait(v3 + 208, v35);
    }
LABEL_51:
    raw_spin_lock_bh(v3 + 232);
    if ( (*(_BYTE *)(v3 + 340) & 1) == 0 )
    {
      if ( *(_QWORD *)(v3 + 352) && *(_DWORD *)(v3 + 360) <= 1u )
        ipc_log_string();
      v24 = -512;
      goto LABEL_65;
    }
    v7 = *(_QWORD **)(v3 + 256);
    if ( !v7 )
    {
LABEL_33:
      v30 = (_QWORD *)*v29;
      _ZF = *v29 == (_QWORD)v29;
      v24 = -5;
      if ( _ZF || (v7 = v30 - 2, v30 == qword_10) )
      {
LABEL_65:
        raw_spin_unlock_bh(v3 + 232);
LABEL_30:
        mutex_unlock(v3 + 272);
        a3 = v24;
        goto LABEL_31;
      }
      v31 = (_QWORD *)v30[1];
      if ( (_QWORD *)*v31 == v30 && (v32 = *v30, *(_QWORD **)(*v30 + 8LL) == v30) )
      {
        *(_QWORD *)(v32 + 8) = v31;
        *v31 = v32;
      }
      else
      {
        _list_del_entry_valid_or_report(v30);
      }
      *v30 = 0xDEAD000000000100LL;
      v30[1] = 0xDEAD000000000122LL;
      *(_QWORD *)(v3 + 256) = v7;
      v33 = *(_QWORD *)(v3 + 352);
      *(_QWORD *)(v3 + 264) = *(v30 - 1);
      if ( v33 && !*(_DWORD *)(v3 + 360) )
      {
        ipc_log_string();
        v7 = *(_QWORD **)(v3 + 256);
      }
    }
  }
  raw_spin_unlock_bh(v3 + 232);
  v8 = *(_QWORD *)(v3 + 264);
  if ( v8 < a3 )
    a3 = *(_QWORD *)(v3 + 264);
  if ( a3 >> 31 )
  {
    v13 = a3;
    __break(0x800u);
  }
  else
  {
    v9 = *v7;
    v10 = v7[1] - v8;
    _check_object_size(*v7 + v10, a3, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v12 = a2 & ((__int64)(a2 << 8) >> 8);
    v13 = a3;
    if ( 0x8000000000LL - a3 >= v12 )
    {
      v14 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v20 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v20);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v14);
      v13 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v9 + v10, a3);
      v21 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v23 - 4096);
      _WriteStatusReg(TTBR1_EL1, v23);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v21);
    }
  }
  v24 = v13;
  if ( v13 )
    goto LABEL_30;
  if ( *(_QWORD *)(v3 + 352) && !*(_DWORD *)(v3 + 360) )
    ipc_log_string();
  v25 = *(_QWORD *)(v3 + 264) - a3;
  *(_QWORD *)(v3 + 264) = v25;
  if ( v25 )
    goto LABEL_23;
  raw_spin_lock_bh(v3 + 232);
  v26 = *(unsigned __int8 *)(v3 + 340);
  *(_QWORD *)(v3 + 256) = 0;
  if ( v26 != 1 )
  {
    v24 = -512;
    goto LABEL_61;
  }
  v27 = mhi_queue_buf(v6, 2, *v7, *(_QWORD *)(v3 + 328), 2);
  if ( v27 )
  {
    v24 = v27;
LABEL_61:
    printk(&unk_7E17, "mhi_uci_read");
    if ( *(_QWORD *)(v3 + 352) && *(_DWORD *)(v3 + 360) <= 2u )
      ipc_log_string();
    kfree(*v7);
    goto LABEL_65;
  }
  raw_spin_unlock_bh(v3 + 232);
LABEL_23:
  if ( *(_QWORD *)(v3 + 352) && !*(_DWORD *)(v3 + 360) )
    ipc_log_string();
  mutex_unlock(v3 + 272);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return a3;
}
