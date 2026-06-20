__int64 __fastcall rmnet_get_rmnet_dev(__int64 result, unsigned __int8 a2)
{
  unsigned __int8 *v2; // x9
  __int64 v3; // x9

  if ( result )
  {
    v2 = (unsigned __int8 *)(result + 8LL * a2);
    while ( 1 )
    {
      v3 = *((_QWORD *)v2 + 2);
      result = 0;
      if ( !v3 )
        break;
      v2 = (unsigned __int8 *)(v3 - 16);
      if ( !v2 )
        break;
      if ( *v2 == a2 )
        return *((_QWORD *)v2 + 1);
    }
  }
  return result;
}
