__int64 __fastcall sub_30C118(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, _DWORD *a6)
{
  int v6; // s23
  int v7; // s29

  *a6 = v7;
  a6[1] = v6;
  return hdd_conn_remove_connect_info(a1, a2, a3, a4, a5, a6 - 42);
}
