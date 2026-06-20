__int64 __usercall sub_1830F4@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, __int64 a4@<X3>, __int64 a5@<X8>)
{
  if ( !a5 )
    JUMPOUT(0x275050);
  return ipahal_init(a1, a2, a3, a4);
}
