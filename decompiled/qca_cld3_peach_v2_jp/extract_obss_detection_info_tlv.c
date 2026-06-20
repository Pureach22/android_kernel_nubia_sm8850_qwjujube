__int64 __fastcall extract_obss_detection_info_tlv(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  int v11; // w4
  __int64 result; // x0
  const char *v13; // x2
  int v14; // w8

  if ( !a2 )
  {
    v13 = "%s: Invalid obss_detection event buffer";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "extract_obss_detection_info_tlv");
    return 4;
  }
  if ( !a1 )
  {
    v13 = "%s: Invalid evt_buf";
    goto LABEL_9;
  }
  v10 = *a1;
  *(_DWORD *)a2 = *(_DWORD *)(*a1 + 4);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(v10 + 12);
  *(_WORD *)(a2 + 12) = *(_DWORD *)(v10 + 16);
  *(_BYTE *)(a2 + 14) = *(_WORD *)(v10 + 18);
  *(_BYTE *)(a2 + 15) = *(_BYTE *)(v10 + 19);
  *(_WORD *)(a2 + 16) = *(_DWORD *)(v10 + 20);
  v11 = *(_DWORD *)(v10 + 8);
  switch ( v11 )
  {
    case 2:
      v14 = 2;
      break;
    case 1:
      v14 = 1;
      break;
    case 0:
      *(_DWORD *)(a2 + 4) = 0;
      return 0;
    default:
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid reason: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "extract_obss_detection_info_tlv");
      return 4;
  }
  result = 0;
  *(_DWORD *)(a2 + 4) = v14;
  return result;
}
