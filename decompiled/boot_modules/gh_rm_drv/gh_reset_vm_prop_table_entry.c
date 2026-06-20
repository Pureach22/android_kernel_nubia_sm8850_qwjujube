__int64 __fastcall gh_reset_vm_prop_table_entry(unsigned __int16 a1)
{
  int v1; // w19
  __int16 *v2; // x8

  v1 = a1;
  raw_spin_lock(&gh_vm_table_lock);
  v2 = &word_13A50;
  if ( (unsigned __int16)word_13A50 == v1
    || (v2 = &word_13AB8, (unsigned __int16)word_13AB8 == v1)
    || (v2 = &word_13B20, (unsigned __int16)word_13B20 == v1)
    || (v2 = &word_13B88, (unsigned __int16)word_13B88 == v1) )
  {
    *((_DWORD *)v2 + 18) = 0;
    *v2 = -1;
    *((_QWORD *)v2 + 1) = 0;
    *((_QWORD *)v2 + 2) = 0;
    *((_QWORD *)v2 + 3) = 0;
    *((_QWORD *)v2 + 4) = 0;
    *((_DWORD *)v2 + 10) = 0;
  }
  return raw_spin_unlock(&gh_vm_table_lock);
}
