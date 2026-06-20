__int64 __fastcall dp_disable_rx_ol_for_low_tput(__int64 result, char a2)
{
  *(_DWORD *)(result + 1132) = a2 & 1;
  return result;
}
