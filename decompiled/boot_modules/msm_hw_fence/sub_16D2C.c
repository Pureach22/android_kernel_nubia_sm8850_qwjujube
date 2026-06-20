__int64 __usercall sub_16D2C@<X0>(
        __int64 a1@<X8>,
        long double a2@<Q0>,
        long double a3@<Q1>,
        long double a4@<Q2>,
        long double a5@<Q3>)
{
  return hw_fence_utils_set_power_vote(a2, a3, a4, a5, *(long double *)(a1 - 912));
}
