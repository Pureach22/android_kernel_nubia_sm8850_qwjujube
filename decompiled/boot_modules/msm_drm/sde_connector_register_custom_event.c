__int64 __fastcall sde_connector_register_custom_event(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 result; // x0
  char v5; // w9
  __int64 v6; // x10
  __int64 v7; // x0
  char v8; // w19
  unsigned int v9; // w19
  char v10; // w19

  result = 4294967274LL;
  if ( a3 > -2147483642 )
  {
    if ( a3 == -2147483641 )
    {
      if ( a2 )
      {
        v7 = *(_QWORD *)(a2 + 2744);
        if ( v7 )
        {
          v8 = a4;
          sde_encoder_enable_recovery_event(v7);
          a4 = v8;
        }
        v9 = 0;
      }
      else
      {
        v10 = a4;
        printk(&unk_242658, "_sde_conn_enable_hw_recovery");
        a4 = v10;
        v9 = -22;
      }
      sde_dbg_update_dump_mode(a4 & 1);
      return v9;
    }
    v5 = a4 & 1;
    if ( a3 == -2147483635 )
    {
      if ( a2 )
      {
        result = 0;
        *(_BYTE *)(a2 + 4541) = v5;
        return result;
      }
    }
    else
    {
      if ( a3 != -2147483632 )
        return result;
      if ( a2 )
      {
        v6 = *(_QWORD *)(a2 + 2744);
        *(_BYTE *)(a2 + 5016) = v5;
        if ( v6 )
        {
          *(_DWORD *)(v6 + 800) = a4 & 1;
          if ( *(_DWORD *)(v6 + 800) )
          {
            *(_BYTE *)(v6 + 808) = 1;
            *(_DWORD *)(v6 + 812) = 1;
            return 0;
          }
          return 0;
        }
        return result;
      }
    }
    printk(&unk_242658, "sde_connector_register_custom_event");
    return 4294967274LL;
  }
  if ( a3 == -2147483645 || a3 == -2147483642 )
    return 0;
  return result;
}
