__int64 __fastcall pmic_glink_write(_QWORD *a1, unsigned int *a2, unsigned int a3)
{
  unsigned int v6; // w22
  __int64 result; // x0
  int v8; // w8
  __int64 v9; // x2

  if ( !a1 || !*a1 || !a1[1] )
    return 4294967277LL;
  down_read(*a1 + 112LL);
  if ( *(_QWORD *)*a1 && *(_DWORD *)(*a1 + 288LL) )
  {
    mutex_lock(a1 + 3);
    v6 = rpmsg_send(*(_QWORD *)(*(_QWORD *)*a1 + 968LL), a2, a3);
    mutex_unlock(a1 + 3);
    up_read(*a1 + 112LL);
    result = v6;
    if ( (v6 & 0x80000000) != 0 )
    {
      printk(&unk_7655, "pmic_glink_write", a3);
      result = v6;
      if ( *(_BYTE *)(*a1 + 305LL) == 1 )
      {
        __break(0x800u);
        goto LABEL_18;
      }
    }
    else if ( !v6 )
    {
      if ( *(_BYTE *)(*a1 + 304LL) != 1 )
        return 0;
      v8 = *(_DWORD *)(*a1 + 300LL);
      v9 = *a2;
      if ( v8 != (_DWORD)v9 )
      {
        if ( v8 == 0xFFFF )
          printk(&unk_792B, "pmic_glink_write", v9);
        return 0;
      }
LABEL_18:
      printk(&unk_7A38, "pmic_glink_write", a3);
      return 0;
    }
  }
  else
  {
    printk(&unk_7815, "pmic_glink_write", a1[1]);
    up_read(*a1 + 112LL);
    return 4294967189LL;
  }
  return result;
}
