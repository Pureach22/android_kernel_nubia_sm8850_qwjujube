__int64 __fastcall cdsprm_register_cdspl3gov(__int64 result)
{
  __int64 *v1; // x19
  __int64 v2; // x0

  if ( result )
  {
    v1 = (__int64 *)result;
    v2 = raw_spin_lock_irqsave(&qword_A318);
    qword_A4D0 = *v1;
    return raw_spin_unlock_irqrestore(&qword_A318, v2);
  }
  return result;
}
