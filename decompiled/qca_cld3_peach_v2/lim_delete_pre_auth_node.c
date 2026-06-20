__int64 __fastcall lim_delete_pre_auth_node(__int64 result, unsigned __int8 *a2)
{
  __int64 *v2; // x20
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 *v13; // x22
  __int64 v14; // x6
  __int64 v15; // x7
  int v16; // w8
  int v17; // w9
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  int v26; // w9
  __int64 v27; // x21

  v2 = *(__int64 **)(result + 11424);
  if ( v2 )
  {
    v4 = result;
    if ( (unsigned int)qdf_mem_cmp(a2, v2 + 1, 6u) )
    {
      while ( 1 )
      {
        v13 = v2;
        v2 = (__int64 *)*v2;
        if ( !v2 )
          break;
        if ( !(unsigned int)qdf_mem_cmp(a2, v2 + 1, 6u) )
        {
          *v13 = *v2;
          if ( a2 )
          {
            v14 = *a2;
            v15 = a2[1];
            v16 = a2[2];
            v17 = a2[5];
          }
          else
          {
            v16 = 0;
            v14 = 0;
            v15 = 0;
            v17 = 0;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: subsequent node to delete, Release data entry: %pK id %d peer %02x:%02x:%02x:**:**:%02x",
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            "lim_delete_pre_auth_node",
            v2,
            *((unsigned __int8 *)v2 + 24),
            v14,
            v15,
            v16,
            v17);
          goto LABEL_17;
        }
      }
      if ( a2 )
      {
        v22 = *a2;
        v23 = a2[1];
        v24 = a2[2];
        v25 = a2[5];
      }
      else
      {
        v24 = 0;
        v22 = 0;
        v23 = 0;
        v25 = 0;
      }
      return qdf_trace_msg(
               0x35u,
               2u,
               "%s: peer not found in pre-auth list, addr= %02x:%02x:%02x:**:**:%02x",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "lim_delete_pre_auth_node",
               v22,
               v23,
               v24,
               v25);
    }
    else
    {
      *(_QWORD *)(v4 + 11424) = *v2;
      if ( a2 )
      {
        v18 = *a2;
        v19 = a2[1];
        v20 = a2[2];
        v21 = a2[5];
      }
      else
      {
        v20 = 0;
        v18 = 0;
        v19 = 0;
        v21 = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: fRelease data for %d peer %02x:%02x:%02x:**:**:%02x",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "lim_delete_pre_auth_node",
        *((unsigned __int8 *)v2 + 24),
        v18,
        v19,
        v20,
        v21);
LABEL_17:
      v26 = *((_DWORD *)v2 + 4);
      *((_BYTE *)v2 + 278) |= 4u;
      if ( v26 == 3 && *((_BYTE *)v2 + 560) == 1 )
      {
        v27 = v2[71];
        lim_free_assoc_req_frm_buf(v27);
        _qdf_mem_free(v27);
        v2[71] = 0;
        *((_BYTE *)v2 + 560) = 0;
      }
      qdf_trace(53, 0xEu, 255, 7);
      result = tx_timer_deactivate(v2 + 35);
      --*(_DWORD *)(v4 + 11404);
    }
  }
  return result;
}
