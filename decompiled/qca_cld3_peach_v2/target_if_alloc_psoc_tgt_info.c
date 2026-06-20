__int64 __fastcall target_if_alloc_psoc_tgt_info(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 v11; // x20

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x16A8u, "target_if_alloc_psoc_tgt_info", 779);
    if ( v10 )
    {
      *(_QWORD *)(a1 + 2800) = v10;
      v11 = v10;
      *(_DWORD *)(v10 + 504) = 11;
      wlan_minidump_log(v10, 5800, a1, 48, "target_psoc_info");
      qdf_event_create((_DWORD *)(v11 + 512));
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_alloc_psoc_tgt_info");
    return 4;
  }
}
