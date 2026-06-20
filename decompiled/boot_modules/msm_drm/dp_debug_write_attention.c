__int64 __fastcall dp_debug_write_attention(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  void (*v8)(void); // x8
  int v9; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      if ( a3 >= 7 )
        v6 = 7;
      else
        v6 = a3;
      v10[0] = 0;
      v9 = 0;
      _check_object_size(v10, v6, 0);
      if ( !inline_copy_from_user((__int64)v10, a2, v6) )
      {
        *((_BYTE *)v10 + v6) = 0;
        if ( !(unsigned int)kstrtoint(v10, 10, &v9) )
        {
          v8 = *(void (**)(void))(*(_QWORD *)(v4 + 104) + 56LL);
          if ( *((_DWORD *)v8 - 1) != -143022559 )
            __break(0x8228u);
          v8();
        }
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
