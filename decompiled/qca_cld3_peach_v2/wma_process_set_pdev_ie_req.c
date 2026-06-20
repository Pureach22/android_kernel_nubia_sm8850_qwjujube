__int64 __fastcall wma_process_set_pdev_ie_req(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x20

  v2 = *(unsigned __int8 *)(a2 + 1);
  if ( v2 == 1 )
  {
    v4 = a1;
    wma_process_set_pdev_ht_ie_req(a1, a2);
    v2 = *(unsigned __int8 *)(a2 + 1);
    a1 = v4;
  }
  if ( v2 == 2 )
    wma_process_set_pdev_vht_ie_req(a1, a2);
  return _qdf_mem_free(*(_QWORD *)(a2 + 8));
}
