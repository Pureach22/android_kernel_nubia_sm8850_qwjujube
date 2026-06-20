__int64 __fastcall wlan_serialization_create_lock(__int64 a1)
{
  *(_DWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  return 0;
}
