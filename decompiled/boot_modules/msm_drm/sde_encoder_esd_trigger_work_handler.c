__int64 __fastcall sde_encoder_esd_trigger_work_handler(__int64 a1)
{
  __int64 v1; // x0

  v1 = a1 - 1104;
  if ( v1 )
    return sde_encoder_resource_control(v1, 1);
  else
    return printk(&unk_268E21, "sde_encoder_esd_trigger_work_handler");
}
