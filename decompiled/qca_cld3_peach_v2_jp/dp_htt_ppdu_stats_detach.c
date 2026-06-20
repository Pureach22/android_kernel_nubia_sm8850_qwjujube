__int64 __fastcall dp_htt_ppdu_stats_detach(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x24
  _QWORD *v3; // x19
  _QWORD *v4; // x8
  _QWORD *v5; // x26
  _QWORD *v6; // x9
  __int64 v7; // x0
  __int64 v8; // x0
  _QWORD *v9; // x19
  _QWORD *v10; // x8
  _QWORD *v11; // x26
  _QWORD *v12; // x9
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 95560);
  v2 = v1 + 36864;
  v3 = *(_QWORD **)(v1 + 39176);
  if ( v3 )
  {
    do
    {
      v5 = (_QWORD *)v3[5];
      v4 = (_QWORD *)v3[6];
      v6 = v5 + 6;
      if ( !v5 )
        v6 = (_QWORD *)(v2 + 2320);
      *v6 = v4;
      *v4 = v3[5];
      v3[5] = 0;
      v3[6] = 0;
      --*(_DWORD *)(v2 + 2356);
      v7 = v3[3];
      if ( v7
        || (v8 = printk(
                   &unk_9BB309,
                   "ppdu_info->nbuf",
                   "dp_htt_ppdu_stats_detach",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c"),
            dump_stack(v8),
            (v7 = v3[3]) != 0) )
      {
        _qdf_nbuf_free(v7);
      }
      _qdf_mem_free((__int64)v3);
      v3 = v5;
    }
    while ( v5 );
  }
  v9 = *(_QWORD **)(v2 + 2328);
  if ( v9 )
  {
    do
    {
      v11 = (_QWORD *)v9[5];
      v10 = (_QWORD *)v9[6];
      v12 = v11 + 6;
      if ( !v11 )
        v12 = (_QWORD *)(v2 + 2336);
      *v12 = v10;
      *v10 = v9[5];
      v9[5] = 0;
      v9[6] = 0;
      --*(_DWORD *)(v2 + 2344);
      v13 = v9[3];
      if ( v13
        || (v14 = printk(
                    &unk_9BB309,
                    "ppdu_info->nbuf",
                    "dp_htt_ppdu_stats_detach",
                    "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c"),
            dump_stack(v14),
            (v13 = v9[3]) != 0) )
      {
        _qdf_nbuf_free(v13);
      }
      _qdf_mem_free((__int64)v9);
      v9 = v11;
    }
    while ( v11 );
  }
  result = *(_QWORD *)(v2 + 2392);
  if ( result )
    return _qdf_mem_free(result);
  return result;
}
