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
  dp_desc_multi_pages_mem_free(a1, *(unsigned int *)(a1 + 22696), a1 + 22640, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22632));
  v2 = *(unsigned int *)(a1 + 22776);
  *(_QWORD *)(a1 + 22632) = 0;
  dp_desc_multi_pages_mem_free(a1, v2, a1 + 22720, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22712));
  v3 = *(unsigned int *)(a1 + 22856);
  *(_QWORD *)(a1 + 22712) = 0;
  dp_desc_multi_pages_mem_free(a1, v3, a1 + 22800, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22792));
  v4 = *(unsigned int *)(a1 + 22936);
  *(_QWORD *)(a1 + 22792) = 0;
  dp_desc_multi_pages_mem_free(a1, v4, a1 + 22880, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22872));
  v5 = *(unsigned int *)(a1 + 23016);
  *(_QWORD *)(a1 + 22872) = 0;
  dp_desc_multi_pages_mem_free(a1, v5, a1 + 22960, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 22952));
  v6 = *(unsigned int *)(a1 + 23096);
  *(_QWORD *)(a1 + 22952) = 0;
  dp_desc_multi_pages_mem_free(a1, v6, a1 + 23040, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23032));
  v7 = *(unsigned int *)(a1 + 23176);
  *(_QWORD *)(a1 + 23032) = 0;
  dp_desc_multi_pages_mem_free(a1, v7, a1 + 23120, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23112));
  v8 = *(unsigned int *)(a1 + 23256);
  *(_QWORD *)(a1 + 23112) = 0;
  dp_desc_multi_pages_mem_free(a1, v8, a1 + 23200, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23192));
  v9 = *(unsigned int *)(a1 + 23336);
  *(_QWORD *)(a1 + 23192) = 0;
  dp_desc_multi_pages_mem_free(a1, v9, a1 + 23280, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23272));
  v10 = *(unsigned int *)(a1 + 23416);
  *(_QWORD *)(a1 + 23272) = 0;
  dp_desc_multi_pages_mem_free(a1, v10, a1 + 23360, 0, 0);
  _qdf_mem_free(*(_QWORD *)(a1 + 23352));
  v11 = *(_QWORD *)(a1 + 22608);
  *(_QWORD *)(a1 + 23352) = 0;
  _qdf_mem_free(v11);
  *(_QWORD *)(a1 + 22608) = 0;
  return 0;
}
