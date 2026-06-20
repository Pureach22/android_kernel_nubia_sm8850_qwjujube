__int64 __fastcall reg_set_11d_offloaded(__int64 a1, char a2)
{
  __int64 psoc_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  psoc_obj = reg_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    *(_BYTE *)(psoc_obj + 91152) = a2 & 1;
    qdf_trace_msg(0x51u, 8u, "%s: set is_11d_offloaded %d", v4, v5, v6, v7, v8, v9, v10, v11, "reg_set_11d_offloaded");
    return 0;
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: NULL psoc reg component", v4, v5, v6, v7, v8, v9, v10, v11, "reg_set_11d_offloaded");
    return 16;
  }
}
