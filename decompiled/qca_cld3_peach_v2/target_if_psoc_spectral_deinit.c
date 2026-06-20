__int64 __fastcall target_if_psoc_spectral_deinit(
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
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  __int64 v11; // x0
  const char *v13; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2136);
    if ( v9 )
    {
      v10 = *(__int64 (**)(void))(v9 + 264);
      if ( *((_DWORD *)v10 - 1) != -373219892 )
        __break(0x8228u);
      v11 = v10();
      if ( v11 )
        return _qdf_mem_free(v11);
    }
    else
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: rx_ops is null",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "get_target_if_spectral_handle_from_psoc");
    }
    v13 = "%s: Spectral target_if psoc object is null";
  }
  else
  {
    v13 = "%s: psoc is null";
  }
  return qdf_trace_msg(0x56u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_psoc_spectral_deinit");
}
