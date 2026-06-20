__int64 __fastcall msm_common_get_backend_name(const char *a1, __int64 *a2)
{
  __int64 result; // x0
  __int64 v4; // x20
  size_t v5; // x0
  unsigned __int64 v6; // x2
  unsigned __int64 StatusReg; // x21
  __int64 v8; // x22
  __int64 (__fastcall *v9)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v10; // [xsp+0h] [xbp-60h] BYREF
  __int64 v11; // [xsp+8h] [xbp-58h]
  __int64 v12; // [xsp+10h] [xbp-50h]
  __int64 v13; // [xsp+18h] [xbp-48h]
  __int64 v14; // [xsp+20h] [xbp-40h]
  __int64 v15; // [xsp+28h] [xbp-38h]
  char v16[13]; // [xsp+30h] [xbp-30h] BYREF
  char string[8]; // [xsp+40h] [xbp-20h] BYREF
  _BYTE v18[13]; // [xsp+48h] [xbp-18h] BYREF
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)string = 0;
  memset(v18, 0, sizeof(v18));
  v15 = 0;
  memset(v16, 0, sizeof(v16));
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 0;
  sscanf(a1, "%20[^-]-%60s", string, &v10);
  result = _kmalloc_cache_noprof(printk, 3520, 21);
  v4 = result;
  for ( *a2 = result; result; *a2 = result )
  {
    v5 = strnlen(string, 0x15u);
    if ( v5 >= 0x16 )
    {
      _fortify_panic(2, 21, v5 + 1);
    }
    else
    {
      if ( v5 == 21 )
        v6 = 21;
      else
        v6 = v5 + 1;
      if ( v6 < 0x16 )
      {
        result = sized_strscpy(v4, string);
        break;
      }
    }
    _fortify_panic(7, 21, v6);
    StatusReg = _ReadStatusReg(SP_EL0);
    v8 = *(_QWORD *)(StatusReg + 80);
    v9 = printk;
    *(_QWORD *)(StatusReg + 80) = &msm_common_get_backend_name__alloc_tag;
    result = _kmalloc_cache_noprof(v9, 3520, 21);
    v4 = result;
    *(_QWORD *)(StatusReg + 80) = v8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
