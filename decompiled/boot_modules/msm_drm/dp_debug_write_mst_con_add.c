__int64 __fastcall dp_debug_write_mst_con_add(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  __int64 v8; // x0
  void (*v9)(void); // x8
  _QWORD v10[5]; // [xsp+8h] [xbp-28h] BYREF

  v10[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      if ( a3 >= 0x1F )
        v6 = 31;
      else
        v6 = a3;
      memset(v10, 0, 32);
      _check_object_size(v10, v6, 0);
      if ( !inline_copy_from_user((__int64)v10, a2, v6) )
      {
        v8 = *(_QWORD *)(v4 + 104);
        *(_BYTE *)(v4 + 302) = 1;
        v9 = *(void (**)(void))(v8 + 56);
        if ( *((_DWORD *)v9 - 1) != -143022559 )
          __break(0x8228u);
        v9();
      }
      result = v6;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
