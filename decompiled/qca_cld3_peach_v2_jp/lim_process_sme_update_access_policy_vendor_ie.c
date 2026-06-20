void *__fastcall lim_process_sme_update_access_policy_vendor_ie(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_vdev_id; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 v21; // x0
  unsigned int v22; // w21
  void *result; // x0

  if ( !a2 )
    return (void *)qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: Buffer is Pointing to NULL",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "lim_process_sme_update_access_policy_vendor_ie");
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned int *)(a2 + 4));
  if ( !session_by_vdev_id )
    return (void *)qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: Session does not exist for given vdev_id %d",
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     "lim_process_sme_update_access_policy_vendor_ie",
                     *(unsigned int *)(a2 + 4));
  v20 = session_by_vdev_id;
  v21 = *(_QWORD *)(session_by_vdev_id + 8664);
  if ( v21 )
    _qdf_mem_free(v21);
  v22 = *(unsigned __int8 *)(a2 + 9) + 2;
  result = (void *)_qdf_mem_malloc(
                     *(unsigned __int8 *)(a2 + 9) + 2LL,
                     "lim_process_sme_update_access_policy_vendor_ie",
                     9622);
  *(_QWORD *)(v20 + 8664) = result;
  if ( result )
  {
    result = qdf_mem_copy(result, (const void *)(a2 + 8), v22);
    *(_BYTE *)(v20 + 8672) = *(_BYTE *)(a2 + 265);
  }
  return result;
}
