__int64 __fastcall cpu_hot_execute_cdev(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w21
  void *v5; // x0

  mutex_lock(&cpu_hot_lock);
  v2 = *(_DWORD *)(a1 - 80);
  if ( *(_BYTE *)(a1 - 76) != 1 )
  {
    if ( (*(_BYTE *)(a1 - 75) & 1) != 0 )
      return mutex_unlock(&cpu_hot_lock);
    mutex_unlock(&cpu_hot_lock);
    v3 = add_cpu(v2);
    mutex_lock(&cpu_hot_lock);
    if ( !v3 )
    {
      *(_BYTE *)(a1 - 75) = 1;
      return mutex_unlock(&cpu_hot_lock);
    }
    v5 = &unk_682F;
    goto LABEL_11;
  }
  if ( *(_BYTE *)(a1 - 75) )
  {
    mutex_unlock(&cpu_hot_lock);
    v3 = remove_cpu(v2);
    mutex_lock(&cpu_hot_lock);
    if ( (v3 & 0x80000000) == 0 )
    {
      *(_BYTE *)(a1 - 75) = 0;
      return mutex_unlock(&cpu_hot_lock);
    }
    v5 = &unk_6888;
LABEL_11:
    printk(v5, v2, v3);
  }
  return mutex_unlock(&cpu_hot_lock);
}
