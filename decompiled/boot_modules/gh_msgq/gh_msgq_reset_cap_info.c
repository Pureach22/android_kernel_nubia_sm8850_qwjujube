__int64 __fastcall gh_msgq_reset_cap_info(int a1, int a2, _DWORD *a3)
{
  _UNKNOWN **v6; // x22
  int v7; // w8
  _UNKNOWN **v8; // x21
  __int64 result; // x0
  int v10; // w8
  void *v11; // x0

  if ( !a3 )
    return 4294967274LL;
  raw_spin_lock(&gh_msgq_cap_list_lock);
  v6 = &gh_msgq_cap_list;
  do
  {
    v6 = (_UNKNOWN **)*v6;
    if ( v6 == &gh_msgq_cap_list )
    {
      raw_spin_unlock(&gh_msgq_cap_list_lock);
      return 4294967274LL;
    }
  }
  while ( *((_DWORD *)v6 - 2) != a1 );
  raw_spin_unlock(&gh_msgq_cap_list_lock);
  if ( v6 == &qword_80 )
    return 4294967274LL;
  if ( a2 == 1 )
  {
    v10 = *((_DWORD *)v6 - 23);
    if ( v10 )
    {
      v8 = v6 - 15;
      *a3 = v10;
      raw_spin_lock(v6 - 15);
      *((_DWORD *)v6 - 23) = 0;
      *(v6 - 13) = (_UNKNOWN *)-1LL;
      goto LABEL_16;
    }
    v11 = &unk_7463;
    goto LABEL_21;
  }
  if ( a2 )
  {
    printk(&unk_73AB, "gh_msgq_reset_cap_info");
    return 4294967274LL;
  }
  v7 = *((_DWORD *)v6 - 24);
  if ( !v7 )
  {
    v11 = &unk_7282;
LABEL_21:
    printk(v11, "gh_msgq_reset_cap_info");
    return 4294967290LL;
  }
  v8 = v6 - 15;
  *a3 = v7;
  raw_spin_lock(v6 - 15);
  *((_DWORD *)v6 - 24) = 0;
  *(v6 - 14) = (_UNKNOWN *)-1LL;
LABEL_16:
  raw_spin_unlock(v8);
  result = (unsigned int)*a3;
  if ( (_DWORD)result )
  {
    free_irq(result, v6 - 16);
    return 0;
  }
  return result;
}
