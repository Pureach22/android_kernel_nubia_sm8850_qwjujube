__int64 __fastcall lim_compare_capabilities(
        __int64 a1,
        _WORD *a2,
        _WORD *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w8
  const char *v13; // x2
  unsigned int v14; // w1
  _WORD *v20; // x9
  _WORD *v21; // x8

  v12 = (unsigned __int16)*a2;
  if ( *(_DWORD *)(a4 + 88) == 1 && (v12 & 2) != 0 )
  {
    v13 = "%s: Requesting STA asserting IBSS capability";
LABEL_6:
    v14 = 8;
LABEL_7:
    qdf_trace_msg(0x35u, v14, v13, a5, a6, a7, a8, a9, a10, a11, a12, "lim_compare_capabilities");
    return 0;
  }
  if ( (v12 & 0xC) != 0 )
  {
    v13 = "%s:  AP does not support PCF functionality";
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: QoS in AssocReq: %d, local capabs qos: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_compare_capabilities",
    (v12 >> 9) & 1,
    ((unsigned __int16)*a3 >> 9) & 1);
  v20 = a3;
  v21 = a2;
  if ( (*a2 & 0x200) != 0 && (*a3 & 0x200) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Received unmatched QOS but cfg to suppress - continuing",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_compare_capabilities");
    v20 = a3;
    v21 = a2;
  }
  if ( *(_DWORD *)(a4 + 88) != 1 || (*v20 & 0x400) == 0 || *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5600LL) != 1 )
    return 1;
  if ( (*v21 & 0x400) == 0 )
  {
    v13 = "%s: AP rejects association as station doesn't support shortslot time";
    v14 = 2;
    goto LABEL_7;
  }
  return 0;
}
