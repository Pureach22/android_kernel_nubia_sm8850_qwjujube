__int64 __fastcall wlan_cm_free_connect_rsp(__int64 a1)
{
  __int64 v2; // x0

  _qdf_mem_free(*(_QWORD *)(a1 + 368));
  v2 = *(_QWORD *)(a1 + 352);
  *(_QWORD *)(a1 + 368) = 0;
  *(_DWORD *)(a1 + 360) = 0;
  _qdf_mem_free(v2);
  cm_free_connect_rsp_ies(a1 + 8);
  qdf_mem_set((void *)a1, 0x180u, 0);
  return _qdf_mem_free(a1);
}
