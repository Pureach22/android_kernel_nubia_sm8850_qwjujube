__int64 __fastcall hdd_config_udp_qos_upgrade_threshold(__int64 a1)
{
  *(_DWORD *)(*(_QWORD *)a1 + 42084LL) = 2;
  return hdd_set_udp_qos_upgrade_config();
}
