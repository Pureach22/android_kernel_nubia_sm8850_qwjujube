unsigned __int64 __fastcall ll_lt_sap_flush_old_entries(unsigned __int64 result)
{
  unsigned __int64 v1; // x19
  char v2; // w8
  char v3; // w8
  char v4; // w8

  v1 = result;
  if ( *(_QWORD *)(result + 224) )
  {
    result = qdf_get_time_of_the_day_ms();
    if ( (__int64)(*(_QWORD *)(v1 + 224) - result + 300000) < 0 )
    {
      v2 = *(_BYTE *)(v1 + 264);
      *(_QWORD *)(v1 + 224) = 0;
      *(_DWORD *)(v1 + 216) = 0;
      *(_BYTE *)(v1 + 264) = v2 - 1;
    }
  }
  if ( *(_QWORD *)(v1 + 240) )
  {
    result = qdf_get_time_of_the_day_ms();
    if ( (__int64)(*(_QWORD *)(v1 + 240) - result + 300000) < 0 )
    {
      v3 = *(_BYTE *)(v1 + 264);
      *(_QWORD *)(v1 + 240) = 0;
      *(_DWORD *)(v1 + 232) = 0;
      *(_BYTE *)(v1 + 264) = v3 - 1;
    }
  }
  if ( *(_QWORD *)(v1 + 256) )
  {
    result = qdf_get_time_of_the_day_ms();
    if ( (__int64)(*(_QWORD *)(v1 + 256) - result + 300000) < 0 )
    {
      v4 = *(_BYTE *)(v1 + 264);
      *(_QWORD *)(v1 + 256) = 0;
      *(_DWORD *)(v1 + 248) = 0;
      *(_BYTE *)(v1 + 264) = v4 - 1;
    }
  }
  return result;
}
