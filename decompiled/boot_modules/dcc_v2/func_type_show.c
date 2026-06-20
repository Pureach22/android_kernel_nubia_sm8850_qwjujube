__int64 __fastcall func_type_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  unsigned __int64 v5; // x21
  __int64 v6; // x20
  __int64 v7; // x8
  int v8; // w0
  int v10; // w0
  int v11; // w1
  char *v12; // x2

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(v3 + 328) )
  {
    v5 = 0;
    v6 = 0;
    while ( 1 )
    {
      v7 = *(unsigned int *)(*(_QWORD *)(v3 + 96) + 4 * v5);
      if ( (unsigned int)v7 >= 2 )
        break;
      v8 = scnprintf(a3 + v6, 4096 - v6, "%u :%s\n", v5++, (&str_dcc_func_type)[v7]);
      v6 += v8;
      if ( v5 >= *(unsigned int *)(v3 + 328) )
        return v6;
    }
    __break(0x5512u);
    v10 = MEMORY[0x710E4AC]();
    return func_type_store(v10, v11, v12);
  }
  else
  {
    return 0;
  }
}
