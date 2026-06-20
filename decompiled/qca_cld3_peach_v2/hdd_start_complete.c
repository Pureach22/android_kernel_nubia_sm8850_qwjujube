__int64 __fastcall hdd_start_complete(int a1, __int64 a2)
{
  wlan_start_ret_val = a1;
  return complete_all(&wlan_start_comp, a2);
}
