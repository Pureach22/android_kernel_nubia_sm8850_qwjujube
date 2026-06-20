__int64 __fastcall syna_tcm_update_cs_config(__int64 a1, char *a2, __int64 a3, int a4, unsigned int a5)
{
  char *v5; // x22
  unsigned int v6; // w23
  unsigned int v10; // w25
  unsigned int v11; // w21
  unsigned int v12; // w0
  __int64 v13; // x2
  unsigned int flash_boot_config; // w0
  int v15; // w11
  unsigned int v16; // w8
  unsigned int v17; // w9
  unsigned int v18; // w12
  __int64 v19; // x13
  unsigned int v20; // w10
  __int64 v21; // x8
  char v22; // t1
  int v23; // w0
  unsigned int v24; // w20
  void *v25; // x0
  __int64 result; // x0
  void *v27; // x0
  __int64 v28; // x19
  __int64 v29; // x0
  __int64 v30; // x2
  __int64 v31; // x19
  __int64 v32; // x0
  __int64 v33; // x2
  __int64 v34; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v35; // [xsp+10h] [xbp-E0h]
  _QWORD v36[6]; // [xsp+18h] [xbp-D8h] BYREF
  __int64 v37; // [xsp+48h] [xbp-A8h]
  __int64 v38; // [xsp+50h] [xbp-A0h] BYREF
  __int64 v39; // [xsp+58h] [xbp-98h]
  __int64 v40; // [xsp+60h] [xbp-90h]
  __int64 v41; // [xsp+68h] [xbp-88h]
  __int64 v42; // [xsp+70h] [xbp-80h]
  __int64 v43; // [xsp+78h] [xbp-78h]
  __int64 v44; // [xsp+80h] [xbp-70h]
  __int64 v45; // [xsp+88h] [xbp-68h]
  __int64 v46; // [xsp+90h] [xbp-60h]
  __int64 v47; // [xsp+98h] [xbp-58h]
  __int64 v48; // [xsp+A0h] [xbp-50h] BYREF
  __int64 v49; // [xsp+A8h] [xbp-48h]
  __int64 v50; // [xsp+B0h] [xbp-40h]
  __int64 v51; // [xsp+B8h] [xbp-38h]
  __int64 v52; // [xsp+C0h] [xbp-30h]
  __int64 v53; // [xsp+C8h] [xbp-28h]
  __int64 v54; // [xsp+D0h] [xbp-20h]
  __int64 v55; // [xsp+D8h] [xbp-18h]
  __int64 v56; // [xsp+E0h] [xbp-10h]
  __int64 v57; // [xsp+E8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
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
  memset(v36, 0, sizeof(v36));
  v34 = 0;
  v35 = 0;
  if ( !a1 )
  {
    v25 = unk_3365A;
LABEL_33:
    printk(v25, "syna_tcm_update_cs_config", a3);
    result = 4294967055LL;
    goto LABEL_53;
  }
  v5 = a2;
  if ( !a2 || (v6 = a3) == 0 )
  {
    v25 = unk_34A93;
    goto LABEL_33;
  }
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
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
  v38 = 0;
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
  v46 = 0;
  v47 = 0;
  _mutex_init(&v48, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  LOBYTE(v37) = 0;
  v34 = 0;
  v35 = 0;
  _mutex_init(v36, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_8);
  *(_DWORD *)(a1 + 904) = 1;
  v12 = syna_tcm_set_up_flash_access(a1, (__int64)&v38, v10, v11);
  if ( (v12 & 0x80000000) != 0 )
  {
    v24 = v12;
    v27 = unk_32BC8;
  }
  else
  {
    flash_boot_config = syna_tcm_read_flash_boot_config(a1, (__int64)&v38, (__int64)&v34, v10);
    if ( (flash_boot_config & 0x80000000) != 0 )
    {
      v24 = flash_boot_config;
      v27 = unk_3728A;
    }
    else
    {
      v15 = 128;
      v16 = HIDWORD(v35) - 136;
      while ( (*(char *)(v34 + (unsigned int)(HIDWORD(v35) + v15 - 135)) & 0x80000000) == 0
           || *(char *)(v34 + (unsigned int)(HIDWORD(v35) + v15 - 143)) < 0 )
      {
        v15 -= 8;
        if ( !v15 )
          goto LABEL_14;
      }
      v16 = HIDWORD(v35) + v15 - 136;
LABEL_14:
      if ( v16 < v6 )
      {
        v24 = flash_boot_config;
        v27 = unk_3BAC0;
      }
      else if ( HIDWORD(v43) )
      {
        if ( a4 )
          v17 = (unsigned int)(a4 + HIDWORD(v43) - 1) / HIDWORD(v43) * HIDWORD(v43);
        else
          v17 = 0;
        do
        {
          v18 = *(unsigned __int8 *)(v34 + v17);
          if ( !*(_BYTE *)(v34 + v17) )
          {
            v19 = HIDWORD(v43);
            while ( !*(_BYTE *)(v34 + v17 + v18) )
            {
              --v19;
              ++v18;
              if ( !v19 )
                goto LABEL_25;
            }
            if ( HIDWORD(v43) <= v18 )
              break;
          }
          v17 += HIDWORD(v43);
        }
        while ( v17 < v16 );
LABEL_25:
        if ( v17 <= v16 )
        {
          v20 = v17;
          HIDWORD(v55) = (v6 + HIDWORD(v43) - 1) / HIDWORD(v43) * HIDWORD(v43);
          v21 = v6;
          do
          {
            v22 = *v5++;
            --v21;
            *(_BYTE *)(v34 + v20++) = v22;
          }
          while ( v21 );
          v23 = syna_tcm_write_flash(a1, (__int64)&v38, (unsigned int)v45 + v17, v34 + v17, HIDWORD(v55), a5);
          if ( v23 >= 0 )
            v24 = HIDWORD(v55);
          else
            v24 = v23;
          goto LABEL_40;
        }
        v24 = flash_boot_config;
        v27 = unk_36D12;
      }
      else
      {
        v24 = flash_boot_config;
        v27 = unk_34AB2;
      }
    }
  }
  printk(v27, "syna_tcm_update_cs_config", v13);
LABEL_40:
  if ( *(_BYTE *)(a1 + 9) == 11 )
    syna_tcm_switch_fw_mode(a1, 1, v11);
  *(_DWORD *)(a1 + 904) = 0;
  if ( (_BYTE)v37 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v37);
  v28 = v34;
  v29 = syna_request_managed_device();
  if ( v29 )
  {
    if ( v28 )
      devm_kfree(v29, v28);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v30);
  }
  v35 = 0;
  LOBYTE(v37) = 0;
  if ( (_BYTE)v54 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v54);
  v31 = v46;
  v32 = syna_request_managed_device();
  if ( v32 )
  {
    if ( v31 )
      devm_kfree(v32, v31);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v33);
  }
  result = v24;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
