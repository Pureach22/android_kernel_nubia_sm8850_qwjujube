__int64 __fastcall cam_get_priv(unsigned int a1, int a2)
{
  __int64 v4; // x8
  unsigned int v5; // w19
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x0
  int v9; // w0
  const char *v10; // x5
  __int64 v11; // x0
  __int64 v12; // x4
  __int64 v13; // x6
  int v14; // w0

  raw_spin_lock_bh(&hdl_tbl_lock);
  if ( !hdl_tbl )
  {
    if ( (unsigned int)__ratelimit(&cam_get_priv__rs, "cam_get_priv") )
      v7 = 3;
    else
      v7 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v7,
      16,
      1,
      "cam_get_priv",
      304,
      "Hdl tbl is NULL");
    goto LABEL_23;
  }
  v4 = hdl_tbl + 40LL * (unsigned __int8)a1;
  if ( *(_DWORD *)(v4 + 4) != a1 )
  {
    if ( (unsigned int)__ratelimit(&cam_get_priv__rs_17, "cam_get_priv") )
      v8 = 3;
    else
      v8 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
      v8,
      16,
      1,
      "cam_get_priv",
      316,
      "Invalid hdl [%d] [%d]",
      a1,
      *(unsigned int *)(hdl_tbl + 40LL * (unsigned __int8)a1 + 4));
    goto LABEL_23;
  }
  if ( *(_DWORD *)(v4 + 12) != 1 )
  {
    v9 = __ratelimit(&cam_get_priv__rs_19, "cam_get_priv");
    v10 = "Invalid state:%d";
    if ( v9 )
      v11 = 3;
    else
      v11 = 2;
    v12 = 322;
    v13 = *(unsigned int *)(hdl_tbl + 40LL * (unsigned __int8)a1 + 12);
    goto LABEL_22;
  }
  v5 = (a1 >> 8) & 0xF;
  if ( v5 != a2 )
  {
    v14 = __ratelimit(&cam_get_priv__rs_20, "cam_get_priv");
    v10 = "Invalid type:%d";
    if ( v14 )
      v11 = 3;
    else
      v11 = 2;
    v12 = 328;
    v13 = v5;
LABEL_22:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      v11,
      16,
      1,
      "cam_get_priv",
      v12,
      v10,
      v13);
LABEL_23:
    v6 = 0;
    goto LABEL_24;
  }
  v6 = *(_QWORD *)(v4 + 32);
LABEL_24:
  raw_spin_unlock_bh(&hdl_tbl_lock);
  return v6;
}
