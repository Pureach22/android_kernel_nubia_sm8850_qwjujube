__int64 __fastcall qcom_glink_ssr_callback(__int64 a1, _DWORD *a2, unsigned int a3)
{
  _QWORD *v3; // x8

  v3 = *(_QWORD **)(a1 + 152);
  if ( a3 <= 0xB )
  {
    dev_err(*v3, "message too short\n");
    return 4294967274LL;
  }
  if ( *a2 )
    return 4294967274LL;
  if ( a2[1] != 1 )
    return 0;
  if ( a2[2] != *((_DWORD *)v3 + 10) )
  {
    dev_err(*v3, "invalid sequence number of response\n");
    return 4294967274LL;
  }
  complete(v3 + 6);
  return 0;
}
