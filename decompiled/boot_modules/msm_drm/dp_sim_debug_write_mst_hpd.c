__int64 __fastcall dp_sim_debug_write_mst_hpd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 *v4; // x22
  __int64 v5; // x21
  __int64 result; // x0
  size_t v7; // x19
  int v9; // w2
  int v10; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(a1 + 32);
  v10 = 0;
  if ( v4 )
  {
    v11[0] = 0;
    v5 = *v4;
    if ( *v4 && *((_DWORD *)v4 + 2) < *(_DWORD *)(v5 + 2256) )
    {
      if ( *a4 )
      {
        result = 0;
      }
      else
      {
        if ( a3 >= 7 )
          v7 = 7;
        else
          v7 = a3;
        _check_object_size(v11, v7, 0);
        if ( !inline_copy_from_user_0((__int64)v11, a2, v7) )
        {
          *((_BYTE *)v11 + v7) = 0;
          if ( !(unsigned int)kstrtoint(v11, 10, &v10) )
          {
            mutex_lock(v5 + 88);
            if ( v10 )
              v9 = 1;
            else
              v9 = 2;
            dp_sim_update_port_status(v5 + 8, *((_DWORD *)v4 + 2), v9);
            mutex_unlock(v5 + 88);
          }
        }
        result = v7;
      }
    }
    else
    {
      result = -22;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
