__int64 __fastcall dsi_display_get_default_lms(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x21
  unsigned int v5; // w8
  __int64 v6; // x10
  __int64 v7; // x11
  unsigned int v8; // w11
  __int64 result; // x0
  __int64 v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a2 = 0;
  mutex_lock(a1 + 72);
  v4 = *(unsigned int *)(*(_QWORD *)(a1 + 264) + 1436LL);
  mutex_unlock(a1 + 72);
  if ( *(_QWORD *)(a1 + 824) || (result = dsi_display_get_modes(a1, v10), !(_DWORD)result) )
  {
    mutex_lock(a1 + 72);
    if ( (_DWORD)v4 )
    {
      v5 = *a2;
      v6 = 0;
      do
      {
        v7 = *(_QWORD *)(a1 + 824) + v6;
        v6 += 192;
        v8 = *(_DWORD *)(*(_QWORD *)(v7 + 184) + 2480LL);
        if ( v8 > v5 )
          v5 = v8;
        *a2 = v5;
      }
      while ( 192 * v4 != v6 );
    }
    mutex_unlock(a1 + 72);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
