__int64 __fastcall tmc_usb_disable(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(a1 + 8) == 1 )
    usb_bypass_stop(*(_QWORD *)(v1 + 304));
  if ( *(_QWORD *)a1 )
    return usb_qdss_close();
  else
    return dev_err(*(_QWORD *)(v1 + 16) + 56LL, "usb channel is null.\n");
}
