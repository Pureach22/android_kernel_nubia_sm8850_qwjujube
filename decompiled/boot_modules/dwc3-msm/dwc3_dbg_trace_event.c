char *__fastcall dwc3_dbg_trace_event(__int64 a1, unsigned int a2, __int64 a3)
{
  char *result; // x0
  const char *v7; // x21
  __int64 v8; // x23
  int v9; // w0
  unsigned int v10; // w9
  __int64 v11; // x22
  unsigned int v12; // w8
  unsigned int v13; // w24
  const char *v14; // x4
  int v15; // w0
  int v16; // w9
  __int64 v17; // x8
  const char *v18; // x2
  unsigned int v19; // w9
  int v20; // w8
  __int64 v21; // x1
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  int v25; // w0
  const char *v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  const char *v30; // x0

  result = (char *)_kmalloc_cache_noprof(_stack_chk_fail, 2336, 500);
  v7 = result;
  if ( result )
  {
    if ( (a2 & 1) != 0 )
    {
      v19 = (a2 >> 8) & 0xF;
      v20 = HIWORD(a2) & 0xF;
      if ( v19 > 5 )
      {
        if ( ((a2 >> 8) & 0xF) <= 8 )
        {
          if ( v19 == 6 )
          {
            snprintf(result, 0x1F4u, "Suspend [%s]", off_15748[v20]);
            goto LABEL_70;
          }
          if ( v19 == 7 )
          {
            snprintf(result, 0x1F4u, "Start-Of-Frame [%s]", off_15748[v20]);
            goto LABEL_70;
          }
        }
        else
        {
          switch ( v19 )
          {
            case 9u:
              snprintf(result, 0x1F4u, "Erratic Error [%s]", off_15748[v20]);
              goto LABEL_70;
            case 0xAu:
              snprintf(result, 0x1F4u, "Command Complete [%s]", off_15748[v20]);
              goto LABEL_70;
            case 0xBu:
              snprintf(result, 0x1F4u, "Overflow [%s]", off_15748[v20]);
              goto LABEL_70;
          }
        }
      }
      else
      {
        if ( ((a2 >> 8) & 0xF) <= 1 )
        {
          if ( v19 )
            snprintf(result, 0x1F4u, "Reset [%s]", off_15748[v20]);
          else
            snprintf(result, 0x1F4u, "Disconnect: [%s]", off_15748[v20]);
          goto LABEL_70;
        }
        switch ( v19 )
        {
          case 2u:
            snprintf(result, 0x1F4u, "Connection Done [%s]", off_15748[v20]);
            goto LABEL_70;
          case 3u:
            snprintf(result, 0x1F4u, "Link Change [%s]", off_15748[v20]);
            goto LABEL_70;
          case 4u:
            snprintf(result, 0x1F4u, "WakeUp [%s]", off_15748[v20]);
            goto LABEL_70;
        }
      }
      *(_QWORD *)result = 0x4E574F4E4B4E55LL;
      goto LABEL_70;
    }
    v8 = *(unsigned int *)(a3 + 1264);
    v9 = ((__int64 (*)(void))scnprintf)();
    v10 = (a2 >> 6) & 0xF;
    v11 = v9;
    v12 = (unsigned __int16)a2 >> 12;
    if ( v10 <= 3 )
    {
      v13 = (a2 >> 1) & 0x1F;
      switch ( v10 )
      {
        case 1u:
          if ( (v12 & 2) != 0 )
            v22 = 83;
          else
            v22 = 115;
          if ( (v12 & 4) != 0 )
            v23 = 73;
          else
            v23 = 105;
          if ( v12 >= 8 )
            v24 = 76;
          else
            v24 = 108;
          v25 = scnprintf(&v7[v9], 500LL - v9, "Transfer Complete (%c%c%c)", v22, v23, v24);
          if ( v13 <= 1 )
          {
            if ( (unsigned int)v8 > 3 )
              v26 = "UNKNOWN";
            else
              v26 = off_157C8[v8];
            scnprintf(&v7[v11 + v25], 500 - (v11 + v25), " [%s]", v26);
          }
          goto LABEL_70;
        case 2u:
          if ( (v12 & 2) != 0 )
            v27 = 83;
          else
            v27 = 115;
          if ( (v12 & 4) != 0 )
            v28 = 73;
          else
            v28 = 105;
          if ( v12 >= 8 )
            v29 = 77;
          else
            v29 = 109;
          scnprintf(&v7[v9], 500LL - v9, "Transfer In Progress [%08x] (%c%c%c)", HIWORD(a2), v27, v28, v29);
          goto LABEL_70;
        case 3u:
          if ( (a2 & 0x8000) != 0 )
            v14 = " (Active)";
          else
            v14 = " (Not Active)";
          v15 = scnprintf(&v7[v9], 500LL - v9, "Transfer Not Ready [%08x]%s", HIWORD(a2), v14);
          if ( v13 > 1 )
            goto LABEL_70;
          v16 = (a2 >> 12) & 3;
          v17 = v11 + v15;
          if ( v16 == 2 )
          {
            v18 = " [Status Phase]";
            goto LABEL_75;
          }
          if ( v16 == 1 )
          {
            v18 = " [Data Phase]";
LABEL_75:
            v21 = 500 - v17;
            v30 = &v7[v17];
            goto LABEL_69;
          }
LABEL_70:
          ipc_log_string(a1, "event (%08x): %s", a2, v7);
          return (char *)kfree(v7);
      }
      goto LABEL_47;
    }
    switch ( v10 )
    {
      case 4u:
        v18 = "FIFO";
        v21 = 500LL - v9;
        break;
      case 6u:
        v21 = 500LL - v9;
        if ( v12 == 1 )
        {
          scnprintf(&v7[v9], v21, " Stream %d Found", HIWORD(a2));
          goto LABEL_70;
        }
        v18 = " Stream Not Found";
        break;
      case 7u:
        v18 = "Endpoint Command Complete";
        v21 = 500LL - v9;
        break;
      default:
LABEL_47:
        v18 = "UNKNOWN";
        v21 = 500LL - v9;
        break;
    }
    v30 = &v7[v9];
LABEL_69:
    scnprintf(v30, v21, v18);
    goto LABEL_70;
  }
  return result;
}
