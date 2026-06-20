__int64 sub_1D56D0()
{
  __int64 v0; // x19

  if ( (v0 & 0x40000000000LL) != 0 )
    JUMPOUT(0x1D1B00);
  return tgt_vdev_mgr_set_param_send();
}
