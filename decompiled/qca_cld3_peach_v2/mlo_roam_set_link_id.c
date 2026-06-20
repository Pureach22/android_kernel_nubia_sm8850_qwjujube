__int64 __fastcall mlo_roam_set_link_id(
        __int64 result,
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
  __int64 v10; // x19
  __int64 v11; // x20
  unsigned int v12; // w8
  __int64 v13; // x21
  __int64 v14; // x21
  __int64 v15; // x20
  __int64 v16; // x19
  unsigned int v17; // w8
  __int64 v18; // x20
  __int64 v19; // x20
  __int64 v20; // x19

  if ( !result )
    return qdf_trace_msg(0x8Fu, 8u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "mlo_roam_set_link_id");
  if ( !a2 )
    return qdf_trace_msg(0x8Fu, 8u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "mlo_roam_set_link_id");
  v10 = *(_QWORD *)(result + 1360);
  if ( !v10 )
    return qdf_trace_msg(0x8Fu, 8u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "mlo_roam_set_link_id");
  v11 = *(_QWORD *)(v10 + 24);
  if ( v11 )
  {
    *(_BYTE *)(v11 + 93) = -1;
    v12 = *(unsigned __int8 *)(a2 + 2497);
    if ( *(_BYTE *)(a2 + 2497) )
    {
      if ( *(_DWORD *)(a2 + 2500) == *(unsigned __int8 *)(v11 + 168) )
      {
        *(_BYTE *)(v11 + 93) = *(_DWORD *)(a2 + 2504);
        v13 = a2;
        result = qdf_trace_msg(
                   0x68u,
                   8u,
                   "%s: Set link for vdev id %d link id %d",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   "mlo_roam_set_link_id");
        v12 = *(unsigned __int8 *)(v13 + 2497);
        a2 = v13;
      }
      if ( v12 >= 2 )
      {
        if ( *(_DWORD *)(a2 + 2552) == *(unsigned __int8 *)(v11 + 168) )
        {
          *(_BYTE *)(v11 + 93) = *(_DWORD *)(a2 + 2556);
          v14 = a2;
          result = qdf_trace_msg(
                     0x68u,
                     8u,
                     "%s: Set link for vdev id %d link id %d",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "mlo_roam_set_link_id");
          v12 = *(unsigned __int8 *)(v14 + 2497);
          a2 = v14;
        }
        if ( v12 >= 3 )
        {
          if ( *(_DWORD *)(a2 + 2604) == *(unsigned __int8 *)(v11 + 168) )
          {
            *(_BYTE *)(v11 + 93) = *(_DWORD *)(a2 + 2608);
            v15 = a2;
            result = qdf_trace_msg(
                       0x68u,
                       8u,
                       "%s: Set link for vdev id %d link id %d",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       "mlo_roam_set_link_id");
            v12 = *(unsigned __int8 *)(v15 + 2497);
            a2 = v15;
          }
          if ( v12 > 3 )
            goto LABEL_26;
        }
      }
    }
  }
  v16 = *(_QWORD *)(v10 + 32);
  if ( v16 )
  {
    *(_BYTE *)(v16 + 93) = -1;
    v17 = *(unsigned __int8 *)(a2 + 2497);
    if ( *(_BYTE *)(a2 + 2497) )
    {
      if ( *(_DWORD *)(a2 + 2500) == *(unsigned __int8 *)(v16 + 168) )
      {
        *(_BYTE *)(v16 + 93) = *(_DWORD *)(a2 + 2504);
        v18 = a2;
        result = qdf_trace_msg(
                   0x68u,
                   8u,
                   "%s: Set link for vdev id %d link id %d",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   "mlo_roam_set_link_id");
        v17 = *(unsigned __int8 *)(v18 + 2497);
        a2 = v18;
      }
      if ( v17 >= 2 )
      {
        if ( *(_DWORD *)(a2 + 2552) == *(unsigned __int8 *)(v16 + 168) )
        {
          *(_BYTE *)(v16 + 93) = *(_DWORD *)(a2 + 2556);
          v19 = a2;
          result = qdf_trace_msg(
                     0x68u,
                     8u,
                     "%s: Set link for vdev id %d link id %d",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "mlo_roam_set_link_id");
          v17 = *(unsigned __int8 *)(v19 + 2497);
          a2 = v19;
        }
        if ( v17 >= 3 )
        {
          if ( *(_DWORD *)(a2 + 2604) == *(unsigned __int8 *)(v16 + 168) )
          {
            *(_BYTE *)(v16 + 93) = *(_DWORD *)(a2 + 2608);
            v20 = a2;
            result = qdf_trace_msg(
                       0x68u,
                       8u,
                       "%s: Set link for vdev id %d link id %d",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       "mlo_roam_set_link_id");
            v17 = *(unsigned __int8 *)(v20 + 2497);
          }
          if ( v17 > 3 )
          {
LABEL_26:
            __break(0x5512u);
            return qdf_trace_msg(
                     0x8Fu,
                     8u,
                     "%s: Invalid input",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "mlo_roam_set_link_id");
          }
        }
      }
    }
  }
  return result;
}
