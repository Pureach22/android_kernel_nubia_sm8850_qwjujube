__int64 __fastcall dsi_panel_dim_handle(__int64 result, __int64 a2, char a3, char a4)
{
  char v4; // w21
  __int64 v5; // x19
  __int64 v6; // x22
  __int64 v7; // x3

  if ( result )
  {
    v4 = a2 & 1;
    if ( dsi_panel_dim_handle_last_en != (a2 & 1) )
    {
      if ( (a2 & 1) != 0 )
      {
        if ( (unsigned int)(*(_DWORD *)(result + 2220) - 1) < 2 )
          return result;
        if ( *(_DWORD *)(*(_QWORD *)(result + 2312) + 8LL) )
          return printk(&unk_22CB1C, a2);
      }
      *(_DWORD *)(result + 2440) = a2 & 1;
      if ( (a3 & 1) == 0 )
      {
        v5 = *(_QWORD *)(result + 2432);
        if ( (a4 & 1) != 0 )
        {
          v6 = result;
          v7 = _msecs_to_jiffies(*(unsigned int *)(result + 2444));
          result = v6;
        }
        else
        {
          v7 = 0;
        }
        result = queue_delayed_work_on(32, v5, result + 2328, v7);
      }
      dsi_panel_dim_handle_last_en = v4;
    }
  }
  return result;
}
