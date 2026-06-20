__int64 gf_irq()
{
  char v1[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v2; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[0] = 1;
  pm_wakeup_ws_event(&fp_wakelock, 2500, 0);
  printk(&unk_941E);
  sendnlmsg(v1);
  _ReadStatusReg(SP_EL0);
  return 1;
}
