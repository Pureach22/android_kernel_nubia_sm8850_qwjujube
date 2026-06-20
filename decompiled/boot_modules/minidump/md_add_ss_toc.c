__int64 __fastcall md_add_ss_toc(char *string, char a2, unsigned __int64 a3)
{
  int v4; // w20
  int v5; // w21
  size_t v6; // x0
  int *v7; // x23
  __int64 v8; // x23
  unsigned __int64 v9; // x2
  __int64 v10; // x20
  __int64 result; // x0
  int v12; // w23
  __int64 v13; // x21
  unsigned int v14; // w24
  int v15; // w25
  int v16; // w26

  v4 = *(_DWORD *)(qword_1100E8 + 16);
  if ( (a2 & 1) == 0 )
  {
    v5 = md_num_regions;
    if ( (unsigned int)md_num_regions >= 0xCA )
    {
LABEL_28:
      __break(0x5512u);
LABEL_29:
      _fortify_panic(7, 13, a3);
      goto LABEL_30;
    }
    v6 = strnlen(string, 0xDu);
    if ( v6 >= 0xE )
      goto LABEL_26;
    if ( v6 == 13 )
      a3 = 13;
    else
      a3 = v6 + 1;
    if ( a3 >= 0xE )
      goto LABEL_29;
    v7 = &minidump_table[12 * v5];
    sized_strscpy(v7 + 8, string);
    if ( v5 == 201 )
    {
LABEL_30:
      __break(1u);
      JUMPOUT(0xF040);
    }
    *((_QWORD *)v7 + 7) = *((_QWORD *)string + 3);
    *((_QWORD *)v7 + 8) = *((_QWORD *)string + 4);
    *((_QWORD *)v7 + 9) = *((_QWORD *)string + 5);
    v7[12] = *((_DWORD *)string + 4);
  }
  v8 = qword_1100F8;
  v6 = strnlen(string, 0xDu);
  if ( v6 >= 0xD && v6 != 16 )
  {
LABEL_26:
    _fortify_panic(2, 13, v6 + 1);
LABEL_27:
    _fortify_panic(7, 16, v9);
    goto LABEL_28;
  }
  if ( v6 == 16 )
    v9 = 16;
  else
    v9 = v6 + 1;
  if ( v9 >= 0x11 )
    goto LABEL_27;
  v10 = v8 + 40LL * v4;
  result = sized_strscpy(v10, string);
  *(_QWORD *)(v10 + 24) = *((_QWORD *)string + 4);
  *(_QWORD *)(v10 + 32) = *((_QWORD *)string + 5);
  v12 = *(_DWORD *)(qword_1100E8 + 16);
  if ( v12 >= 1 )
  {
    v13 = qword_1100F8;
    v14 = 0;
    v15 = 0;
    v16 = -22;
    do
    {
      result = strcmp((const char *)v13, string);
      if ( !(_DWORD)result )
      {
        v16 = v15;
        if ( *(_DWORD *)(v13 + 16) > v14 )
          v14 = *(_DWORD *)(v13 + 16);
      }
      ++v15;
      v13 += 40;
    }
    while ( v12 != v15 );
    if ( (v16 & 0x80000000) == 0 )
      *(_DWORD *)(v10 + 16) = v14 + 1;
  }
  *(_DWORD *)(v10 + 20) = 1447119945;
  ++*(_DWORD *)(qword_1100E8 + 16);
  return result;
}
