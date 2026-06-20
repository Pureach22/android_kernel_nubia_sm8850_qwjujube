__int64 __fastcall _qdf_mem_unmap_page(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x0

  v4 = *(_QWORD *)(a1 + 40);
  if ( (unsigned int)a4 >= 3 )
    a4 = 3;
  else
    a4 = (unsigned int)a4;
  return dma_unmap_page_attrs(v4, a2, a3, a4, 0);
}
