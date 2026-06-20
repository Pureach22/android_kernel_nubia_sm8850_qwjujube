__int64 __fastcall _cam_synx_obj_signal_cb(__int64 result, int a2, __int64 a3)
{
  _DWORD *v3; // x8
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x19
  int v7; // w0
  __int64 v8; // [xsp+0h] [xbp-20h]
  int v9; // [xsp+8h] [xbp-18h]
  unsigned int v10; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  if ( a3 )
  {
    if ( (*(_BYTE *)(a3 + 81) & 1) == 0 )
    {
      if ( *(_DWORD *)(a3 + 64) == (_DWORD)result )
      {
        if ( *(_DWORD *)(a3 + 68) )
        {
          if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
          {
            v9 = a2;
            v8 = a3;
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       debug_mdl & 0x1000000000LL,
                       4,
                       "__cam_synx_obj_signal_cb",
                       169,
                       "Synx obj: %d signaled, signal sync obj: %d",
                       result,
                       *(_DWORD *)(a3 + 84));
            a2 = v9;
            a3 = v8;
          }
          if ( *(_BYTE *)(a3 + 80) == 1 )
          {
            v3 = *(_DWORD **)(a3 + 72);
            if ( v3 )
            {
              LODWORD(v11[0]) = *(_DWORD *)(a3 + 64);
              if ( a2 == 4 )
              {
                HIDWORD(v11[0]) = 4;
              }
              else if ( a2 == 2 )
              {
                HIDWORD(v11[0]) = 2;
              }
              else
              {
                v4 = a3;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x1000000000LL,
                  2,
                  "__cam_synx_obj_signal_cb",
                  183,
                  "Synx signal status %d is neither SUCCESS nor CANCEL, custom code?",
                  a2);
                v3 = *(_DWORD **)(v4 + 72);
                a3 = v4;
                HIDWORD(v11[0]) = 3;
              }
              v5 = *(unsigned int *)(a3 + 84);
              *(_DWORD *)(a3 + 68) = 2;
              v6 = a3;
              if ( *(v3 - 1) != 775567914 )
                __break(0x8228u);
              result = ((__int64 (__fastcall *)(__int64, _QWORD *))v3)(v5, v11);
              if ( (cam_sync_monitor_mask & 8) != 0 )
              {
                v7 = *(_DWORD *)(v6 + 64);
                v10 = 0;
                cam_synx_obj_find_obj_in_table(v7, &v10);
                result = cam_generic_fence_update_monitor_array(
                           v10,
                           g_cam_synx_obj_dev + 23560,
                           *(_QWORD *)(g_cam_synx_obj_dev + 23640),
                           5);
              }
            }
          }
        }
        else
        {
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     0x1000000000LL,
                     1,
                     "__cam_synx_obj_signal_cb",
                     164,
                     "Synx obj :%d is in invalid state: %d",
                     result,
                     0);
        }
      }
      else
      {
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                   3,
                   0x1000000000LL,
                   1,
                   "__cam_synx_obj_signal_cb",
                   157,
                   "Synx obj: %d callback does not match synx obj: %d in sync table.",
                   (unsigned int)result);
      }
    }
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x1000000000LL,
               1,
               "__cam_synx_obj_signal_cb",
               144,
               "Invalid data passed to synx obj : No callback function set.");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
