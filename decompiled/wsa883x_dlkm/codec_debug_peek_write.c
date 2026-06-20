__int64 __fastcall codec_debug_peek_write(__int64 a1, __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v6; // x19
  int v7; // w20
  char *stringp; // [xsp+8h] [xbp-48h] BYREF
  __int64 v10; // [xsp+10h] [xbp-40h]
  __int64 v11; // [xsp+18h] [xbp-38h]
  int v12; // [xsp+20h] [xbp-30h]
  _QWORD v13[5]; // [xsp+28h] [xbp-28h] BYREF

  result = -22;
  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
            if ( *(_QWORD *)(v6 + 224) && a3 <= 0x1F && (*a4 & 0x8000000000000000LL) == 0 )
            {
              v7 = a2;
              memset(v13, 0, 32);
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
                stringp = (char *)v13;
                if ( !strsep(&stringp, " ")
                  || (unsigned int)kstrtouint()
                  || (strsep(&stringp, " "), (unsigned int)v10 >= 0x200A) )
                {
                  result = -22;
                }
                else
                {
                  swr_read(v6, *(unsigned __int8 *)(v6 + 64));
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
