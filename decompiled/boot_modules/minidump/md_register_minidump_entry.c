__int64 __fastcall md_register_minidump_entry(const char *a1, __int64 a2, __int64 a3, __int64 a4)
{
  size_t v8; // x0
  unsigned __int64 v9; // x2
  __int64 result; // x0
  unsigned int v11; // w20
  _QWORD v12[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v13 = 0;
  memset(v12, 0, sizeof(v12));
  v8 = strnlen(a1, 0xDu);
  if ( v8 == -1 )
  {
    _fortify_panic(2, -1, 0);
    goto LABEL_10;
  }
  if ( v8 == 13 )
    v9 = 13;
  else
    v9 = v8 + 1;
  if ( v9 >= 0xE )
LABEL_10:
    _fortify_panic(7, 13, v9);
  sized_strscpy(v12, a1);
  v13 = a2;
  v14 = a3;
  v15 = a4;
  result = msm_minidump_add_region(v12);
  if ( (result & 0x80000000) != 0 )
  {
    v11 = result;
    printk(&unk_11285F, a1);
    result = v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
