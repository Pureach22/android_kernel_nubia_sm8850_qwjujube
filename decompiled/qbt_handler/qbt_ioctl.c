__int64 __fastcall qbt_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x21
  signed __int64 v6; // x20
  unsigned __int64 StatusReg; // x8
  char v8; // w9
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v16; // x8
  int v17; // w0
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  __int64 result; // x0
  _DWORD *v22; // x20
  int v23; // w0
  int v24; // w19
  __int64 v25; // x20
  void *v26; // x0
  void *v27; // x0
  __int64 v28; // x0
  unsigned int v29; // w19
  __int64 v30; // x0
  unsigned int v33; // w9
  unsigned int v36; // w8
  unsigned int v37; // w8
  _QWORD v38[2]; // [xsp+0h] [xbp-10h] BYREF

  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v3 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    if ( a3 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(*(_QWORD *)(v3 + 288), "%s: invalid user space pointer %lu\n", "qbt_ioctl", a3);
      result = -22;
    }
    else
    {
      mutex_lock(v3 + 312);
      switch ( a2 )
      {
        case 'd':
          LOBYTE(v38[0]) = *(_BYTE *)(v3 + 1144);
          v24 = inline_copy_to_user(a3, v38, 1);
          printk(&unk_A0E5, "qbt_ioctl");
          if ( !v24 )
            goto LABEL_16;
          v25 = 0xFFF200000000LL;
          v26 = &unk_A1AF;
          goto LABEL_53;
        case 'e':
          v38[0] = 0;
          if ( inline_copy_from_user((int)v38, a3, 8u) )
            goto LABEL_52;
          input_event(*(_QWORD *)(v3 + 280), 1, LODWORD(v38[0]), HIDWORD(v38[0]));
          input_event(*(_QWORD *)(v3 + 280), 0, 0, 0);
          v6 = 0;
          goto LABEL_17;
        case 'f':
          if ( (*(_BYTE *)(v3 + 464) & 1) != 0 )
            goto LABEL_45;
          enable_irq(*(unsigned int *)(v3 + 460));
          v27 = &unk_9374;
          *(_BYTE *)(v3 + 464) = 1;
          goto LABEL_49;
        case 'g':
          if ( *(_BYTE *)(v3 + 464) == 1 )
          {
            disable_irq(*(unsigned int *)(v3 + 460));
            *(_BYTE *)(v3 + 464) = 0;
            v27 = &unk_938E;
            goto LABEL_49;
          }
LABEL_45:
          printk(&unk_952A, "qbt_ioctl");
          v6 = 0;
          goto LABEL_17;
        case 'h':
          if ( *(_BYTE *)(v3 + 1144) != 1 || (*(_BYTE *)(v3 + 560) & 1) != 0 )
            goto LABEL_35;
          enable_irq(*(unsigned int *)(v3 + 512));
          v27 = &unk_9180;
          *(_BYTE *)(v3 + 560) = 1;
          goto LABEL_49;
        case 'i':
          if ( *(_BYTE *)(v3 + 1144) == 1 && (*(_BYTE *)(v3 + 560) & 1) != 0 )
          {
            disable_irq(*(unsigned int *)(v3 + 512));
            *(_BYTE *)(v3 + 560) = 0;
            v27 = &unk_9199;
            goto LABEL_49;
          }
LABEL_35:
          printk(&unk_98E0, "qbt_ioctl");
          v6 = 0;
          goto LABEL_17;
        case 'j':
          v6 = 0xFFFFFFEA00000000LL;
          printk(&unk_A1E3, "qbt_ioctl");
          goto LABEL_17;
        case 'k':
          if ( !*(_DWORD *)(v3 + 6280) )
          {
            printk(&unk_9D62, "qbt_ioctl");
            pm_stay_awake(*(_QWORD *)(v3 + 288));
          }
          v6 = 0;
          _X8 = (unsigned int *)(v3 + 6280);
          __asm { PRFM            #0x11, [X8] }
          do
            v33 = __ldxr(_X8);
          while ( __stxr(v33 + 1, _X8) );
          goto LABEL_17;
        case 'l':
          if ( !*(_DWORD *)(v3 + 6280) )
            goto LABEL_16;
          _X9 = (unsigned int *)(v3 + 6280);
          __asm { PRFM            #0x11, [X9] }
          do
          {
            v36 = __ldxr(_X9);
            v37 = v36 - 1;
          }
          while ( __stlxr(v37, _X9) );
          __dmb(0xBu);
          if ( v37 )
            goto LABEL_16;
          printk(&unk_95CF, "qbt_ioctl");
          pm_relax(*(_QWORD *)(v3 + 288));
          v6 = 0;
          goto LABEL_17;
        case 'm':
          StatusReg = _ReadStatusReg(SP_EL0);
          v8 = *(_BYTE *)(StatusReg + 70);
          LODWORD(v38[0]) = 3;
          if ( (v8 & 0x20) != 0 || (v9 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v9 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( v9 <= 0x7FFFFFFFFCLL )
          {
            v10 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v16 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v16);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v10);
            v17 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v38, 4);
            v18 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v20 - 4096);
            _WriteStatusReg(TTBR1_EL1, v20);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v18);
            if ( !v17 )
            {
LABEL_16:
              v6 = 0;
              goto LABEL_17;
            }
          }
          v26 = &unk_9AFB;
          v6 = 0xFFFFFFF200000000LL;
          goto LABEL_54;
        case 'n':
        case 'p':
          v22 = (_DWORD *)(v3 + 568);
          if ( inline_copy_from_user((int)v3 + 568, a3, 4u) )
            goto LABEL_52;
          if ( (*v22 & 0xFFFFFFFE) == 2 )
          {
            v23 = v3 + 568;
            if ( *v22 == 2 )
            {
              if ( !inline_copy_from_user(v23, a3, 0x23u) )
              {
                *(_BYTE *)(v3 + 600) = *(_BYTE *)(v3 + 572);
LABEL_51:
                printk(&unk_9913, "qbt_ioctl");
                printk(&unk_A3F3, "qbt_ioctl");
                printk(&unk_9547, "qbt_ioctl");
                printk(&unk_9EC6, "qbt_ioctl");
                printk(&unk_A424, "qbt_ioctl");
                v6 = 0;
                goto LABEL_17;
              }
            }
            else if ( !inline_copy_from_user(v23, a3, 0x24u) )
            {
              goto LABEL_51;
            }
LABEL_52:
            v25 = 0xFFF200000000LL;
            v26 = &unk_9C85;
          }
          else
          {
            v25 = 0xFFEA00000000LL;
            v26 = &unk_9978;
          }
LABEL_53:
          v6 = v25 & 0xFFFFFFFFFFFFLL | 0xFFFF000000000000LL;
LABEL_54:
          printk(v26, "qbt_ioctl");
LABEL_17:
          mutex_unlock(v3 + 312);
          result = v6 >> 32;
          break;
        case 'o':
          LODWORD(v38[0]) = 0;
          if ( inline_copy_from_user((int)v38, a3, 4u) )
            goto LABEL_52;
          printk(&unk_9D80, "qbt_ioctl");
          v28 = *(unsigned int *)(v3 + 1048);
          if ( (v28 & 0x80000000) != 0 )
          {
            v27 = &unk_9E0F;
LABEL_49:
            printk(v27, "qbt_ioctl");
            v6 = 0;
          }
          else
          {
            v29 = v38[0];
            v30 = gpio_to_desc(v28);
            gpiod_set_raw_value(v30, v29);
            v6 = 0;
          }
          goto LABEL_17;
        default:
          printk(&unk_985F, "qbt_ioctl");
          v6 = 0xFFFFFDFD00000000LL;
          goto LABEL_17;
      }
    }
  }
  else
  {
    printk(&unk_9A11, "qbt_ioctl");
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
