__int64 __fastcall syna_tcm_do_fw_update_ex(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned __int8 a7)
{
  void *v7; // x0
  __int64 result; // x0
  unsigned int v15; // w23
  int v16; // w8
  __int64 v17; // x2
  int v18; // w9
  unsigned int v19; // w3
  int v20; // w8
  unsigned int v21; // w0
  __int64 v22; // x2
  unsigned int v23; // w20
  void *v24; // x0
  char v25; // w8
  unsigned int updated; // w0
  __int64 v27; // x2
  unsigned int v28; // w0
  __int64 v29; // x19
  __int64 v30; // x0
  __int64 v31; // x2
  _QWORD v32[2]; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v33; // [xsp+10h] [xbp-90h]
  _DWORD *v34; // [xsp+18h] [xbp-88h]
  __int64 v35; // [xsp+20h] [xbp-80h]
  __int64 v36; // [xsp+28h] [xbp-78h]
  __int64 v37; // [xsp+30h] [xbp-70h]
  __int64 v38; // [xsp+38h] [xbp-68h]
  __int64 v39; // [xsp+40h] [xbp-60h]
  __int64 v40; // [xsp+48h] [xbp-58h]
  _QWORD v41[6]; // [xsp+50h] [xbp-50h] BYREF
  __int64 v42; // [xsp+80h] [xbp-20h]
  __int64 v43; // [xsp+88h] [xbp-18h]
  __int64 v44; // [xsp+90h] [xbp-10h]
  __int64 v45; // [xsp+98h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v7 = &unk_3365A;
LABEL_6:
    printk(v7, "syna_tcm_do_fw_update_ex", a3);
    result = 4294967055LL;
    goto LABEL_7;
  }
  if ( !a2 || !*a2 )
  {
    v7 = &unk_37F8D;
    goto LABEL_6;
  }
  v43 = 0;
  v44 = 0;
  v42 = 0;
  v40 = 0;
  memset(v41, 0, sizeof(v41));
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = nullptr;
  v35 = 0;
  v32[1] = 0;
  v33 = 0;
  v32[0] = (unsigned int)a3;
  if ( a6 )
    v15 = *(_DWORD *)(a1 + 524);
  else
    v15 = 0;
  v39 = 0;
  v40 = 0;
  _mutex_init(v41, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  v16 = *a2;
  v34 = a2;
  LODWORD(v33) = v16;
  printk(&unk_33EB7, "syna_tcm_do_fw_update_ex", v17);
  *(_DWORD *)(a1 + 904) = 1;
  v18 = *(unsigned __int8 *)(a1 + 9);
  if ( v18 == 11 )
  {
    v19 = a6;
    v20 = LODWORD(v32[0]) | 9;
    LODWORD(v32[0]) = v20;
    if ( (v20 & 8) == 0 )
      goto LABEL_19;
LABEL_18:
    HIDWORD(v43) += v34[16];
    goto LABEL_19;
  }
  LOBYTE(v20) = v32[0];
  if ( v18 == 1 )
  {
    v19 = a6;
    if ( *(_WORD *)(a1 + 178) )
    {
      LOBYTE(v20) = LOBYTE(v32[0]) | 9;
      LODWORD(v32[0]) |= 9u;
    }
    if ( (v20 & 8) != 0 )
      goto LABEL_18;
  }
  else
  {
    v19 = a6;
    if ( (v32[0] & 8) != 0 )
      goto LABEL_18;
  }
LABEL_19:
  if ( (v20 & 1) != 0 )
    HIDWORD(v43) += v34[32];
  v21 = syna_tcm_set_up_flash_access(a1, (__int64)v32, v15, v19);
  if ( (v21 & 0x80000000) != 0 )
  {
    v23 = v21;
    v24 = &unk_32BC8;
  }
  else
  {
    v22 = *(unsigned __int8 *)(a1 + 9);
    if ( (_DWORD)v22 == 11 )
    {
      v25 = v32[0];
      if ( (v32[0] & 8) != 0 )
      {
        updated = syna_tcm_update_flash_block(a1, v32, v34 + 12, a4, a5, (unsigned __int8)v43 & a7 & 1);
        if ( (updated & 0x80000000) != 0 )
        {
          v23 = updated;
          v24 = &unk_32BF3;
          goto LABEL_23;
        }
        v25 = v32[0];
      }
      if ( (v25 & 1) != 0 )
      {
        v28 = syna_tcm_update_flash_block(a1, v32, v34 + 28, a4, a5, 0);
        if ( (v28 & 0x80000000) != 0 )
        {
          v23 = v28;
          v24 = &unk_38A6F;
          goto LABEL_23;
        }
      }
      printk(&unk_36395, "syna_tcm_do_fw_update_ex", v22);
    }
    else
    {
      printk(&unk_32176, "syna_tcm_do_fw_update_ex", v22);
    }
    v23 = syna_tcm_reset(a1, a6, v27);
    if ( (v23 & 0x80000000) == 0 )
      goto LABEL_37;
    v24 = &unk_39948;
  }
LABEL_23:
  printk(v24, "syna_tcm_do_fw_update_ex", v22);
LABEL_37:
  *(_DWORD *)(a1 + 904) = 0;
  if ( (_BYTE)v42 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v42);
  v29 = v39;
  v30 = syna_request_managed_device();
  if ( v30 )
  {
    if ( v29 )
      devm_kfree(v30, v29);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v31);
  }
  result = v23;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
