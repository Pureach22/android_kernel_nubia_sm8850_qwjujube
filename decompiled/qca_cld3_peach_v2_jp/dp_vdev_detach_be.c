__int64 __fastcall dp_vdev_detach_be(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 32) != 4 )
    dp_tx_put_bank_profile(a1, a2);
  return 0;
}
