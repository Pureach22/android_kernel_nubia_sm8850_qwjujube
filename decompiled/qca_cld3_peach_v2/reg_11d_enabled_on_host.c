__int64 __fastcall reg_11d_enabled_on_host(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  char v10; // w8

  psoc_obj = reg_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    if ( *(_BYTE *)(psoc_obj + 91151) == 1 )
      v10 = *(_BYTE *)(psoc_obj + 91152) ^ 1;
    else
      v10 = 0;
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: NULL reg psoc private obj", v2, v3, v4, v5, v6, v7, v8, v9, "reg_11d_enabled_on_host");
    v10 = 1;
  }
  return v10 & 1;
}
