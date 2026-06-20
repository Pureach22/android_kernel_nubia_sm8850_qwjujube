_QWORD *__fastcall wma_delete_invalid_peer_entries(
        unsigned __int8 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  __int64 v13; // x21
  void *v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  void *v23; // x0
  size_t v24; // x1

  result = _cds_get_context(54, (__int64)"wma_delete_invalid_peer_entries", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v13 = result[65] + 488LL * a1;
    v14 = (void *)(v13 + 448);
    if ( a2 )
    {
      if ( (unsigned int)qdf_mem_cmp((const void *)(v13 + 448), a2, 6u) )
      {
        v14 = (void *)(v13 + 454);
        if ( (unsigned int)qdf_mem_cmp((const void *)(v13 + 454), a2, 6u) )
        {
          v14 = (void *)(v13 + 460);
          if ( (unsigned int)qdf_mem_cmp((const void *)(v13 + 460), a2, 6u) )
          {
            v14 = (void *)(v13 + 466);
            if ( (unsigned int)qdf_mem_cmp((const void *)(v13 + 466), a2, 6u) )
            {
              v14 = (void *)(v13 + 472);
              if ( (unsigned int)qdf_mem_cmp((const void *)(v13 + 472), a2, 6u) )
                return (_QWORD *)qdf_trace_msg(
                                   0x36u,
                                   8u,
                                   "%s: peer_mac_addr %02x:%02x:%02x:**:**:%02x is not found",
                                   v15,
                                   v16,
                                   v17,
                                   v18,
                                   v19,
                                   v20,
                                   v21,
                                   v22,
                                   "wma_delete_invalid_peer_entries",
                                   *a2,
                                   a2[1],
                                   a2[2],
                                   a2[5]);
            }
          }
        }
      }
      v23 = v14;
      v24 = 4;
    }
    else
    {
      v23 = (void *)(v13 + 448);
      v24 = 30;
    }
    return qdf_mem_set(v23, v24, 0);
  }
  return result;
}
