__int64 __fastcall hal_reo_status_get_header_peach(
        __int64 result,
        int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  unsigned int v13; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a2 <= 286 )
  {
    if ( a2 != 172 && a2 != 285 && a2 != 286 )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( a2 > 305 )
  {
    if ( a2 != 306 && a2 != 307 )
      goto LABEL_13;
LABEL_12:
    v13 = *(_DWORD *)(result + 8);
    *(_WORD *)a3 = v13;
    *(_WORD *)(a3 + 2) = HIWORD(v13) & 0x3FF;
    *(_DWORD *)(a3 + 4) = (v13 >> 26) & 3;
    *(_DWORD *)(a3 + 8) = *(_DWORD *)(result + 12);
    return result;
  }
  if ( a2 == 287 || a2 == 288 )
    goto LABEL_12;
LABEL_13:
  qdf_trace_msg(0x38u, 2u, "ERROR: Unknown tlv\n", a4, a5, a6, a7, a8, a9, a10, a11, v11, v12);
  *(_QWORD *)a3 = 0;
  result = qdf_trace_msg(0x38u, 2u, "ERROR: Unknown tlv\n", v15, v16, v17, v18, v19, v20, v21, v22);
  *(_DWORD *)(a3 + 8) = 0;
  return result;
}
