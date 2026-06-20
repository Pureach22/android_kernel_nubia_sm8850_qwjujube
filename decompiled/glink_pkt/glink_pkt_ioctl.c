__int64 __fastcall glink_pkt_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  __int64 result; // x0
  int v7; // w8
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x11
  int v11; // w21
  unsigned __int64 v13; // x11
  unsigned __int64 v19; // x9
  unsigned __int64 v21; // x9
  unsigned __int64 v23; // x10
  unsigned __int8 v24; // w21
  unsigned __int64 v25; // x1
  __int64 v26; // x0
  int signals; // w0
  unsigned __int64 v28; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v30; // x10
  unsigned __int64 v31; // x9
  __int64 v33; // x0
  unsigned __int64 v34; // x20
  int v35; // w22
  _QWORD v36[3]; // [xsp+8h] [xbp-18h] BYREF

  v36[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v36[0] = 0;
  v36[1] = 0;
  if ( !v3 || *(_DWORD *)(v3 + 1128) == 1 )
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_ioctl__rs, "glink_pkt_ioctl") )
      printk("%s[%s]: invalid device handle\n", byte_9300, "glink_pkt_ioctl");
    ipc_log_string(glink_pkt_ilctxt, "%s[%s]: invalid device handle\n", (const char *)&unk_90F5, "glink_pkt_ioctl");
    result = -22;
    goto LABEL_44;
  }
  if ( (unsigned int)mutex_lock_interruptible(v3 + 1048) )
  {
    result = -512;
    goto LABEL_44;
  }
  if ( (completion_done(v3 + 1096) & 1) != 0 )
  {
    v7 = a2;
    if ( a2 <= 21525 )
    {
      v25 = a3;
      switch ( a2 )
      {
        case -1072643327:
          v34 = a3;
          v11 = -14;
          if ( !inline_copy_from_user(v36, v25) )
          {
            v35 = glink_pkt_zerocopy_receive(v3, v36);
            if ( inline_copy_to_user(v34, v36, 16) )
              v11 = -14;
            else
              v11 = v35;
          }
          goto LABEL_43;
        case -1072643326:
          v11 = -14;
          if ( !inline_copy_from_user(v36, v25) )
            v11 = glink_pkt_zerocopy_done(v3, v36);
          goto LABEL_43;
        case 21525:
          v26 = raw_spin_lock_irqsave(v3 + 1148);
          *(_DWORD *)(v3 + 1224) = 0;
          raw_spin_unlock_irqrestore(v3 + 1148, v26);
          signals = qcom_glink_get_signals(*(_QWORD *)(*(_QWORD *)(v3 + 1136) + 968LL));
          v28 = a3;
          v11 = signals;
          if ( (signals & 0x80000000) == 0 )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0
              || (v30 = *(_QWORD *)StatusReg, v31 = v28, (v30 & 0x4000000) != 0) )
            {
              v31 = v28 & ((__int64)(v28 << 8) >> 8);
            }
            v11 = -14;
            if ( v31 <= 0x7FFFFFFFFCLL )
            {
              _W21 = signals;
              v33 = uaccess_ttbr0_enable();
              __asm { STTR            W21, [X20] }
              uaccess_ttbr0_disable(v33);
              v11 = 0;
            }
          }
          goto LABEL_43;
      }
    }
    else
    {
      if ( (unsigned int)(a2 - 21526) < 3 )
      {
        v8 = _ReadStatusReg(SP_EL0);
        v9 = a3;
        if ( (*(_BYTE *)(v8 + 70) & 0x20) != 0 || (v10 = a3, (*(_QWORD *)v8 & 0x4000000) != 0) )
          v10 = a3 & ((__int64)(a3 << 8) >> 8);
        v11 = -14;
        if ( v10 <= 0x7FFFFFFFFCLL )
        {
          _X10 = v9 & 0xFF7FFFFFFFFFFFFFLL;
          v13 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v19 = *(_QWORD *)(v8 + 8);
          _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v19);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v13);
          __asm { LDTR            W20, [X10] }
          v21 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v23 - 4096);
          _WriteStatusReg(TTBR1_EL1, v23);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v21);
          if ( v7 == 21528 )
          {
            v24 = ~(_BYTE)_X20;
          }
          else if ( v7 == 21527 )
          {
            v24 = _X20;
            LOBYTE(_X20) = 0;
          }
          else
          {
            v24 = 0;
          }
          ipc_log_string(
            glink_pkt_ilctxt,
            "[%s]: set[0x%x] clear[0x%x]\n",
            "glink_pkt_tiocmset",
            _X20 & 0xC6,
            v24 & 0xC6);
          v11 = qcom_glink_set_signals(
                  *(_QWORD *)(*(_QWORD *)(v3 + 1136) + 968LL),
                  (unsigned __int8)_X20 & 0xC6,
                  v24 & 0xC6);
        }
        goto LABEL_43;
      }
      v11 = 0;
      if ( a2 == 1074053888 )
      {
LABEL_43:
        mutex_unlock(v3 + 1048);
        result = v11;
        goto LABEL_44;
      }
    }
    if ( (unsigned int)__ratelimit(&glink_pkt_ioctl__rs_54, "glink_pkt_ioctl") )
      printk("%s[%s]: unrecognized ioctl command 0x%x\n", byte_9300, "glink_pkt_ioctl", a2);
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: unrecognized ioctl command 0x%x\n",
      (const char *)&unk_90F5,
      "glink_pkt_ioctl",
      a2);
    v11 = -515;
    goto LABEL_43;
  }
  if ( (unsigned int)__ratelimit(&glink_pkt_ioctl__rs_53, "glink_pkt_ioctl") )
    printk("%s[%s]: %s channel in reset\n", byte_9300, "glink_pkt_ioctl", *(const char **)(v3 + 1512));
  ipc_log_string(
    glink_pkt_ilctxt,
    "%s[%s]: %s channel in reset\n",
    (const char *)&unk_90F5,
    "glink_pkt_ioctl",
    *(const char **)(v3 + 1512));
  mutex_unlock(v3 + 1048);
  result = -102;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
