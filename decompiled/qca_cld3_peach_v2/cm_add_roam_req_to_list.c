__int64 __fastcall cm_add_roam_req_to_list(unsigned int *a1, __int64 a2)
{
  int cm_id; // w0
  unsigned int v5; // w2

  cm_id = cm_get_cm_id(a1, *(_DWORD *)(a2 + 36));
  *(_DWORD *)(a2 + 24) = cm_id;
  v5 = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a2 + 16) = cm_id;
  *(_BYTE *)(a2 + 33) = *(_BYTE *)(*(_QWORD *)a1 + 168LL);
  return cm_add_req_to_list_and_indicate_osif(a1, a2, v5);
}
