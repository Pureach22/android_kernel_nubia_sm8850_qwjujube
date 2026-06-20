__int64 __fastcall _qdf_nbuf_frag_map(__int64 a1, __int64 a2, int a3, unsigned int a4, unsigned int a5)
{
  __int64 v5; // x0
  __int64 v7; // x9
  __int64 v8; // x4
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 result; // x0

  if ( a5 >= 0x12 )
  {
    __break(0x5512u);
    JUMPOUT(0x17FADC);
  }
  v5 = *(_QWORD *)(a1 + 40);
  v7 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 16LL * a5;
  if ( a4 >= 3 )
    v8 = 3;
  else
    v8 = a4;
  v9 = *(_QWORD *)(v7 + 88);
  v10 = *(unsigned int *)(v7 + 96);
  v11 = *(unsigned int *)(v7 + 100);
  if ( (v9 & 1) != 0 )
    v12 = 0;
  else
    v12 = v9;
  v13 = dma_map_page_attrs(v5, v12, v11 + a3, v10, v8, 0);
  if ( v13 == -1 )
    result = 5;
  else
    result = 0;
  *(_QWORD *)(a2 + 80) = v13;
  return result;
}
