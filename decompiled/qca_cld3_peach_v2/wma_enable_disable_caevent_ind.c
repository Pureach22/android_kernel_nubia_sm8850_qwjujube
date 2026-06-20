__int64 __fastcall wma_enable_disable_caevent_ind(__int64 *a1, unsigned __int8 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 result; // x0
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8

  if ( (unsigned int)_wma_validate_handle(a1, "wma_enable_disable_caevent_ind") )
    return 4;
  v12 = *a1;
  if ( (unsigned int)_wmi_validate_handle(
                       v12,
                       (__int64)"wma_enable_disable_caevent_ind",
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11) )
    return 4;
  v14 = wmi_buf_alloc_fl(v12, 8u, "wma_enable_disable_caevent_ind", 0x15D3u);
  if ( !v14 )
    return 2;
  v23 = *(_DWORD **)(v14 + 224);
  *v23 = 34340868;
  v23[1] = a2;
  result = wmi_unified_cmd_send_fl(
             v12,
             v14,
             8u,
             0x29004u,
             "wma_enable_disable_caevent_ind",
             0x15DFu,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    return 16;
  }
  return result;
}
