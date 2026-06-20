__int64 __usercall sub_71EA0C@<X0>(__int16 a1@<W8>)
{
  if ( (a1 & 0x100) != 0 )
    JUMPOUT(0x71A2C4);
  return hdd_get_tsf_time();
}
