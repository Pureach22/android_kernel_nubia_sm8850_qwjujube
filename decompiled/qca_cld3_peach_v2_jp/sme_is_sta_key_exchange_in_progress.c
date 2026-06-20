bool __fastcall sme_is_sta_key_exchange_in_progress(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8
  __int64 v13; // x8

  if ( a1 && a2 <= 5u && (v12 = *(_QWORD *)(a1 + 17224)) != 0 && (*(_BYTE *)(v12 + 96LL * a2 + 1) & 1) != 0 )
  {
    v13 = a1 + 4LL * a2;
    return *(_DWORD *)(v13 + 17172) == 3 && *(_DWORD *)(v13 + 17196) == 5;
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid session id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_is_sta_key_exchange_in_progress",
      a2,
      v10,
      v11);
    return 0;
  }
}
