__int64 __fastcall timespec_sub(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return (a2 - a4 + 1000000000 * (a1 - a3)) / 1000000000;
}
