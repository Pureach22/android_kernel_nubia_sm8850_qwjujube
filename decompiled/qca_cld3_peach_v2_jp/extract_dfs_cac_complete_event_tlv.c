__int64 __fastcall extract_dfs_cac_complete_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11)
{
  if ( a10 )
  {
    *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: processed cac complete event vdev %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_dfs_cac_complete_event_tlv");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid cac complete event buf",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_dfs_cac_complete_event_tlv");
    return 16;
  }
}
