__int64 __fastcall dp_sim_debug_write_skip_dpcd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 result; // x0
  size_t v6; // x19
  int v8; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v8 = 0;
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
      v9[0] = 0;
      _check_object_size(v9, v6, 0);
      if ( !inline_copy_from_user_0((__int64)v9, a2, v6) )
      {
        *((_BYTE *)v9 + v6) = 0;
        if ( !(unsigned int)kstrtoint(v9, 10, &v8) )
        {
          mutex_lock(v4 + 88);
          *(_BYTE *)(v4 + 2281) = v8 != 0;
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
