__int64 __fastcall _dsc_trans_queue(__int64 a1, __int64 a2, __int64 a3)
{
  *(_BYTE *)a2 = 0;
  *(_QWORD *)(a2 + 8) = a3;
  qdf_event_create((_DWORD *)(a2 + 32));
  qdf_list_insert_back((_QWORD *)(a1 + 8), (_QWORD *)(a2 + 16));
  return 0;
}
