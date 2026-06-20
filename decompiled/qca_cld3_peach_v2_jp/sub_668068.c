__int64 __usercall sub_668068@<X0>(__int16 a1@<W8>)
{
  if ( (a1 & 0x100) != 0 )
    JUMPOUT(0x663920);
  return hdd_get_tsf_time();
}
