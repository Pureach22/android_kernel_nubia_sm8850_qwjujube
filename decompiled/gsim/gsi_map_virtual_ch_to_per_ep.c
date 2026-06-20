__int64 __fastcall gsi_map_virtual_ch_to_per_ep(unsigned int a1, unsigned int a2)
{
  if ( gsi_ctx )
  {
    if ( *(_QWORD *)gsi_ctx )
    {
      gsihal_write_reg_nk(119, a1, a2);
      return 0;
    }
    else
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d access to GSI HW has not been mapped\n",
        "gsi_map_virtual_ch_to_per_ep",
        5384);
      return 4294967290LL;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_map_virtual_ch_to_per_ep", 5379);
    return 4294967288LL;
  }
}
