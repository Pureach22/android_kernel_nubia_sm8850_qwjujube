__int64 __fastcall cam_common_evt_inject_get(const char *a1)
{
  __int64 v2; // x24
  unsigned int v3; // w19
  int v4; // w26
  int v5; // w8
  int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x9
  int v9; // w5
  __int64 v10; // x6
  int v11; // w8
  const char *v12; // x0
  int v13; // w0
  __int64 v14; // x4
  unsigned int v15; // w0
  __int128 v17; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v18[3]; // [xsp+18h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  v17 = 0u;
  if ( (byte_394041 & 1) == 0 )
  {
    v15 = scnprintf(a1, 4096, "uninitialised");
LABEL_36:
    v3 = v15;
    goto LABEL_39;
  }
  v2 = qword_394030;
  if ( (__int64 *)qword_394030 == &qword_394030 )
  {
    v15 = scnprintf(a1, 4096, "Active err inject list is empty");
    goto LABEL_36;
  }
  v3 = 0;
  v4 = 4096;
  while ( 1 )
  {
    v5 = *(unsigned __int8 *)(v2 + 52);
    if ( v5 == 2 )
    {
      BYTE4(v18[0]) = 0;
      v6 = 1195724874;
      goto LABEL_10;
    }
    if ( v5 == 1 )
    {
      v6 = 4542537;
LABEL_10:
      LODWORD(v18[0]) = v6;
      goto LABEL_11;
    }
    if ( *(_BYTE *)(v2 + 52) )
    {
      v13 = scnprintf(&a1[v3], (unsigned __int16)v4, "Undefined HW id\n");
      goto LABEL_27;
    }
    LODWORD(v18[0]) = 4539977;
LABEL_11:
    if ( *(_BYTE *)(v2 + 16) == 1 )
    {
      v7 = *(_QWORD *)"Notify_Event";
      v8 = *(_QWORD *)"y_Event";
    }
    else
    {
      if ( *(_BYTE *)(v2 + 16) )
      {
        v13 = scnprintf(&a1[v3], (unsigned __int16)v4, "Undefined string id\n");
        goto LABEL_27;
      }
      v7 = *(_QWORD *)"Buffer_Error";
      v8 = *(_QWORD *)"r_Error";
    }
    *(_QWORD *)&v17 = v7;
    v9 = *(_DWORD *)(v2 + 48);
    v10 = *(_QWORD *)(v2 + 24);
    *(_QWORD *)((char *)&v17 + 5) = v8;
    v3 += scnprintf(
            &a1[v3],
            (unsigned __int16)v4,
            "string_id: %s hw_name: %s dev_hdl: %d req_id: %llu ",
            (const char *)&v17,
            (const char *)v18,
            v9,
            v10);
    if ( v3 >= (unsigned __int16)v4 )
      break;
    v4 -= v3;
    if ( *(_BYTE *)(v2 + 16) )
    {
      v11 = *(_DWORD *)(v2 + 32);
      if ( v11 == 6 )
      {
        v13 = scnprintf(&a1[v3], (unsigned __int16)v4, "PF event: ctx found %hhu\n", *(unsigned __int8 *)(v2 + 36));
      }
      else
      {
        v12 = &a1[v3];
        if ( v11 == 4 )
        {
          v13 = scnprintf(
                  v12,
                  (unsigned __int16)v4,
                  "Node event: event type: %u event cause: %u\n",
                  *(_DWORD *)(v2 + 36),
                  *(_DWORD *)(v2 + 40));
        }
        else if ( v11 == 1 )
        {
          v13 = scnprintf(
                  v12,
                  (unsigned __int16)v4,
                  "Error event: error type: %u error code: %u\n",
                  *(_DWORD *)(v2 + 36),
                  *(_DWORD *)(v2 + 40));
        }
        else
        {
          v13 = scnprintf(v12, (unsigned __int16)v4, "Undefined notification event\n");
        }
      }
    }
    else
    {
      v13 = scnprintf(&a1[v3], (unsigned __int16)v4, "sync_error: %u\n", *(_DWORD *)(v2 + 32));
    }
LABEL_27:
    v3 += v13;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_common_evt_inject_get",
        860,
        "output buffer: %s",
        a1);
      if ( v3 >= (unsigned __int16)v4 )
      {
LABEL_33:
        v14 = 865;
        goto LABEL_38;
      }
    }
    else if ( v3 >= (unsigned __int16)v4 )
    {
      goto LABEL_33;
    }
    v2 = *(_QWORD *)v2;
    v4 -= v3;
    if ( (__int64 *)v2 == &qword_394030 )
      goto LABEL_39;
  }
  v14 = 819;
LABEL_38:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    2,
    "cam_common_evt_inject_get",
    v14,
    "out buff max limit reached");
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return v3;
}
