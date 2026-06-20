__int64 __fastcall cnss_pci_suspend_late(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
  {
    if ( (cnss_is_device_powered_on(*(_QWORD *)(v1 + 8)) & 1) != 0 )
    {
      v2 = *(_QWORD *)(v1 + 8);
      if ( *(_BYTE *)(v2 + 7880) == 1 )
      {
        *(_BYTE *)(v1 + 48) = 0;
        cnss_power_off_device(v2);
      }
    }
  }
  return 0;
}
