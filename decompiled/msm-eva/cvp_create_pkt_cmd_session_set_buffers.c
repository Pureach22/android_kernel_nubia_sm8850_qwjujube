__int64 __fastcall cvp_create_pkt_cmd_session_set_buffers(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a1 + 52) = a3;
      *(_DWORD *)(a1 + 56) = a4;
      *(_QWORD *)a1 = 0x120100100000060LL;
      *(_DWORD *)(a1 + 8) = HIDWORD(a2) ^ a2;
      return 0;
    }
  }
  return result;
}
