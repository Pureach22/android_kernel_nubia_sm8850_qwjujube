__int64 __usercall sub_151B80@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X5>,
        int a7@<W7>,
        __int64 a8@<X8>)
{
  *(_DWORD *)(a8 + 4612) = a7;
  return hif_map_service_to_pipe(a1, a2, a3, a4, a5, a6);
}
