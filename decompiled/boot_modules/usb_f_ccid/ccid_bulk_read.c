__int64 __fastcall ccid_bulk_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x20
  __int64 v4; // x23
  int v6; // w21
  __int64 v7; // x1
  int v8; // w24
  __int64 *v9; // x21
  __int64 v10; // x2
  __int64 v11; // x0
  __int64 v12; // x22
  unsigned __int64 v13; // x2
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  __int64 v30; // x0
  __int64 v31; // x19
  _QWORD *v32; // x20
  __int64 v33; // x21
  _QWORD v34[6]; // [xsp+0h] [xbp-30h] BYREF

  v3 = a3;
  v34[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0x401 )
  {
    printk(&unk_8038, "ccid_bulk_read", 1024);
    result = -12;
  }
  else
  {
    v4 = *(_QWORD *)(a1 + 32);
    if ( *(_DWORD *)(v4 + 464) )
    {
      printk(&unk_8467, "ccid_bulk_read", a3);
      LODWORD(v3) = -5;
LABEL_44:
      result = (int)v3;
      goto LABEL_45;
    }
    v6 = *(unsigned __int16 *)(*(_QWORD *)(v4 + 256) + 64LL);
    v7 = raw_spin_lock_irqsave(v4 + 228);
    if ( *(_DWORD *)(v4 + 232) )
    {
      v8 = (v3 + v6 - 1) & -v6;
      while ( 1 )
      {
        v9 = *(__int64 **)(v4 + 528);
        *((_DWORD *)v9 + 2) = v8;
        *(_DWORD *)(v4 + 536) = 0;
        raw_spin_unlock_irqrestore(v4 + 228, v7);
        if ( (usb_ep_queue(*(_QWORD *)(v4 + 256), v9, 3264) & 0x80000000) != 0 )
          break;
        if ( !*(_DWORD *)(v4 + 536) && !*(_DWORD *)(v4 + 464) && *(_DWORD *)(v4 + 232) )
        {
          memset(v34, 0, 40);
          init_wait_entry(v34, 0);
          while ( 1 )
          {
            v11 = prepare_to_wait_event(v4 + 480, v34, 1);
            if ( *(_DWORD *)(v4 + 536) || *(_DWORD *)(v4 + 464) || !*(_DWORD *)(v4 + 232) )
            {
              finish_wait(v4 + 480, v34);
              goto LABEL_16;
            }
            if ( v11 )
              break;
            schedule();
          }
          if ( (v11 & 0x80000000) != 0 )
          {
            LODWORD(v3) = v11;
            *(_DWORD *)(v4 + 464) = 1;
            usb_ep_dequeue(*(_QWORD *)(v4 + 256), v9);
            goto LABEL_44;
          }
        }
LABEL_16:
        if ( *(_DWORD *)(v4 + 464) )
        {
          LODWORD(v3) = -5;
          goto LABEL_44;
        }
        v12 = raw_spin_lock_irqsave(v4 + 228);
        if ( !*(_DWORD *)(v4 + 232) )
        {
          v15 = v4 + 228;
          v16 = v12;
LABEL_43:
          raw_spin_unlock_irqrestore(v15, v16);
          LODWORD(v3) = -19;
          goto LABEL_44;
        }
        v13 = *((unsigned int *)v9 + 22);
        if ( (_DWORD)v13 )
        {
          if ( v13 > v3 )
          {
            printk(&unk_81E6, "ccid_bulk_read", v13);
            v13 = *((unsigned int *)v9 + 22);
          }
          if ( v13 >= v3 )
            v3 = (unsigned int)v3;
          else
            v3 = (unsigned int)v13;
          *(_DWORD *)(v4 + 472) = 1;
          raw_spin_unlock_irqrestore(v4 + 228, v12);
          v17 = *v9;
          _check_object_size(v17, v3, 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v19 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v19 = a2 & ((__int64)(a2 << 8) >> 8);
          if ( 0x8000000000LL - v3 >= v19 )
          {
            v20 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v26 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v26);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v20);
            _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v17, v3);
            v27 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v29 - 4096);
            _WriteStatusReg(TTBR1_EL1, v29);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v27);
          }
          v30 = raw_spin_lock_irqsave(v4 + 228);
          *(_DWORD *)(v4 + 472) = 0;
          v31 = v30;
          if ( *(_DWORD *)(v4 + 232) )
          {
            raw_spin_unlock_irqrestore(v4 + 228, v30);
            goto LABEL_44;
          }
          v32 = *(_QWORD **)(v4 + 528);
          if ( v32 )
          {
            v33 = *(_QWORD *)(v4 + 256);
            kfree(*v32);
            usb_ep_free_request(v33, v32);
          }
          v15 = v4 + 228;
          v16 = v31;
          goto LABEL_43;
        }
        raw_spin_unlock_irqrestore(v4 + 228, v12);
        v7 = raw_spin_lock_irqsave(v4 + 228);
        if ( !*(_DWORD *)(v4 + 232) )
          goto LABEL_23;
      }
      printk(&unk_830D, "ccid_bulk_read", v10);
      LODWORD(v3) = -5;
      *(_DWORD *)(v4 + 464) = 1;
      goto LABEL_44;
    }
LABEL_23:
    raw_spin_unlock_irqrestore(v4 + 228, v7);
    result = -19;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
