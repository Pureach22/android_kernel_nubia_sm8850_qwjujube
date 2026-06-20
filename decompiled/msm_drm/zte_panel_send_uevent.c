__int64 __fastcall zte_panel_send_uevent(int a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  char *v6; // x8
  char *v7; // [xsp+0h] [xbp-20h] BYREF
  __int64 v8; // [xsp+8h] [xbp-18h]
  __int64 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v9 = 0;
  v7 = nullptr;
  result = get_disp_dev();
  if ( result )
  {
    if ( a1 )
    {
      v9 = 0;
      result = kobject_uevent_env(result, 2, &v7);
      goto LABEL_4;
    }
    if ( a2 > 143 )
    {
      if ( a2 == 144 )
      {
        v5 = 3;
        goto LABEL_15;
      }
      if ( a2 == 165 )
      {
        v5 = 4;
        goto LABEL_15;
      }
    }
    else
    {
      if ( a2 == 90 )
      {
        v5 = 1;
        goto LABEL_15;
      }
      if ( a2 == 120 )
      {
        v5 = 2;
LABEL_15:
        v6 = msg[v5];
        v9 = 0;
        v7 = v6;
        v8 = 0;
        kobject_uevent_env(result, 2, &v7);
        result = printk(&unk_27202D, v7);
        goto LABEL_4;
      }
    }
    v5 = 0;
    goto LABEL_15;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
