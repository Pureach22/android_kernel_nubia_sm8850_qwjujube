__int64 __fastcall cvp_create_pkt_cmd_session_cmd(_DWORD *a1, int a2, __int64 a3)
{
  if ( !a1 )
    return 4294967274LL;
  *a1 = 12;
  a1[1] = a2;
  a1[2] = HIDWORD(a3) ^ a3;
  return 0;
}
