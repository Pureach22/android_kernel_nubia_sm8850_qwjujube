__int64 __fastcall gsi_ctrl_dev_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  unsigned int *v3; // x8
  __int64 v4; // x23
  __int64 v5; // x22
  char *v8; // x19
  char v9; // w23
  __int64 v10; // x19
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v19; // x8
  int v20; // w0
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x20
  __int64 v25; // x1
  __int64 result; // x0
  unsigned int v27; // w3
  int v28; // w4
  unsigned int v29; // w3
  int v30; // w4
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v35; // x8
  int v36; // w0
  unsigned __int64 v37; // x8
  unsigned __int64 v39; // x9
  __int64 v40; // x1
  void *v41; // x0
  int v42; // w3
  unsigned int v43; // w21
  int v44; // w5
  int v45; // w22
  int v46; // w9
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x9
  unsigned __int64 v49; // x9
  unsigned __int64 v51; // x8
  int v52; // w0
  unsigned __int64 v53; // x8
  unsigned __int64 v55; // x9
  __int64 v56; // x1
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v58; // x9
  unsigned __int64 v59; // x9
  unsigned __int64 v61; // x8
  int v62; // w0
  unsigned __int64 v63; // x8
  unsigned __int64 v65; // x9
  __int64 v66; // x1
  unsigned __int64 v67; // x8
  unsigned __int64 v68; // x9
  int v69; // w0
  unsigned __int64 v70; // x9
  unsigned __int64 v72; // x8
  unsigned __int64 v73; // x8
  unsigned __int64 v75; // x9
  __int64 v76; // x1
  unsigned __int64 v77; // x0
  unsigned __int64 v78; // x21
  __int64 v79; // x20
  int v80; // [xsp+4h] [xbp-2Ch] BYREF
  unsigned __int64 v81; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int64 v82; // [xsp+10h] [xbp-20h]
  __int64 v83; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int64 v84; // [xsp+20h] [xbp-10h]
  __int64 v85; // [xsp+28h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int **)(a1 + 32);
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v4 = *v3;
  if ( (unsigned int)v4 >= 7 )
LABEL_108:
    __break(0x5512u);
  v5 = v4 << 6;
  v80 = 0;
  v8 = (char *)&inst_status + 64 * v4;
  mutex_lock(v8);
  if ( (((unsigned __int64)(unsigned int)v4 << 6) | 0x30) > 0x180 )
    goto LABEL_107;
  v9 = v8[48];
  mutex_unlock(v8);
  if ( (v9 & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&gsi_ctrl_dev_ioctl__rs, "gsi_ctrl_dev_ioctl") )
      printk(&unk_1045C, "gsi_ctrl_dev_ioctl");
    result = -19;
    goto LABEL_99;
  }
  if ( (v5 | 0x38uLL) > 0x180 )
  {
LABEL_107:
    __break(1u);
    goto LABEL_108;
  }
  v10 = *(_QWORD *)(*((_QWORD *)v8 + 7) + 176LL);
  if ( *(_DWORD *)(v10 + 272) )
  {
    if ( a2 <= -2146405886 )
    {
      if ( a2 <= -2147192319 )
      {
        if ( a2 == -2147324157 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v58 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v58 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( v58 > 0x7FFFFFFFFELL )
            goto LABEL_67;
          v59 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v61 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v61 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v61);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v59);
          v62 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v10 + 568, 2);
          v63 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v65 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v65 - 4096);
          _WriteStatusReg(TTBR1_EL1, v65);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v63);
          if ( v62 )
          {
LABEL_67:
            v24 = 0xFFFFFFF200000000LL;
            if ( !v10 )
              goto LABEL_98;
            ipc_log_string(*(_QWORD *)(v10 + 1344), "copy_to_user fail DATAGRAM");
            printk(&unk_11C73, v66);
          }
          else
          {
            v24 = 0;
            if ( !v10 )
              goto LABEL_98;
          }
          ipc_log_string(*(_QWORD *)(v10 + 1344), "Sent NTB datagrams count %d", *(unsigned __int16 *)(v10 + 568));
          goto LABEL_98;
        }
        if ( a2 == -2147193086 )
        {
          v11 = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(v11 + 70) & 0x20) != 0 || (v12 = a3, (*(_QWORD *)v11 & 0x4000000) != 0) )
            v12 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( v12 > 0x7FFFFFFFFCLL )
            goto LABEL_15;
          v13 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v19 = *(_QWORD *)(v11 + 8);
          _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v19);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v13);
          v20 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v10 + 564, 4);
          v21 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v23 - 4096);
          _WriteStatusReg(TTBR1_EL1, v23);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v21);
          if ( v20 )
          {
LABEL_15:
            v24 = 0xFFFFFFF200000000LL;
            if ( v10 )
            {
              ipc_log_string(*(_QWORD *)(v10 + 1344), "copy_to_user failNTB_SIZE");
              printk(&unk_11610, v25);
LABEL_103:
              ipc_log_string(*(_QWORD *)(v10 + 1344), "Sent NTB size %d", *(unsigned int *)(v10 + 564));
            }
          }
          else
          {
            v24 = 0;
            if ( v10 )
              goto LABEL_103;
          }
LABEL_98:
          result = v24 >> 32;
          goto LABEL_99;
        }
        goto LABEL_59;
      }
      if ( a2 != -2147192318 )
      {
        if ( a2 == -2146406652 )
        {
LABEL_40:
          if ( v10 )
            ipc_log_string(
              *(_QWORD *)(v10 + 1344),
              "%s: EP_LOOKUP for prot id:%d",
              "gsi_ctrl_dev_ioctl",
              *(_DWORD *)(v10 + 224));
          v42 = *(_DWORD *)(v10 + 224);
          v43 = *(_DWORD *)(v10 + 532);
          if ( v42 == 4 )
          {
            if ( v43 != -22 )
            {
              v44 = *(_DWORD *)(v10 + 232);
              v45 = -1;
LABEL_76:
              LODWORD(v83) = 2;
              HIDWORD(v83) = v44;
              v84 = __PAIR64__(v43, v45);
              if ( v10 )
              {
                ipc_log_string(
                  *(_QWORD *)(v10 + 1344),
                  "%s: prot id :%d ep_type:%d intf:%d",
                  "gsi_ctrl_dev_ioctl",
                  v42,
                  2,
                  v44);
                ipc_log_string(
                  *(_QWORD *)(v10 + 1344),
                  "%s: ipa_cons_idx:%d ipa_prod_idx:%d",
                  "gsi_ctrl_dev_ioctl",
                  v45,
                  v43);
              }
              v67 = _ReadStatusReg(SP_EL0);
              if ( (*(_BYTE *)(v67 + 70) & 0x20) != 0 || (v68 = a3, (*(_QWORD *)v67 & 0x4000000) != 0) )
                v68 = a3 & ((__int64)(a3 << 8) >> 8);
              v69 = 16;
              if ( v68 <= 0x7FFFFFFFF0LL )
              {
                v70 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v72 = *(_QWORD *)(v67 + 8);
                _WriteStatusReg(TTBR1_EL1, v72 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v72);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v70);
                v69 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v83, 16);
                v73 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v75 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v75 - 4096);
                _WriteStatusReg(TTBR1_EL1, v75);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v73);
              }
              if ( v69 )
                v24 = 0xFFFFFFF200000000LL;
              else
                v24 = 0;
              if ( v10 && v69 )
              {
                ipc_log_string(*(_QWORD *)(v10 + 1344), "copy_to_user fail MBIM");
                printk(&unk_1191D, v76);
                v24 = 0xFFFFFFF200000000LL;
              }
              goto LABEL_98;
            }
          }
          else if ( v43 != -22 || *(_DWORD *)(v10 + 536) != -22 )
          {
            v44 = *(_DWORD *)(v10 + 232);
            v45 = *(_DWORD *)(v10 + 536);
            goto LABEL_76;
          }
          v24 = 0xFFFFFFF500000000LL;
          goto LABEL_98;
        }
        goto LABEL_59;
      }
LABEL_45:
      v46 = *(_DWORD *)(v10 + 224);
      v80 = *(_DWORD *)(v10 + 272);
      if ( v46 == 2 )
        v80 = *(unsigned __int8 *)(v10 + 1352);
      v47 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v47 + 70) & 0x20) != 0 || (v48 = a3, (*(_QWORD *)v47 & 0x4000000) != 0) )
        v48 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v48 > 0x7FFFFFFFFCLL )
        goto LABEL_52;
      v49 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v51 = *(_QWORD *)(v47 + 8);
      _WriteStatusReg(TTBR1_EL1, v51 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v51);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v49);
      v52 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v80, 4);
      v53 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v55 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v55 - 4096);
      _WriteStatusReg(TTBR1_EL1, v55);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v53);
      if ( v52 )
      {
LABEL_52:
        v24 = 0xFFFFFFF200000000LL;
        if ( !v10 )
          goto LABEL_98;
        ipc_log_string(*(_QWORD *)(v10 + 1344), "copy_to_user fail LINE_STATE");
        printk(&unk_10B9B, v56);
      }
      else
      {
        v24 = 0;
        if ( !v10 )
          goto LABEL_98;
      }
      ipc_log_string(
        *(_QWORD *)(v10 + 1344),
        "%s: Sent line_state: %d for prot id:%d",
        "gsi_ctrl_dev_ioctl",
        v80,
        *(_DWORD *)(v10 + 224));
      goto LABEL_98;
    }
    if ( a2 <= 29187 )
    {
      if ( a2 == -2146405885 )
        goto LABEL_40;
      if ( a2 != -2146405882 )
      {
LABEL_59:
        v24 = 0xFFFFFFEA00000000LL;
        if ( !v10 )
          goto LABEL_98;
        ipc_log_string(*(_QWORD *)(v10 + 1344), "wrong parameter");
        v41 = &unk_FF2A;
        goto LABEL_61;
      }
      if ( *(_QWORD *)(v10 + 312) )
      {
        v27 = *(_DWORD *)(v10 + 432);
        v28 = *(_DWORD *)(v10 + 424) * v27;
        v81 = __PAIR64__(v28, v27);
        if ( v10 )
          ipc_log_string(
            *(_QWORD *)(v10 + 1344),
            "prot id :%d OUT: buf_len:%u total_len: %u",
            *(_DWORD *)(v10 + 224),
            v27,
            v28);
      }
      if ( *(_QWORD *)(v10 + 304) )
      {
        v29 = *(_DWORD *)(v10 + 344);
        v30 = *(_DWORD *)(v10 + 336) * v29;
        v82 = __PAIR64__(v30, v29);
        if ( v10 )
          ipc_log_string(
            *(_QWORD *)(v10 + 1344),
            "prot id :%d IN: buf_len:%u total_len:%u\n",
            *(_DWORD *)(v10 + 224),
            v29,
            v30);
      }
      v31 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v31 + 70) & 0x20) != 0 || (v32 = a3, (*(_QWORD *)v31 & 0x4000000) != 0) )
        v32 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v32 > 0x7FFFFFFFF0LL )
        goto LABEL_36;
      v33 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v35 = *(_QWORD *)(v31 + 8);
      _WriteStatusReg(TTBR1_EL1, v35 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v35);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v33);
      v36 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v81, 16);
      v37 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v39 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v39 - 4096);
      _WriteStatusReg(TTBR1_EL1, v39);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v37);
      if ( v36 )
      {
LABEL_36:
        v24 = 0xFFFFFFF200000000LL;
        if ( !v10 )
          goto LABEL_98;
        ipc_log_string(*(_QWORD *)(v10 + 1344), "QTI_CTRL_DATA_BUF_INFO: copy_to_user failed");
        v41 = &unk_117ED;
LABEL_61:
        printk(v41, v40);
        goto LABEL_98;
      }
LABEL_97:
      v24 = 0;
      goto LABEL_98;
    }
    if ( a2 == 29189 )
    {
      if ( *(_DWORD *)(v10 + 224) != 4 )
      {
        v24 = 0;
        *(_DWORD *)(v10 + 1228) = 1;
        goto LABEL_98;
      }
      if ( v10 )
        ipc_log_string(*(_QWORD *)(v10 + 1344), "%s:Modem Online not handled", "gsi_ctrl_dev_ioctl");
      goto LABEL_97;
    }
    if ( a2 != 29188 )
      goto LABEL_59;
    if ( *(_DWORD *)(v10 + 224) == 4 )
    {
      if ( v10 )
        ipc_log_string(*(_QWORD *)(v10 + 1344), "%s:Modem Offline not handled", "gsi_ctrl_dev_ioctl");
      goto LABEL_97;
    }
    *(_DWORD *)(v10 + 1228) = 0;
    gsi_ctrl_clear_cpkt_queues(v10, 1);
    v77 = gsi_ctrl_pkt_alloc(0, 3264);
    if ( v77 < 0xFFFFFFFFFFFFF001LL )
    {
      v78 = v77;
      *(_DWORD *)(v77 + 12) = 3;
      v79 = raw_spin_lock_irqsave(v10 + 1304);
      list_add_tail(v78 + 16, v10 + 1280);
      raw_spin_unlock_irqrestore(v10 + 1304, v79);
      gsi_ctrl_send_notification(v10);
      goto LABEL_97;
    }
    if ( v10 )
    {
      ipc_log_string(*(_QWORD *)(v10 + 1344), "%s: err allocating cpkt\n", "gsi_ctrl_dev_ioctl");
      printk(&unk_11EA6, "gsi_ctrl_dev_ioctl");
    }
    result = -12;
  }
  else
  {
    if ( a2 == -2147193083 )
      goto LABEL_59;
    if ( a2 == -2147192318 )
      goto LABEL_45;
    if ( v10 )
    {
      ipc_log_string(*(_QWORD *)(v10 + 1344), "%s:cmd %u failed, USB not connected\n", "gsi_ctrl_dev_ioctl", a2);
      printk(&unk_117C6, "gsi_ctrl_dev_ioctl");
    }
    result = -104;
  }
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return result;
}
