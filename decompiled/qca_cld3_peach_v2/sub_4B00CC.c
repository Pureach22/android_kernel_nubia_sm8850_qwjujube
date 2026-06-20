__int64 __usercall sub_4B00CC@<X0>(
        __int64 a1@<X8>,
        long double a2@<Q0>,
        long double a3@<Q1>,
        long double a4@<Q2>,
        long double a5@<Q3>,
        long double a6@<Q4>,
        long double a7@<Q5>,
        float a8@<S6>)
{
  LOWORD(a8) = *(_WORD *)(a1 + 7828);
  return csr_is11h_supported(a2, a3, a4, a5, a6, a7, a8);
}
