__int64 proxy_invalid_map()
{
  _warn_printk("Trying to map with SMMU proxy driver when it has not fully probed!\n");
  __break(0x800u);
  return 4294967274LL;
}
