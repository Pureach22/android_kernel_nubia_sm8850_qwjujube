__int64 __fastcall pmo_allocate_ctx(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v9; // x0

  if ( gp_pmo_ctx )
  {
    qdf_trace_msg(0x4Du, 8u, "%s: already allocated pmo_ctx", a1, a2, a3, a4, a5, a6, a7, a8, "pmo_allocate_ctx");
    return 0;
  }
  else
  {
    v9 = _qdf_mem_malloc(0x6D0u, "pmo_allocate_ctx", 44);
    gp_pmo_ctx = v9;
    if ( v9 )
    {
      *(_DWORD *)(v9 + 1728) = 0;
      *(_QWORD *)(v9 + 1736) = 0;
      return 0;
    }
    else
    {
      return 2;
    }
  }
}
