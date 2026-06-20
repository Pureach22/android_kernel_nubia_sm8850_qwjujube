__int64 __fastcall hdcp2_app_load(__int64 a1)
{
  __int64 v2; // x8
  unsigned int started; // w0
  __int64 v4; // x9
  unsigned int v5; // w0
  __int64 v6; // x20
  unsigned int v7; // w0
  __int64 (__fastcall *v8)(); // x9
  int v9; // w8
  __int64 (__fastcall *v10)(); // x10
  unsigned int v11; // w0
  int v12; // w9
  __int64 result; // x0
  unsigned int v14; // w22
  void *v15; // x0
  unsigned int v16; // w19

  if ( (*(_BYTE *)(a1 + 48) & 1) != 0 )
  {
    printk(&unk_C6E6);
    return 0;
  }
  v2 = qseecom_handle_g;
  if ( !qseecom_handle_g )
  {
    started = qseecom_start_app(&qseecom_handle_g, *(_QWORD *)(a1 + 88), 4096);
    if ( started )
    {
      v16 = started;
      printk(&unk_C658);
      return v16;
    }
    v2 = qseecom_handle_g;
  }
  *(_QWORD *)(a1 + 56) = v2;
  v4 = hdcpsrm_qseecom_handle_g;
  if ( hdcpsrm_qseecom_handle_g )
  {
LABEL_8:
    *(_QWORD *)(a1 + 64) = v4;
    if ( v2 )
    {
      v6 = *(_QWORD *)(v2 + 8);
      *(_DWORD *)v6 = 4110;
      if ( (*(_BYTE *)(a1 + 48) & 1) != 0 )
      {
        printk(&unk_C130);
LABEL_15:
        v8 = hdcp2_app_init;
        v9 = hdcp2_app_started;
        if ( *(_BYTE *)(a1 + 76) )
        {
          v8 = hdcp2_app_init_legacy;
          v10 = hdcp2_app_tx_init_legacy;
        }
        else
        {
          v10 = hdcp2_app_tx_init;
        }
        *(_QWORD *)(a1 + 112) = v8;
        *(_QWORD *)(a1 + 120) = v10;
        if ( v9 )
          goto LABEL_23;
        if ( *((_DWORD *)v8 - 1) != 1649215283 )
          __break(0x8229u);
        v11 = ((__int64 (__fastcall *)(__int64))v8)(a1);
        if ( !v11 )
        {
          v9 = hdcp2_app_started;
LABEL_23:
          v12 = *(_DWORD *)(a1 + 48);
          result = 0;
          hdcp2_app_started = v9 + 1;
          *(_DWORD *)(a1 + 48) = v12 | 1;
          return result;
        }
        v14 = v11;
        v15 = &unk_C210;
        goto LABEL_32;
      }
      v7 = qseecom_send_command(*(_QWORD *)(a1 + 56), v6, 64, v6 + 64, 64);
      if ( (v7 & 0x80000000) == 0 && !*(_DWORD *)(v6 + 64) )
      {
        if ( !v7 )
        {
          if ( *(unsigned __int8 *)(v6 + 74) << 16 == 0x10000 )
            *(_BYTE *)(a1 + 76) = 1;
          goto LABEL_15;
        }
        v14 = v7;
LABEL_31:
        v15 = &unk_C7C0;
LABEL_32:
        printk(v15);
        if ( !hdcp2_app_started )
        {
          qseecom_shutdown_app(&hdcpsrm_qseecom_handle_g);
          hdcpsrm_qseecom_handle_g = 0;
        }
        *(_QWORD *)(a1 + 64) = 0;
        goto LABEL_35;
      }
      printk(&unk_C4E8);
    }
    else
    {
      printk(&unk_CC25);
    }
    v14 = -22;
    goto LABEL_31;
  }
  v5 = qseecom_start_app(&hdcpsrm_qseecom_handle_g, "hdcpsrm", 4096);
  if ( !v5 )
  {
    v2 = *(_QWORD *)(a1 + 56);
    v4 = hdcpsrm_qseecom_handle_g;
    goto LABEL_8;
  }
  v14 = v5;
  printk(&unk_C326);
LABEL_35:
  result = v14;
  if ( !hdcp2_app_started )
  {
    qseecom_shutdown_app(&qseecom_handle_g);
    result = v14;
    qseecom_handle_g = 0;
  }
  *(_QWORD *)(a1 + 56) = 0;
  return result;
}
