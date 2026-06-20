__int64 __fastcall cm_roam_pmkid_request_handler(unsigned __int8 *a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v10; // w19

  result = cm_roam_pmkid_req_ind(*((_QWORD *)a1 + 1), *a1);
  if ( (_DWORD)result )
  {
    v10 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Pmkid request failed",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "cm_roam_pmkid_request_handler");
    return v10;
  }
  return result;
}
