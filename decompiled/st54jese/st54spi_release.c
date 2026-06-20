__int64 __fastcall st54spi_release(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x0
  int v5; // w8
  __int64 v7; // x0

  mutex_lock(&device_list_lock);
  v3 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(a2 + 32) = 0;
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
    v4 = *(_QWORD *)(v3 + 16);
  dev_info(v4, "st54spi: release\n");
  v5 = *(_DWORD *)(v3 + 88) - 1;
  *(_DWORD *)(v3 + 88) = v5;
  if ( !v5 )
  {
    v7 = *(_QWORD *)(v3 + 8);
    if ( !v7 )
      v7 = *(_QWORD *)(v3 + 16);
    dev_info(v7, "st54spi: release - may allow power off\n");
    st54spi_power_off_for_comm(v3);
    if ( !*(_DWORD *)(v3 + 140) )
      st54spi_power_off(v3);
  }
  mutex_unlock(&device_list_lock);
  return 0;
}
