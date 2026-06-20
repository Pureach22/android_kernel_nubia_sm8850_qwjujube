__int64 __fastcall qdf_idr_alloc(__int64 a1, __int64 a2, int *a3)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x4
  __int64 v9; // x1
  int v10; // w20

  result = 4;
  if ( a1 && a2 )
  {
    qdf_spinlock_acquire(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    {
      v8 = 2080;
      v9 = a2;
    }
    else
    {
      v8 = 2080;
      v9 = a2;
      if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      {
        if ( *(_DWORD *)(StatusReg + 16) )
          v8 = 2080;
        else
          v8 = 3264;
      }
    }
    v10 = idr_alloc(a1 + 16, v9, 256, 0, v8);
    qdf_spinlock_release(a1);
    if ( v10 >= 256 )
    {
      *a3 = v10;
      return 0;
    }
    else
    {
      return 16;
    }
  }
  return result;
}
