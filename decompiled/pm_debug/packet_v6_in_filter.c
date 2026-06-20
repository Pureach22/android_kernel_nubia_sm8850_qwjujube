__int64 __fastcall packet_v6_in_filter(__int64 a1, __int64 a2, __int64 a3)
{
  ((void (__fastcall *)(__int64, __int64, __int64))packet_v6_filter)(a2, a3, 1);
  return 1;
}
