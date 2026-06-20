__int64 __fastcall target_if_cp_stats_free_stats_event(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // w8
  __int64 v12; // x0
  int v13; // w20
  __int64 *v14; // x21
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 208);
  if ( v2 )
  {
    _qdf_mem_free(v2);
    *(_QWORD *)(a1 + 208) = 0;
  }
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  v3 = *(_QWORD *)(a1 + 24);
  *(_QWORD *)(a1 + 8) = 0;
  _qdf_mem_free(v3);
  v4 = *(_QWORD *)(a1 + 40);
  *(_QWORD *)(a1 + 24) = 0;
  _qdf_mem_free(v4);
  v5 = *(_QWORD *)(a1 + 56);
  *(_QWORD *)(a1 + 40) = 0;
  _qdf_mem_free(v5);
  v6 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)(a1 + 56) = 0;
  _qdf_mem_free(v6);
  v7 = *(_QWORD *)(a1 + 80);
  *(_QWORD *)(a1 + 72) = 0;
  _qdf_mem_free(v7);
  v8 = *(_QWORD *)(a1 + 96);
  *(_QWORD *)(a1 + 80) = 0;
  _qdf_mem_free(v8);
  v9 = *(_QWORD *)(a1 + 128);
  *(_QWORD *)(a1 + 96) = 0;
  _qdf_mem_free(v9);
  v10 = *(_QWORD *)(a1 + 112);
  *(_QWORD *)(a1 + 128) = 0;
  _qdf_mem_free(v10);
  v11 = *(_DWORD *)(a1 + 156);
  v12 = *(_QWORD *)(a1 + 160);
  *(_QWORD *)(a1 + 112) = 0;
  if ( v11 )
  {
    v13 = 0;
    v14 = (__int64 *)(v12 + 120);
    do
    {
      _qdf_mem_free(*(v14 - 1));
      v15 = *v14;
      *(v14 - 1) = 0;
      _qdf_mem_free(v15);
      *v14 = 0;
      v14 += 17;
      ++v13;
    }
    while ( *(_DWORD *)(a1 + 156) > (unsigned int)(unsigned __int16)v13 );
    v12 = *(_QWORD *)(a1 + 160);
  }
  _qdf_mem_free(v12);
  v16 = *(_QWORD *)(a1 + 192);
  *(_QWORD *)(a1 + 160) = 0;
  *(_DWORD *)(a1 + 156) = 0;
  result = _qdf_mem_free(v16);
  *(_QWORD *)(a1 + 192) = 0;
  return result;
}
