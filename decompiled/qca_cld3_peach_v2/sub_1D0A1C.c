__int64 __fastcall sub_1D0A1C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x18

  if ( v6 )
    JUMPOUT(0x1985BC);
  return wlan_ser_cancel_scan_cmd(a1, a2, a3, a4, a5, a6);
}
