__int64 __fastcall ot_show(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x0
  __int64 i; // x20
  const char *v11; // x5
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _rcu_read_lock(a1, a2, a3, a4, a5, a6, a7, a8);
  v13[0] = 2147483649LL;
  v9 = xa_find(&xa_si_objects, v13, -1, 8);
  for ( i = 0; v9; v9 = xa_find_after(&xa_si_objects, v13, -1, 8) )
  {
    if ( v9 == 1 )
    {
      v11 = "root";
    }
    else if ( *(_QWORD *)v9 )
    {
      v11 = *(const char **)v9;
    }
    else
    {
      v11 = "noname";
    }
    i += (int)scnprintf(a3 + i, 4096 - i, "%lx %4d %s\n", v13[0], *(_DWORD *)(v9 + 8), v11);
  }
  _rcu_read_unlock(v9);
  _ReadStatusReg(SP_EL0);
  return i;
}
