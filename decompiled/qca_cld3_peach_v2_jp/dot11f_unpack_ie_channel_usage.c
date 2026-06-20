__int64 __fastcall dot11f_unpack_ie_channel_usage(__int64 a1, char *a2, char a3, _BYTE *a4)
{
  char v5; // t1

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( a3 )
  {
    v5 = *a2;
    a4[2] = a3 - 1;
    a4[1] = v5;
    qdf_mem_copy(a4 + 3, a2 + 1, (unsigned __int8)(a3 - 1));
    return 0;
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
