__int64 __fastcall marshal_in_req_cleanup(__int64 result, int a2)
{
  __int64 v3; // x20
  int i; // w21
  __int64 v5; // x8
  unsigned __int64 v6; // x0

  v3 = result;
  for ( i = 0; ; ++i )
  {
    v5 = v3 + 24LL * i;
    if ( *(_DWORD *)v5 != 3 )
      break;
    v6 = *(_QWORD *)(v5 + 8);
    if ( v6 >= 2 )
    {
      if ( *(_DWORD *)(v6 + 12) == 2 && *(__int64 (__fastcall ***)())(v6 + 24) == &cbo_sio_ops )
      {
        *(_DWORD *)(v6 + 88) = a2;
      }
      else if ( *(_DWORD *)(v6 + 12) == 1 )
      {
        *(_QWORD *)(v5 + 8) = 0;
      }
    }
    result = put_si_object();
LABEL_4:
    ;
  }
  if ( *(_DWORD *)v5 )
    goto LABEL_4;
  return result;
}
