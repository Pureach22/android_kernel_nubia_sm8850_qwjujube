__int64 __fastcall wlansap_clear_acl(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x24
  __int64 v10; // d13
  __int64 v11; // d27
  unsigned __int64 v13; // x21
  char *v14; // x20
  unsigned __int64 v15; // x1
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  unsigned __int64 v26; // x21
  char *v27; // x20
  unsigned __int64 v28; // x1

  if ( !a1 )
    return 1;
  if ( a1[607] )
  {
    v13 = 0;
    v14 = (char *)(a1 + 511);
    while ( v13 != 33 )
    {
      qdf_mem_set(v14, 6u, 0);
      v15 = a1[607];
      ++v13;
      v14 += 6;
      if ( v13 >= v15 )
        goto LABEL_9;
    }
    goto LABEL_17;
  }
  LOWORD(v15) = 0;
LABEL_9:
  sap_print_acl((unsigned __int8 *)a1 + 1022, v15, a2, a3, a4, a5, a6, a7, a8, a9);
  v25 = a1[510];
  a1[607] = 0;
  if ( v25 )
  {
    v26 = 0;
    v27 = (char *)(a1 + 414);
    while ( v26 != 33 )
    {
      qdf_mem_set(v27, 6u, 0);
      v28 = a1[510];
      ++v26;
      v27 += 6;
      if ( v26 >= v28 )
        goto LABEL_15;
    }
LABEL_17:
    __break(0x5512u);
    *(_QWORD *)(v9 + 136) = v10;
    *(_QWORD *)(v9 + 144) = v11;
    return wlansap_modify_acl();
  }
  LOWORD(v28) = 0;
LABEL_15:
  sap_print_acl((unsigned __int8 *)a1 + 828, v28, v17, v18, v19, v20, v21, v22, v23, v24);
  result = 0;
  a1[510] = 0;
  return result;
}
