__int64 __fastcall mlo_link_recfg_ctx_free_ies(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  void *v3; // x20
  void *v4; // x20
  void *v5; // x20
  void *v6; // x20
  void *v7; // x20

  if ( result )
  {
    v1 = *(_QWORD *)(result + 3224);
    v2 = result;
    if ( v1 )
    {
      qdf_mem_set(*(void **)(result + 3224), *(unsigned int *)(result + 3216), 0);
      result = _qdf_mem_free(v1);
    }
    v3 = *(void **)(v2 + 3240);
    *(_DWORD *)(v2 + 3216) = 0;
    *(_QWORD *)(v2 + 3224) = 0;
    if ( v3 )
    {
      qdf_mem_set(v3, *(unsigned int *)(v2 + 3232), 0);
      result = _qdf_mem_free((__int64)v3);
    }
    v4 = *(void **)(v2 + 3280);
    *(_DWORD *)(v2 + 3232) = 0;
    *(_QWORD *)(v2 + 3240) = 0;
    if ( v4 )
    {
      qdf_mem_set(v4, *(unsigned int *)(v2 + 3272), 0);
      result = _qdf_mem_free((__int64)v4);
    }
    v5 = *(void **)(v2 + 720);
    *(_DWORD *)(v2 + 3272) = 0;
    *(_QWORD *)(v2 + 3280) = 0;
    if ( v5 )
    {
      qdf_mem_set(v5, *(unsigned int *)(v2 + 712), 0);
      result = _qdf_mem_free((__int64)v5);
    }
    v6 = *(void **)(v2 + 736);
    *(_DWORD *)(v2 + 712) = 0;
    *(_QWORD *)(v2 + 720) = 0;
    if ( v6 )
    {
      qdf_mem_set(v6, *(unsigned int *)(v2 + 728), 0);
      result = _qdf_mem_free((__int64)v6);
    }
    v7 = *(void **)(v2 + 752);
    *(_DWORD *)(v2 + 728) = 0;
    *(_QWORD *)(v2 + 736) = 0;
    if ( v7 )
    {
      qdf_mem_set(v7, *(unsigned int *)(v2 + 744), 0);
      result = _qdf_mem_free((__int64)v7);
    }
    *(_DWORD *)(v2 + 744) = 0;
    *(_QWORD *)(v2 + 752) = 0;
    *(_BYTE *)(v2 + 578) = 0;
  }
  return result;
}
