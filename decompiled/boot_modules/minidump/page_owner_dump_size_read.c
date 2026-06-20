__int64 __fastcall page_owner_dump_size_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  size_t v7; // x0
  __int64 result; // x0
  _QWORD v9[12]; // [xsp+0h] [xbp-70h] BYREF
  int v10; // [xsp+60h] [xbp-10h]
  __int64 v11; // [xsp+68h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  memset(v9, 0, sizeof(v9));
  snprintf((char *)v9, 0x64u, "%zu MB\n", (unsigned __int64)md_pageowner_dump_size >> 20);
  v7 = strnlen((const char *)v9, 0x64u);
  if ( v7 >= 0x65 )
  {
    _fortify_panic(2, 100, v7 + 1);
LABEL_5:
    _fortify_panic(4, 100, 101);
  }
  if ( v7 == 100 )
    goto LABEL_5;
  result = simple_read_from_buffer(a2, a3, a4, v9, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
