__int64 __fastcall dp_tx_flow_control_deinit(__int64 result)
{
  _WORD *v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  v1 = (_WORD *)result;
  if ( *(_WORD *)(result + 2274) )
  {
    v2 = ((double (__fastcall *)(__int64, _QWORD, _QWORD))dp_tx_desc_pool_deinit)(result, 0, 0);
    result = dp_tx_desc_pool_free((__int64)v1, 0, v2, v3, v4, v5, v6, v7, v8, v9);
  }
  if ( v1[1285] )
  {
    v10 = ((double (__fastcall *)(_WORD *, __int64, _QWORD))dp_tx_desc_pool_deinit)(v1, 1, 0);
    result = dp_tx_desc_pool_free((__int64)v1, 1u, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  if ( v1[1433] )
  {
    v18 = ((double (__fastcall *)(_WORD *, __int64, _QWORD))dp_tx_desc_pool_deinit)(v1, 2, 0);
    result = dp_tx_desc_pool_free((__int64)v1, 2u, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  if ( v1[1581] )
  {
    v26 = ((double (__fastcall *)(_WORD *, __int64, _QWORD))dp_tx_desc_pool_deinit)(v1, 3, 0);
    result = dp_tx_desc_pool_free((__int64)v1, 3u, v26, v27, v28, v29, v30, v31, v32, v33);
  }
  if ( v1[1729] )
  {
    v34 = ((double (__fastcall *)(_WORD *, __int64, _QWORD))dp_tx_desc_pool_deinit)(v1, 4, 0);
    result = dp_tx_desc_pool_free((__int64)v1, 4u, v34, v35, v36, v37, v38, v39, v40, v41);
  }
  if ( v1[1877] )
  {
    v42 = ((double (__fastcall *)(_WORD *, __int64, _QWORD))dp_tx_desc_pool_deinit)(v1, 5, 0);
    return dp_tx_desc_pool_free((__int64)v1, 5u, v42, v43, v44, v45, v46, v47, v48, v49);
  }
  return result;
}
