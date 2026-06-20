__int64 __fastcall sub_1CFEE4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { SYSL            X2, #1, c7, c1, #2 }
  return wlan_ser_remove_non_scan_cmd(a1, a2, a3, a4);
}
