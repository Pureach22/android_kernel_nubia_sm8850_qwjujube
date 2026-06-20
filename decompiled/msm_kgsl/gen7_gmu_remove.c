__int64 __fastcall gen7_gmu_remove(__int64 a1)
{
  unsigned __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 - 704);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    mbox_free_channel();
  v3 = *(_QWORD *)(a1 - 1768);
  *(_BYTE *)(a1 + 20433) = 0;
  if ( v3 )
    release_firmware(v3);
  gmu_core_free_globals(a1);
  result = vfree(*(_QWORD *)(a1 - 688));
  if ( (*(_BYTE *)(a1 - 596) & 1) != 0 )
    result = kobject_put(a1 - 656);
  if ( (*(_BYTE *)(a1 - 468) & 1) != 0 )
    return kobject_put(a1 - 528);
  return result;
}
