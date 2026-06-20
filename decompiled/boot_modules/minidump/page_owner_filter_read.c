__int64 __fastcall page_owner_filter_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  size_t v7; // x0
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v10; // [xsp+10h] [xbp-40h]
  __int64 v11; // [xsp+18h] [xbp-38h]
  __int64 v12; // [xsp+20h] [xbp-30h]
  __int64 v13; // [xsp+28h] [xbp-28h]
  __int64 v14; // [xsp+30h] [xbp-20h]
  __int64 v15; // [xsp+38h] [xbp-18h]
  __int64 v16; // [xsp+40h] [xbp-10h]
  __int64 v17; // [xsp+48h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  *(_QWORD *)s = 0;
  v10 = 0;
  snprintf(s, 0x40u, "0x%lx\n", page_owner_filter);
  v7 = strnlen(s, 0x40u);
  if ( v7 >= 0x41 )
  {
    _fortify_panic(2, 64, v7 + 1);
LABEL_5:
    _fortify_panic(4, 64, 65);
  }
  if ( v7 == 64 )
    goto LABEL_5;
  result = simple_read_from_buffer(a2, a3, a4, s, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
