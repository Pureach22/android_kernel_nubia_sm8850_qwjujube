__int64 __fastcall dp_power_clk_get_rate(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v5; // x22
  __int64 v6; // x21
  unsigned __int64 v7; // x23
  int v8; // w0
  bool v9; // w22
  __int64 result; // x0
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 v13; // x23
  __int64 i; // x22
  __int64 v15; // x23
  __int64 v16; // x23
  __int64 v17; // x23
  __int64 v18; // x23
  __int64 v19; // x23
  __int64 v20; // x23
  __int64 ipc_log_context; // x0

  if ( !s2 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]invalid pointer for clk_name\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24EA5D, "dp_power_clk_get_rate");
    return 0;
  }
  v2 = *(_QWORD *)(a1 + 8);
  v5 = *(unsigned int *)(v2 + 32);
  if ( (_DWORD)v5 )
  {
    v6 = *(_QWORD *)(v2 + 40);
    if ( !strcmp((const char *)(v6 + 8), s2) )
    {
      v9 = 1;
LABEL_10:
      result = clk_get_rate(*(_QWORD *)v6);
      if ( v9 )
        return result;
      goto LABEL_11;
    }
    v7 = 0;
    while ( v5 - 1 != v7 )
    {
      v8 = strcmp((const char *)(v6 + 128), s2);
      v6 += 120;
      ++v7;
      if ( !v8 )
      {
        v9 = v7 < v5;
        goto LABEL_10;
      }
    }
  }
  result = 0;
LABEL_11:
  v11 = *(_QWORD *)(a1 - 72);
  v12 = result;
  v13 = *(unsigned int *)(v11 + 48);
  if ( (_DWORD)v13 )
  {
    i = *(_QWORD *)(v11 + 56);
    while ( strcmp((const char *)(i + 8), s2) )
    {
      --v13;
      i += 120;
      if ( !v13 )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    v15 = *(unsigned int *)(v11 + 96);
    if ( (_DWORD)v15 )
    {
      i = *(_QWORD *)(v11 + 104);
      while ( strcmp((const char *)(i + 8), s2) )
      {
        --v15;
        i += 120;
        if ( !v15 )
          goto LABEL_19;
      }
    }
    else
    {
LABEL_19:
      v16 = *(unsigned int *)(v11 + 144);
      if ( (_DWORD)v16 )
      {
        i = *(_QWORD *)(v11 + 152);
        while ( strcmp((const char *)(i + 8), s2) )
        {
          --v16;
          i += 120;
          if ( !v16 )
            goto LABEL_23;
        }
      }
      else
      {
LABEL_23:
        v17 = *(unsigned int *)(v11 + 192);
        if ( (_DWORD)v17 )
        {
          i = *(_QWORD *)(v11 + 200);
          while ( strcmp((const char *)(i + 8), s2) )
          {
            --v17;
            i += 120;
            if ( !v17 )
              goto LABEL_27;
          }
        }
        else
        {
LABEL_27:
          v18 = *(unsigned int *)(v11 + 240);
          if ( (_DWORD)v18 )
          {
            i = *(_QWORD *)(v11 + 248);
            while ( strcmp((const char *)(i + 8), s2) )
            {
              --v18;
              i += 120;
              if ( !v18 )
                goto LABEL_31;
            }
          }
          else
          {
LABEL_31:
            v19 = *(unsigned int *)(v11 + 288);
            if ( (_DWORD)v19 )
            {
              i = *(_QWORD *)(v11 + 296);
              while ( strcmp((const char *)(i + 8), s2) )
              {
                --v19;
                i += 120;
                if ( !v19 )
                  goto LABEL_35;
              }
            }
            else
            {
LABEL_35:
              v20 = *(unsigned int *)(v11 + 336);
              if ( !(_DWORD)v20 )
                return v12;
              for ( i = *(_QWORD *)(v11 + 344); strcmp((const char *)(i + 8), s2); i += 120 )
              {
                if ( !--v20 )
                  return v12;
              }
            }
          }
        }
      }
    }
  }
  return clk_get_rate(*(_QWORD *)i);
}
