__int64 sub_6D748()
{
  __int64 v0; // x28

  if ( (v0 & 0x20000000000000LL) != 0 )
    JUMPOUT(0x741F8);
  return msm_vb2_queue_setup();
}
