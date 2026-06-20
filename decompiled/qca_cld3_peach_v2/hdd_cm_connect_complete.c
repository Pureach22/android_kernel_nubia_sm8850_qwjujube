__int64 __fastcall hdd_cm_connect_complete(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x19
  __int64 v6; // x20

  if ( !*(_DWORD *)(a2 + 52) )
  {
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        hdd_cm_connect_success_pre_user_update();
        return 0;
      }
      v5 = a1;
      v6 = a2;
      hdd_cm_connect_success_pre_user_update();
      a1 = v5;
      a2 = v6;
    }
    ((void (__fastcall *)(__int64, __int64))hdd_cm_connect_success_post_user_update)(a1, a2);
    return 0;
  }
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      hdd_cm_connect_failure_pre_user_update();
    }
    else
    {
      v3 = a1;
      v4 = a2;
      hdd_cm_connect_failure_pre_user_update();
      hdd_cm_connect_failure_post_user_update(v3, v4);
    }
  }
  else
  {
    ((void (*)(void))hdd_cm_connect_failure_post_user_update)();
  }
  return 0;
}
