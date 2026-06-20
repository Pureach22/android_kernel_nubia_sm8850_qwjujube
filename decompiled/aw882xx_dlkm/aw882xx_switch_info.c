__int64 __fastcall aw882xx_switch_info(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w8
  const char *v6; // x20
  size_t v7; // x21
  size_t v8; // x0
  unsigned __int64 v10; // x2
  __int64 v11; // x2
  __int64 v13; // x0

  v4 = a2[21];
  a2[16] = 3;
  a2[18] = 1;
  a2[20] = 2;
  if ( v4 >= 2 )
  {
    v4 = 1;
    a2[21] = 1;
  }
  v6 = aw882xx_switch[v4];
  v7 = strlen(v6) + 1;
  v8 = strnlen(v6, v7);
  if ( v8 == -1 && v7 != -1 )
  {
    _fortify_panic(2);
LABEL_15:
    v13 = _fortify_panic(7);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return aw882xx_switch_get(v13);
  }
  if ( v8 == v7 )
    v10 = v7;
  else
    v10 = v8 + 1;
  if ( v10 >= 0x41 )
    goto LABEL_15;
  if ( (sized_strscpy(a2 + 22, v6) & 0x80000000) != 0 )
    printk(&unk_23430, "aw882xx_switch_info", v11);
  return 0;
}
