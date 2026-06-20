__int64 __fastcall llcc_staling_conf_capacity(int a1)
{
  return regmap_update_bits_base(*(_QWORD *)(drv_data + 8), (a1 << 12) | 0x10u, 4097, 0, 0, 0, 0);
}
