__int64 __fastcall cam_icp_validate_secure_port_config(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x7
  int v5; // w8
  int v6; // w11

  v2 = 0;
  while ( 1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + v2);
    if ( v3 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(v3 + 80) + 16LL) == 1 )
        break;
    }
    v2 += 8;
    if ( v2 == 432 )
      return 0;
  }
  v4 = 0;
  while ( 1 )
  {
    v5 = *(unsigned __int8 *)(v3 + 30108 + v4);
    v6 = *(unsigned __int8 *)(a2 + 30108 + v4);
    if ( v5 != v6 )
      break;
    if ( ++v4 == 65 )
      return 0;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_validate_secure_port_config",
    8731,
    "%s: port security map mismatch %d prev: 0x%x, curr: 0x%x",
    (const char *)(a2 + 29824),
    v4,
    v5,
    v6);
  return 4294967274LL;
}
