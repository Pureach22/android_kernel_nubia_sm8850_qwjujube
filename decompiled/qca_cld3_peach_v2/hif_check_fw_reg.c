__int64 __fastcall hif_check_fw_reg(_QWORD *a1)
{
  __int64 v1; // x20
  unsigned int v3; // w20
  unsigned int v4; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v1 = a1[3840];
  if ( (hif_target_sleep_state_adjust((__int64)a1) & 0x80000000) != 0 )
  {
    return 0;
  }
  else
  {
    v3 = hif_read32_mb_reg_window((__int64)a1, v1 + *(unsigned int *)(a1[77] + 260LL));
    v4 = 1;
    if ( (hif_target_sleep_state_adjust((__int64)a1) & 0x80000000) == 0 )
    {
      qdf_trace_msg(
        0x3Du,
        8u,
        "%s: FW_INDICATOR register is 0x%x",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hif_check_fw_reg",
        v3);
      return (*(_DWORD *)(a1[79] + 192LL) & v3) == 0;
    }
  }
  return v4;
}
