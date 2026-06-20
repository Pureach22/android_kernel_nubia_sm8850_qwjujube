__int64 __fastcall codec_debug_address_write(__int64 a1, __int64 a2, size_t a3, __int64 a4)
{
  __int64 result; // x0
  _QWORD *v6; // x21
  int v7; // w19
  _QWORD v9[2]; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  result = -22;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a1 )
    {
      if ( a4 )
      {
        v6 = *(_QWORD **)(a1 + 32);
        if ( v6 )
        {
          v10 = 0;
          v9[0] = 0;
          v9[1] = 0;
          if ( a3 <= 0x13 )
          {
            if ( *v6 )
            {
              v7 = a2;
              _check_object_size(v9, a3, 0);
              if ( (unsigned int)inline_copy_from_user((int)v9, v7, a3) )
              {
                result = -14;
              }
              else
              {
                *((_BYTE *)v9 + a3) = 0;
                if ( (unsigned int)kstrtouint(v9, 0, v6 + 2) )
                  result = -22;
                else
                  result = a3;
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
