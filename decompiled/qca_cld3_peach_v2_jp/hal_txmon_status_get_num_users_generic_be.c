__int64 __fastcall hal_txmon_status_get_num_users_generic_be(__int64 a1, char *a2)
{
  int v2; // w8
  __int64 result; // x0
  __int64 v5; // x9
  char v6; // w8
  char v7; // w8
  int v8; // w8

  v2 = (*(_DWORD *)a1 >> 1) & 0x1FF;
  if ( v2 == 204 )
  {
    v7 = *(_DWORD *)(a1 + 24);
    result = 2;
    v8 = v7 & 0x7F;
    if ( !v8 )
      LOBYTE(v8) = 1;
    *a2 = v8;
  }
  else if ( v2 == 157 )
  {
    result = 0;
    v5 = *(_QWORD *)(a1 + 4) >> 55;
    v6 = v5 & 0x3F;
    if ( (v5 & 0x3E) == 0 )
      v6 = 1;
    *a2 = v6;
  }
  else
  {
    return 36;
  }
  return result;
}
