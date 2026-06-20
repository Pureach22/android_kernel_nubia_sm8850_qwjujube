__int64 __fastcall hfi_util_kv_helper_add(unsigned int *a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x9
  unsigned int v4; // w10
  unsigned int *v5; // x9
  unsigned int v6; // w8
  void *v8; // x0

  if ( !a1 )
  {
    v8 = &unk_2733C5;
LABEL_7:
    printk(v8, "hfi_util_kv_helper_add");
    return (unsigned int)-22;
  }
  v3 = a1[1];
  v4 = v3 + 1;
  if ( *a1 < 16 * (unsigned __int64)(unsigned int)(v3 + 1) )
  {
    v8 = &unk_26C172;
    goto LABEL_7;
  }
  v5 = &a1[4 * v3];
  v6 = 0;
  a1[1] = v4;
  v5[4] = a2;
  *((_QWORD *)v5 + 3) = a3;
  return v6;
}
