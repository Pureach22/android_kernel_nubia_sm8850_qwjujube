__int64 __fastcall drm_dsc_dp_rc_buffer_size(unsigned __int8 a1, unsigned __int8 a2)
{
  int v2; // w8
  __int64 result; // x0

  v2 = a1;
  result = (a2 << 10) + 1024;
  if ( v2 > 1 )
  {
    if ( v2 == 2 )
    {
      return (unsigned int)(16 * result);
    }
    else if ( v2 == 3 )
    {
      return (unsigned int)((_DWORD)result << 6);
    }
    else
    {
      return 0;
    }
  }
  else if ( v2 )
  {
    return (unsigned int)(4 * result);
  }
  return result;
}
