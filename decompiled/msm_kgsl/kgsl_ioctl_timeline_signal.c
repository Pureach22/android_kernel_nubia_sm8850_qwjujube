__int64 __fastcall kgsl_ioctl_timeline_signal(__int64 *a1, __int64 a2, __int64 *a3)
{
  unsigned __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x21
  unsigned int v7; // w23
  size_t v8; // x22
  __int64 v9; // x9
  _QWORD *v10; // x0
  unsigned __int64 v11; // x22
  int v18; // w8
  __int64 result; // x0
  unsigned __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  __int64 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((unsigned int *)a3 + 3);
  if ( (_DWORD)v4 )
  {
    if ( *((_DWORD *)a3 + 2) )
    {
      v5 = *a1;
      v6 = *a3;
      v7 = 0;
      do
      {
        v20 = 0;
        v21 = 0;
        if ( v4 >= 0x10 )
          v8 = 16;
        else
          v8 = v4;
        if ( v4 <= 0x10 )
          v9 = 16;
        else
          v9 = v4;
        if ( v4 > 0xF )
        {
          if ( v4 != 16 && (int)check_zeroed_user(v6 + v8, v9 - v8) < 1 )
          {
LABEL_27:
            result = -14;
            goto LABEL_30;
          }
        }
        else
        {
          memset((char *)&v20 + v8, 0, v9 - v8);
        }
        _check_object_size(&v20, v8, 0);
        if ( inline_copy_from_user_2((int)&v20, v6, v8) )
          goto LABEL_27;
        if ( HIDWORD(v21) )
          goto LABEL_26;
        v10 = (_QWORD *)kgsl_timeline_by_id(v5, v21);
        if ( !v10 )
        {
          result = -19;
          goto LABEL_30;
        }
        v11 = (unsigned __int64)v10;
        kgsl_timeline_signal(v10, v20);
        if ( v11 <= 0xFFFFFFFFFFFFF000LL )
        {
          _X0 = (unsigned int *)(v11 + 32);
          __asm { PRFM            #0x11, [X0] }
          do
            v18 = __ldxr(_X0);
          while ( __stlxr(v18 - 1, _X0) );
          if ( v18 == 1 )
          {
            __dmb(9u);
            kgsl_timeline_destroy((__int64)_X0);
          }
          else if ( v18 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
        }
        v4 = *((unsigned int *)a3 + 3);
        ++v7;
        v6 += v4;
      }
      while ( v7 < *((_DWORD *)a3 + 2) );
      result = 0;
    }
    else
    {
LABEL_26:
      result = -22;
    }
  }
  else
  {
    result = -11;
    *((_DWORD *)a3 + 3) = 16;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
