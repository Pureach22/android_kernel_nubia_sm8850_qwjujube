__int64 __fastcall syna_tcm_erase_mtp_data(__int64 a1, int a2, __int64 a3)
{
  unsigned int v4; // w23
  unsigned int v5; // w20
  unsigned int v6; // w0
  __int64 v7; // x2
  __int64 v8; // x2
  unsigned int v9; // w8
  unsigned int v10; // w21
  unsigned int v11; // w22
  __int64 v12; // x3
  __int64 v13; // x2
  __int64 v14; // x5
  _DWORD *v15; // x8
  unsigned int v16; // w0
  unsigned int v17; // w23
  __int64 v18; // x19
  __int64 v19; // x0
  __int64 v20; // x2
  __int64 result; // x0
  void *v22; // x0
  unsigned int v23; // w23
  unsigned int v24; // w24
  unsigned int v25; // w23
  unsigned int v26; // w24
  int v27; // [xsp+Ch] [xbp-A4h] BYREF
  _QWORD v28[4]; // [xsp+10h] [xbp-A0h] BYREF
  unsigned __int8 *v29; // [xsp+30h] [xbp-80h]
  __int64 v30; // [xsp+38h] [xbp-78h]
  __int64 v31; // [xsp+40h] [xbp-70h]
  __int64 v32; // [xsp+48h] [xbp-68h]
  __int64 v33; // [xsp+50h] [xbp-60h]
  __int64 v34; // [xsp+58h] [xbp-58h]
  _QWORD v35[6]; // [xsp+60h] [xbp-50h] BYREF
  __int64 v36; // [xsp+90h] [xbp-20h]
  __int64 v37; // [xsp+98h] [xbp-18h]
  __int64 v38; // [xsp+A0h] [xbp-10h]
  __int64 v39; // [xsp+A8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    printk(unk_3365A, "syna_tcm_erase_mtp_data", a3);
    result = 4294967055LL;
    goto LABEL_26;
  }
  v37 = 0;
  v38 = 0;
  v36 = 0;
  memset(v35, 0, sizeof(v35));
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = nullptr;
  v30 = 0;
  memset(v28, 0, sizeof(v28));
  if ( a2 )
  {
    v4 = *(_DWORD *)(a1 + 524);
    v5 = *(_DWORD *)(a1 + 488);
  }
  else
  {
    v5 = 0;
    v4 = 0;
  }
  v33 = 0;
  v34 = 0;
  _mutex_init(v35, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  v6 = syna_tcm_set_up_flash_access(a1, (__int64)v28, v4, v5);
  if ( (v6 & 0x80000000) != 0 )
  {
    v17 = v6;
    v22 = unk_32BC8;
LABEL_34:
    printk(v22, "syna_tcm_erase_mtp_data", v7);
    goto LABEL_18;
  }
  v8 = *v29;
  if ( (unsigned int)v8 <= 2 )
  {
    v17 = v6;
    printk(unk_34475, "syna_tcm_erase_mtp_data", v8);
    goto LABEL_18;
  }
  v9 = v29[21];
  v27 = 0;
  v10 = HIDWORD(v32) / (unsigned int)v30;
  v11 = ((unsigned int)v30 + (_DWORD)v30 * v9 - 1) / (unsigned int)v30;
  if ( (v11 | (HIDWORD(v32) / (unsigned int)v30)) >= 0x100 )
  {
    v9 = v10 >> 8;
    v12 = 4;
    HIWORD(v27) = v11;
  }
  else
  {
    v12 = 2;
    LOBYTE(v9) = ((unsigned int)v30 + (_DWORD)v30 * v9 - 1) / (unsigned int)v30;
  }
  v13 = *(unsigned __int8 *)(a1 + 9);
  v14 = v11 * v4;
  LOBYTE(v27) = HIDWORD(v32) / (unsigned int)v30;
  BYTE1(v27) = v9;
  if ( (_DWORD)v13 == 11 )
  {
    if ( (_DWORD)v14 )
      goto LABEL_14;
  }
  else
  {
    v23 = v12;
    v24 = v14;
    printk(unk_37A54, "syna_tcm_reflash_send_command", v13);
    v14 = v24;
    v12 = v23;
    if ( v24 )
      goto LABEL_14;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
  {
    v14 = 0;
  }
  else
  {
    v25 = *(_DWORD *)(a1 + 524);
    v26 = v12;
    printk(unk_36818, "syna_tcm_reflash_send_command", v25);
    v14 = v25;
    v12 = v26;
  }
LABEL_14:
  v15 = *(_DWORD **)(a1 + 920);
  if ( *(v15 - 1) != 606091918 )
    __break(0x8228u);
  v16 = ((__int64 (__fastcall *)(__int64, __int64, int *, __int64, _QWORD, __int64))v15)(a1, 17, &v27, v12, 0, v14);
  if ( (v16 & 0x80000000) != 0 )
  {
    v17 = v16;
    printk(unk_39AB7, "syna_tcm_reflash_send_command", 17);
    printk(unk_36439, "syna_tcm_erase_flash", v10);
    v22 = unk_38FD4;
    goto LABEL_34;
  }
  v17 = 0;
LABEL_18:
  if ( *(_BYTE *)(a1 + 9) == 11 )
    syna_tcm_switch_fw_mode(a1, 1, v5);
  if ( (_BYTE)v36 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v36);
  v18 = v33;
  v19 = syna_request_managed_device();
  if ( v19 )
  {
    if ( v18 )
      devm_kfree(v19, v18);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v20);
  }
  result = v17;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
