__int64 __fastcall parse_param(char **a1, __int64 a2)
{
  char *v3; // x0
  unsigned int v4; // w0
  unsigned int v5; // w8
  unsigned int v7; // w19
  void *v8; // x0

  v3 = strsep(a1, " ");
  if ( !v3 )
  {
    v7 = -22;
    v8 = &unk_B2D9;
LABEL_6:
    printk(v8, "ipclite_test", "parse_param");
    return v7;
  }
  v4 = kstrtoint(v3, 0, a2);
  v5 = 0;
  if ( (v4 & 0x80000000) != 0 )
  {
    v7 = v4;
    v8 = &unk_AF38;
    goto LABEL_6;
  }
  return v5;
}
