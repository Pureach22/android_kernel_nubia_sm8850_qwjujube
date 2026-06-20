__int64 __fastcall mhi_intvec_handler(__int64 a1, __int64 a2)
{
  _wake_up(a2 + 456, 3, 0, 0);
  return 2;
}
