__int64 __fastcall hdd_init_scan_reject_params(__int64 result)
{
  if ( result )
  {
    *(_QWORD *)(result + 1808) = 0;
    *(_BYTE *)(result + 1803) = -1;
    *(_DWORD *)(result + 1804) = 0;
    *(_BYTE *)(result + 1816) = 0;
  }
  return result;
}
