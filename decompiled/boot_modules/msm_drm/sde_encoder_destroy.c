void __fastcall sde_encoder_destroy(__int64 a1)
{
  int v2; // w21

  if ( a1 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
    v2 = *(_DWORD *)(a1 + 196);
    mutex_lock(a1 + 528);
    if ( v2 )
      JUMPOUT(0xDA0A0);
    JUMPOUT(0xDA178);
  }
  printk(&unk_26FCAB, "sde_encoder_destroy");
  JUMPOUT(0xDA1A8);
}
