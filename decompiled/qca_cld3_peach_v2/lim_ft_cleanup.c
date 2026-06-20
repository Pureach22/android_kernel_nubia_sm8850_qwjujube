void *__fastcall lim_ft_cleanup(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  const char *v15; // x2
  unsigned int v16; // w1

  if ( !a10 )
  {
    v15 = "%s: pe_session is NULL";
    v16 = 2;
    return (void *)qdf_trace_msg(0x35u, v16, v15, a1, a2, a3, a4, a5, a6, a7, a8, "lim_ft_cleanup");
  }
  if ( *(_DWORD *)(a10 + 88) != 2 )
  {
    v15 = "%s: pe_session is not in STA mode";
    v16 = 8;
    return (void *)qdf_trace_msg(0x35u, v16, v15, a1, a2, a3, a4, a5, a6, a7, a8, "lim_ft_cleanup");
  }
  if ( *(_QWORD *)(a10 + 7432) )
  {
    qdf_trace_msg(0x35u, 8u, "%s: Freeing pFTPreAuthReq: %pK", a1, a2, a3, a4, a5, a6, a7, a8, "lim_ft_cleanup");
    v11 = *(_QWORD *)(a10 + 7432);
    if ( *(_QWORD *)(v11 + 424) )
    {
      _qdf_mem_free(*(_QWORD *)(v11 + 424));
      *(_QWORD *)(*(_QWORD *)(a10 + 7432) + 424LL) = 0;
      v11 = *(_QWORD *)(a10 + 7432);
    }
    _qdf_mem_free(v11);
    *(_QWORD *)(a10 + 7432) = 0;
  }
  v12 = *(_QWORD *)(a10 + 7832);
  if ( v12 )
  {
    _qdf_mem_free(v12);
    *(_QWORD *)(a10 + 7832) = 0;
  }
  v13 = *(_QWORD *)(a10 + 7840);
  if ( v13 )
  {
    _qdf_mem_free(v13);
    *(_QWORD *)(a10 + 7840) = 0;
  }
  return qdf_mem_set((void *)(a10 + 7432), 0x1B0u, 0);
}
