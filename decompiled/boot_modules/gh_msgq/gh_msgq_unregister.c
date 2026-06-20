__int64 __fastcall gh_msgq_unregister(__int64 a1)
{
  _QWORD *v2; // x20

  if ( !a1 )
    return 4294967274LL;
  v2 = *(_QWORD **)(a1 + 8);
  raw_spin_lock(v2 + 1);
  if ( *v2 == a1 )
  {
    *v2 = 0;
    raw_spin_unlock(v2 + 1);
    printk(&unk_74F3, "gh_msgq_unregister");
    kfree(a1);
    return 0;
  }
  else
  {
    printk(&unk_73FF, "gh_msgq_unregister");
    raw_spin_unlock(v2 + 1);
    return 4294967274LL;
  }
}
