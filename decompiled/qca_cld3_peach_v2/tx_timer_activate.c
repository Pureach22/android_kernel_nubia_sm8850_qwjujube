__int64 __fastcall tx_timer_activate(char *string)
{
  size_t v2; // x0
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2

  if ( !string || *((_QWORD *)string + 7) != 3735928559LL )
    return 21;
  v2 = strnlen(string, 0x32u);
  if ( v2 >= 0x33 )
  {
    _fortify_panic(2, 50, v2 + 1);
    goto LABEL_12;
  }
  if ( v2 == 50 )
  {
LABEL_12:
    v12 = _fortify_panic(4, 50, 51);
    return tx_timer_change(v12, v13, v14);
  }
  result = qdf_mc_timer_start((__int64)(string + 88), *((_DWORD *)string + 18));
  if ( !(_DWORD)result )
    return result;
  if ( (_DWORD)result == 6 )
  {
    qdf_trace_msg(0x37u, 8u, "Timer %s is already running\n", v4, v5, v6, v7, v8, v9, v10, v11, string);
    return 0;
  }
  qdf_trace_msg(0x37u, 2u, "Timer %s fails to activate\n", v4, v5, v6, v7, v8, v9, v10, v11, string);
  return 21;
}
