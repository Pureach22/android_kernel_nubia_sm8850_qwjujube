__int64 __fastcall dp_rx_skip_fisa(__int64 result, int a2)
{
  *(_DWORD *)(result + 1500) = a2 == 0;
  return result;
}
