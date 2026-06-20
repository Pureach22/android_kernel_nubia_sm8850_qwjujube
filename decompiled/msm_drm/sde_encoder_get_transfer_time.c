__int64 __fastcall sde_encoder_get_transfer_time(__int64 result, _DWORD *a2)
{
  if ( !result || !a2 )
    return printk(&unk_22AC3A, "sde_encoder_get_transfer_time");
  *a2 = *(_DWORD *)(result + 4740);
  return result;
}
