__int64 sub_567454()
{
  unsigned __int64 v0; // x23

  _WriteStatusReg(ARM64_SYSREG(3, 0, 4, 10, 6), v0);
  return dp_peer_get_tx_capture_stats();
}
