// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_40B880@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        const char *a3@<X2>,
        int a4@<W8>,
        double a5@<D0>,
        double a6@<D1>,
        double a7@<D2>,
        double a8@<D3>,
        double a9@<D4>,
        double a10@<D5>,
        double a11@<D6>,
        double a12@<D7>)
{
  __int64 v12; // x21
  __int64 result; // x0

  if ( !v12 )
    return populate_dot11f_sr_info(a1, a2, a3);
  result = qdf_trace_msg(a1, 8u, a3, a5, a6, a7, a8, a9, a10, a11, a12, a4);
  _ReadStatusReg(SP_EL0);
  return result;
}
