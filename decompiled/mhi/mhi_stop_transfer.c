__int64 __fastcall mhi_stop_transfer(__int64 a1)
{
  return mhi_update_transfer_state(a1, 1);
}
