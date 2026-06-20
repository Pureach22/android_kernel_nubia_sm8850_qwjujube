__int64 __fastcall wma_vdev_deinit(
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
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0

  result = (__int64)_cds_get_context(54, (__int64)"wma_vdev_deinit", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v11 = *(_QWORD *)(a1 + 8);
    if ( v11 )
    {
      if ( *(_BYTE *)(v11 + 12) )
        _qdf_nbuf_unmap_single(*(_QWORD *)(result + 184), *(_QWORD *)v11, 1);
      if ( *(_QWORD *)v11 )
        _qdf_nbuf_free(*(_QWORD *)v11);
      _qdf_mem_free(v11);
      *(_QWORD *)(a1 + 8) = 0;
    }
    if ( *(_BYTE *)(a1 + 184) == 1 )
      *(_BYTE *)(a1 + 184) = 0;
    v12 = *(_QWORD *)(a1 + 200);
    if ( v12 )
    {
      _qdf_mem_free(v12);
      *(_QWORD *)(a1 + 200) = 0;
    }
    v13 = *(_QWORD *)(a1 + 256);
    if ( v13 )
    {
      _qdf_mem_free(v13);
      *(_QWORD *)(a1 + 256) = 0;
    }
    v14 = *(_QWORD *)(a1 + 272);
    if ( v14 )
    {
      _qdf_mem_free(v14);
      *(_QWORD *)(a1 + 272) = 0;
    }
    v15 = *(_QWORD *)(a1 + 440);
    if ( v15 )
    {
      *(_QWORD *)(a1 + 440) = 0;
      _qdf_mem_free(v15);
    }
    v16 = *(_QWORD *)(a1 + 368);
    if ( v16 )
    {
      _qdf_mem_free(v16);
      *(_QWORD *)(a1 + 368) = 0;
    }
    v17 = *(_QWORD *)(a1 + 400);
    if ( v17 )
    {
      _qdf_mem_free(v17);
      *(_QWORD *)(a1 + 400) = 0;
    }
    v18 = *(_QWORD *)(a1 + 416);
    if ( v18 )
    {
      _qdf_mem_free(v18);
      *(_QWORD *)(a1 + 416) = 0;
    }
    result = *(_QWORD *)(a1 + 248);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)(a1 + 248) = 0;
    }
    *(_BYTE *)(a1 + 432) = 0;
  }
  return result;
}
