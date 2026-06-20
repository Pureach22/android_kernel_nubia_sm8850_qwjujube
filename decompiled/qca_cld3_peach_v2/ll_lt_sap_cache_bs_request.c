__int64 __fastcall ll_lt_sap_cache_bs_request(
        __int64 a1,
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
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned __int8 *v13; // x20
  int v14; // w8
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x9
  int v18; // w8
  __int64 v19; // x9
  __int64 result; // x0

  v10 = *((_QWORD *)a2 + 2);
  v11 = *(_QWORD *)(a1 + 272);
  v13 = (unsigned __int8 *)(a1 + 256);
  if ( v11 == v10
    && *v13 == *a2
    && *(_DWORD *)(a1 + 264) == *((_DWORD *)a2 + 2)
    && *(_DWORD *)(a1 + 280) == *((_DWORD *)a2 + 6)
    && *(_QWORD *)(a1 + 288) == *((_QWORD *)a2 + 4)
    && *(_DWORD *)(a1 + 268) == *((_DWORD *)a2 + 3) )
  {
    v14 = 0;
    return qdf_trace_msg(
             0xA1u,
             4u,
             "%s: BS_SM_%d req_id 0x%x: req_vdev %d have already cached request %d at %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "ll_lt_sap_cache_bs_request",
             *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
             *((unsigned int *)a2 + 1),
             v14);
  }
  if ( v11 )
  {
    v15 = *(_QWORD *)(a1 + 312);
    v13 = (unsigned __int8 *)(a1 + 296);
    if ( v15 == v10
      && *v13 == *a2
      && *(_DWORD *)(a1 + 304) == *((_DWORD *)a2 + 2)
      && *(_DWORD *)(a1 + 320) == *((_DWORD *)a2 + 6)
      && *(_QWORD *)(a1 + 328) == *((_QWORD *)a2 + 4)
      && *(_DWORD *)(a1 + 308) == *((_DWORD *)a2 + 3) )
    {
      v14 = 1;
      return qdf_trace_msg(
               0xA1u,
               4u,
               "%s: BS_SM_%d req_id 0x%x: req_vdev %d have already cached request %d at %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "ll_lt_sap_cache_bs_request",
               *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
               *((unsigned int *)a2 + 1),
               v14);
    }
    if ( v15 )
    {
      v16 = *(_QWORD *)(a1 + 352);
      v13 = (unsigned __int8 *)(a1 + 336);
      if ( v16 == v10
        && *v13 == *a2
        && *(_DWORD *)(a1 + 344) == *((_DWORD *)a2 + 2)
        && *(_DWORD *)(a1 + 360) == *((_DWORD *)a2 + 6)
        && *(_QWORD *)(a1 + 368) == *((_QWORD *)a2 + 4)
        && *(_DWORD *)(a1 + 348) == *((_DWORD *)a2 + 3) )
      {
        v14 = 2;
        return qdf_trace_msg(
                 0xA1u,
                 4u,
                 "%s: BS_SM_%d req_id 0x%x: req_vdev %d have already cached request %d at %d",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "ll_lt_sap_cache_bs_request",
                 *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
                 *((unsigned int *)a2 + 1),
                 v14);
      }
      if ( v16 )
      {
        v17 = *(_QWORD *)(a1 + 392);
        v13 = (unsigned __int8 *)(a1 + 376);
        if ( v17 == v10
          && *v13 == *a2
          && *(_DWORD *)(a1 + 384) == *((_DWORD *)a2 + 2)
          && *(_DWORD *)(a1 + 400) == *((_DWORD *)a2 + 6)
          && *(_QWORD *)(a1 + 408) == *((_QWORD *)a2 + 4)
          && *(_DWORD *)(a1 + 388) == *((_DWORD *)a2 + 3) )
        {
          v14 = 3;
          return qdf_trace_msg(
                   0xA1u,
                   4u,
                   "%s: BS_SM_%d req_id 0x%x: req_vdev %d have already cached request %d at %d",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   "ll_lt_sap_cache_bs_request",
                   *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
                   *((unsigned int *)a2 + 1),
                   v14);
        }
        if ( v17 )
        {
          v19 = *(_QWORD *)(a1 + 432);
          v13 = (unsigned __int8 *)(a1 + 416);
          if ( v19 == v10
            && *v13 == *a2
            && *(_DWORD *)(a1 + 424) == *((_DWORD *)a2 + 2)
            && *(_DWORD *)(a1 + 440) == *((_DWORD *)a2 + 6)
            && *(_QWORD *)(a1 + 448) == *((_QWORD *)a2 + 4)
            && *(_DWORD *)(a1 + 428) == *((_DWORD *)a2 + 3) )
          {
            v14 = 4;
            return qdf_trace_msg(
                     0xA1u,
                     4u,
                     "%s: BS_SM_%d req_id 0x%x: req_vdev %d have already cached request %d at %d",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "ll_lt_sap_cache_bs_request",
                     *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
                     *((unsigned int *)a2 + 1),
                     v14);
          }
          if ( v19 )
            return qdf_trace_msg(
                     0xA1u,
                     2u,
                     "%s: BS_SM_%d req_id 0x%x: Max number of requests reached",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "ll_lt_sap_cache_bs_request",
                     *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
                     *((unsigned int *)a2 + 1));
          v18 = 4;
        }
        else
        {
          v18 = 3;
        }
      }
      else
      {
        v18 = 2;
      }
    }
    else
    {
      v18 = 1;
    }
  }
  else
  {
    v18 = 0;
  }
  result = qdf_trace_msg(
             0xA1u,
             8u,
             "%s: BS_SM_%d req_id 0x%x: req_vdev %d cache %d request at %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "ll_lt_sap_cache_bs_request",
             *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
             *((unsigned int *)a2 + 1),
             *a2,
             *((unsigned int *)a2 + 2),
             v18);
  *v13 = *a2;
  *((_DWORD *)v13 + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)v13 + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)v13 + 3) = *((_DWORD *)a2 + 3);
  *((_QWORD *)v13 + 2) = *((_QWORD *)a2 + 2);
  *((_DWORD *)v13 + 6) = *((_DWORD *)a2 + 6);
  *((_QWORD *)v13 + 4) = *((_QWORD *)a2 + 4);
  return result;
}
