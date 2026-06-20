__int64 __fastcall hfi_send_system_cmd(unsigned int a1, int a2, __int64 a3)
{
  __int64 v4; // x8
  unsigned int v5; // w20
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x8
  __int64 v10; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v11[4]; // [xsp+10h] [xbp-20h]

  v11[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v5 = -22;
LABEL_10:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_send_system_cmd",
      829,
      "Failed to get hfi info rc: %d for hdl: %d",
      v5,
      a1);
    goto LABEL_30;
  }
  v4 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v5 = -19;
    goto LABEL_10;
  }
  v5 = 0;
  if ( a2 <= 65540 )
  {
    if ( a2 <= 65538 )
    {
      if ( a2 == 65537 )
      {
        v6 = 0x100000008LL;
        goto LABEL_21;
      }
      if ( a2 == 65538 )
      {
        v6 = 0x200000008LL;
LABEL_21:
        v8 = v6 & 0xFFFFFFFFFFFFLL | 0x1000000000000LL;
LABEL_28:
        v10 = v8;
        goto LABEL_29;
      }
      goto LABEL_19;
    }
    if ( a2 != 65539 )
      goto LABEL_30;
    if ( (_DWORD)a3 != 1 )
      goto LABEL_26;
    v10 = 0x1000300000010LL;
    v11[0] = 0x100000001LL;
LABEL_29:
    v5 = hfi_write_cmd(a1, (unsigned int *)&v10);
    goto LABEL_30;
  }
  if ( a2 <= 16842759 )
  {
    if ( a2 == 65541 )
    {
      v7 = 65541;
      goto LABEL_23;
    }
    if ( a2 == 65542 )
    {
      v7 = 65542;
LABEL_23:
      LODWORD(v10) = 16;
      HIDWORD(v10) = v7;
      v11[0] = a3;
      goto LABEL_29;
    }
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_send_system_cmd",
      896,
      "[%s] command not supported: %u client handle: %d",
      v4 + 1004);
LABEL_26:
    v5 = 0;
    goto LABEL_30;
  }
  if ( a2 == 16842760 )
  {
    *(_QWORD *)((char *)&v11[1] + 4) = 0;
    LODWORD(v11[0]) = a3;
    v8 = 0x10100080000001CLL;
    *(_QWORD *)((char *)v11 + 4) = 0;
    goto LABEL_28;
  }
  if ( a2 != 16842766 )
    goto LABEL_19;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v5;
}
