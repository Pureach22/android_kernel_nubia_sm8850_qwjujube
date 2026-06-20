__int64 __fastcall cm_add_disconnect_req_to_list(__int64 a1, _DWORD *a2)
{
  int cm_id; // w0
  __int64 v5; // x2

  cm_id = cm_get_cm_id(a1, (unsigned int)a2[2]);
  v5 = (unsigned int)a2[2];
  *a2 = cm_id;
  *(a2 - 2) = cm_id;
  return cm_add_req_to_list_and_indicate_osif(a1, a2 - 6, v5);
}
