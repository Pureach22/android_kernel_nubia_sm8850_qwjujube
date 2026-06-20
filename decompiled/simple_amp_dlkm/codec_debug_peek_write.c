__int64 __fastcall codec_debug_peek_write(__int64 a1, __int64 a2, size_t a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v7; // x22
  int v8; // w20
  char *v10; // x0
  __int64 v11; // x1
  char *stringp; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-40h] BYREF
  int v14; // [xsp+20h] [xbp-30h]
  _QWORD v15[5]; // [xsp+28h] [xbp-28h] BYREF

  result = -22;
  v15[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
            v7 = *(_QWORD *)(v6 + 224);
            if ( v7 )
            {
              if ( a3 <= 0x1F && (*a4 & 0x8000000000000000LL) == 0 )
              {
                v8 = a2;
                memset(v15, 0, 32);
                v13[0] = 0;
                v13[1] = 0;
                v14 = 0;
                _check_object_size(v15, a3, 0);
                if ( (unsigned int)inline_copy_from_user((int)v15, v8, a3) )
                {
                  result = -14;
                }
                else
                {
                  *((_BYTE *)v15 + a3) = 0;
                  stringp = (char *)v15;
                  v10 = strsep(&stringp, " ");
                  if ( !v10
                    || (((v10[1] - 88) & 0xDF) != 0 ? (v11 = 10) : (v11 = 16),
                        (unsigned int)kstrtouint(v10, v11, v13) || (strsep(&stringp, " "), LODWORD(v13[0]) >= 0x200A)) )
                  {
                    result = -22;
                  }
                  else
                  {
                    swr_read(v6, *(unsigned __int8 *)(v6 + 64), LODWORD(v13[0]), v7 + 528, 1);
                    result = a3;
                  }
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
