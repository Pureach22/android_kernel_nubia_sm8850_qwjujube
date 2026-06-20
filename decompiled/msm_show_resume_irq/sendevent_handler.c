__int64 __fastcall sendevent_handler(__int64 a1)
{
  __int64 v1; // x19
  const char *v2; // x20
  int v3; // w5
  unsigned int v4; // w21
  __int64 result; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-80h] BYREF
  char s[8]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v8; // [xsp+18h] [xbp-68h]
  __int64 v9; // [xsp+20h] [xbp-60h]
  __int64 v10; // [xsp+28h] [xbp-58h]
  __int64 v11; // [xsp+30h] [xbp-50h]
  __int64 v12; // [xsp+38h] [xbp-48h]
  __int64 v13; // [xsp+40h] [xbp-40h]
  __int64 v14; // [xsp+48h] [xbp-38h]
  __int64 v15; // [xsp+50h] [xbp-30h]
  __int64 v16; // [xsp+58h] [xbp-28h]
  __int64 v17; // [xsp+60h] [xbp-20h]
  __int64 v18; // [xsp+68h] [xbp-18h]
  int v19; // [xsp+70h] [xbp-10h]
  __int64 v20; // [xsp+78h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1 - 16;
  v2 = *(const char **)(a1 - 16);
  v19 = 0;
  v4 = *(_DWORD *)(a1 - 8);
  v3 = *(_DWORD *)(a1 - 4);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  *(_QWORD *)s = 0;
  v8 = 0;
  v6[0] = s;
  v6[1] = 0;
  if ( v3 )
    snprintf(s, 0x64u, "%sUID=%u:%u", v2, v4, v3);
  else
    snprintf(s, 0x64u, "%sUID=%u", v2, v4);
  kobject_uevent_env(dev, 2, v6);
  kfree(v1);
  result = printk(&unk_7170, v4, v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
