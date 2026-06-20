__int64 sub_1002D0()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cam_req_mgr_is_shutdown();
}
