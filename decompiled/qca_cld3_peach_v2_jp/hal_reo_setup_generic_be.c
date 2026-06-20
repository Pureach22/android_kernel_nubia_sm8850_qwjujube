__int64 __fastcall hal_reo_setup_generic_be(__int64 a1, __int64 a2)
{
  __int64 v4; // x1
  void (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v4 = (unsigned int)hal_read32_mb(a1, 10715136);
  v5 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 74392) + 784LL);
  if ( *((_DWORD *)v5 - 1) != -708585980 )
    __break(0x8228u);
  v5(a1, v4, a2);
  hal_write32_mb(a1, 10717996, 100000);
  hal_write32_mb(a1, 10718000, 100000);
  hal_write32_mb(a1, 10718004, 100000);
  result = hal_write32_mb(a1, 10718008, 40000);
  if ( *(_BYTE *)a2 == 1 )
  {
    hal_write32_mb(a1, 10715148, *(unsigned int *)(a2 + 8));
    v7 = hal_read32_mb(a1, 10715148);
    qdf_trace_msg(
      0x46u,
      8u,
      "%s: HWIO_REO_R0_DESTINATION_RING_CTRL_IX_2_ADDR 0x%x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hal_reo_setup_generic_be",
      v7);
    hal_write32_mb(a1, 10715152, *(unsigned int *)(a2 + 12));
    v16 = hal_read32_mb(a1, 10715152);
    return qdf_trace_msg(
             0x46u,
             8u,
             "%s: HWIO_REO_R0_DESTINATION_RING_CTRL_IX_3_ADDR 0x%x",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "hal_reo_setup_generic_be",
             v16);
  }
  return result;
}
