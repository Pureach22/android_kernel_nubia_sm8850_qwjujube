__int64 __fastcall wlan_cm_free_connect_rsp(__int64 a1)
{
  __int64 v2; // x0

  _qdf_mem_free(*(_QWORD *)(a1 + 192));
  v2 = *(_QWORD *)(a1 + 176);
  *(_QWORD *)(a1 + 192) = 0;
  *(_DWORD *)(a1 + 184) = 0;
  _qdf_mem_free(v2);
  cm_free_connect_rsp_ies(a1 + 8);
  qdf_mem_set((void *)a1, 0xD0u, 0);
  return _qdf_mem_free(a1);
}
