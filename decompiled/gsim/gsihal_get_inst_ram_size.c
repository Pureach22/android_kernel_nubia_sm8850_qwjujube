__int64 gsihal_get_inst_ram_size()
{
  unsigned int v0; // w8

  v0 = *(_DWORD *)gsihal_ctx - 1;
  if ( v0 < 0xB && ((0x6FFu >> v0) & 1) != 0 )
    return (__int64)*(&off_2F2B0 + v0);
  dev_err(
    *(_QWORD *)(gsi_ctx + 8),
    "%s:%d GSI version is not supported %d\n",
    "gsihal_get_inst_ram_size",
    2432,
    *(_DWORD *)gsihal_ctx);
  __break(0x800u);
  return 0;
}
