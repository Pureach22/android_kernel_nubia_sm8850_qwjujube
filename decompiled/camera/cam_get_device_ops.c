__int64 __fastcall cam_get_device_ops(unsigned int a1)
{
  __int64 v2; // x8
  const char *v3; // x5
  __int64 v4; // x4
  __int64 v5; // x19

  raw_spin_lock_bh(&hdl_tbl_lock);
  if ( hdl_tbl )
  {
    v2 = hdl_tbl + 40LL * (unsigned __int8)a1;
    if ( *(_DWORD *)(v2 + 12) == 1 )
    {
      if ( ((a1 >> 8) & 0xF) - 4 > 0xFFFFFFFC )
      {
        if ( *(_DWORD *)(v2 + 4) == a1 )
        {
          v5 = *(_QWORD *)(v2 + 24);
          goto LABEL_8;
        }
        v3 = "Invalid hdl";
        v4 = 400;
      }
      else
      {
        v3 = "Invalid type";
        v4 = 395;
      }
    }
    else
    {
      v3 = "Invalid state";
      v4 = 389;
    }
  }
  else
  {
    v3 = "Hdl tbl is NULL";
    v4 = 378;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    16,
    1,
    "cam_get_device_ops",
    v4,
    v3);
  v5 = 0;
LABEL_8:
  raw_spin_unlock_bh(&hdl_tbl_lock);
  return v5;
}
