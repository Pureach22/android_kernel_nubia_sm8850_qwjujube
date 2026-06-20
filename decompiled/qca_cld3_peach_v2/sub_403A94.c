__int64 __usercall sub_403A94@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X5>,
        int a7@<W8>)
{
  int v7; // w15
  __int64 v8; // x27

  *(_DWORD *)(v8 + 204) = v7;
  *(_DWORD *)(v8 + 208) = a7;
  return lim_send_sme_join_reassoc_rsp(a1, a2, a3, a4, a5, a6);
}
