__int64 __fastcall send_capacity_event(_QWORD *a1, unsigned int a2)
{
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+8h] [xbp-58h] BYREF
  char s[8]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v7; // [xsp+20h] [xbp-40h]
  __int64 v8; // [xsp+28h] [xbp-38h]
  __int64 v9; // [xsp+30h] [xbp-30h]
  __int64 v10; // [xsp+38h] [xbp-28h]
  __int64 v11; // [xsp+40h] [xbp-20h]
  __int64 v12; // [xsp+48h] [xbp-18h]
  __int64 v13; // [xsp+50h] [xbp-10h]
  __int64 v14; // [xsp+58h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  *(_QWORD *)s = 0;
  v7 = 0;
  v5[0] = s;
  v5[1] = 0;
  printk(&unk_10FD6, "send_capacity_event", a2);
  snprintf(s, 0x40u, "capacity=%d", a2);
  result = kobject_uevent_env(*a1, 2, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
