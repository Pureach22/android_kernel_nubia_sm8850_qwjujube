__int64 __usercall sub_1B6018@<X0>(int a1@<W0>, int a2@<W1>, int a3@<W2>, __int64 a4@<X8>)
{
  if ( (a4 & 0x8000000000LL) == 0 )
    JUMPOUT(0x1B7FA8);
  return sde_cesta_sw_client_update(a1, a2, a3);
}
