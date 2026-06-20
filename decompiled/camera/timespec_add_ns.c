__int64 __fastcall timespec_add_ns(__int64 a1, __int64 a2, __int64 a3)
{
  return (a2 + a3) / 1000000000 + a1;
}
