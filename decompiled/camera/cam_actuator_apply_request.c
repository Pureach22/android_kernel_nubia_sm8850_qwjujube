__int64 __fastcall cam_actuator_apply_request(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x1
  unsigned int v6; // w0
  unsigned int v7; // w21
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v10; // x27
  __int64 i; // x21
  __int64 v12; // x24
  __int64 v14; // x6

  if ( !a1 )
  {
    v8 = "Invalid Input Args";
    v9 = 293;
LABEL_24:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_apply_request",
      v9,
      v8);
    return 4294967274LL;
  }
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    v8 = "Device data is NULL";
    v9 = 300;
    goto LABEL_24;
  }
  v3 = device_priv;
  v4 = *(_QWORD *)(a1 + 8) & 0x1FLL;
  if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000,
      4,
      "cam_actuator_apply_request",
      307,
      "Request Id: %lld",
      *(_QWORD *)(a1 + 8));
  mutex_lock(v3 + 3672);
  v5 = *(_QWORD *)(v3 + 4448) + 48LL * (unsigned int)v4;
  if ( *(_QWORD *)(a1 + 8) != *(_QWORD *)(v5 + 24) || *(_DWORD *)(v5 + 16) != 1 )
  {
    v6 = 0;
LABEL_12:
    v10 = 0;
    for ( i = 0; i != 32; ++i )
    {
      v12 = *(_QWORD *)(v3 + 4448) + v10;
      if ( *(_DWORD *)(v12 + 16) == 1 && *(_QWORD *)(a1 + 8) > (unsigned __int64)(*(_QWORD *)(v12 + 24) + 2LL) )
      {
        if ( (debug_mdl & 0x2000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 0x2000,
            4,
            "cam_actuator_apply_request",
            328,
            "Clean up per frame[%d] = %lld",
            (unsigned int)i);
        *(_QWORD *)(v12 + 24) = 0;
        v6 = delete_request(v12);
        if ( (v6 & 0x80000000) != 0 )
        {
          v14 = (unsigned int)i;
          v7 = v6;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            0x2000,
            1,
            "cam_actuator_apply_request",
            334,
            "Fail deleting the req: %d err: %d\n",
            v14);
          goto LABEL_27;
        }
      }
      v10 += 48;
    }
    if ( (debug_mdl & 0x2000) != 0 )
    {
      v7 = v6;
      if ( !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x2000,
          4,
          "cam_actuator_apply_request",
          339,
          "Req Per frame validation check Finished");
    }
    else
    {
      v7 = v6;
    }
    goto LABEL_27;
  }
  v6 = cam_actuator_apply_settings(v3, v5);
  if ( (v6 & 0x80000000) == 0 )
    goto LABEL_12;
  v7 = v6;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x2000,
    1,
    "cam_actuator_apply_request",
    318,
    "Failed in applying the request: %lld\n",
    *(_QWORD *)(a1 + 8));
LABEL_27:
  mutex_unlock(v3 + 3672);
  return v7;
}
