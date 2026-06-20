__int64 __fastcall cam_handle_validate(int a1, int a2)
{
  int *v4; // x8
  int v5; // w6
  int v6; // w6
  int v7; // w8
  unsigned int v9; // w19

  raw_spin_lock_bh(&hdl_tbl_lock);
  if ( hdl_tbl )
  {
    v4 = (int *)(hdl_tbl + 40LL * (unsigned __int8)a2);
    v5 = v4[3];
    if ( v5 == 1 )
    {
      v6 = *v4;
      v7 = v4[1];
      if ( v6 == a1 && v7 == a2 )
      {
        v9 = 0;
        goto LABEL_11;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "cam_handle_validate",
        118,
        "Exp ses_hdl: 0x%x ses_hdl: 0x%x Exp hdl: 0x%x hdl: 0x%x",
        v6,
        a1,
        v7,
        a2);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "cam_handle_validate",
        109,
        "Invalid state:%d",
        v5);
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_handle_validate",
      96,
      "Hdl tbl is NULL");
  }
  v9 = -22;
LABEL_11:
  raw_spin_unlock_bh(&hdl_tbl_lock);
  return v9;
}
