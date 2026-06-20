__int64 __fastcall dp_rx_set_link_id_be(__int64 result)
{
  *(_DWORD *)(result + 48) &= 0xFFC3FFFF;
  return result;
}
