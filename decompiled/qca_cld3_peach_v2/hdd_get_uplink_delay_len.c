__int64 __fastcall hdd_get_uplink_delay_len(__int64 a1)
{
  return 8 * (unsigned int)(*(_DWORD *)(a1 + 40) == 0);
}
