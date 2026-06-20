__int64 __fastcall hdd_fips_cb(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x19
  _QWORD *v22; // x0
  _QWORD *v23; // x21
  __int64 v24; // x8
  const char *v25; // x2
  unsigned int v26; // w1
  __int64 v28; // x9
  void *v29; // x0

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_fips_cb");
  if ( a2 )
  {
    v20 = osif_request_get(a1);
    if ( v20 )
    {
      v21 = v20;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: pdev_id %u, status %u, data_len %u",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_fips_cb",
        *a2,
        a2[1],
        a2[2]);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(51, 8, *((_QWORD *)a2 + 2), a2[2]);
      v22 = (_QWORD *)osif_request_priv(v21);
      v23 = v22;
      if ( a2[1] )
      {
        LODWORD(v24) = -110;
      }
      else
      {
        v24 = *((_QWORD *)a2 + 1);
        v28 = *((_QWORD *)a2 + 2);
        v22[6] = *(_QWORD *)a2;
        v22[7] = v24;
        v22[8] = v28;
        if ( (_DWORD)v24 )
        {
          v29 = (void *)_qdf_mem_malloc((unsigned int)v24, "hdd_fips_event_dup", 62);
          v23[8] = v29;
          if ( v29 )
          {
            qdf_mem_copy(v29, *((const void **)a2 + 2), a2[2]);
            LODWORD(v24) = 0;
          }
          else
          {
            LODWORD(v24) = -12;
          }
        }
        else
        {
          v22[8] = 0;
        }
      }
      *(_DWORD *)v23 = v24;
      osif_request_complete(v21);
      osif_request_put(v21);
      v25 = "%s: exit";
    }
    else
    {
      v25 = "%s: Obsolete request";
    }
    v26 = 8;
  }
  else
  {
    v25 = "%s: response is NULL";
    v26 = 2;
  }
  return qdf_trace_msg(0x33u, v26, v25, v12, v13, v14, v15, v16, v17, v18, v19, "hdd_fips_cb");
}
