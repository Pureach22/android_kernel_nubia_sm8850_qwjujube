__int64 __fastcall sub_6A1A78(__int64 a1, __int64 a2, __int64 a3, unsigned __int16 a4)
{
  __int64 v4; // x26

  atomic_store(a4, (unsigned __int16 *)(v4 - 90));
  return hdd_adapter_link_switch_notification();
}
