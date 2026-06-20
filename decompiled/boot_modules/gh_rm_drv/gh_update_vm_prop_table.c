__int64 __fastcall gh_update_vm_prop_table(unsigned int a1, __int64 a2)
{
  unsigned int v2; // w19
  __int16 *v5; // x8
  __int64 v7; // x10
  __int64 v8; // x10
  __int64 v9; // x10
  __int64 v10; // x9

  v2 = -22;
  if ( a1 <= 4 && a2 )
  {
    raw_spin_lock(&gh_vm_table_lock);
    v5 = &gh_vm_table[52 * a1];
    if ( *((_QWORD *)v5 + 1) || *((_QWORD *)v5 + 2) || *((_QWORD *)v5 + 3) || *((_QWORD *)v5 + 4) )
    {
      v2 = -17;
    }
    else
    {
      if ( *(_WORD *)a2 )
        *v5 = *(_WORD *)a2;
      v7 = *(_QWORD *)(a2 + 8);
      if ( v7 )
        *((_QWORD *)v5 + 1) = v7;
      v8 = *(_QWORD *)(a2 + 16);
      if ( v8 )
        *((_QWORD *)v5 + 2) = v8;
      v9 = *(_QWORD *)(a2 + 24);
      if ( v9 )
        *((_QWORD *)v5 + 3) = v9;
      v10 = *(_QWORD *)(a2 + 32);
      v2 = 0;
      if ( v10 )
        *((_QWORD *)v5 + 4) = v10;
    }
    raw_spin_unlock(&gh_vm_table_lock);
  }
  return v2;
}
