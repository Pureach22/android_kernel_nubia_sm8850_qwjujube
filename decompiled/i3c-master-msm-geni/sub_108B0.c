__int64 sub_108B0()
{
  __int64 v0; // x22

  if ( (v0 & 0x10000000000000LL) != 0 )
    JUMPOUT(0xD834);
  return geni_i3c_master_recycle_ibi_slot();
}
