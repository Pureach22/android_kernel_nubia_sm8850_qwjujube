__int64 __fastcall device_ioctl(file *filp, unsigned int cmd, unsigned __int64 arg)
{
  unsigned __int64 StatusReg; // x8
  char v5; // w9
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x9
  unsigned __int64 v13; // x8
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9
  __int64 result; // x0
  unsigned __int64 v19; // x2
  unsigned int v20; // w0
  int v21; // w1
  unsigned __int64 v22; // x1
  int v23; // w0
  int v24; // w2
  int v25; // w0
  unsigned __int64 v26; // x1
  int v27; // w19
  int v28; // w20
  unsigned __int64 v29; // x21
  int v30; // w19
  unsigned __int64 v31; // x20
  int v32; // w21
  int v33; // w19
  unsigned __int64 v34; // x20
  int pid[2]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v36; // [xsp+8h] [xbp-28h]
  __int64 v37; // [xsp+10h] [xbp-20h]
  __int64 v38; // [xsp+18h] [xbp-18h]
  unsigned __int64 identifier; // [xsp+20h] [xbp-10h]
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_BYTE *)(StatusReg + 70);
  v38 = 0;
  identifier = 0;
  v36 = 0;
  v37 = 0;
  *(_QWORD *)pid = 0;
  if ( (v5 & 0x20) != 0 || (v6 = arg, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v6 = arg & ((__int64)(arg << 8) >> 8);
  if ( v6 > 0x7FFFFFFFD8LL )
    goto LABEL_6;
  v7 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v13 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v13);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v7);
  v14 = _arch_copy_from_user(pid, arg & 0xFF7FFFFFFFFFFFFFLL, 40);
  v15 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v17 - 4096);
  _WriteStatusReg(TTBR1_EL1, v17);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v15);
  if ( v14 )
  {
LABEL_6:
    result = -14;
  }
  else
  {
    switch ( cmd )
    {
      case 0x4028671Eu:
        v19 = identifier;
        v21 = pid[0];
        v20 = pid[1];
        if ( ifas_log_enable )
        {
          v27 = pid[1];
          v28 = pid[0];
          v29 = identifier;
          printk(&unk_10762, "ifas_notify_qudeq_gpu");
          v19 = v29;
          v21 = v28;
          v20 = v27;
        }
        perfmgr_notify_qudeq_gpu(v20, v21, v19);
        result = 0;
        break;
      case 0x4028670Fu:
        v22 = identifier;
        v23 = pid[0];
        v24 = pid[1];
        if ( ifas_log_enable )
        {
          v30 = pid[0];
          v31 = identifier;
          v32 = pid[1];
          printk(&unk_F335, "ifas_notify_connect");
          v22 = v31;
          v23 = v30;
          v24 = v32;
        }
        perfmgr_notify_connect(v23, v22, v24);
        result = 0;
        break;
      case 0x40286701u:
        if ( pid[1] )
        {
          result = 0;
        }
        else
        {
          v25 = pid[0];
          v26 = identifier;
          if ( ifas_log_enable )
          {
            v33 = pid[0];
            v34 = identifier;
            printk(&unk_EA66, "ifas_notify_qudeq");
            v26 = v34;
            v25 = v33;
          }
          perfmgr_notify_qudeq(v25, v26);
          result = 0;
        }
        break;
      default:
        printk(&unk_F244, "../soc-repo/drivers/vendor/soc/qcom/ifas/ifas_main.c");
        result = -1;
        break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
