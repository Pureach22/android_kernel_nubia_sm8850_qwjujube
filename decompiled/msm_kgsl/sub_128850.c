__int64 __fastcall sub_128850(__int64 a1, __int64 a2)
{
  __int64 v2; // x14
  __int64 v3; // x26

  return bind_fence_get_timeline_name(a1, a2, v2 & ~__ROR8__(v3, 8));
}
