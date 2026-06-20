__int64 __usercall sub_B1B2C@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, __int64 a4@<X3>, int a5@<W8>)
{
  unsigned int v5; // w19

  return ieee80211_smps_is_restrictive(a1, a2, a3, a4, a5 + (v5 >> 20));
}
