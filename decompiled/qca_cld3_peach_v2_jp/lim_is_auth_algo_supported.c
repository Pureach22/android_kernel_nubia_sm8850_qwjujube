__int64 __fastcall lim_is_auth_algo_supported(__int64 a1, int a2, __int64 a3)
{
  int v3; // w9
  unsigned int v4; // w8
  bool v5; // cf
  unsigned int v6; // w8
  int v7; // w9
  int v8; // w8
  int v10; // w9
  int v11; // w8

  v3 = *(_DWORD *)(a3 + 88);
  if ( a2 )
  {
    if ( v3 == 1 )
    {
      v4 = *(_DWORD *)(a3 + 1624);
      v5 = v4 >= 0xA;
      v6 = 0x212u >> v4;
      v7 = !v5;
      v10 = v7 & v6;
      v11 = *(unsigned __int8 *)(a3 + 1620) != 0;
    }
    else
    {
      v10 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5437LL);
      v11 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5436LL);
    }
    return v10 & v11 & 1;
  }
  else if ( v3 == 1 )
  {
    v8 = *(_DWORD *)(a3 + 1624);
    return !v8 || v8 == 9;
  }
  else
  {
    return *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5438LL);
  }
}
