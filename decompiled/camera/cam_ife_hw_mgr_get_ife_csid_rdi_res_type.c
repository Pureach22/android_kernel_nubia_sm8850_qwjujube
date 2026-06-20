__int64 __fastcall cam_ife_hw_mgr_get_ife_csid_rdi_res_type(int a1)
{
  unsigned int v1; // w19
  int v2; // w10
  int v4; // w19

  v1 = 0;
  if ( a1 < 24576 )
  {
    if ( a1 > 12295 )
    {
      if ( a1 != 12296 )
      {
        if ( a1 != 12297 )
        {
          if ( a1 != 12327 )
            goto LABEL_23;
LABEL_11:
          v1 = 4;
          goto LABEL_19;
        }
LABEL_18:
        v1 = 3;
        goto LABEL_19;
      }
LABEL_17:
      v1 = 2;
      goto LABEL_19;
    }
    if ( a1 == 12294 )
      goto LABEL_19;
    v2 = 12295;
LABEL_15:
    if ( a1 == v2 )
    {
      v1 = 1;
      goto LABEL_19;
    }
    goto LABEL_23;
  }
  v2 = 24577;
  if ( a1 <= 24577 )
  {
    if ( a1 == 24576 )
      goto LABEL_19;
    goto LABEL_15;
  }
  switch ( a1 )
  {
    case 24578:
      goto LABEL_17;
    case 24579:
      goto LABEL_18;
    case 24580:
      goto LABEL_11;
  }
LABEL_23:
  v1 = 12;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v4 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_get_ife_csid_rdi_res_type",
      4747,
      "maximum rdi output type exceeded");
    a1 = v4;
    v1 = 12;
  }
LABEL_19:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_get_ife_csid_rdi_res_type",
      4752,
      "out_port: 0x%x path_id: 0x%x",
      a1,
      v1);
  return v1;
}
