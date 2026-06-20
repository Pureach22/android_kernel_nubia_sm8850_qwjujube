__int64 __fastcall reg_is_11d_scan_inprogress(__int64 a1)
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
    v10 = *(_BYTE *)(psoc_obj + 91151);
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: NULL reg psoc private obj",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "reg_is_11d_scan_inprogress");
    v10 = 0;
  }
  return v10 & 1;
}
