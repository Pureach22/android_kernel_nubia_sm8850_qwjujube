__int64 __fastcall debug_wmi_enable_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x21
  unsigned int v8; // [xsp+Ch] [xbp-44h] BYREF
  char s[8]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v10; // [xsp+18h] [xbp-38h]
  __int64 v11; // [xsp+20h] [xbp-30h]
  __int64 v12; // [xsp+28h] [xbp-28h]
  __int64 v13; // [xsp+30h] [xbp-20h]
  __int64 v14; // [xsp+38h] [xbp-18h]
  __int16 v15; // [xsp+40h] [xbp-10h]
  __int64 v16; // [xsp+48h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  result = -14;
  v15 = 0;
  v13 = 0;
  v14 = 0;
  v5 = *(_QWORD *)(v3 + 128);
  v11 = 0;
  v12 = 0;
  *(_QWORD *)s = 0;
  v10 = 0;
  if ( a2 && a3 <= 0x32 )
  {
    v8 = 0;
    _check_object_size(s, a3, 0);
    if ( inline_copy_from_user_0((__int64)s, a2, a3) )
    {
      result = -14;
    }
    else if ( sscanf(s, "%d", &v8) == 1 && v8 <= 1 )
    {
      result = a3;
      *(_BYTE *)(v5 + 680) = v8;
    }
    else
    {
      result = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
