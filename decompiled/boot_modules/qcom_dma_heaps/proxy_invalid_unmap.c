__int64 proxy_invalid_unmap()
{
  __int64 result; // x0

  result = _warn_printk("Trying to unmap with SMMU proxy driver when it has not fully probed!\n");
  __break(0x800u);
  return result;
}
