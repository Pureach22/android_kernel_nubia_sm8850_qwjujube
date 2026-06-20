__int64 __fastcall msm_geni_serial_isr(__int64 a1, __int64 a2)
{
  __int64 v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = raw_spin_lock_irqsave(a2);
  msm_geni_serial_handle_isr(a2, v4, 0);
  raw_spin_unlock_irqrestore(a2, v4[0]);
  _ReadStatusReg(SP_EL0);
  return 1;
}
