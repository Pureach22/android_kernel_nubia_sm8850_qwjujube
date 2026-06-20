__int64 __fastcall send_obss_spatial_reuse_set_def_thresh_cmd_tlv(__int64 a1, _DWORD *a2)
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
  __int64 result; // x0
  unsigned int v15; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_obss_spatial_reuse_set_def_thresh_cmd_tlv", 0x32E8u);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  *v13 = 49676300;
  v13[1] = *a2;
  v13[2] = a2[1];
  v13[3] = a2[2];
  result = wmi_unified_cmd_send_fl(
             a1,
             v4,
             0x10u,
             0x40002u,
             "send_obss_spatial_reuse_set_def_thresh_cmd_tlv",
             0x32FAu,
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
    v15 = result;
    wmi_buf_free();
    return v15;
  }
  return result;
}
