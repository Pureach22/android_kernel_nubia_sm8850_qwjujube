__int64 __fastcall mmrm_sw_clk_client_setval(__int64 a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  unsigned int v4; // w8
  __int64 v5; // x20
  unsigned __int64 v6; // x9
  __int64 v8; // x22
  _DWORD *v9; // x21
  __int64 max_crm_rate; // x0
  __int64 v11; // x21
  void *v12; // x0
  int v13; // w27
  int v14; // w9
  __int64 v15; // x23
  _DWORD *v16; // x24
  __int64 v17; // x1
  unsigned int v18; // w22
  __int64 v19; // x24
  unsigned int *v20; // x23
  _DWORD *v21; // x28
  __int64 v22; // x3
  unsigned int v23; // w0
  unsigned int v24; // w19
  __int64 result; // x0
  int v26; // w8
  unsigned int v27; // w10
  __int64 v28; // x21
  _DWORD *v29; // x22
  __int64 v30; // x21
  unsigned int v31; // w19
  __int64 v32; // x21
  _DWORD *v33; // x22
  int v34; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  if ( !a2 )
  {
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_72;
    v12 = &unk_CA9A;
LABEL_36:
    printk(v12, "err ", "mmrm_sw_clk_client_setval");
    goto LABEL_72;
  }
  v4 = *(_DWORD *)(a2 + 4);
  if ( v4 >= *(_DWORD *)(a1 + 72) )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_C610, "err ", "mmrm_sw_clk_client_setval");
    goto LABEL_72;
  }
  if ( !a3 )
  {
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_72;
    v12 = &unk_C3CF;
    goto LABEL_36;
  }
  v5 = *(_QWORD *)(a1 + 64) + 720LL * v4;
  v6 = *(_QWORD *)(v5 + 128);
  if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (~msm_mmrm_debug & 0x10001) != 0 )
      goto LABEL_72;
    v12 = &unk_C595;
    goto LABEL_36;
  }
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
  {
    v28 = a1;
    v29 = a3;
    printk(&unk_DA88, "high", "mmrm_sw_clk_client_setval");
    a1 = v28;
    a3 = v29;
  }
  if ( *(_BYTE *)(v5 + 688) != 1 )
  {
    v11 = 0;
    goto LABEL_21;
  }
  if ( a3[3] >= *(_DWORD *)(v5 + 692) || a3[4] >= *(_DWORD *)(v5 + 696) )
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v12 = &unk_C917;
      goto LABEL_36;
    }
LABEL_72:
    result = 4294967274LL;
LABEL_73:
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v31 = result;
      printk(&unk_DA62, "err ", "mmrm_sw_clk_client_setval");
      result = v31;
    }
    goto LABEL_75;
  }
  v8 = a1;
  v9 = a3;
  max_crm_rate = mmrm_sw_get_max_crm_rate(v5, a3, a4, &v34);
  a3 = v9;
  v11 = max_crm_rate;
  a1 = v8;
LABEL_21:
  v13 = a3[1] & 1;
  if ( *(_QWORD *)(v5 + 664) == a4 && *(_DWORD *)(v5 + 684) == *a3 && (*(_BYTE *)(v5 + 688) & 1) == 0 )
  {
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
    {
      v32 = a1;
      v33 = a3;
      printk(&unk_D467, "high", "mmrm_sw_clk_client_setval");
      a1 = v32;
      a3 = v33;
    }
    if ( v13 == *(unsigned __int8 *)(v5 + 676) )
      goto LABEL_78;
    v30 = a1;
    v21 = a3;
    mutex_lock(a1);
    *(_BYTE *)(v5 + 676) = v13;
    mutex_unlock(v30);
    if ( v13 )
      goto LABEL_78;
    if ( (*(_BYTE *)(v5 + 688) & 1) != 0 )
      goto LABEL_62;
LABEL_67:
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
      printk(&unk_C93E, "high", "mmrm_sw_clk_client_setval");
    if ( !(unsigned int)clk_set_rate(*(_QWORD *)(v5 + 128), a4) )
      goto LABEL_78;
LABEL_70:
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_C768, "err ", "mmrm_sw_clk_client_setval");
    goto LABEL_72;
  }
  if ( a4 )
  {
    v14 = *(unsigned __int8 *)(v5 + 688);
    v15 = a1;
    v16 = a3;
    v35 = 0;
    if ( v14 )
      v17 = v11;
    else
      v17 = a4;
    if ( (unsigned int)mmrm_sw_get_req_level(v5, v17, &v35) || (v18 = v35, v35 >= 9) )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_C3F9, "err ", "mmrm_sw_clk_client_setval");
      goto LABEL_72;
    }
    if ( !*v16 || (a3 = v16, a1 = v15, *v16 > *(_DWORD *)(v5 + 176)) )
    {
      if ( (~msm_mmrm_debug & 0x10001) == 0 )
        printk(&unk_C450, "err ", "mmrm_sw_clk_client_setval");
      goto LABEL_72;
    }
  }
  else
  {
    v18 = 0;
  }
  v19 = a1;
  v20 = a3;
  mutex_lock(a1);
  v21 = v20;
  if ( *(_BYTE *)(v5 + 688) )
    v22 = (unsigned int)v11;
  else
    v22 = (unsigned int)a4;
  v23 = mmrm_sw_check_peak_current(v19 + 56, v5, v18, v22, *v20);
  if ( v23 )
  {
    v24 = v23;
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_CF3B, "err ", "mmrm_sw_clk_client_setval");
    mutex_unlock(v19);
    result = v24;
    goto LABEL_73;
  }
  if ( (*(_BYTE *)(v5 + 688) & 1) != 0 )
  {
    v26 = v34;
    *(_QWORD *)(v5 + 664) = v11;
    *(_DWORD *)(v5 + 700) = v26;
    if ( v20[2] )
      v27 = v20[4] + v20[3] * *(_DWORD *)(v5 + 696);
    else
      v27 = *(_DWORD *)(v5 + 704) - 1;
    *(_QWORD *)(*(_QWORD *)(v5 + 712) + 8LL * v27) = a4;
    mmrm_sw_print_crm_table(v5);
  }
  else
  {
    *(_QWORD *)(v5 + 664) = a4;
  }
  *(_DWORD *)(v5 + 672) = v18;
  *(_BYTE *)(v5 + 676) = v13;
  *(_DWORD *)(v5 + 684) = *v20;
  mutex_unlock(v19);
  if ( v13 && (*(_BYTE *)(v5 + 688) & 1) == 0 )
  {
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
      printk(&unk_C731, "high", "mmrm_sw_clk_client_setval");
    goto LABEL_78;
  }
  if ( (*(_BYTE *)(v5 + 688) & 1) == 0 )
    goto LABEL_67;
LABEL_62:
  if ( !v21[2] )
    goto LABEL_67;
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
    printk(&unk_D5D9, "high", "mmrm_sw_clk_client_setval");
  if ( (unsigned int)qcom_clk_crm_set_rate(*(_QWORD *)(v5 + 128), 0, (unsigned int)v21[3], (unsigned int)v21[4], a4) )
    goto LABEL_70;
LABEL_78:
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
    printk(&unk_C27F, "high", "mmrm_sw_clk_client_setval");
  result = 0;
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
