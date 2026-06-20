__int64 __fastcall sde_connector_state_get_mode_info(__int64 a1, void *dest)
{
  if ( a1 && dest )
  {
    memcpy(dest, (const void *)(a1 + 2208), 0x388u);
    return 0;
  }
  else
  {
    printk(&unk_2249AA, "sde_connector_state_get_mode_info");
    return 4294967274LL;
  }
}
