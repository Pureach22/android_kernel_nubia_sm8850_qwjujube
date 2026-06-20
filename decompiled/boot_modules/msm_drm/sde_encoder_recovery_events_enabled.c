__int64 __fastcall sde_encoder_recovery_events_enabled(__int64 a1)
{
  if ( a1 )
    return *(_BYTE *)(a1 + 1369) & 1;
  printk(&unk_23BA87, "sde_encoder_recovery_events_enabled");
  return 0;
}
