char *__fastcall dsi_parser_find_nodes(__int64 a1, char **a2)
{
  char *result; // x0
  char *v5; // x0
  char *v6; // x8
  char *v7; // x21
  char *v8; // x22
  char *v9; // x0
  char *v10; // x21
  __int64 v11; // x0
  const char *v12; // x21
  char *v13; // x0
  int v14; // t1
  __int64 nodes; // x0
  __int64 v16; // x1
  __int64 v17; // x8
  __int64 v18; // x9
  char *v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_7;
  result = *a2;
  if ( !*a2 )
  {
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v5 = strpbrk(result, "{}");
  if ( !v5 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: {} not found\n");
LABEL_7:
    result = nullptr;
    goto LABEL_8;
  }
  if ( *v5 == 125 )
  {
    v6 = v5;
    result = nullptr;
    *a2 = v6 + 1;
    goto LABEL_8;
  }
  v7 = strsep(a2, "{");
  result = nullptr;
  if ( !*a2 )
    goto LABEL_8;
  if ( !v7 )
    goto LABEL_8;
  result = (char *)devm_kmalloc(a1, 200, 3520);
  if ( !result )
    goto LABEL_8;
  v8 = result;
  v19[0] = v7;
  do
    v9 = strsep(v19, ";");
  while ( v19[0] );
  v10 = v9;
  strreplace(v9, 42, 32);
  v11 = strim(v10);
  v12 = *a2;
  *(_QWORD *)v8 = v11;
  v13 = strpbrk(v12, "{}");
  if ( !v13 )
  {
LABEL_26:
    result = v8;
    *((_QWORD *)v8 + 1) = v12;
    goto LABEL_8;
  }
  if ( *v13 != 123 )
  {
    *v13 = 0;
    *a2 = v13 + 1;
    goto LABEL_26;
  }
  while ( v13 != v12 )
  {
    v14 = (unsigned __int8)*--v13;
    if ( v14 == 59 )
    {
      v13[1] = 0;
      *a2 = v13 + 2;
      break;
    }
  }
  *((_QWORD *)v8 + 1) = v12;
  nodes = dsi_parser_find_nodes(a1);
  if ( !nodes )
  {
    result = v8;
    goto LABEL_8;
  }
  v17 = nodes;
  result = v8;
  while ( 1 )
  {
    v18 = *((unsigned int *)result + 48);
    if ( (int)v18 <= 19 )
      break;
LABEL_21:
    v17 = dsi_parser_find_nodes(a1);
    result = v8;
    if ( !v17 )
      goto LABEL_8;
  }
  *((_DWORD *)result + 48) = v18 + 1;
  if ( (unsigned int)v18 < 0x14 )
  {
    *(_QWORD *)&v8[8 * v18 + 32] = v17;
    goto LABEL_21;
  }
  __break(0x5512u);
  return (char *)dsi_parser_count_properties(result, v16);
}
