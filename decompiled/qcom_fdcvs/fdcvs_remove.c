__int64 __fastcall fdcvs_remove(__int64 a1)
{
  __int64 v2; // x20

  v2 = *(_QWORD *)(a1 + 168);
  device_remove_file(a1 + 16, &dev_attr_profile_index);
  device_remove_file(a1 + 16, &dev_attr_profile_interval);
  return qmp_put(*(_QWORD *)(v2 + 48));
}
