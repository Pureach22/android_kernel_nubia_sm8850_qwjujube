__int64 __fastcall dp_sim_debug_write_hpd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  _DWORD *v8; // x8
  __int64 v9; // x0
  _BOOL8 v10; // x1
  int v11; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v11 = 0;
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
      v12[0] = 0;
      _check_object_size(v12, v6, 0);
      if ( !inline_copy_from_user_0((__int64)v12, a2, v6) )
      {
        *((_BYTE *)v12 + v6) = 0;
        if ( !(unsigned int)kstrtoint(v12, 10, &v11) )
        {
          mutex_lock(v4 + 88);
          v8 = *(_DWORD **)(v4 + 80);
          if ( v8 )
          {
            v9 = *(_QWORD *)(v4 + 72);
            v10 = v11 != 0;
            if ( *(v8 - 1) != -121262737 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _BOOL8, _QWORD))v8)(v9, v10, 0);
          }
          mutex_unlock(v4 + 88);
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
