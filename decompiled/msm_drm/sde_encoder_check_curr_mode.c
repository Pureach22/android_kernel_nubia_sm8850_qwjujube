bool __fastcall sde_encoder_check_curr_mode(__int64 a1, int a2)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 648) == a2;
  printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
  return 0;
}
