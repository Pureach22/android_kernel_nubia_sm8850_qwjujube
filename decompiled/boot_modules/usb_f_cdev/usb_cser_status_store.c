__int64 __fastcall usb_cser_status_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v5; // x20
  __int64 v6; // x3
  __int64 v7; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD **)(a1 + 176);
  v9[0] = 0;
  if ( a2 )
  {
    if ( (unsigned int)kstrtou8(a2, 0, v9) || v9[0] )
    {
      printk(&unk_9252, "usb_cser_status_store", v9[0], v6);
    }
    else
    {
      v7 = raw_spin_lock_irqsave((char *)v5 + 1068);
      v5[196] = 0;
      v5[197] = 0;
      v5[198] = 0;
      v5[199] = 0;
      raw_spin_unlock_irqrestore((char *)v5 + 1068, v7);
    }
  }
  else
  {
    printk(&unk_8E7B, "usb_cser_status_store", a3, a4);
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
