__int64 __fastcall cam_ois_update_time(_QWORD **a1, int a2)
{
  __int64 result; // x0
  _QWORD *i; // x23
  __int64 v6; // x26
  int v7; // w8
  __int64 v8; // x22
  __int64 v9; // x27
  unsigned int v10; // w28
  __int64 v11; // x8
  __int64 v12; // x22
  __int64 v13; // x27
  unsigned int v14; // w28
  const char *v15; // x5
  __int64 v16; // x4
  unsigned int v17; // w19
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  if ( !a1 )
  {
    v15 = "Invalid Args";
    v16 = 256;
    goto LABEL_25;
  }
  result = cam_sensor_util_get_current_qtimer_ns(v18);
  if ( (result & 0x80000000) != 0 )
  {
    v17 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_update_time",
      264,
      "Failed to get current qtimer value: %d",
      result);
    result = v17;
    goto LABEL_27;
  }
  if ( !a2 )
    v18[0] = HIWORD(v18[0])
           | ((((unsigned __int64)LOWORD(v18[0]) << 32) | ((unsigned __int64)WORD1(v18[0]) << 16) | WORD2(v18[0])) << 16);
  for ( i = *a1; i != a1; i = (_QWORD *)*i )
  {
    if ( (*((_DWORD *)i - 2) | 2) == 2 )
    {
      v6 = *((unsigned int *)i - 16);
      v7 = *((_DWORD *)i - 14);
      if ( v7 * (_DWORD)v6 != 8 )
      {
        v15 = "Invalid write time settings";
        v16 = 279;
        goto LABEL_25;
      }
      if ( v7 == 1 )
      {
        if ( (_DWORD)v6 )
        {
          LOBYTE(v11) = v18[0];
          v12 = 0;
          v13 = 4;
          do
          {
            if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
            {
              v14 = result;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x100000,
                4,
                "cam_ois_update_time",
                286,
                "time: reg_data[%d]: 0x%x",
                v12,
                (unsigned __int8)v11);
              LOBYTE(v11) = v18[0];
              result = v14;
            }
            ++v12;
            *(_DWORD *)(*(i - 9) + v13) = (unsigned __int8)v11;
            v13 += 16;
            v11 = v18[0] >> 8;
            v18[0] >>= 8;
          }
          while ( v6 != v12 );
        }
      }
      else
      {
        if ( v7 != 2 )
        {
          v15 = "Unsupported reg data type";
          v16 = 307;
LABEL_25:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x100000,
            1,
            "cam_ois_update_time",
            v16,
            v15);
          result = 4294967274LL;
          break;
        }
        if ( (_DWORD)v6 )
        {
          v8 = 0;
          v9 = 4;
          do
          {
            *(_DWORD *)(*(i - 9) + v9) = LOWORD(v18[0]);
            v18[0] >>= 16;
            if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
            {
              v10 = result;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                debug_mdl & 0x100000,
                4,
                "cam_ois_update_time",
                302,
                "time: reg_data[%d]: 0x%x",
                (unsigned int)v8);
              result = v10;
            }
            ++v8;
            v9 += 16;
          }
          while ( v6 != v8 );
        }
      }
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
