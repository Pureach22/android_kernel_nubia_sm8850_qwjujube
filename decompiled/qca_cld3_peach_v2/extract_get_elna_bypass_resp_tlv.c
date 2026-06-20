__int64 __fastcall extract_get_elna_bypass_resp_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x20

  v11 = *a10;
  if ( *a10 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Get elna bypass %d from vdev %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_get_elna_bypass_resp_tlv",
      *(unsigned int *)(v11 + 8),
      *(unsigned int *)(v11 + 4));
    *(_BYTE *)a11 = *(_DWORD *)(v11 + 4);
    *(_DWORD *)(a11 + 4) = *(_DWORD *)(v11 + 8);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid get elna bypass event",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_get_elna_bypass_resp_tlv");
    return 4;
  }
}
