__int64 __usercall sub_50AA88@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X8>)
{
  __int64 v6; // x30

  return dp_get_uplink_delay(a1, a2, a3, a4, a5, a6 - __ROR8__(v6, 14));
}
