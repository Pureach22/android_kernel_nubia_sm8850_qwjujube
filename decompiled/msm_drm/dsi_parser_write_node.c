__int64 __fastcall dsi_parser_write_node(__int64 a1, unsigned __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  const char *v8; // x0
  int v9; // w0
  __int64 v10; // x19
  __int64 v11; // x0
  _BYTE s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v13; // [xsp+208h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      memset(s, 0, sizeof(s));
      if ( a3 >= 0x1FF )
        a3 = 511;
      _check_object_size(s, a3, 0);
      if ( !inline_copy_from_user_9((__int64)s, a2, a3) )
      {
        s[a3] = 0;
        strreplace(s, 10, 32);
        v8 = (const char *)strim(s);
        v9 = strcmp(v8, "head_node");
        v10 = *(_QWORD *)(v4 + 8);
        if ( v9 )
        {
          v11 = strim(s);
          v10 = ((__int64 (__fastcall *)(__int64, __int64))dsi_parser_get_node_by_name)(v10, v11);
        }
        *(_QWORD *)(v4 + 16) = v10;
      }
      result = a3;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
