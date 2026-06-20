__int64 cleanup_module()
{
  __int64 result; // x0

  mutex_lock(&pil_reloc_lock);
  iounmap(reloc_0);
  reloc_0 = 0;
  mutex_unlock(&pil_reloc_lock);
  result = iounmap(pil_timeout_base);
  pil_timeout_base = 0;
  return result;
}
