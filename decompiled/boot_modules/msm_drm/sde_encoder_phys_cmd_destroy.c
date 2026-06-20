__int64 __fastcall sde_encoder_phys_cmd_destroy(__int64 a1)
{
  if ( a1 )
    return kfree(a1);
  else
    return printk(&unk_26FCAB, "sde_encoder_phys_cmd_destroy");
}
