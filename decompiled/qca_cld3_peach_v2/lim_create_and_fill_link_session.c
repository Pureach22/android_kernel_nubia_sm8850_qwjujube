__int64 __fastcall lim_create_and_fill_link_session(__int64 a1, __int64 a2, __int64 a3, __int16 a4)
{
  unsigned int v7; // w23
  __int64 session; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  __int64 result; // x0

  if ( !a1 )
    return 4;
  v7 = a2;
  session = lim_cm_roam_create_session(a1, a2, a3);
  if ( session )
  {
    v17 = session;
    pe_update_crypto_params(a1, session, a3, v9, v10, v11, v12, v13, v14, v15, v16);
    result = lim_cm_fill_link_session(a1, v7, v17, a3, a4);
    if ( !(_DWORD)result )
      return result;
    pe_delete_session(a1);
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: MLO ROAM: Link session creation failed",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "lim_create_and_fill_link_session");
  return 16;
}
