__int64 __fastcall camera_io_init(unsigned int *a1)
{
  __int64 v1; // x6
  __int64 *v2; // x9
  __int64 v3; // x8
  unsigned int v4; // w0
  const char *v5; // x5
  __int64 v6; // x4
  __int64 v7; // x9
  __int64 v8; // x19
  __int64 v9; // x9
  _DWORD *v10; // x9
  __int64 v11; // x9
  unsigned int *v12; // x20
  int v13; // w6
  const char *v14; // x7
  __int64 v15; // x9
  unsigned int *v17; // x19
  unsigned int *v18; // x19
  unsigned int *v19; // x20

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "camera_io_init",
      219,
      "Invalid Args");
LABEL_45:
    LODWORD(v3) = -22;
    return (unsigned int)v3;
  }
  v1 = *a1;
  if ( (int)v1 > 2 )
  {
    if ( (_DWORD)v1 == 3 )
      goto LABEL_42;
    if ( (_DWORD)v1 == 4 )
    {
      v3 = *((_QWORD *)a1 + 1);
      if ( !v3 )
        return (unsigned int)v3;
      v7 = *(_QWORD *)(v3 + 8);
      if ( v7 )
      {
        v8 = *(_QWORD *)(v7 + 96);
        if ( v8 )
        {
          v9 = *(_QWORD *)(v8 + 744);
          if ( v9 )
          {
            v10 = *(_DWORD **)(v9 + 240);
            if ( v10 )
            {
              if ( *(_BYTE *)(v3 + 17) == 1 && *(_BYTE *)(v3 + 16) == 1 )
              {
                *v10 = 1;
                if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
                {
                  v19 = a1;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x4000000000LL,
                    4,
                    "camera_io_init",
                    243,
                    "%s:%d: %s: SET of_node->data: %d",
                    "camera_io_init",
                    243,
                    (const char *)a1 + 32,
                    **(_DWORD **)(*(_QWORD *)(v8 + 744) + 240LL));
                  a1 = v19;
                }
              }
            }
          }
          v11 = *((_QWORD *)a1 + 1);
          if ( *(_BYTE *)(v11 + 16) == 1 )
          {
            v12 = a1;
            if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000000000LL,
                4,
                "camera_io_init",
                249,
                "%s:%d: %s: wait_for_hotjoin: %d I3C_MASTER: Calling get_sync",
                "camera_io_init",
                249,
                (const char *)a1 + 32,
                *(unsigned __int8 *)(v11 + 17));
            v13 = _pm_runtime_resume(v8, 4);
            a1 = v12;
            if ( v13 < 0 )
            {
              v14 = *(const char **)(v8 + 112);
              if ( !v14 )
                v14 = *(const char **)v8;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x4000000000LL,
                2,
                "camera_io_init",
                254,
                "Fail I3C getsync rc: %d for parent: %s",
                v13,
                v14);
              a1 = v12;
            }
          }
          v3 = *(_QWORD *)(v8 + 744);
          if ( !v3 )
            return (unsigned int)v3;
          v3 = *(_QWORD *)(v3 + 240);
          if ( !v3 )
            return (unsigned int)v3;
          v15 = *((_QWORD *)a1 + 1);
          if ( *(_BYTE *)(v15 + 17) == 1 && *(_BYTE *)(v15 + 16) == 1 )
          {
            *(_DWORD *)v3 = 0;
            LODWORD(v3) = 0;
            if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x4000000000LL,
                4,
                "camera_io_init",
                265,
                "%s:%d: %s: SET of_node->data: %d",
                "camera_io_init",
                265,
                (const char *)a1 + 32,
                **(_DWORD **)(*(_QWORD *)(v8 + 744) + 240LL));
              LODWORD(v3) = 0;
            }
            return (unsigned int)v3;
          }
        }
      }
LABEL_42:
      LODWORD(v3) = 0;
      return (unsigned int)v3;
    }
LABEL_43:
    v5 = "Invalid Master Type:%d";
    v6 = 287;
    goto LABEL_44;
  }
  if ( (_DWORD)v1 == 1 )
  {
    v17 = a1;
    **((_QWORD **)a1 + 2) = cam_cci_get_subdev(*(unsigned __int16 *)(*((_QWORD *)a1 + 2) + 32LL));
    LODWORD(v3) = cam_sensor_cci_i2c_util(*((_QWORD *)v17 + 2), 0);
    return (unsigned int)v3;
  }
  if ( (_DWORD)v1 != 2 )
    goto LABEL_43;
  v2 = *((__int64 **)a1 + 1);
  if ( !v2 )
    goto LABEL_42;
  v3 = *v2;
  if ( *v2 )
  {
    v3 = *(_QWORD *)(v3 + 24);
    if ( v3 )
    {
      if ( *((_BYTE *)v2 + 16) == 1 )
      {
        if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
        {
          v18 = a1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000000000LL,
            4,
            "camera_io_init",
            276,
            "%s:%d: %s: I2C_MASTER: Calling get_sync",
            "camera_io_init",
            276,
            (const char *)a1 + 32);
          v3 = *(_QWORD *)(**((_QWORD **)v18 + 1) + 24LL);
        }
        v4 = _pm_runtime_resume(*(_QWORD *)(v3 + 208), 4);
        if ( (v4 & 0x80000000) != 0 )
        {
          v1 = v4;
          v5 = "Failed to get sync rc: %d";
          v6 = 280;
LABEL_44:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            0x4000000000LL,
            1,
            "camera_io_init",
            v6,
            v5,
            v1);
          goto LABEL_45;
        }
      }
      goto LABEL_42;
    }
  }
  return (unsigned int)v3;
}
