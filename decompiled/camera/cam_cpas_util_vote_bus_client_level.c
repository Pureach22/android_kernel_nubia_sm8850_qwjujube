__int64 __fastcall cam_cpas_util_vote_bus_client_level(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w20
  const char *v5; // x6
  unsigned int v6; // w19

  if ( (*(_BYTE *)a1 & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_vote_bus_client_level",
      223,
      "bus client not valid");
    return 4294967274LL;
  }
  if ( (unsigned int)a2 >= 0xA )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_vote_bus_client_level",
      232,
      "Invalid votelevel=%d,usecases=%d,Bus client=[%s]",
      a2,
      *(_DWORD *)(a1 + 84),
      *(const char **)(a1 + 64));
    return 4294967274LL;
  }
  if ( *(_DWORD *)(a1 + 56) == (_DWORD)a2 )
    return 0;
  v4 = a2;
  result = cam_soc_bus_client_update_request(*(_QWORD *)(a1 + 232), a2);
  if ( (_DWORD)result )
  {
    v5 = *(const char **)(a1 + 64);
    v6 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_vote_bus_client_level",
      243,
      "Client: %s update request failed rc: %d",
      v5,
      result);
    return v6;
  }
  else
  {
    *(_DWORD *)(a1 + 56) = v4;
  }
  return result;
}
