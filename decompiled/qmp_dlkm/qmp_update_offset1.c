__int64 __fastcall qmp_update_offset1(__int64 result, unsigned __int8 a2, unsigned __int8 a3)
{
  _DWORD *v3; // x9
  int v4; // w10
  __int64 v5; // x2
  __int64 v6; // x0

  if ( a2 <= 1u )
  {
    v3 = (_DWORD *)(result + 8LL * a2);
    v4 = a3;
    v5 = result + 128;
    v6 = *(_QWORD *)(result + 16);
    v3[15] = v4;
    v3[19] = v4;
    v3[23] = v4;
    v3[27] = v4;
    return swr_init_port_params(v6, 2, v5);
  }
  return result;
}
