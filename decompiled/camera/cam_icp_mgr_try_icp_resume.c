__int64 __fastcall cam_icp_mgr_try_icp_resume(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  unsigned int v6; // w22
  __int64 v7; // x26
  __int64 v8; // x8
  __int64 v9; // x1
  __int64 v10; // x8
  char v11; // w10
  _DWORD *v12; // x11
  __int64 v13; // x0
  const char *v14; // x6
  unsigned int v15; // w19
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a1 + 40960;
  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 44080) )
  {
    result = 0;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 64) )
    {
      v6 = 0;
      do
      {
        v7 = *(_QWORD *)(a1 + 56) + 584LL * (int)v6;
        *(_DWORD *)(v7 + 24) = *(_QWORD *)(v2 + 3200);
        v8 = *(_QWORD *)(v2 + 3200);
        *(_QWORD *)(v7 + 36) = 5;
        *(_QWORD *)(v7 + 48) = 1024;
        *(_QWORD *)(v7 + 56) = 1024;
        *(_DWORD *)(v7 + 28) = v8;
        memset((void *)(v7 + 72), 0, 0x1E0u);
        *(_DWORD *)(v7 + 560) = 0;
        ++v6;
      }
      while ( v6 < *(_DWORD *)(a1 + 64) );
    }
    *(_QWORD *)(v2 + 3144) = *(_QWORD *)(v2 + 3200);
    result = cam_icp_mgr_icp_resume(a1, a2);
    if ( !(_DWORD)result )
    {
      v9 = *(_QWORD *)(v2 + 3160);
      if ( v9 )
        hfi_set_debug_level(*(unsigned int *)(a1 + 156), v9, *(unsigned int *)(v2 + 3168));
      hfi_set_fw_dump_levels(*(unsigned int *)(a1 + 156), *(unsigned int *)(v2 + 3176), *(unsigned int *)(v2 + 3184));
      v10 = *(_QWORD *)(a1 + 80);
      v16[0] = 0;
      if ( v10 )
      {
        v11 = *(_BYTE *)(v2 + 3274);
        v12 = *(_DWORD **)(v10 + 88);
        v13 = *(_QWORD *)(v10 + 112);
        LODWORD(v16[0]) = *(_DWORD *)(v2 + 3220);
        BYTE4(v16[0]) = v11;
        if ( *(v12 - 1) != -1055839300 )
          __break(0x822Bu);
        result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v12)(v13, 10, v16, 8);
        if ( (_DWORD)result )
        {
          v14 = (const char *)(a1 + 112);
          v15 = result;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_send_ubwc_cfg",
            240,
            "[%s] Fail to submit UBWC config",
            v14);
          result = v15;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_send_ubwc_cfg",
          230,
          "[%s] ICP device interface is NULL",
          (const char *)(a1 + 112));
        result = 4294967274LL;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
