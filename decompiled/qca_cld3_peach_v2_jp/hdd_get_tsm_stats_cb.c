__int64 __fastcall hdd_get_tsm_stats_cb(__int64 *a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  _QWORD *v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  const char *v16; // x2
  unsigned int v17; // w1

  v3 = osif_request_get(a2);
  if ( v3 )
  {
    v12 = v3;
    v13 = (_QWORD *)osif_request_priv(v3);
    v14 = *a1;
    v15 = a1[1];
    v13[2] = a1[2];
    *v13 = v14;
    v13[1] = v15;
    osif_request_complete(v12);
    osif_request_put(v12);
    v16 = "%s: exit";
    v17 = 8;
  }
  else
  {
    v16 = "%s: Obsolete request";
    v17 = 2;
  }
  return qdf_trace_msg(0x33u, v17, v16, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_get_tsm_stats_cb");
}
