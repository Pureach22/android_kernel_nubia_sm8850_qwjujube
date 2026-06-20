__int64 __fastcall sde_sync_get_name_prefix(__int64 result)
{
  __int64 (*v1)(void); // x8
  unsigned __int8 *v2; // x8
  unsigned int v3; // w9
  unsigned int v4; // w8

  if ( result )
  {
    v1 = *(__int64 (**)(void))(*(_QWORD *)(result + 8) + 8LL);
    if ( *((_DWORD *)v1 - 1) != -352706110 )
      __break(0x8228u);
    result = v1();
    if ( result )
    {
      v2 = (unsigned __int8 *)result;
      result = *(unsigned __int8 *)result;
      if ( (_DWORD)result )
      {
        if ( v2[1] )
        {
          v3 = v2[2];
          result = (unsigned int)v2[1] | ((_DWORD)result << 8);
          if ( v2[2] )
          {
            v4 = v2[3];
            result = v3 | ((_DWORD)result << 8);
            if ( v4 )
              return v4 | ((_DWORD)result << 8);
          }
        }
      }
    }
  }
  return result;
}
