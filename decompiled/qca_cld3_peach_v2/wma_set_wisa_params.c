__int64 __fastcall wma_set_wisa_params(__int64 *a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x8
  int v14; // w9
  __int64 result; // x0
  unsigned int v16; // w20

  v4 = wmi_buf_alloc_fl(*a1, 0xCu, "wma_set_wisa_params", 0x24Cu);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v13[2] = *a2;
  v14 = a2[1];
  *v13 = 34930696;
  v13[1] = v14;
  result = wmi_unified_cmd_send_fl(
             *a1,
             v4,
             0xCu,
             0x1D013u,
             "wma_set_wisa_params",
             0x25Au,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12);
  if ( (_DWORD)result )
  {
    v16 = result;
    wmi_buf_free();
    return v16;
  }
  return result;
}
