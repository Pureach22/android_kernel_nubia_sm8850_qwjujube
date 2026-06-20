__int64 cdsprm_unregister_cdspl3gov()
{
  __int64 v0; // x0

  v0 = raw_spin_lock_irqsave(&qword_A318);
  qword_A4D0 = 0;
  return raw_spin_unlock_irqrestore(&qword_A318, v0);
}
