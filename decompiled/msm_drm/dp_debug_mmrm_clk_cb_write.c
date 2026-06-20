__int64 __fastcall dp_debug_mmrm_clk_cb_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x21
  size_t v7; // x19
  size_t v9; // x8
  int v10; // w8
  int v11; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD v12[4]; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v13[2]; // [xsp+30h] [xbp-20h] BYREF
  _QWORD v14[2]; // [xsp+40h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      v6 = *(_QWORD *)(v4 + 368);
      if ( a3 >= 7 )
        v7 = 7;
      else
        v7 = a3;
      v13[1] = 0;
      v14[0] = 0;
      memset(v12, 0, 24);
      v11 = 0;
      _check_object_size(v14, v7, 0);
      v9 = inline_copy_from_user((__int64)v14, a2, v7);
      result = 0;
      if ( !v9 )
      {
        *((_BYTE *)v14 + v7) = 0;
        v10 = kstrtoint(v14, 10, &v11);
        result = 0;
        if ( !v10 && v11 == 1 )
        {
          v13[0] = v6;
          LODWORD(v12[0]) = 1;
          v12[3] = v13;
          dp_display_mmrm_callback(v12);
          result = v7;
        }
      }
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
