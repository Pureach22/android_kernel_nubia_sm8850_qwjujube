__int64 __fastcall gh_rm_get_vminfo(unsigned int a1, _QWORD *a2)
{
  bool v3; // cf
  bool v4; // zf
  __int64 result; // x0
  __int16 *v7; // x8

  v3 = a1 >= 4;
  v4 = a1 == 4;
  result = 4294967274LL;
  if ( v4 || !v3 )
  {
    if ( a2 )
    {
      raw_spin_lock(&gh_vm_table_lock);
      v7 = &gh_vm_table[52 * a1];
      *a2 = *((_QWORD *)v7 + 1);
      a2[1] = *((_QWORD *)v7 + 2);
      a2[2] = *((_QWORD *)v7 + 3);
      a2[3] = *((_QWORD *)v7 + 4);
      raw_spin_unlock(&gh_vm_table_lock);
      return 0;
    }
  }
  return result;
}
