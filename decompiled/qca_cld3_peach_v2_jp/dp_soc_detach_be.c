__int64 __fastcall dp_soc_detach_be(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x1
  __int64 v4; // x1
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x1
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 v11; // x0

  _qdf_mem_free_consistent(*(_QWORD *)(a1 + 24), *(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), 139400);
  _qdf_mem_free_consistent(*(_QWORD *)(a1 + 24), *(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), 278528);
  dp_desc_multi_pages_mem_free(a1, *(unsigned int *)(a1 + 22640), a1 + 22584, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22576));
  v2 = *(unsigned int *)(a1 + 22720);
  *(_QWORD *)(a1 + 22576) = 0;
  dp_desc_multi_pages_mem_free(a1, v2, a1 + 22664, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22656));
  v3 = *(unsigned int *)(a1 + 22800);
  *(_QWORD *)(a1 + 22656) = 0;
  dp_desc_multi_pages_mem_free(a1, v3, a1 + 22744, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22736));
  v4 = *(unsigned int *)(a1 + 22880);
  *(_QWORD *)(a1 + 22736) = 0;
  dp_desc_multi_pages_mem_free(a1, v4, a1 + 22824, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22816));
  v5 = *(unsigned int *)(a1 + 22960);
  *(_QWORD *)(a1 + 22816) = 0;
  dp_desc_multi_pages_mem_free(a1, v5, a1 + 22904, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22896));
  v6 = *(unsigned int *)(a1 + 23040);
  *(_QWORD *)(a1 + 22896) = 0;
  dp_desc_multi_pages_mem_free(a1, v6, a1 + 22984, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22976));
  v7 = *(unsigned int *)(a1 + 23120);
  *(_QWORD *)(a1 + 22976) = 0;
  dp_desc_multi_pages_mem_free(a1, v7, a1 + 23064, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23056));
  v8 = *(unsigned int *)(a1 + 23200);
  *(_QWORD *)(a1 + 23056) = 0;
  dp_desc_multi_pages_mem_free(a1, v8, a1 + 23144, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23136));
  v9 = *(unsigned int *)(a1 + 23280);
  *(_QWORD *)(a1 + 23136) = 0;
  dp_desc_multi_pages_mem_free(a1, v9, a1 + 23224, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23216));
  v10 = *(unsigned int *)(a1 + 23360);
  *(_QWORD *)(a1 + 23216) = 0;
  dp_desc_multi_pages_mem_free(a1, v10, a1 + 23304, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23296));
  v11 = *(_QWORD *)(a1 + 22552);
  *(_QWORD *)(a1 + 23296) = 0;
  _qdf_mem_free(v11);
  *(_QWORD *)(a1 + 22552) = 0;
  return 0;
}
