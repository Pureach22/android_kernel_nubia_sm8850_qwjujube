__int64 __fastcall sde_encoder_get_fps(__int64 a1)
{
  if ( a1 )
    return *(unsigned int *)(a1 + 3944);
  printk(&unk_26FCAB, "sde_encoder_get_fps");
  return 0;
}
