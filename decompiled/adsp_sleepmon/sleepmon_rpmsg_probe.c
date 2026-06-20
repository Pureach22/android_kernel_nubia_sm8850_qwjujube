__int64 __fastcall sleepmon_rpmsg_probe(__int64 a1)
{
  of_platform_populate(*(_QWORD *)(a1 + 744), 0, 0, a1);
  qword_A680 = a1;
  if ( !qword_B138 && dword_B130 )
    qword_B138 = rproc_get_by_phandle();
  return adspsleepmon_smem_init();
}
