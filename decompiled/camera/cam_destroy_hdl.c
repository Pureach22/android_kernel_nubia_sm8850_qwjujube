__int64 __fastcall cam_destroy_hdl(unsigned int a1, int a2)
{
  __int64 v4; // x8
  __int64 v5; // x10
  int v6; // w6
  __int64 v7; // x11
  __int64 v8; // x9
  const char *v9; // x5
  __int64 v10; // x4
  unsigned int v11; // w19
  unsigned __int64 v19; // x10

  raw_spin_lock_bh(&hdl_tbl_lock);
  v4 = hdl_tbl;
  if ( !hdl_tbl )
  {
    v9 = "Hdl tbl is NULL";
    v10 = 421;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_destroy_hdl",
      v10,
      v9);
LABEL_9:
    v11 = -22;
    goto LABEL_10;
  }
  v5 = hdl_tbl + 40LL * (unsigned __int8)a1;
  if ( *(_DWORD *)(v5 + 12) != 1 )
  {
    v9 = "Invalid state";
    v10 = 432;
    goto LABEL_8;
  }
  v6 = (a1 >> 8) & 0xF;
  if ( v6 != a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_destroy_hdl",
      438,
      "Invalid type %d, %d",
      v6,
      a2);
    goto LABEL_9;
  }
  if ( *(_DWORD *)(v5 + 4) != a1 )
  {
    v9 = "Invalid hdl";
    v10 = 443;
    goto LABEL_8;
  }
  *(_DWORD *)(v5 + 12) = 0;
  v7 = v4 + 40LL * (unsigned __int8)a1;
  v8 = *(_QWORD *)(v4 + 10240);
  *(_QWORD *)(v7 + 24) = 0;
  *(_QWORD *)(v7 + 32) = 0;
  _X9 = (unsigned __int64 *)(v8 + 8LL * ((unsigned __int8)a1 >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v19 = __ldxr(_X9);
  while ( __stxr(v19 & ~(1LL << a1), _X9) );
  v11 = 0;
LABEL_10:
  raw_spin_unlock_bh(&hdl_tbl_lock);
  return v11;
}
