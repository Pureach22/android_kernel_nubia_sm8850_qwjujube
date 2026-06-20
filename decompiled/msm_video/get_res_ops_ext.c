void *__fastcall get_res_ops_ext(__int64 a1)
{
  __int64 (__fastcall **resources_ops)(); // x0
  __int64 v3; // x8
  int v4; // w20
  __int64 v5; // x21

  resources_ops = get_resources_ops();
  v3 = *(_QWORD *)(a1 + 3912);
  v4 = *(_DWORD *)(v3 + 24);
  v5 = *(_QWORD *)(v3 + 16);
  memcpy(&get_res_ops_ext_res_ops_ext, resources_ops, 0xA0u);
  if ( v5 && v4 )
  {
    qword_9EAA8 = (__int64)_init_regulators;
    qword_9EAB0 = (__int64)_enable_regulator;
    qword_9EAB8 = (__int64)_disable_regulator;
    qword_9EAC0 = (__int64)_hand_off_regulators;
    qword_9EAC8 = (__int64)_acquire_regulators;
  }
  qword_9EAE0 = (__int64)_set_clocks_ext;
  qword_9EAF8 = (__int64)_clock_set_flag_ext;
  return &get_res_ops_ext_res_ops_ext;
}
