bool __fastcall wlan_serialization_is_cmd_present_in_given_queue(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return wlan_serialization_find_cmd(
           a1,
           3,
           (_DWORD *)a2,
           0,
           0,
           *(_QWORD *)(a2 + 32),
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11) != nullptr;
}
