__int64 __fastcall hif_rtpm_open(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x9
  __int64 v3; // x0
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w9
  unsigned __int64 i; // x21
  __int64 v10; // x0

  v1 = *(_QWORD *)(a1 + 576);
  dword_7CF0B8 = 0;
  v2 = *(_QWORD *)(v1 + 40);
  qword_7CF0C0 = 0;
  dword_7CF0C8 = 0;
  qword_7CF0B0 = v2;
  gp_hif_rtpm_ctx = (__int64)&g_hif_rtpm_ctx;
  qword_7CF0D0 = 0;
  dword_7CF140 = 0;
  qword_7CF148 = 0;
  dword_7CF164 = 0;
  dword_7CF170 = 0;
  qword_7CF150 = (__int64)&qword_7CF150;
  qword_7CF158 = (__int64)&qword_7CF150;
  dword_7CF0D8 = 0;
  qword_7CF168 = 0;
  if ( qword_7CF110 )
  {
    qdf_trace_msg(61, 2, "%s: Invalid client %d", "hif_rtpm_register", 6);
  }
  else
  {
    v3 = _qdf_mem_malloc(48, "hif_rtpm_register", 504);
    if ( v3 )
    {
      *(_QWORD *)v3 = 0;
      *(_DWORD *)(v3 + 8) = 0;
      *(_DWORD *)(v3 + 12) = 0;
      *(_DWORD *)(v3 + 16) = 0;
      v4 = gp_hif_rtpm_ctx;
      v5 = *(_DWORD *)(gp_hif_rtpm_ctx + 48);
      *(_QWORD *)(gp_hif_rtpm_ctx + 104) = v3;
      *(_DWORD *)(v4 + 48) = v5 + 1;
    }
  }
  if ( gp_hif_rtpm_ctx )
  {
    if ( *(_QWORD *)(gp_hif_rtpm_ctx + 112) )
    {
      qdf_trace_msg(61, 2, "%s: Invalid client %d", "hif_rtpm_register", 7);
    }
    else
    {
      v6 = _qdf_mem_malloc(48, "hif_rtpm_register", 504);
      if ( v6 )
      {
        *(_QWORD *)v6 = 0;
        *(_DWORD *)(v6 + 8) = 0;
        *(_DWORD *)(v6 + 12) = 0;
        *(_DWORD *)(v6 + 16) = 0;
        v7 = gp_hif_rtpm_ctx;
        v8 = *(_DWORD *)(gp_hif_rtpm_ctx + 48);
        *(_QWORD *)(gp_hif_rtpm_ctx + 112) = v6;
        *(_DWORD *)(v7 + 48) = v8 + 1;
      }
    }
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: Runtime PM context NULL", "hif_rtpm_register");
  }
  for ( i = 0; (unsigned int)i > 7 || ((1 << i) & 0x86) == 0; ++i )
  {
    *(_QWORD *)(gp_hif_rtpm_ctx + 8 * i + 320) = 0;
    if ( i > 0xA )
      return qdf_trace_msg(61, 5, "%s: Runtime PM attached", "hif_rtpm_open");
LABEL_12:
    ;
  }
  v10 = _qdf_mem_malloc(144, "hif_rtpm_alloc_last_busy_hist", 319);
  *(_QWORD *)(gp_hif_rtpm_ctx + 8 * i + 320) = v10;
  if ( v10 )
    goto LABEL_12;
  return qdf_trace_msg(61, 5, "%s: Runtime PM attached", "hif_rtpm_open");
}
