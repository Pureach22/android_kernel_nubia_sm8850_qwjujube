__int64 __usercall sub_3BA238@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X5>,
        __int64 a7@<X8>)
{
  if ( a7 )
    JUMPOUT(0x3BF0C0);
  return lim_send_sme_addts_rsp(a1, a2, a3, a4, a5, a6);
}
