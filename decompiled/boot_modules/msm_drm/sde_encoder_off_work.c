__int64 __fastcall sde_encoder_off_work(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21

  v1 = a1 - 944;
  if ( a1 == 944 )
    return printk(&unk_268E21, "sde_encoder_off_work");
  _ReadStatusReg(SP_EL0);
  v2 = a1 - 48;
  mutex_lock(a1 - 48);
  sde_encoder_resource_control(v1, 6);
  return mutex_unlock(v2);
}
