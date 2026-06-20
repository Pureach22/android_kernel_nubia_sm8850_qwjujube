__int64 __fastcall prepare_core_sub_state_name(unsigned int a1, const char *a2)
{
  int v2; // s11
  __int64 v5; // x23
  __int64 v6; // x26
  __int64 v7; // x8
  size_t v8; // x20
  const char *v9; // x21
  size_t v10; // x22
  size_t v11; // x0
  size_t v12; // x2
  __int64 v13; // x20
  __int64 v15; // x0
  __int64 v16; // x9
  int v17; // s25

  if ( !a2 )
    return 4294967274LL;
  sized_strscpy(a2, &unk_9DB98);
  if ( !a1 )
  {
    sized_strscpy(a2, "CORE_SUBSTATE_NONE");
    return 0;
  }
  v5 = 0;
  v6 = a1;
  v7 = 1;
  while ( 1 )
  {
    if ( (v7 & v6) == 0 )
      goto LABEL_4;
    if ( (int)v7 > 15 )
    {
      if ( (int)v7 <= 63 )
      {
        if ( (_DWORD)v7 == 16 )
        {
          v8 = 12;
          v9 = "PAGE_FAULT ";
          goto LABEL_30;
        }
        if ( (_DWORD)v7 == 32 )
        {
          v8 = 14;
          v9 = "CPU_WATCHDOG ";
          goto LABEL_30;
        }
      }
      else
      {
        switch ( (_DWORD)v7 )
        {
          case 0x40:
            v8 = 20;
            v9 = "VIDEO_UNRESPONSIVE ";
            goto LABEL_30;
          case 0x80:
            v8 = 14;
            v9 = "RPROC_ENABLE ";
            goto LABEL_30;
          case 0x100:
            v8 = 5;
            v9 = "MAX ";
            goto LABEL_30;
        }
      }
    }
    else if ( (int)v7 <= 1 )
    {
      if ( !(_DWORD)v7 )
      {
        v8 = 6;
        v9 = "NONE ";
        goto LABEL_30;
      }
      if ( (_DWORD)v7 == 1 )
      {
        v8 = 14;
        v9 = "POWER_ENABLE ";
        goto LABEL_30;
      }
    }
    else
    {
      switch ( (_DWORD)v7 )
      {
        case 2:
          v8 = 14;
          v9 = "GDSC_HANDOFF ";
          goto LABEL_30;
        case 4:
          v8 = 12;
          v9 = "PM_SUSPEND ";
          goto LABEL_30;
        case 8:
          v8 = 13;
          v9 = "FW_PWR_CTRL ";
          goto LABEL_30;
      }
    }
    v8 = 9;
    v9 = "UNKNOWN ";
LABEL_30:
    v10 = strnlen(a2, 0x7Fu);
    if ( v10 == -1 )
      goto LABEL_47;
    v11 = strnlen(v9, v8);
    if ( v11 > v8 )
      break;
    if ( v11 >= v8 )
      goto LABEL_46;
    if ( v10 <= 0x7E )
    {
      if ( v11 + v10 >= 0x7F )
        v12 = 126 - v10;
      else
        v12 = v11;
      if ( v11 + v10 >= 0x7F )
        v13 = 126;
      else
        v13 = v11 + v10;
      memcpy((void *)&a2[v10], v9, v12);
      a2[v13] = 0;
    }
LABEL_4:
    v7 = 2LL << v5++;
    if ( v5 == 8 )
      return 0;
  }
  v11 = _fortify_panic(2, v8, v11 + 1);
LABEL_46:
  _fortify_panic(4, v8, v11 + 1);
LABEL_47:
  v15 = _fortify_panic(2, -1, v10 + 1);
  *(_DWORD *)(v16 - 24) = v17;
  *(_DWORD *)(v16 - 20) = v2;
  return state_name(v15);
}
