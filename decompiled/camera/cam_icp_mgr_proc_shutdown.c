__int64 __fastcall cam_icp_mgr_proc_shutdown(__int64 a1, char a2, char a3)
{
  __int64 v3; // x23
  _QWORD *v5; // x24
  unsigned int v6; // w22
  _DWORD *v9; // x8
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 v12; // x0
  __int64 result; // x0
  _DWORD *v14; // x8
  __int64 v15; // x0
  bool v16[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v3 = a1 + 40960;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  v5 = *(_QWORD **)(a1 + 80);
  if ( (a2 & 1) != 0 )
    v6 = 18;
  else
    v6 = 0;
  v16[0] = *(_DWORD *)(a1 + 44148) != 0;
  if ( v5 )
  {
    if ( (a3 & 1) == 0 )
    {
      v9 = (_DWORD *)v5[2];
      v10 = v5[14];
      if ( *(v9 - 1) != 1989616049 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _BYTE *, __int64))v9)(v10, v17, 1);
    }
    v11 = (_DWORD *)v5[11];
    v12 = v5[14];
    if ( *(v11 - 1) != -1055839300 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, bool *, __int64))v11)(v12, v6, v16, 1);
    if ( (a2 & 1) != 0 )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 256,
                 1,
                 "cam_icp_mgr_proc_shutdown",
                 4699,
                 "[%s] Failed in sending icp boot up command to PVM rc %d",
                 (const char *)(a1 + 112),
                 -22);
    if ( (a3 & 1) == 0 )
    {
      v14 = (_DWORD *)v5[3];
      v15 = v5[14];
      if ( *(v14 - 1) != 1989616049 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64))v14)(v15, v17, 1);
    }
    if ( *(_BYTE *)(v3 + 3275) == 1 )
      result = cam_sync_synx_core_recovery();
    *(_BYTE *)(v3 + 3269) = 0;
  }
  else
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_mgr_proc_shutdown",
               4685,
               "[%s] ICP device interface is NULL",
               (const char *)(a1 + 112));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
