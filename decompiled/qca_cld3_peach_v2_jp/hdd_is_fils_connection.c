__int64 __fastcall hdd_is_fils_connection(__int64 *a1, __int64 a2)
{
  char *fils_connection_info; // x0
  char v3; // w8

  fils_connection_info = (char *)wlan_cm_get_fils_connection_info(
                                   *a1,
                                   *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL));
  if ( fils_connection_info )
    v3 = *fils_connection_info;
  else
    v3 = 0;
  return v3 & 1;
}
