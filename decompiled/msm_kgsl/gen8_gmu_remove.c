__int64 __fastcall gen8_gmu_remove(__int64 a1)
{
  unsigned __int64 v2; // x0
  __int64 v3; // x0

  v2 = *(_QWORD *)(a1 - 808);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    qmp_put();
  v3 = *(_QWORD *)(a1 - 1816);
  *(_BYTE *)(a1 + 20433) = 0;
  if ( v3 )
  {
    release_firmware(v3);
    kfree(*(_QWORD *)(a1 + 8240));
    kfree(*(_QWORD *)(a1 + 8256));
  }
  gmu_core_free_globals(a1);
  vfree(*(_QWORD *)(a1 - 792));
  kobject_put(a1 - 760);
  kobject_put(a1 - 640);
  kfree(*(_QWORD *)(a1 - 16));
  return kfree(*(_QWORD *)(a1 - 8));
}
