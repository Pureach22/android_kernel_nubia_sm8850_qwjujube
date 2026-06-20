_QWORD *__fastcall mlme_set_peer_assoc_rsp_ie(
        __int64 a1,
        _BYTE *a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *result; // x0
  __int64 v13; // x19
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 v24; // x0
  void *v25; // x0

  if ( !a3 || !*a3 || !a2 || !*((_QWORD *)a3 + 1) )
    return (_QWORD *)qdf_trace_msg(
                       0x1Fu,
                       8u,
                       "%s: Assoc IE is NULL",
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11,
                       "mlme_set_peer_assoc_rsp_ie");
  result = wlan_objmgr_get_peer_by_mac(a1, a2, 7u);
  if ( result )
  {
    v13 = (__int64)result;
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)result, 0);
    if ( comp_private_obj )
    {
      v23 = comp_private_obj;
      v24 = *(_QWORD *)(comp_private_obj + 64);
      if ( v24 )
      {
        _qdf_mem_free(v24);
        *(_QWORD *)(v23 + 64) = 0;
        *(_DWORD *)(v23 + 56) = 0;
      }
      v25 = (void *)_qdf_mem_malloc(*a3, "mlme_set_peer_assoc_rsp_ie", 4525);
      *(_QWORD *)(v23 + 64) = v25;
      if ( v25 )
      {
        qdf_mem_copy(v25, *((const void **)a3 + 1), *a3);
        *(_DWORD *)(v23 + 56) = *a3;
      }
    }
    return (_QWORD *)wlan_objmgr_peer_release_ref(v13, 7u, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  return result;
}
