__int64 __fastcall swrm_copy_port_config(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x8
  int v4; // w10
  __int64 v5; // x11
  int v6; // w13
  __int64 v7; // x11
  __int64 v8; // x12
  __int64 v9; // x19

  if ( a3 )
  {
    v3 = *(int *)(a2 + 4);
    v4 = 0;
    while ( 1 )
    {
      v5 = *(_QWORD *)(a2 + 8) + 12LL * v4;
      if ( !v5 )
        break;
      v6 = *(_DWORD *)(v5 + 8);
      v7 = *(_QWORD *)v5;
      v8 = *(_QWORD *)(*(_QWORD *)(result + 15840) + 8 * v3) + 12LL * v4++;
      *(_DWORD *)(v8 + 8) = v6;
      *(_QWORD *)v8 = v7;
      if ( a3 == v4 )
        return result;
    }
    v9 = result;
    result = __ratelimit(&swrm_copy_port_config__rs, "swrm_copy_port_config");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(v9 + 8512), "%s: Invalid params\n", "swrm_copy_port_config");
  }
  return result;
}
