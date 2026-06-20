__int64 __fastcall gsi_wdi3_write_evt_ring_db(unsigned int a1)
{
  __int64 v2; // x1
  __int64 v3; // x8
  __int64 v4; // x0

  if ( !gsi_ctx )
    return printk(&unk_2DEB9, "gsi_wdi3_write_evt_ring_db", 5399);
  v2 = *(unsigned int *)(gsi_ctx + 20);
  if ( *(_DWORD *)(gsi_ctx + 16) < 8u )
  {
    gsihal_write_reg_nk(44, v2, a1);
    v3 = gsi_ctx;
    v4 = 45;
  }
  else
  {
    gsihal_write_reg_nk(42, v2, a1);
    v3 = gsi_ctx;
    v4 = 43;
  }
  return gsihal_write_reg_nk(v4, *(unsigned int *)(v3 + 20), a1);
}
