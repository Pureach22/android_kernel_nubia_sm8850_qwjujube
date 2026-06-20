__int64 __fastcall init_si_object_user(
        unsigned __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int64 v11; // x0
  __int64 result; // x0
  _QWORD v13[4]; // [xsp+28h] [xbp-48h] BYREF
  char *v14; // [xsp+48h] [xbp-28h]
  _QWORD *v15; // [xsp+50h] [xbp-20h]
  __int64 v16; // [xsp+58h] [xbp-18h]
  __int64 v17; // [xsp+60h] [xbp-10h]
  __int64 v18; // [xsp+68h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 8) = 1;
  *(_DWORD *)(a1 + 12) = 16;
  v14 = &a9;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  v15 = v13;
  v16 = 0;
  v17 = 4294967264LL;
  if ( a2 == 2 )
  {
LABEL_4:
    *(_QWORD *)(a1 + 24) = a3;
    if ( *(_QWORD *)(a3 + 16) )
    {
      v13[0] = v14;
      v13[1] = v15;
      v13[2] = v16;
      v13[3] = v17;
      v11 = kvasprintf_const(3264, a4, v13);
      *(_QWORD *)a1 = v11;
      if ( !v11 )
      {
        result = 4294967284LL;
        goto LABEL_12;
      }
      *(_QWORD *)(a1 + 16) = 0;
      *(_DWORD *)(a1 + 12) = 2;
      *(_QWORD *)(a1 + 80) = 0;
      if ( a2 == 8 )
      {
        *(_QWORD *)(a1 + 80) = primordial_object_release;
        if ( a1 >= 2 )
        {
          mutex_lock(&primordial_object_lock);
          atomic_store(a1, (unsigned __int64 *)&primordial_object);
          mutex_unlock(&primordial_object_lock);
        }
      }
      goto LABEL_9;
    }
LABEL_10:
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( a2 != 16 )
  {
    if ( a2 != 8 )
      goto LABEL_10;
    goto LABEL_4;
  }
LABEL_9:
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
