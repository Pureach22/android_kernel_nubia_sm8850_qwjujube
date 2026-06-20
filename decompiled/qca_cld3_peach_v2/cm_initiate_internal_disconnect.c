__int64 __fastcall cm_initiate_internal_disconnect(__int64 *a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  char v12; // w8
  int cm_id; // w0
  __int64 v14; // x2
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  result = _qdf_mem_malloc(0x9F0u, "cm_initiate_internal_disconnect", 294);
  if ( result )
  {
    v11 = result;
    v12 = *(_BYTE *)(*a1 + 168);
    *(_DWORD *)(result + 32) = 9;
    *(_BYTE *)(result + 28) = v12;
    if ( (wlan_vdev_mlme_is_mlo_vdev(*a1, v3, v4, v5, v6, v7, v8, v9, v10) & 1) != 0 )
      mlo_internal_disconnect_links(*a1);
    cm_id = cm_get_cm_id(a1, *(unsigned int *)(v11 + 32));
    v14 = *(unsigned int *)(v11 + 32);
    *(_DWORD *)(v11 + 24) = cm_id;
    *(_DWORD *)(v11 + 16) = cm_id;
    if ( (unsigned int)cm_add_req_to_list_and_indicate_osif(a1, v11, v14) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: failed to add disconnect req",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "cm_initiate_internal_disconnect",
        *(unsigned __int8 *)(v11 + 28),
        *(unsigned int *)(v11 + 24));
      return _qdf_mem_free(v11);
    }
    else
    {
      return cm_disconnect_start(a1, v11 + 24);
    }
  }
  return result;
}
