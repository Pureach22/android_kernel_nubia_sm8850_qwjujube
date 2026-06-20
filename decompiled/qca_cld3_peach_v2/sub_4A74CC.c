__int64 sub_4A74CC()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x4AC05C);
  return cm_csr_disconnect_done_ind();
}
