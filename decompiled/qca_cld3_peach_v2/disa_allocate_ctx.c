__int64 __fastcall disa_allocate_ctx(
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

  if ( gp_disa_ctx )
  {
    qdf_trace_msg(0x5Cu, 8u, "%s: already allocated disa_ctx", a1, a2, a3, a4, a5, a6, a7, a8, "disa_allocate_ctx");
    return 0;
  }
  else
  {
    v9 = _qdf_mem_malloc(0x28u, "disa_allocate_ctx", 38);
    gp_disa_ctx = v9;
    if ( v9 )
    {
      *(_DWORD *)(v9 + 24) = 0;
      *(_QWORD *)(v9 + 32) = 0;
      return 0;
    }
    else
    {
      return 2;
    }
  }
}
