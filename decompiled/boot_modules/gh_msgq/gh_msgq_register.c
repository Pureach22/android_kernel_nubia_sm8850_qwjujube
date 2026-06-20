__int64 __fastcall gh_msgq_register(unsigned int a1)
{
  _UNKNOWN **v2; // x9
  _QWORD *v3; // x20
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x19
  __int64 v7; // x0
  __int64 v8; // x21

  if ( a1 - 271 <= 0xFFFFFFF1 )
  {
    printk(&unk_7366, 257);
    return -22;
  }
  else
  {
    raw_spin_lock(&gh_msgq_cap_list_lock);
    v2 = &gh_msgq_cap_list;
    while ( 1 )
    {
      v2 = (_UNKNOWN **)*v2;
      if ( v2 == &gh_msgq_cap_list )
        break;
      if ( *((_DWORD *)v2 - 2) == a1 )
      {
        v3 = v2 - 16;
        if ( v2 != &qword_80 )
          goto LABEL_9;
        break;
      }
    }
    v4 = gh_msgq_alloc_entry(a1);
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = v4;
      raw_spin_unlock(&gh_msgq_cap_list_lock);
      return v5;
    }
    v3 = (_QWORD *)v4;
LABEL_9:
    raw_spin_unlock(&gh_msgq_cap_list_lock);
    raw_spin_lock(v3 + 1);
    if ( *v3 )
    {
      raw_spin_unlock(v3 + 1);
      printk(&unk_74AD, "gh_msgq_register");
      return -16;
    }
    else
    {
      v7 = _kmalloc_cache_noprof(kfree, 2336, 16);
      if ( v7 )
      {
        *(_DWORD *)v7 = a1;
        v8 = v7;
        *(_QWORD *)(v7 + 8) = v3;
        *v3 = v7;
        raw_spin_unlock(v3 + 1);
        printk(&unk_72ED, a1);
        return v8;
      }
      else
      {
        raw_spin_unlock(v3 + 1);
        return -12;
      }
    }
  }
}
