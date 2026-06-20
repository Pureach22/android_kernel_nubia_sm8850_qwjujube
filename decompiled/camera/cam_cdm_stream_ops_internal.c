__int64 __fastcall cam_cdm_stream_ops_internal(__int64 a1, _DWORD *a2, char a3)
{
  __int64 v3; // x22
  _DWORD *v7; // x20
  int v8; // w8
  const char *v9; // x5
  __int64 v10; // x4
  const char *v12; // x6
  unsigned int v13; // w21
  int v14; // w8
  __int64 v15; // x0
  char v16; // w9
  char v17; // w8
  int v18; // w8
  char v19; // w9
  unsigned int v20; // w0
  __int64 v21; // x0
  unsigned int v22; // w0
  unsigned int v23; // w0

  if ( !a1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 3680);
  if ( (*(_QWORD *)(v3 + 4856) & 0x100) == 0 )
  {
    mutex_lock(a1);
    v7 = *(_DWORD **)(v3 + 8LL * (unsigned __int8)*a2 + 248);
    if ( !v7 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_stream_ops_internal",
        391,
        "Invalid client %pK hdl=%x",
        0);
      mutex_unlock(a1);
      return 4294967274LL;
    }
    mutex_lock(v7 + 70);
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_get_client_refcount",
        60,
        "CDM client get refcount=%d",
        v7[69]);
    ++v7[69];
    mutex_unlock(v7 + 70);
    if ( *a2 != v7[82] )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_stream_ops_internal",
        397,
        "client id given handle=%x invalid",
        *a2);
      v13 = -22;
      goto LABEL_33;
    }
    v8 = v7[68];
    if ( (a3 & 1) != 0 )
    {
      if ( v8 == 1 )
      {
        v9 = "Invalid CDM client is already streamed ON";
        v10 = 404;
LABEL_32:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_stream_ops_internal",
          v10,
          v9);
        v13 = -1;
        goto LABEL_33;
      }
      v18 = *(_DWORD *)(a1 + 88);
      if ( v18 )
      {
        v19 = debug_mdl;
        *(_DWORD *)(a1 + 88) = v18 + 1;
        if ( (v19 & 1) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            4,
            "cam_cdm_stream_ops_internal",
            441,
            "CDM HW already ON count=%d",
            v18 + 1);
        v13 = 0;
        v7[68] = 1;
      }
      else
      {
        v20 = cam_cdm_util_cpas_start(a1);
        if ( v20 )
        {
          v13 = v20;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_stream_ops_internal",
            419,
            "CPAS start failed");
        }
        else
        {
          if ( (debug_mdl & 1) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              1,
              4,
              "cam_cdm_stream_ops_internal",
              422,
              "CDM init first time");
          if ( *(_DWORD *)(v3 + 132) )
          {
            v21 = a1;
            if ( ((unsigned __int8)debug_mdl & (debug_priority == 0)) != 0 )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                1,
                4,
                "cam_cdm_stream_ops_internal",
                428,
                "CDM HW init first time");
              v21 = a1;
            }
            v22 = cam_cdm_stream_handle_init(v21, 1);
            if ( v22 )
            {
              v13 = v22;
              if ( (unsigned int)cam_cpas_stop(*(_DWORD *)(v3 + 4868)) )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  1,
                  1,
                  "cam_cdm_stream_ops_internal",
                  436,
                  "CPAS stop failed");
              goto LABEL_33;
            }
          }
          else if ( ((unsigned __int8)debug_mdl & (debug_priority == 0)) != 0 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              1,
              4,
              "cam_cdm_stream_ops_internal",
              425,
              "Virtual CDM HW init first time");
          }
          v13 = 0;
          ++*(_DWORD *)(a1 + 88);
          v7[68] = 1;
        }
      }
LABEL_33:
      cam_cdm_put_client_refcount((__int64)v7);
      mutex_unlock(a1);
      return v13;
    }
    if ( !v8 )
    {
      v9 = "Invalid CDM client is already streamed Off";
      v10 = 410;
      goto LABEL_32;
    }
    v14 = *(_DWORD *)(a1 + 88);
    v15 = a1;
    if ( !v14 )
    {
      v13 = -6;
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_cdm_stream_ops_internal",
          477,
          "stream OFF CDM Invalid %d",
          0);
      goto LABEL_33;
    }
    v16 = debug_mdl;
    *(_DWORD *)(a1 + 88) = v14 - 1;
    if ( (v16 & 1) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_stream_ops_internal",
        449,
        "stream OFF CDM %d",
        v14 - 1);
      v15 = a1;
      if ( *(_DWORD *)(a1 + 88) )
        goto LABEL_23;
    }
    else if ( v14 != 1 )
    {
LABEL_23:
      v17 = debug_mdl;
      v13 = 0;
      v7[68] = 0;
      if ( (v17 & 1) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_cdm_stream_ops_internal",
          473,
          "Client stream off success =%d",
          *(_DWORD *)(a1 + 88));
        v13 = 0;
      }
      goto LABEL_33;
    }
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_stream_ops_internal",
        451,
        "CDM Deinit now");
      v15 = a1;
    }
    if ( *(_DWORD *)(v3 + 132) )
    {
      if ( ((unsigned __int8)debug_mdl & (debug_priority == 0)) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          4,
          "cam_cdm_stream_ops_internal",
          457,
          "CDM HW Deinit now");
        v15 = a1;
      }
      v13 = cam_cdm_stream_handle_init(v15, 0);
      if ( v13 )
        goto LABEL_33;
    }
    else if ( ((unsigned __int8)debug_mdl & (debug_priority == 0)) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_stream_ops_internal",
        454,
        "Virtual CDM HW Deinit");
    }
    v7[68] = 0;
    v23 = cam_cpas_stop(*(_DWORD *)(v3 + 4868));
    if ( v23 )
    {
      v13 = v23;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_stream_ops_internal",
        466,
        "CPAS stop failed");
    }
    else
    {
      v13 = 0;
    }
    goto LABEL_33;
  }
  if ( (a3 & 1) != 0 )
    v12 = "on";
  else
    v12 = "off";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    2,
    "cam_cdm_stream_ops_internal",
    383,
    "Attempt to stream %s failed. %s%u has encountered a page fault",
    v12,
    (const char *)(v3 + 4),
    *(_DWORD *)(v3 + 132));
  return 4294967285LL;
}
