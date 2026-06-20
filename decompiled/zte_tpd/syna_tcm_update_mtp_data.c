__int64 __fastcall syna_tcm_update_mtp_data(__int64 a1, const void *a2, __int64 a3, int a4, unsigned int a5)
{
  unsigned int v6; // w22
  unsigned int v10; // w24
  unsigned int v11; // w20
  __int64 v12; // x2
  unsigned int v13; // w24
  unsigned int v14; // w26
  unsigned int v15; // w9
  __int64 v16; // x25
  __int64 v17; // x0
  __int64 v18; // x2
  void *v19; // x0
  __int64 v20; // x2
  __int64 v21; // x24
  int v22; // w0
  __int64 v23; // x19
  __int64 v24; // x0
  __int64 v25; // x2
  void *v27; // x0
  void *v28; // x0
  void *v29; // x0
  __int64 v30; // x0
  _QWORD v31[4]; // [xsp+0h] [xbp-A0h] BYREF
  unsigned __int8 *v32; // [xsp+20h] [xbp-80h]
  __int64 v33; // [xsp+28h] [xbp-78h]
  __int64 v34; // [xsp+30h] [xbp-70h]
  __int64 v35; // [xsp+38h] [xbp-68h]
  __int64 v36; // [xsp+40h] [xbp-60h]
  __int64 v37; // [xsp+48h] [xbp-58h]
  _QWORD v38[6]; // [xsp+50h] [xbp-50h] BYREF
  __int64 v39; // [xsp+80h] [xbp-20h]
  __int64 v40; // [xsp+88h] [xbp-18h]
  __int64 v41; // [xsp+90h] [xbp-10h]
  __int64 v42; // [xsp+98h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  v41 = 0;
  v39 = 0;
  v37 = 0;
  memset(v38, 0, sizeof(v38));
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v32 = nullptr;
  memset(v31, 0, sizeof(v31));
  if ( !a1 )
  {
    v27 = &unk_3365A;
LABEL_32:
    printk(v27, "syna_tcm_update_mtp_data", a3);
    v13 = -241;
LABEL_29:
    _ReadStatusReg(SP_EL0);
    return v13;
  }
  if ( !a2 || (v6 = a3) == 0 )
  {
    v27 = &unk_372B2;
    goto LABEL_32;
  }
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
  v36 = 0;
  v37 = 0;
  _mutex_init(v38, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  *(_DWORD *)(a1 + 904) = 1;
  v13 = syna_tcm_set_up_flash_access(a1, (__int64)v31, v10, v11);
  if ( (v13 & 0x80000000) != 0 )
  {
    v28 = &unk_32BC8;
LABEL_37:
    printk(v28, "syna_tcm_update_mtp_data", v12);
    goto LABEL_22;
  }
  v12 = *v32;
  if ( (unsigned int)v12 <= 2 )
  {
    printk(&unk_34475, "syna_tcm_update_mtp_data", v12);
LABEL_22:
    if ( *(_BYTE *)(a1 + 9) == 11 )
      syna_tcm_switch_fw_mode(a1, 1, v11);
    *(_DWORD *)(a1 + 904) = 0;
    if ( (_BYTE)v39 )
      printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v39);
    v23 = v36;
    v24 = syna_request_managed_device();
    if ( v24 )
    {
      if ( v23 )
        devm_kfree(v24, v23);
    }
    else
    {
      printk(&unk_3BE43, "syna_pal_mem_free", v25);
    }
    goto LABEL_29;
  }
  if ( !HIDWORD(v33) )
  {
    v28 = &unk_34AB2;
    goto LABEL_37;
  }
  if ( a4 )
    v14 = (unsigned int)(a4 + HIDWORD(v33) - 1) / HIDWORD(v33) * HIDWORD(v33);
  else
    v14 = 0;
  v15 = (v6 + HIDWORD(v33) - 1) / HIDWORD(v33);
  v16 = v15 * HIDWORD(v33);
  HIDWORD(v40) = v15 * HIDWORD(v33);
  v17 = syna_request_managed_device();
  if ( !v17 )
  {
    v29 = &unk_3BE43;
LABEL_40:
    printk(v29, "syna_pal_mem_alloc", v18);
    goto LABEL_41;
  }
  if ( (int)v16 < 1 )
  {
    v29 = &unk_38286;
    goto LABEL_40;
  }
  v19 = (void *)devm_kmalloc(v17, v16, 3520);
  if ( !v19 )
  {
LABEL_41:
    printk(&unk_32BC8, "syna_tcm_update_mtp_data", v20);
    v13 = -243;
    goto LABEL_22;
  }
  v21 = (__int64)v19;
  if ( HIDWORD(v40) < v6 )
  {
    printk(&unk_3944E, "syna_pal_mem_cpy", v6);
LABEL_19:
    v22 = syna_tcm_write_flash(a1, (__int64)v31, HIDWORD(v35) + v14, v21, HIDWORD(v40), a5);
    if ( v22 >= 0 )
      v13 = HIDWORD(v40);
    else
      v13 = v22;
    goto LABEL_22;
  }
  if ( (unsigned int)v16 >= v6 )
  {
    memcpy(v19, a2, v6);
    goto LABEL_19;
  }
  v30 = _fortify_panic(17, v16, v6);
  return syna_pal_mem_alloc(v30);
}
