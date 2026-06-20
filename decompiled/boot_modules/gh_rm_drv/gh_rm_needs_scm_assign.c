__int64 __fastcall gh_rm_needs_scm_assign(_QWORD *a1, _DWORD *a2, int a3)
{
  __int64 result; // x0
  __int64 v7; // x11
  int v8; // w11
  int v9; // w13
  bool v10; // cc
  __int64 v11; // x13
  __int16 v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (gh_feature_use_scm_assign & 1) == 0 )
  {
    v13 = 0;
    if ( !(unsigned int)gh_rm_get_this_vmid(&v13) )
    {
      if ( v13 != 3 )
      {
LABEL_26:
        result = 0;
        goto LABEL_4;
      }
      v7 = 0;
      while ( ((*a1 >> v7) & 1) == 0 || (unsigned int)v7 <= 0x3C && ((1LL << v7) & 0x1002200000000008LL) != 0 )
      {
        if ( ++v7 == 64 )
        {
          if ( a3 )
          {
            v8 = 0;
            do
            {
              v9 = a2[2 * v8];
              if ( v9 <= 63 )
              {
                v10 = (unsigned int)v9 > 0x3C;
                v11 = (1LL << v9) & 0x1002200000000008LL;
                if ( v10 || v11 == 0 )
                  goto LABEL_3;
              }
            }
            while ( a3 != ++v8 );
          }
          if ( _sw_hweight64() == 1 && a3 == 1 && (*a1 & 8) != 0 && *a2 == 3 )
            break;
          goto LABEL_26;
        }
      }
    }
  }
LABEL_3:
  result = 1;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
