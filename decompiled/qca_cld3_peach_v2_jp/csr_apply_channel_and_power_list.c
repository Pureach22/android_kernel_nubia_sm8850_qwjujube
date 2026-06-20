__int64 __fastcall csr_apply_channel_and_power_list(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  csr_prune_channel_list_for_mode(a1, a1 + 16532);
  csr_save_channel_power_for_band(a1, 0);
  csr_save_channel_power_for_band(a1, 1);
  v2 = csr_apply_channel_power_info_to_fw(a1, a1 + 16532);
  csr_init_operating_classes(a1, v2, v3, v4, v5, v6, v7, v8, v9);
  return 0;
}
