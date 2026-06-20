__int64 __fastcall a6xx_gmu_remove(__int64 a1)
{
  unsigned __int64 v2; // x0
  __int64 v3; // x0

  v2 = *(_QWORD *)(a1 - 384);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    mbox_free_channel();
  v3 = *(_QWORD *)(a1 - 1640);
  *(_BYTE *)(a1 + 20433) = 0;
  if ( v3 )
    release_firmware(v3);
  gmu_core_free_globals(a1);
  vfree(*(_QWORD *)(a1 - 360));
  kobject_put(a1 - 328);
  return kobject_put(a1 - 192);
}
