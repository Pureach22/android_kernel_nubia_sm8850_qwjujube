__int64 __fastcall gh_rm_get_vm_name(unsigned __int16 a1, int *a2)
{
  int v2; // w20
  int v4; // w8
  unsigned int v5; // w20

  v2 = a1;
  raw_spin_lock(&gh_vm_table_lock);
  if ( (unsigned __int16)gh_vm_table[0] == v2 )
  {
    v4 = 0;
    v5 = 0;
    if ( !a2 )
      goto LABEL_16;
    goto LABEL_15;
  }
  if ( (unsigned __int16)word_13A50 == v2 )
  {
    v4 = 1;
    v5 = 0;
    if ( !a2 )
      goto LABEL_16;
    goto LABEL_15;
  }
  if ( (unsigned __int16)word_13AB8 == v2 )
  {
    v4 = 2;
    v5 = 0;
    if ( !a2 )
      goto LABEL_16;
    goto LABEL_15;
  }
  if ( (unsigned __int16)word_13B20 == v2 )
  {
    v4 = 3;
    v5 = 0;
    if ( !a2 )
      goto LABEL_16;
LABEL_15:
    *a2 = v4;
    goto LABEL_16;
  }
  if ( (unsigned __int16)word_13B88 != v2 )
  {
    v5 = -22;
    goto LABEL_16;
  }
  v4 = 4;
  v5 = 0;
  if ( a2 )
    goto LABEL_15;
LABEL_16:
  raw_spin_unlock(&gh_vm_table_lock);
  return v5;
}
