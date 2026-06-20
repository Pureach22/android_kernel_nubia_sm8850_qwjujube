__int64 __fastcall send_twt_vdev_config_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  unsigned int v9; // w0
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
  __int64 result; // x0
  unsigned int v27; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_twt_vdev_config_cmd_tlv", 0xD41u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 81657868;
  v7 = *a2;
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v8 - 1) != -2112860426 )
    __break(0x8228u);
  v9 = v8(a1, v7);
  v5[1] = v9;
  v5[2] = a2[1];
  v5[3] = a2[2];
  qdf_trace_msg(0x31u, 8u, "Set pdev %d vdev %d to %u", v10, v11, v12, v13, v14, v15, v16, v17, v9);
  qdf_mtrace(49, 100, 0x1F0Cu, v5[2], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x10u,
             0x3E00Cu,
             "send_twt_vdev_config_cmd_tlv",
             0xD54u,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25);
  if ( (_DWORD)result )
  {
    v27 = result;
    wmi_buf_free();
    return v27;
  }
  return result;
}
