__int64 __fastcall ghd_rm_get_vmid(unsigned int a1, __int16 *a2)
{
  unsigned int v2; // w19
  __int16 v5; // w8

  if ( a1 <= 4 )
  {
    raw_spin_lock(&gh_vm_table_lock);
    if ( gh_rm_core_initialized == 1 )
    {
      v5 = gh_vm_table[52 * a1];
      if ( !a1 || gh_vm_table[52 * a1] )
      {
        v2 = 0;
        if ( a2 )
          *a2 = v5;
      }
      else
      {
        v2 = -22;
      }
    }
    else
    {
      v2 = -517;
    }
    raw_spin_unlock(&gh_vm_table_lock);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v2;
}
