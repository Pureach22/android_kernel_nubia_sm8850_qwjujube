__int64 __fastcall extract_dfs_ocac_complete_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10,
        _DWORD *a11)
{
  _DWORD *v11; // x8
  int v12; // w9
  const char *v14; // x2

  if ( a10 )
  {
    v11 = (_DWORD *)*a10;
    if ( *a10 )
    {
      *a11 = v11[1];
      a11[1] = v11[2];
      a11[3] = v11[4];
      a11[4] = v11[6];
      v12 = v11[5];
      a11[5] = v12;
      a11[2] = v11[3];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: processed ocac complete event vdev %d agile chan %d %d width %d status %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_dfs_ocac_complete_event_tlv",
        v12);
      return 0;
    }
    v14 = "%s: invalid param_tlvs->fixed_param";
  }
  else
  {
    v14 = "%s: invalid ocac complete event buf";
  }
  qdf_trace_msg(0x31u, 2u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "extract_dfs_ocac_complete_event_tlv");
  return 16;
}
