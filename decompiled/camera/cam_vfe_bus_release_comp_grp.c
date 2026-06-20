_QWORD *__fastcall cam_vfe_bus_release_comp_grp(_QWORD *result, __int64 a2)
{
  int v2; // w8
  _DWORD *v3; // x20
  _QWORD *v4; // x19
  int v5; // w8
  _QWORD *v6; // x21
  __int64 v7; // x8
  __int64 v8; // x19
  _QWORD *v9; // x21

  if ( !a2 )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_vfe_bus_release_comp_grp",
                       1709,
                       "Invalid Params Comp Grp %pK",
                       nullptr);
  v2 = *(_DWORD *)(a2 + 8);
  if ( v2 == 4 )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_vfe_bus_release_comp_grp",
                       1720,
                       "Invalid State %d",
                       4);
  if ( v2 == 1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_vfe_bus_release_comp_grp",
                       1714,
                       "Already released Comp Grp");
  v3 = *(_DWORD **)(a2 + 24);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v8 = a2;
    v9 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_release_comp_grp",
      1725,
      "Comp Grp type %u",
      *v3);
    a2 = v8;
    result = v9;
  }
  v4 = result + 5329;
  do
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == result + 5329 )
      return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         8,
                         1,
                         "cam_vfe_bus_release_comp_grp",
                         1736,
                         "Could not find matching Comp Grp type %u",
                         *v3);
  }
  while ( v4 - 4 != (_QWORD *)a2 );
  v5 = v3[13] - 1;
  v3[13] = v5;
  if ( v5 )
    return result;
  v6 = result;
  result = (_QWORD *)list_del(v4);
  *(_QWORD *)(v3 + 11) = 0;
  *((_QWORD *)v3 + 3) = 4294967274LL;
  v3[9] = 3;
  v4[3] = 0;
  *((_DWORD *)v4 - 6) = 1;
  if ( (unsigned int)(*v3 - 6) > 5 )
  {
    if ( *v3 > 5u )
      return result;
    v7 = 5325;
  }
  else
  {
    v7 = 5327;
  }
  return list_add_tail_1(v4, &v6[v7]);
}
