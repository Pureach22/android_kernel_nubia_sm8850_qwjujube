__int64 __fastcall sde_encoder_enable_recovery_event(__int64 result)
{
  if ( !result )
    return printk(&unk_23BA87, "sde_encoder_enable_recovery_event");
  *(_BYTE *)(result + 1369) = 1;
  return result;
}
