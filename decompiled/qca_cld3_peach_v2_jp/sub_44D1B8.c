__int64 sub_44D1B8()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x451D48);
  return cm_csr_disconnect_done_ind();
}
