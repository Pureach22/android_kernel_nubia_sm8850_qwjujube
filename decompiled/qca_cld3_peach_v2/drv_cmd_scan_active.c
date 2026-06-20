__int64 __fastcall drv_cmd_scan_active(__int64 a1, __int64 a2)
{
  *(_DWORD *)(a2 + 856) = 1;
  return 0;
}
