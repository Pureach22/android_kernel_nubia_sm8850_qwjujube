__int64 __fastcall dcc_configure_list(__int64 a1, __int64 a2)
{
  __int64 next_available_child; // x0
  __int64 v5; // x21
  int v6; // w0
  __int64 result; // x0
  int v8; // w21

  next_available_child = of_get_next_available_child(a2, 0);
  if ( !next_available_child )
    goto LABEL_7;
  v5 = next_available_child;
  while ( 1 )
  {
    v6 = dcc_dt_parse(a1, v5);
    if ( v6 )
      break;
    v5 = of_get_next_available_child(a2, v5);
    if ( !v5 )
      return dcc_enable(a1);
  }
  v8 = v6;
  result = dev_err(*(_QWORD *)(a1 + 16), "DCC link list config failed err:%d\n", v6);
  if ( v8 == -1 )
  {
LABEL_7:
    result = dcc_dt_parse(a1, a2);
    if ( !(_DWORD)result )
      return dcc_enable(a1);
  }
  return result;
}
