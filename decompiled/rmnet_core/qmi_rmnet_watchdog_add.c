__int64 __fastcall qmi_rmnet_watchdog_add(__int64 result)
{
  char v1; // w8

  v1 = *(_BYTE *)(result + 120);
  *(_BYTE *)(result + 121) = 0;
  if ( (v1 & 1) == 0 )
  {
    *(_BYTE *)(result + 120) = 1;
    return mod_timer(result + 80, jiffies + 13LL);
  }
  return result;
}
