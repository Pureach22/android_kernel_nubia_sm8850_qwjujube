__int64 __fastcall aw_cali_misc_ops(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v4; // x22
  int v6; // w8
  int v7; // w8
  unsigned __int64 v8; // x20
  _DWORD *v9; // x0
  size_t v10; // x23
  int f0; // w0
  int *v12; // x20
  unsigned int v13; // w21
  int v14; // w22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x0
  size_t v28; // x21
  unsigned __int64 v29; // x23
  __int64 *v30; // x8
  __int64 v31; // x1
  void *v32; // x0
  const char *v33; // x2
  __int64 *v34; // x8
  __int64 v35; // x1
  __int64 *v36; // x8
  __int64 v37; // x1
  __int64 *v38; // x8
  __int64 *v39; // x8
  __int64 v40; // x1
  unsigned __int8 v41; // w1
  __int64 *v42; // x8
  __int64 *v43; // x9
  __int64 v44; // x1
  __int64 *v45; // x8
  __int64 v46; // x1
  unsigned __int64 v47; // x24
  __int64 v48; // x25
  __int64 v50; // [xsp+8h] [xbp-28h] BYREF
  __int64 v51; // [xsp+10h] [xbp-20h]
  int v52[2]; // [xsp+18h] [xbp-18h]
  __int64 v53; // [xsp+20h] [xbp-10h]
  __int64 v54; // [xsp+28h] [xbp-8h]

  LODWORD(v4) = a2;
  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 <= -1073192688 )
  {
    if ( (unsigned int)(a2 + 1073454844) > 0xB )
      goto LABEL_5;
    v6 = 1 << (a2 - 4);
    if ( (v6 & 0xC15) != 0 )
      goto LABEL_25;
    if ( (v6 & 0x2A) == 0 )
    {
LABEL_5:
      v7 = -1073651445;
      goto LABEL_24;
    }
LABEL_16:
    v8 = HIWORD(a2) & 0x3FFF;
    v9 = (_DWORD *)_kmalloc_noprof(v8, 3520);
    v10 = (size_t)v9;
    if ( !v9 )
    {
LABEL_131:
      v13 = -12;
      goto LABEL_132;
    }
    if ( (int)v4 <= -1073192688 )
    {
      switch ( (_DWORD)v4 )
      {
        case 0xC0046105:
          f0 = aw882xx_dsp_read_f0(a1, v9);
          goto LABEL_54;
        case 0xC0046107:
          f0 = aw882xx_dsp_read_cali_re(a1, v9);
          goto LABEL_54;
        case 0xC0046109:
          f0 = aw882xx_dsp_read_vmax(a1, v9, (unsigned int)v8);
          goto LABEL_54;
      }
    }
    else if ( (int)v4 > -1072668404 )
    {
      if ( (_DWORD)v4 == -1072668403 )
      {
        f0 = aw882xx_dsp_read_f0_q(a1, v9, v9 + 1);
        goto LABEL_54;
      }
      if ( (_DWORD)v4 == -1072144125 )
      {
        f0 = aw882xx_dsp_read_cali_data(a1, v9, (unsigned int)v8);
        goto LABEL_54;
      }
    }
    else
    {
      if ( (_DWORD)v4 == -1073192687 )
      {
        if ( v8 < 4 )
          goto LABEL_130;
        *v9 = *(_DWORD *)(a1 + 64);
        if ( (v8 & 0x3FFC) == 4 )
          goto LABEL_130;
        v14 = 0;
        v9[1] = *(_DWORD *)(a1 + 60);
        goto LABEL_55;
      }
      if ( (_DWORD)v4 == -1072930558 )
      {
        f0 = aw882xx_dsp_read_cali_cfg(a1, v9, (unsigned int)v8);
LABEL_54:
        v14 = f0;
LABEL_55:
        _check_object_size(v10, v8, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v16 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v16 = a3 & ((__int64)(a3 << 8) >> 8);
        if ( 0x8000000000LL - v8 >= v16 )
        {
          v17 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v23 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v23);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v17);
          v8 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v10, v8);
          v24 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v26 - 4096);
          _WriteStatusReg(TTBR1_EL1, v26);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v24);
        }
        if ( v8 )
          v13 = -14;
        else
          v13 = v14;
        kfree(v10);
        goto LABEL_132;
      }
    }
    v34 = *(__int64 **)(a1 + 112);
    v35 = v34[14];
    if ( !v35 )
      v35 = *v34;
    printk(&unk_23228, v35, "aw_cali_misc_ops_read");
    v14 = -22;
    goto LABEL_55;
  }
  if ( a2 > -1072668404 )
  {
    if ( a2 <= -1071619825 )
    {
      if ( a2 != -1072668403 && a2 != -1072144125 )
        goto LABEL_92;
      goto LABEL_16;
    }
    if ( a2 == -1071619824 )
    {
      *(_QWORD *)v52 = 0;
      v53 = 0;
      v50 = 0;
      v51 = 0;
      if ( inline_copy_from_user((__int64)&v50, a3, 0x20u) )
      {
        v13 = -14;
        goto LABEL_132;
      }
      if ( (_DWORD)v51 )
      {
        v38 = *(__int64 **)(a1 + 112);
        v31 = v38[14];
        if ( !v31 )
          v31 = *v38;
        v32 = &unk_2471F;
      }
      else
      {
        switch ( (_DWORD)v50 )
        {
          case 0:
            v13 = aw_cali_misc_ops(a1);
            goto LABEL_132;
          case 2:
            v13 = aw_cali_misc_write_dsp(a1, &v50);
            goto LABEL_132;
          case 1:
            v13 = aw_cali_misc_read_dsp(a1, &v50);
            goto LABEL_132;
        }
        v42 = *(__int64 **)(a1 + 112);
        v31 = v42[14];
        if ( !v31 )
          v31 = *v42;
        v32 = &unk_25AB1;
      }
      v33 = "aw_cali_misc_ops_msg";
LABEL_120:
      printk(v32, v31, v33);
      v13 = -22;
      goto LABEL_132;
    }
    v7 = -916430582;
  }
  else if ( a2 > -1072930559 )
  {
    if ( a2 == -1072930558 )
      goto LABEL_16;
    v7 = -1072668404;
  }
  else
  {
    if ( a2 == -1073192687 )
      goto LABEL_16;
    v7 = -1072930559;
  }
LABEL_24:
  if ( a2 != v7 )
  {
LABEL_92:
    v30 = *(__int64 **)(a1 + 112);
    v31 = v30[14];
    if ( !v31 )
      v31 = *v30;
    v32 = &unk_23228;
    v33 = "aw_cali_misc_ops";
    goto LABEL_120;
  }
LABEL_25:
  v10 = HIWORD(a2) & 0x3FFF;
  v12 = (int *)_kmalloc_noprof(v10, 3520);
  if ( !v12 )
    goto LABEL_131;
  while ( 1 )
  {
    _check_object_size(v12, v10, 0);
    if ( inline_copy_from_user((__int64)v12, a3, v10) )
      goto LABEL_27;
    if ( (int)v4 <= -1073454834 )
      break;
    if ( (int)v4 > -1072668405 )
    {
      if ( (_DWORD)v4 != -1072668404 )
      {
        if ( (_DWORD)v4 == -916430582 )
        {
          v13 = aw882xx_dsp_write_params(a1, v12, (unsigned int)v10);
          goto LABEL_28;
        }
        goto LABEL_110;
      }
      if ( v10 >= 8 && (v10 & 0x3FF8) != 8 )
      {
        if ( !*((_QWORD *)v12 + 1) || !*v12 )
        {
          v36 = *(__int64 **)(a1 + 112);
          v37 = v36[14];
          if ( !v37 )
            v37 = *v36;
          printk(&unk_22929, v37, "aw_cali_misc_params_ptr");
LABEL_27:
          v13 = -14;
          goto LABEL_28;
        }
        v27 = _kmalloc_noprof(*v12, 3520);
        v4 = v27;
        if ( !v27 )
        {
          v13 = -12;
          goto LABEL_28;
        }
        if ( (v10 & 0x3FF8) != 8 )
        {
          v28 = (unsigned int)*v12;
          if ( (v28 & 0x80000000) != 0 )
          {
            __break(0x800u);
          }
          else
          {
            v29 = *((_QWORD *)v12 + 1);
            _check_object_size(v27, (unsigned int)*v12, 0);
            if ( inline_copy_from_user(v4, v29, v28) )
              goto LABEL_88;
            v13 = aw882xx_dsp_write_params(a1, v4, (unsigned int)*v12);
            if ( (v13 & 0x80000000) == 0 )
            {
LABEL_96:
              kfree(v4);
              goto LABEL_28;
            }
            v45 = *(__int64 **)(a1 + 112);
            v46 = v45[14];
            if ( !v46 )
              v46 = *v45;
            printk(&unk_27CA1, v46, "aw_cali_misc_params_ptr");
          }
LABEL_88:
          v13 = -14;
          goto LABEL_96;
        }
      }
    }
    else
    {
      if ( (_DWORD)v4 != -1073454833 )
      {
        if ( (_DWORD)v4 == -1072930559 )
        {
          v13 = aw882xx_dsp_write_cali_cfg(a1, v12, (unsigned int)v10);
          goto LABEL_28;
        }
LABEL_110:
        v39 = *(__int64 **)(a1 + 112);
        v40 = v39[14];
        if ( !v40 )
          v40 = *v39;
        printk(&unk_23228, v40, "aw_cali_misc_ops_write");
        v13 = -22;
        goto LABEL_28;
      }
      if ( v10 >= 4 )
      {
        v13 = aw882xx_dsp_cali_en(a1, (unsigned int)*v12);
        goto LABEL_28;
      }
    }
LABEL_130:
    __break(1u);
    v47 = _ReadStatusReg(SP_EL0);
    v48 = *(_QWORD *)(v47 + 80);
    *(_QWORD *)(v47 + 80) = &aw_cali_misc_ops_write__alloc_tag;
    v12 = (int *)_kmalloc_noprof(v10, 3520);
    *(_QWORD *)(v47 + 80) = v48;
    if ( !v12 )
      goto LABEL_131;
  }
  if ( (int)v4 > -1073454841 )
  {
    if ( (_DWORD)v4 == -1073454840 )
    {
      v13 = aw882xx_dsp_write_vmax(a1, v12, (unsigned int)v10);
      goto LABEL_28;
    }
    if ( (_DWORD)v4 != -1073454834 )
      goto LABEL_110;
    if ( v10 >= 4 )
    {
      v13 = aw882xx_dsp_hmute_en(a1, *v12 != 0);
      goto LABEL_28;
    }
    goto LABEL_130;
  }
  if ( (_DWORD)v4 == -1073454844 )
  {
    if ( v10 >= 4 )
    {
      v13 = aw882xx_dsp_noise_en(a1, *v12 != 0);
      goto LABEL_28;
    }
    goto LABEL_130;
  }
  if ( (_DWORD)v4 == -1073454842 )
  {
    if ( v10 >= 4 )
    {
      aw_cali_store_cali_re(a1, *v12);
      v13 = 0;
      goto LABEL_28;
    }
    goto LABEL_130;
  }
  if ( (_DWORD)v4 != -1073651445 )
    goto LABEL_110;
  if ( !*(_BYTE *)(a1 + 665) )
  {
    if ( v10 )
      goto LABEL_123;
    goto LABEL_130;
  }
  if ( !v10 )
    goto LABEL_130;
  if ( *(_BYTE *)v12 )
    v41 = 1;
  else
    v41 = *(_BYTE *)(a1 + 664);
  aw_cali_svc_run_mute(a1, v41);
LABEL_123:
  v43 = *(__int64 **)(a1 + 112);
  v44 = v43[14];
  g_cali_status = *(_BYTE *)v12 != 0;
  if ( !v44 )
    v44 = *v43;
  printk(&unk_261EB, v44, "aw_cali_svc_set_cali_status");
  v13 = 0;
LABEL_28:
  kfree(v12);
LABEL_132:
  _ReadStatusReg(SP_EL0);
  return v13;
}
