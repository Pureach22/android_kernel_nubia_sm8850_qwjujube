__int64 __fastcall rmnet_fill_info(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  int v4; // w8
  __int64 v5; // x20
  __int64 result; // x0
  _DWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 2696);
  LOWORD(v7[0]) = *(unsigned __int8 *)(a2 + 2688);
  if ( !(unsigned int)nla_put(a1, 1, 2, v7) )
  {
    if ( *(__int64 (__fastcall **)())(v3 + 264) == rmnet_rx_handler )
    {
      v5 = *(_QWORD *)(v3 + 272);
      v4 = *(_DWORD *)(v5 + 8);
    }
    else
    {
      v4 = 0;
      v5 = 0;
    }
    v7[0] = v4;
    v7[1] = -1;
    if ( !(unsigned int)nla_put(a1, 2, 8, v7) )
    {
      if ( !v5 )
      {
        result = 0;
        goto LABEL_7;
      }
      result = nla_put(a1, 4, 8, v5 + 2072);
      if ( !(_DWORD)result )
        goto LABEL_7;
    }
  }
  result = 4294967206LL;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
