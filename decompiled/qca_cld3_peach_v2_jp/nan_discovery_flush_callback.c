__int64 __fastcall nan_discovery_flush_callback(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x8

  if ( a1 && (v9 = *((__int64 **)a1 + 1)) != nullptr )
  {
    if ( *a1 < 3u )
    {
      wlan_objmgr_psoc_release_ref(*v9, 0x14u, a2, a3, a4, a5, a6, a7, a8, a9);
      _qdf_mem_free(*((_QWORD *)a1 + 1));
      return 0;
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Unsupported request type: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "nan_discovery_flush_callback");
    _qdf_mem_free(*((_QWORD *)a1 + 1));
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Null pointer for NAN Discovery message",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "nan_discovery_flush_callback");
  }
  return 4;
}
