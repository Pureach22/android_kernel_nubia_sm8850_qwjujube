__int64 __fastcall dp_debug_write_sim(__int64 a1, unsigned __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  int v8; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      v9[0] = 0;
      v8 = 0;
      mutex_lock(v4 + 376);
      if ( a3 >= 7 )
        a3 = 7;
      _check_object_size(v9, a3, 0);
      if ( !inline_copy_from_user((__int64)v9, a2, a3) )
      {
        *((_BYTE *)v9 + a3) = 0;
        if ( !(unsigned int)kstrtoint(v9, 10, &v8) )
          dp_debug_set_sim_mode(v4, v8 != 0);
      }
      mutex_unlock(v4 + 376);
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
