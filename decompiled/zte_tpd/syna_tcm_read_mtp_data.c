__int64 __fastcall syna_tcm_read_mtp_data(__int64 a1, void *a2, __int64 a3, int a4, int a5)
{
  unsigned int v6; // w20
  unsigned int v10; // w25
  unsigned int v11; // w21
  unsigned int v12; // w0
  __int64 v13; // x2
  __int64 v14; // x2
  unsigned int v15; // w9
  unsigned int flash_mtp_config; // w0
  unsigned int v17; // w20
  void *v18; // x19
  __int64 v19; // x0
  __int64 v20; // x2
  __int64 v21; // x19
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 result; // x0
  void *v25; // x0
  void *v26; // x0
  void *src; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v28; // [xsp+10h] [xbp-E0h]
  _QWORD v29[6]; // [xsp+18h] [xbp-D8h] BYREF
  __int64 v30; // [xsp+48h] [xbp-A8h]
  __int64 v31; // [xsp+50h] [xbp-A0h] BYREF
  __int64 v32; // [xsp+58h] [xbp-98h]
  __int64 v33; // [xsp+60h] [xbp-90h]
  __int64 v34; // [xsp+68h] [xbp-88h]
  unsigned __int8 *v35; // [xsp+70h] [xbp-80h]
  __int64 v36; // [xsp+78h] [xbp-78h]
  __int64 v37; // [xsp+80h] [xbp-70h]
  __int64 v38; // [xsp+88h] [xbp-68h]
  __int64 v39; // [xsp+90h] [xbp-60h]
  __int64 v40; // [xsp+98h] [xbp-58h]
  __int64 v41; // [xsp+A0h] [xbp-50h] BYREF
  __int64 v42; // [xsp+A8h] [xbp-48h]
  __int64 v43; // [xsp+B0h] [xbp-40h]
  __int64 v44; // [xsp+B8h] [xbp-38h]
  __int64 v45; // [xsp+C0h] [xbp-30h]
  __int64 v46; // [xsp+C8h] [xbp-28h]
  __int64 v47; // [xsp+D0h] [xbp-20h]
  __int64 v48; // [xsp+D8h] [xbp-18h]
  __int64 v49; // [xsp+E0h] [xbp-10h]
  __int64 v50; // [xsp+E8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  memset(v29, 0, sizeof(v29));
  src = nullptr;
  v28 = 0;
  if ( !a1 )
  {
    v25 = &unk_3365A;
LABEL_32:
    printk(v25, "syna_tcm_read_mtp_data", a3);
    result = 4294967055LL;
    goto LABEL_29;
  }
  if ( !a2 || (v6 = a3) == 0 )
  {
    v25 = &unk_372B2;
    goto LABEL_32;
  }
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = 0;
  v31 = 0;
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
  v39 = 0;
  v40 = 0;
  _mutex_init(&v41, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  LOBYTE(v30) = 0;
  src = nullptr;
  v28 = 0;
  _mutex_init(v29, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  v12 = syna_tcm_set_up_flash_access(a1, (__int64)&v31, v10, v11);
  if ( (v12 & 0x80000000) != 0 )
  {
    v17 = v12;
    v26 = &unk_32BC8;
LABEL_38:
    printk(v26, "syna_tcm_read_mtp_data", v13);
    goto LABEL_16;
  }
  v14 = *v35;
  if ( (unsigned int)v14 <= 2 )
  {
    v17 = v12;
    printk(&unk_34475, "syna_tcm_read_mtp_data", v14);
    goto LABEL_16;
  }
  if ( HIDWORD(v36) )
    v15 = (v6 + HIDWORD(v36) - 1) / HIDWORD(v36);
  else
    v15 = 0;
  flash_mtp_config = syna_tcm_read_flash_mtp_config(a1, (__int64)&v31, (__int64)&src, v15 * HIDWORD(v36), a4, a5);
  if ( (flash_mtp_config & 0x80000000) != 0 )
  {
    v17 = flash_mtp_config;
    v26 = &unk_38FA8;
    goto LABEL_38;
  }
  if ( !src )
  {
LABEL_40:
    printk(&unk_3D41E, "syna_tcm_read_mtp_data", v13);
    v17 = -22;
    goto LABEL_16;
  }
  if ( (unsigned int)v28 < v6 )
  {
    printk(&unk_3944E, "syna_pal_mem_cpy", (unsigned int)v28);
    goto LABEL_40;
  }
  memcpy(a2, src, v6);
  v17 = 0;
LABEL_16:
  if ( *(_BYTE *)(a1 + 9) == 11 )
    syna_tcm_switch_fw_mode(a1, 1, v11);
  if ( (_BYTE)v30 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v30);
  v18 = src;
  v19 = syna_request_managed_device();
  if ( v19 )
  {
    if ( v18 )
      devm_kfree(v19, v18);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v20);
  }
  v28 = 0;
  LOBYTE(v30) = 0;
  if ( (_BYTE)v47 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v47);
  v21 = v39;
  v22 = syna_request_managed_device();
  if ( v22 )
  {
    if ( v21 )
      devm_kfree(v22, v21);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v23);
  }
  result = v17;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
