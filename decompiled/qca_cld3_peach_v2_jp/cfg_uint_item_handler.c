__int64 __fastcall cfg_uint_item_handler(__int64 a1, const char **a2, const char *a3)
{
  __int64 v4; // x24
  unsigned int v6; // w20
  unsigned int v7; // w21
  __int64 v8; // x23
  __int64 result; // x0
  int v10; // w5
  int v11; // w8
  unsigned int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v4 = a1 + 28;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((_DWORD *)a2 + 6);
  v7 = *((_DWORD *)a2 + 7);
  v8 = *((unsigned int *)a2 + 2);
  v12 = 0;
  result = qdf_uint32_parse(a3, &v12);
  if ( (_DWORD)result )
  {
    result = qdf_trace_msg(
               80,
               2,
               "%s: %s=%s - Invalid format (status %d); Using default %u",
               "cfg_uint_item_handler",
               *a2,
               a3,
               result,
               *(_DWORD *)(v4 + v8));
  }
  else if ( v6 <= v7 )
  {
    v10 = v12;
    if ( v12 < v6 || v12 > v7 )
    {
      if ( *((_DWORD *)a2 + 8) )
      {
        v11 = *(_DWORD *)(v4 + v8);
      }
      else
      {
        if ( v12 >= v7 )
          v11 = v7;
        else
          v11 = v12;
        if ( v12 < v6 )
          v11 = v6;
        *(_DWORD *)(v4 + v8) = v11;
      }
      result = qdf_trace_msg(
                 80,
                 2,
                 "%s: %s=%u - Out of range [%d, %d]; Using %u",
                 "cfg_uint_item_handler",
                 *a2,
                 v10,
                 v6,
                 v7,
                 v11);
    }
    else
    {
      *(_DWORD *)(v4 + v8) = v12;
    }
  }
  else
  {
    result = qdf_trace_msg(80, 2, "%s: Invalid config item meta for %s", "cfg_uint_item_handler", *a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
