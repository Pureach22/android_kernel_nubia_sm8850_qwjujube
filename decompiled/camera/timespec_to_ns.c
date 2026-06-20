__int64 __fastcall timespec_to_ns(__int64 a1, __int64 a2)
{
  return a2 + 1000000000 * a1;
}
