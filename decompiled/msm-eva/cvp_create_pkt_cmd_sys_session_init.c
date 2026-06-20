__int64 __fastcall cvp_create_pkt_cmd_sys_session_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _DWORD *v4; // x9

  result = 4294967274LL;
  if ( a1 )
  {
    v4 = *(_DWORD **)(a2 + 16);
    if ( v4 )
    {
      *(_QWORD *)a1 = 0x110100800000020LL;
      *(_DWORD *)(a1 + 8) = HIDWORD(a2) ^ a2;
      *(_DWORD *)(a1 + 12) = v4[3707];
      *(_DWORD *)(a1 + 16) = v4[3708];
      *(_DWORD *)(a1 + 20) = v4[3709];
      *(_DWORD *)(a1 + 24) = v4[3710];
      *(_DWORD *)(a1 + 28) = v4[3711];
      return 0;
    }
  }
  return result;
}
