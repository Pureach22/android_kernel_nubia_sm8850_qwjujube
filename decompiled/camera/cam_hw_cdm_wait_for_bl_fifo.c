__int64 __fastcall cam_hw_cdm_wait_for_bl_fifo(__int64 a1, unsigned int a2, unsigned int a3)
{
  const char *v4; // x5
  __int64 v5; // x2
  __int64 v6; // x4
  __int64 v7; // x6
  __int64 v8; // x7
  unsigned int done; // w23
  __int64 v11; // x22
  const char *v13; // x5
  __int64 v14; // x4
  _DWORD *v16; // x22
  int v17; // w8
  __int64 v18; // x7
  __int64 v19; // x6
  unsigned int v20; // w0
  int v21; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  if ( a3 >= 4 )
  {
    v4 = "Invalid fifo index %d rc = %d";
    v5 = 1;
    v6 = 744;
    v7 = a3;
    v8 = 4294967274LL;
    done = -22;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      1,
      v5,
      "cam_hw_cdm_wait_for_bl_fifo",
      v6,
      v4,
      v7,
      v8);
    goto LABEL_8;
  }
  v11 = *(_QWORD *)(a1 + 3680);
  if ( (unsigned int)cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo(a1, a3, &v21) )
    goto LABEL_5;
  v16 = (_DWORD *)(v11 + 640LL * a3 + 2296);
  v17 = v21;
  v18 = (unsigned int)v16[27];
  v19 = (unsigned int)(v18 - v21);
  if ( (int)v18 - v21 < 0 )
  {
    done = -5;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_wait_for_bl_fifo",
      760,
      "Invalid available slots %d:%d:%d",
      v19,
      v18,
      v17);
  }
  else
  {
    done = v19 - 1;
    if ( (_DWORD)v19 == 1 )
    {
      *v16 = 0;
      done = cam_hw_cdm_enable_bl_done_irq(a1, 1, a3);
      if ( !done )
      {
        if ( cam_common_wait_for_completion_timeout((__int64)v16) < 1 )
        {
LABEL_36:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            1,
            1,
            "cam_hw_cdm_wait_for_bl_fifo",
            778,
            "CDM HW BL Wait timed out failed");
          if ( !(unsigned int)cam_hw_cdm_enable_bl_done_irq(a1, 0, a3) )
            goto LABEL_7;
          v13 = "Disable BL done irq failed";
          v14 = 782;
LABEL_6:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            1,
            1,
            "cam_hw_cdm_wait_for_bl_fifo",
            v14,
            v13);
LABEL_7:
          done = -5;
          goto LABEL_8;
        }
        if ( (unsigned int)cam_hw_cdm_enable_bl_done_irq(a1, 0, a3) )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            1,
            1,
            "cam_hw_cdm_wait_for_bl_fifo",
            788,
            "Disable BL done irq failed");
        if ( (debug_mdl & 1) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            1,
            4,
            "cam_hw_cdm_wait_for_bl_fifo",
            790,
            "CDM HW is ready for data");
        if ( (unsigned int)cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo(a1, a3, &v21) )
        {
LABEL_5:
          v13 = "Failed to read CDM pending BL's";
          v14 = 752;
          goto LABEL_6;
        }
        while ( 1 )
        {
          v18 = (unsigned int)v16[27];
          v17 = v21;
          v19 = (unsigned int)(v18 - v21);
          if ( (int)v18 - v21 < 0 )
          {
            done = 1;
            goto LABEL_15;
          }
          done = v19 - 1;
          if ( (_DWORD)v19 != 1 )
            goto LABEL_11;
          *v16 = 0;
          v20 = cam_hw_cdm_enable_bl_done_irq(a1, 1, a3);
          if ( v20 )
            break;
          if ( cam_common_wait_for_completion_timeout((__int64)v16) <= 0 )
            goto LABEL_36;
          if ( (unsigned int)cam_hw_cdm_enable_bl_done_irq(a1, 0, a3) )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              1,
              1,
              "cam_hw_cdm_wait_for_bl_fifo",
              788,
              "Disable BL done irq failed");
          if ( (debug_mdl & 1) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              1,
              4,
              "cam_hw_cdm_wait_for_bl_fifo",
              790,
              "CDM HW is ready for data");
          if ( (unsigned int)cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo(a1, a3, &v21) )
            goto LABEL_5;
        }
        done = v20;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_wait_for_bl_fifo",
        769,
        "Enable BL done irq failed");
      goto LABEL_8;
    }
LABEL_11:
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      v4 = "BL slot available_cnt=%d requested=%d";
      v5 = 4;
      v6 = 794;
      v7 = done;
      v8 = a2;
      goto LABEL_3;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return done;
}
