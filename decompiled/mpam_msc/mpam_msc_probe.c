__int64 __fastcall mpam_msc_probe(__int64 a1)
{
  if ( (of_platform_populate(*(_QWORD *)(a1 + 760), 0, 0, a1 + 16) & 0x80000000) != 0 )
    dev_err(a1 + 16, "Mpam driver probe failed.!\n");
  return 0;
}
