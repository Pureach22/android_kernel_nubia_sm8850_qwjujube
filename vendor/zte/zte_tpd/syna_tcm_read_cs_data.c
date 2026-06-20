__int64 __fastcall syna_tcm_read_cs_data(__int64 a1, void *a2, __int64 a3, int a4, int a5)
{
  unsigned int v6; // w20
  unsigned int v10; // w25
  unsigned int v11; // w22
  unsigned int v12; // w0
  __int64 v13; // x2
  unsigned int v14; // w9
  unsigned int flash_boot_cs_config; // w0
  unsigned int v16; // w20
  void *v17; // x19
  __int64 v18; // x0
  __int64 v19; // x2
  __int64 v20; // x19
  __int64 v21; // x0
  __int64 v22; // x2
  __int64 result; // x0
  void *v24; // x0
  void *v25; // x0
  void *src; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v27; // [xsp+10h] [xbp-E0h]
  _QWORD v28[6]; // [xsp+18h] [xbp-D8h] BYREF
  __int64 v29; // [xsp+48h] [xbp-A8h]
  __int64 v30; // [xsp+50h] [xbp-A0h] BYREF
  __int64 v31; // [xsp+58h] [xbp-98h]
  __int64 v32; // [xsp+60h] [xbp-90h]
  __int64 v33; // [xsp+68h] [xbp-88h]
  __int64 v34; // [xsp+70h] [xbp-80h]
  __int64 v35; // [xsp+78h] [xbp-78h]
  __int64 v36; // [xsp+80h] [xbp-70h]
  __int64 v37; // [xsp+88h] [xbp-68h]
  __int64 v38; // [xsp+90h] [xbp-60h]
  __int64 v39; // [xsp+98h] [xbp-58h]
  __int64 v40; // [xsp+A0h] [xbp-50h] BYREF
  __int64 v41; // [xsp+A8h] [xbp-48h]
  __int64 v42; // [xsp+B0h] [xbp-40h]
  __int64 v43; // [xsp+B8h] [xbp-38h]
  __int64 v44; // [xsp+C0h] [xbp-30h]
  __int64 v45; // [xsp+C8h] [xbp-28h]
  __int64 v46; // [xsp+D0h] [xbp-20h]
  __int64 v47; // [xsp+D8h] [xbp-18h]
  __int64 v48; // [xsp+E0h] [xbp-10h]
  __int64 v49; // [xsp+E8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  memset(v28, 0, sizeof(v28));
  src = nullptr;
  v27 = 0;
  if ( !a1 )
  {
    v24 = unk_3365A;
LABEL_31:
    printk(v24, "syna_tcm_read_cs_data", a3);
    result = 4294967055LL;
    goto LABEL_28;
  }
  if ( !a2 || (v6 = a3) == 0 )
  {
    v24 = unk_34A93;
    goto LABEL_31;
  }
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v30 = 0;
  if ( a5 )
  {
    v10 = *(_DWORD *)(a1 + 524);
    v11 = *(_DWORD *)(a1 + 488);
  }
  else
  {
    v11 = 0;
    v10 = 0;
  }
  v38 = 0;
  v39 = 0;
  _mutex_init(&v40, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  LOBYTE(v29) = 0;
  src = nullptr;
  v27 = 0;
  _mutex_init(v28, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  v12 = syna_tcm_set_up_flash_access(a1, (__int64)&v30, v10, v11);
  if ( (v12 & 0x80000000) != 0 )
  {
    v16 = v12;
    v25 = unk_32BC8;
LABEL_36:
    printk(v25, "syna_tcm_read_cs_data", v13);
    goto LABEL_15;
  }
  if ( HIDWORD(v35) )
    v14 = (v6 + HIDWORD(v35) - 1) / HIDWORD(v35);
  else
    v14 = 0;
  flash_boot_cs_config = syna_tcm_read_flash_boot_cs_config(
                           a1,
                           (__int64)&v30,
                           (__int64)&src,
                           v14 * HIDWORD(v35),
                           a4,
                           a5);
  if ( (flash_boot_cs_config & 0x80000000) != 0 )
  {
    v16 = flash_boot_cs_config;
    v25 = unk_33953;
    goto LABEL_36;
  }
  if ( !src )
  {
LABEL_38:
    printk(unk_3D41E, "syna_tcm_read_cs_data", v13);
    v16 = -22;
    goto LABEL_15;
  }
  if ( (unsigned int)v27 < v6 )
  {
    printk(unk_3944E, "syna_pal_mem_cpy", (unsigned int)v27);
    goto LABEL_38;
  }
  memcpy(a2, src, v6);
  v16 = 0;
LABEL_15:
  if ( *(_BYTE *)(a1 + 9) == 11 )
    syna_tcm_switch_fw_mode(a1, 1, v11);
  if ( (_BYTE)v29 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v29);
  v17 = src;
  v18 = syna_request_managed_device();
  if ( v18 )
  {
    if ( v17 )
      devm_kfree(v18, v17);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v19);
  }
  v27 = 0;
  LOBYTE(v29) = 0;
  if ( (_BYTE)v46 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v46);
  v20 = v38;
  v21 = syna_request_managed_device();
  if ( v21 )
  {
    if ( v20 )
      devm_kfree(v21, v20);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v22);
  }
  result = v16;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
