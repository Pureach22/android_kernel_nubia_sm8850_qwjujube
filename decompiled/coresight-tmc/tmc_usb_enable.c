__int64 __fastcall tmc_usb_enable(__int64 a1)
{
  __int64 v1; // x19
  unsigned __int64 v3; // x0

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(a1 + 8) == 1 )
  {
    v3 = usb_qdss_open("qdss_sw", v1, usb_notifier);
    *(_QWORD *)a1 = v3;
  }
  else
  {
    v3 = *(_QWORD *)a1;
  }
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
    return 0;
  dev_err(*(_QWORD *)(v1 + 16) + 56LL, "usb_qdss_open failed for qdss.\n");
  return 4294967277LL;
}
