__int64 __fastcall cam_icp_mgr_proc_boot(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int64 v5; // x1
  __int64 v6; // x8
  char v7; // w9
  unsigned int v8; // w21
  __int64 v9; // x11
  __int64 v10; // x12
  char v11; // w10
  __int64 (__fastcall *v12)(__int64, __int64, __int64 *, __int64); // x9
  __int64 v13; // x0
  unsigned int v14; // w0
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v19)(); // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v5 = 17;
  else
    v5 = 1;
  v22 = v3;
  v6 = *(_QWORD *)(a1 + 80);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = nullptr;
  v16 = 0;
  v17 = 0;
  if ( v6 )
  {
    if ( (*(_BYTE *)(a1 + 44232) & 1) != 0 )
    {
      v7 = 1;
    }
    else
    {
      v9 = *(_QWORD *)(a1 + 368);
      v7 = 0;
      v10 = *(_QWORD *)(a1 + 392);
      LODWORD(v16) = *(_DWORD *)(a1 + 376);
      v17 = v9;
      v18 = v10;
    }
    BYTE1(v21) = v7;
    v11 = *(_BYTE *)(a1 + 44233);
    v19 = cam_icp_hw_mgr_cb;
    v20 = a1;
    v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v6 + 88);
    v13 = *(_QWORD *)(v6 + 112);
    LOBYTE(v21) = v11;
    if ( *((_DWORD *)v12 - 1) != -1055839300 )
      __break(0x8229u);
    v14 = v12(v13, v5, &v16, 48);
    if ( v14 )
    {
      v8 = v14;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_proc_boot",
        4657,
        "[%s] processor boot failed rc=%d",
        (const char *)(a1 + 112),
        v14);
    }
    else if ( (a2 & 1) != 0 )
    {
      v8 = -22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_proc_boot",
        4665,
        "[%s] Failed in sending icp boot up command to PVM rc %d",
        (const char *)(a1 + 112),
        -22);
    }
    else
    {
      v8 = 0;
      *(_BYTE *)(a1 + 44229) = 1;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_proc_boot",
      4636,
      "[%s] invalid device interface",
      (const char *)(a1 + 112));
    v8 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
