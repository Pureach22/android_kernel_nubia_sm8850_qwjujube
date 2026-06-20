__int64 __fastcall mlo_mgr_update_link_status_code(
        __int64 result,
        unsigned __int8 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x4
  __int64 v18; // x5

  if ( result )
  {
    v15 = *(_QWORD *)(result + 1360);
    if ( v15 )
    {
      if ( a2 <= 0xEu )
      {
        v16 = *(_QWORD *)(v15 + 3880);
        a15 = a3;
        if ( *(unsigned __int8 *)(v16 + 6) == a2 )
          goto LABEL_7;
        if ( *(unsigned __int8 *)(v16 + 54) == a2 )
        {
          v16 += 48;
LABEL_7:
          if ( v16 )
          {
LABEL_8:
            v17 = *(unsigned __int8 *)(v16 + 6);
            v18 = *(unsigned __int8 *)(v16 + 12);
            *(_DWORD *)(v16 + 44) = a3;
            return qdf_trace_msg(
                     0x8Fu,
                     8u,
                     "%s: Update status code info for link_id: %d, vdev_id:%d, link_status_code: %d",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "mlo_mgr_update_link_status_code",
                     v17,
                     v18);
          }
          return qdf_trace_msg(
                   0x8Fu,
                   2u,
                   "%s: Link info not found for link id %d",
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "mlo_mgr_update_link_status_code",
                   a2,
                   a14,
                   a15);
        }
        if ( *(unsigned __int8 *)(v16 + 102) == a2 )
        {
          v16 += 96;
          if ( v16 )
            goto LABEL_8;
        }
      }
      return qdf_trace_msg(
               0x8Fu,
               2u,
               "%s: Link info not found for link id %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "mlo_mgr_update_link_status_code",
               a2,
               a14,
               a15);
    }
  }
  return result;
}
