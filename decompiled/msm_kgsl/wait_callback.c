__int64 __fastcall wait_callback(__int64 a1, __int64 a2, __int64 a3)
{
  return _wake_up(a3 + 1464, 3, 0, 0);
}
