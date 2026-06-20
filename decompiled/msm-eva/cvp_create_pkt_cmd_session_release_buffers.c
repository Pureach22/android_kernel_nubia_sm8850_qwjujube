__int64 __fastcall cvp_create_pkt_cmd_session_release_buffers(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      *(_QWORD *)(a1 + 56) = 0x100000000LL;
      *(_DWORD *)(a1 + 8) = HIDWORD(a2) ^ a2;
      *(_QWORD *)a1 = 0x120100400000044LL;
      return 0;
    }
  }
  return result;
}
