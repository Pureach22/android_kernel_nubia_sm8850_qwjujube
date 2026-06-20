__int64 __fastcall vreg_configure(__int64 *a1, char a2)
{
  unsigned int v2; // w8
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 result; // x0
  __int64 v8; // x1
  void *v9; // x8
  unsigned int v10; // w19

  v2 = *((_DWORD *)a1 + 4);
  if ( v2 && *((_DWORD *)a1 + 5) )
  {
    v5 = *a1;
    v6 = (a2 & 1) != 0 ? 0LL : v2;
    LODWORD(result) = regulator_set_voltage(v5, v6);
    if ( (result & 0x80000000) != 0 )
    {
      v9 = &unk_13848;
      goto LABEL_13;
    }
  }
  if ( (a2 & 1) != 0 )
    v8 = 0;
  else
    v8 = *((unsigned int *)a1 + 6);
  result = regulator_set_load(*a1, v8);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = &unk_132AE;
LABEL_13:
    v10 = result;
    printk(v9, "vreg_configure");
    return v10;
  }
  return result;
}
