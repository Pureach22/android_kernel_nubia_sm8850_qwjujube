__int64 __fastcall swrm_debug_peek_write(__int64 a1, __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v6; // x19
  int v7; // w20
  char *v9; // [xsp+0h] [xbp-30h] BYREF
  __int64 v10; // [xsp+8h] [xbp-28h]
  __int64 v11; // [xsp+10h] [xbp-20h]
  int v12; // [xsp+18h] [xbp-18h]
  _QWORD v13[2]; // [xsp+20h] [xbp-10h] BYREF

  result = -22;
  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 )
    {
      if ( a3 )
      {
        if ( a4 )
        {
          v6 = *(_QWORD *)(a1 + 32);
          if ( v6 )
          {
            if ( a3 <= 7 && (*a4 & 0x8000000000000000LL) == 0 )
            {
              v7 = a2;
              v13[0] = 0;
              v10 = 0;
              v11 = 0;
              v12 = 0;
              _check_object_size(v13, a3, 0);
              if ( (unsigned int)inline_copy_from_user((int)v13, v7, a3) )
              {
                result = -14;
              }
              else
              {
                *((_BYTE *)v13 + a3) = 0;
                v9 = (char *)v13;
                if ( !strsep(&v9, " ")
                  || (unsigned int)kstrtouint()
                  || (strsep(&v9, " "), (unsigned int)v10 > 0x60A8)
                  || (v10 & 3) != 0 )
                {
                  if ( (unsigned int)__ratelimit(&swrm_debug_peek_write__rs, "swrm_debug_peek_write") )
                    dev_err(*(_QWORD *)(v6 + 8512), "%s: rc = %d\n", "swrm_debug_peek_write", -22);
                  result = -22;
                }
                else
                {
                  *(_DWORD *)(v6 + 20872) = swr_master_read(v6, v10);
                  result = a3;
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
