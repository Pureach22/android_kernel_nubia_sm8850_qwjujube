__int64 __fastcall hif_rtpm_register(unsigned int a1, __int64 a2)
{
  __int64 v5; // x0
  __int64 v6; // x9
  int v7; // w11

  if ( gp_hif_rtpm_ctx )
  {
    if ( a1 > 0xB || *(_QWORD *)(gp_hif_rtpm_ctx + 8LL * a1 + 56) )
    {
      qdf_trace_msg(61, 2, "%s: Invalid client %d", "hif_rtpm_register", a1);
      return 4;
    }
    else
    {
      v5 = _qdf_mem_malloc(48, "hif_rtpm_register", 504);
      if ( v5 )
      {
        *(_QWORD *)v5 = a2;
        *(_DWORD *)(v5 + 8) = 0;
        *(_DWORD *)(v5 + 12) = 0;
        *(_DWORD *)(v5 + 16) = 0;
        v6 = gp_hif_rtpm_ctx;
        v7 = *(_DWORD *)(gp_hif_rtpm_ctx + 48);
        *(_QWORD *)(gp_hif_rtpm_ctx + 8LL * a1 + 56) = v5;
        *(_DWORD *)(v6 + 48) = v7 + 1;
        return 0;
      }
      else
      {
        return 2;
      }
    }
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: Runtime PM context NULL", "hif_rtpm_register");
    return 16;
  }
}
