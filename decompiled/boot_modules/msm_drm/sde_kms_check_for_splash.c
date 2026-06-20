bool __fastcall sde_kms_check_for_splash(__int64 a1)
{
  if ( a1 )
    return *(_DWORD *)(a1 + 2544) != 0;
  printk(&unk_234896, "sde_kms_check_for_splash");
  return 0;
}
