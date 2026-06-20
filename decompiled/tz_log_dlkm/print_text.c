__int64 __fastcall print_text(const char *a1, __int64 a2, int a3, __int64 a4, unsigned int a5)
{
  unsigned int v8; // w19
  int v9; // w20
  __int64 v10; // x25

  v8 = a5;
  v9 = scnprintf(a4, a5, "%s\n", a1);
  if ( a3 )
  {
    v10 = 0;
    while ( v9 + 6 < v8 )
    {
      v9 += scnprintf(a4 + v9, v8 - v9, "%02hhx ", *(unsigned __int8 *)(a2 + v10));
      if ( (~(_BYTE)v10 & 0x1F) == 0 )
        v9 += scnprintf(a4 + v9, v8 - v9, "%c", 10);
      if ( a3 == ++v10 )
        return (unsigned int)scnprintf(a4 + v9, v8 - v9, "%c", 10) + v9;
    }
    printk(&unk_AA16, "print_text", v8);
  }
  else
  {
    return (unsigned int)scnprintf(a4 + v9, v8 - v9, "%c", 10) + v9;
  }
  return v8;
}
