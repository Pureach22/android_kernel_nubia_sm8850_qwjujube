__int64 __fastcall cnss_utils_update_device_type(unsigned int a1)
{
  __int64 v1; // x20
  __int64 v4; // x1
  void *v5; // x0

  v1 = cnss_utils_priv;
  if ( !cnss_utils_priv )
    return 4294967274LL;
  mutex_lock(cnss_utils_priv + 464);
  printk(&unk_74C5, a1);
  v4 = *(unsigned int *)(v1 + 552);
  if ( (_DWORD)v4 == -1 )
  {
    v4 = a1;
    *(_DWORD *)(v1 + 552) = a1;
    v5 = &unk_7458;
  }
  else
  {
    v5 = &unk_7421;
  }
  printk(v5, v4);
  mutex_unlock(v1 + 464);
  return *(unsigned int *)(v1 + 552);
}
