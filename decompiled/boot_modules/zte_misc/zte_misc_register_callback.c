__int64 __fastcall zte_misc_register_callback(__int64 a1, __int64 a2)
{
  const char *v2; // x20
  size_t v5; // x21
  __int64 v6; // x19
  _QWORD *i; // x24
  const char *v8; // x22
  size_t v9; // x23
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = *(const char **)a1;
  if ( !*(_QWORD *)a1 )
    return 4294967274LL;
  v5 = strlen(*(const char **)a1);
  v6 = 0;
  for ( i = &unk_88; ; i += 5 )
  {
    v8 = (const char *)*(i - 2);
    if ( !strncmp(v8, v2, v5) )
    {
      v9 = strlen(v8);
      if ( v9 == strlen(v2) )
        break;
    }
    if ( ++v6 == 36 )
      return 4294967274LL;
  }
  printk(&unk_7E95, "zte_misc_register_callback", (unsigned int)v6);
  if ( *i || *(i - 1) || i[1] || i[2] )
  {
    printk(&unk_7D1F, "zte_misc_register_callback", (unsigned int)v6);
    result = 4294967282LL;
  }
  else
  {
    *i = *(_QWORD *)(a1 + 16);
    *(i - 1) = *(_QWORD *)(a1 + 8);
    i[1] = *(_QWORD *)(a1 + 24);
    if ( !a2 )
      a2 = *(_QWORD *)(a1 + 32);
    result = 0;
    i[2] = a2;
  }
  if ( (unsigned int)v6 >= 0x24 )
    return 4294967274LL;
  return result;
}
