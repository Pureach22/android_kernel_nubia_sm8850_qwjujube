__int64 __fastcall _cam_req_mgr_validate_crm_wd_timer(__int64 result)
{
  __int64 v1; // x20
  int v2; // w8
  __int64 v3; // x21
  _DWORD *v4; // x19
  __int64 v5; // x9
  int v6; // w24
  __int64 v7; // x25
  __int64 v8; // x1
  __int64 v9; // x9
  int v10; // w26
  __int64 v11; // x27
  int v12; // w9
  unsigned int v13; // w10
  __int64 v14; // x0
  int v15; // w25
  int *v16; // x0
  int v17; // w6
  unsigned int v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v1 = result + 0x8000;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(result + 33344);
  v18 = 0;
  if ( v2 == 1 )
  {
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                 3,
                 debug_mdl & 0x10,
                 4,
                 "__cam_req_mgr_validate_crm_wd_timer",
                 1035,
                 "skipping modifying wd timer for first frame after streamon");
    *(_BYTE *)(v1 + 576) = 0;
    goto LABEL_44;
  }
  v3 = *(_QWORD *)(result + 48);
  v4 = (_DWORD *)result;
  v18 = *(_DWORD *)(v3 + 3464);
  cam_common_dec_idx(&v18, (unsigned int)(*(_DWORD *)(result + 8) - 1));
  if ( v18 >= 0x30 )
    goto LABEL_45;
  v5 = v3 + 8 + 72LL * v18;
  v6 = *(_DWORD *)(v5 + 28);
  v7 = *(_QWORD *)(v5 + 16);
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_validate_crm_wd_timer",
      1048,
      "rd_idx: %d idx: %d next_req_id: %lld next_frame_timeout: %d ms",
      *(_DWORD *)(v3 + 3464),
      v18,
      v7,
      v6);
  v8 = (unsigned int)v4[2];
  v18 = *(_DWORD *)(v3 + 3464);
  result = cam_common_dec_idx(&v18, v8);
  if ( v18 > 0x2F )
LABEL_45:
    __break(0x5512u);
  v9 = v3 + 8 + 72LL * v18;
  v10 = *(_DWORD *)(v9 + 28);
  v11 = *(_QWORD *)(v9 + 16);
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x10,
               4,
               "__cam_req_mgr_validate_crm_wd_timer",
               1058,
               "rd_idx: %d idx: %d curr_req_id: %lld current_frame_timeout: %d ms",
               *(_DWORD *)(v3 + 3464),
               v18,
               v11,
               v10);
    if ( v11 != -1 )
    {
LABEL_24:
      if ( v10 <= v6 )
        v15 = v6;
      else
        v15 = v10;
      raw_spin_lock_bh(v4 + 8304);
      v16 = *(int **)(v1 + 344);
      if ( v16 )
      {
        v17 = *v16;
        if ( v15 + 1000 > *v16 )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_validate_crm_wd_timer",
              1093,
              "Modifying wd timer expiry from %d ms to %d ms",
              v17,
              v6 + 1000);
            v16 = *(int **)(v1 + 344);
          }
LABEL_42:
          crm_timer_modify(v16);
          goto LABEL_43;
        }
        if ( v15 )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_validate_crm_wd_timer",
              1103,
              "Reset wd timer to frame from %d ms to %d ms",
              v17,
              v15 + 1000 + (v15 + 25) * v15 / 100);
            v16 = *(int **)(v1 + 344);
          }
          goto LABEL_42;
        }
        if ( v17 >= 1001 )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_validate_crm_wd_timer",
              1111,
              "Reset wd timer to default from %d ms to %d ms",
              v17,
              1000);
            v16 = *(int **)(v1 + 344);
          }
          goto LABEL_42;
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          16,
          2,
          "__cam_req_mgr_validate_crm_wd_timer",
          1116,
          "Watchdog timer exited already");
      }
LABEL_43:
      result = raw_spin_unlock_bh(v4 + 8304);
      goto LABEL_44;
    }
  }
  else if ( v11 != -1 )
  {
    goto LABEL_24;
  }
  if ( v7 != -1 )
    goto LABEL_24;
  v12 = *(_DWORD *)(v1 + 624);
  v13 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 4);
  if ( v12 )
  {
    if ( v13 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "__cam_req_mgr_validate_crm_wd_timer",
        1066,
        "Modifying wd timer expiry to %d ms on link: 0x%x",
        v12 + 1000,
        *v4);
    raw_spin_lock_bh(v4 + 8304);
    v14 = *(_QWORD *)(v1 + 344);
    if ( v14 )
      crm_timer_modify(v14);
    *(_DWORD *)(v1 + 624) = 0;
    goto LABEL_43;
  }
  if ( v13 )
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               debug_mdl & 0x10,
               4,
               "__cam_req_mgr_validate_crm_wd_timer",
               1077,
               "Skip modifying wd timer, continue with same timeout");
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
