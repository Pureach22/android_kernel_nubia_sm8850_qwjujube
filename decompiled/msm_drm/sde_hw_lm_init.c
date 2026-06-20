__int64 __fastcall sde_hw_lm_init(int a1, __int64 a2, int *a3)
{
  __int64 result; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x1
  unsigned int v10; // w2
  int v11; // w9
  int v12; // w8
  char v13; // w8
  void *v14; // x8
  __int64 (__fastcall *v15)(); // x8
  __int64 (__fastcall *v16)(); // x8
  __int64 (__fastcall *v17)(); // x8
  void *v18; // x8
  __int64 v19; // x19
  __int64 v20; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v22; // x23
  __int64 (__fastcall *v23)(_QWORD); // x0
  __int64 v24; // [xsp+18h] [xbp+18h]

  result = _kmalloc_cache_noprof(msleep, 3520, 392);
  if ( !result )
    return -12;
  while ( 1 )
  {
    v7 = a3[1738];
    if ( !v7 )
      goto LABEL_12;
    if ( a3[1744] == a1 )
    {
      v8 = 1740;
LABEL_5:
      v9 = (unsigned __int64)&a3[v8];
      goto LABEL_6;
    }
    if ( v7 == 1 )
      goto LABEL_12;
    if ( a3[1768] == a1 )
    {
      v8 = 1764;
      goto LABEL_5;
    }
    if ( v7 == 2 )
      goto LABEL_12;
    if ( a3[1792] == a1 )
    {
      v8 = 1788;
      goto LABEL_5;
    }
    if ( v7 == 3 )
      goto LABEL_12;
    if ( a3[1816] == a1 )
    {
      v8 = 1812;
      goto LABEL_5;
    }
    if ( v7 == 4 )
      goto LABEL_12;
    if ( a3[1840] == a1 )
    {
      v8 = 1836;
      goto LABEL_5;
    }
    if ( v7 == 5 )
      goto LABEL_12;
    if ( a3[1864] == a1 )
    {
      v8 = 1860;
      goto LABEL_5;
    }
    if ( v7 == 6 )
      goto LABEL_12;
    if ( a3[1888] == a1 )
    {
      v8 = 1884;
      goto LABEL_5;
    }
    if ( v7 == 7 )
      goto LABEL_12;
    if ( a3[1912] == a1 )
      break;
    if ( v7 == 8 )
      goto LABEL_12;
    if ( a3[1936] == a1 )
    {
      v20 = 1932;
      goto LABEL_61;
    }
    if ( v7 == 9 )
      goto LABEL_12;
    if ( a3[1960] == a1 )
    {
      v20 = 1956;
      goto LABEL_61;
    }
    if ( v7 == 10 )
      goto LABEL_12;
    if ( a3[1984] == a1 )
    {
      v20 = 1980;
      goto LABEL_61;
    }
    if ( v7 == 11 )
      goto LABEL_12;
    if ( a3[2008] == a1 )
    {
      v20 = 2004;
      goto LABEL_61;
    }
    if ( v7 == 12 )
      goto LABEL_12;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_QWORD *)(StatusReg + 80);
    v23 = msleep;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_lm_init__alloc_tag;
    result = _kmalloc_cache_noprof(v23, 3520, 392);
    *(_QWORD *)(StatusReg + 80) = v22;
    if ( !result )
      return -12;
  }
  v20 = 1908;
LABEL_61:
  v9 = (unsigned __int64)&a3[v20];
LABEL_6:
  v10 = *(_DWORD *)(v9 + 20);
  v11 = *(_DWORD *)(v9 + 24);
  v12 = *a3;
  *(_QWORD *)result = a2;
  *(_DWORD *)(result + 8) = v10;
  *(_DWORD *)(result + 12) = v11;
  *(_DWORD *)(result + 20) = v12;
  *(_DWORD *)(result + 24) = 16;
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_12:
    kfree(result);
    return -22;
  }
  v13 = *(_BYTE *)(v9 + 72);
  *(_DWORD *)(result + 32) = a1;
  *(_QWORD *)(result + 40) = v9;
  if ( (v13 & 1) == 0 )
  {
    v24 = *(_QWORD *)(v9 + 32);
    *(_QWORD *)(result + 64) = sde_hw_lm_setup_out;
    if ( (v24 & 0x200) != 0 )
    {
      if ( (v24 & 0x1000) != 0 )
      {
        v14 = &sde_hw_lm_setup_blend_config_combined_alpha_10_bits;
      }
      else
      {
        v14 = &sde_hw_lm_setup_blend_config_combined_alpha;
        if ( (*((_QWORD *)a3 + 2751) & 0x2000000000000LL) != 0 )
          v14 = &sde_hw_lm_setup_blend_config_combined_alpha_v1;
      }
    }
    else
    {
      v14 = &sde_hw_lm_setup_blend_config;
    }
    *(_QWORD *)(result + 88) = v14;
    if ( (v24 & 0x800) != 0 )
    {
      *(_QWORD *)(result + 304) = sde_hw_lm_setup_blendstage;
      *(_QWORD *)(result + 352) = &sde_hw_lm_get_staged_sspp;
      *(_QWORD *)(result + 328) = sde_hw_lm_clear_all_blendstages;
      v15 = sde_hw_lm_setup_color3_v1;
    }
    else
    {
      v15 = sde_hw_lm_setup_color3;
    }
    *(_QWORD *)(result + 112) = v15;
    if ( (v24 & 0x2000) != 0 )
    {
      v16 = sde_hw_lm_setup_border_color_10_bits;
    }
    else
    {
      v16 = sde_hw_lm_setup_border_color;
      if ( (*((_QWORD *)a3 + 2751) & 0x2000000000000LL) != 0 )
        v16 = sde_hw_lm_setup_border_color_v1;
    }
    *(_QWORD *)(result + 136) = v16;
    *(_QWORD *)(result + 160) = sde_hw_lm_gc;
    *(_QWORD *)(result + 232) = sde_hw_lm_setup_misr;
    *(_QWORD *)(result + 256) = sde_hw_lm_collect_misr;
    if ( (v24 & 0x10) != 0 )
    {
      if ( (v24 & 0x2000) != 0 )
      {
        v17 = sde_hw_lm_setup_dim_layer_10_bits;
      }
      else
      {
        v17 = (__int64 (__fastcall *)())&sde_hw_lm_setup_dim_layer;
        if ( (*((_QWORD *)a3 + 2751) & 0x2000000000000LL) != 0 )
          v17 = sde_hw_lm_setup_dim_layer_v1;
      }
      *(_QWORD *)(result + 184) = v17;
      *(_QWORD *)(result + 208) = &sde_hw_lm_clear_dim_layer;
    }
    if ( (v24 & 0x400) != 0 )
    {
      if ( (v24 & 0x2000) != 0 )
      {
        v18 = &sde_hw_lm_setup_noise_layer_10_bits;
      }
      else
      {
        v18 = &sde_hw_lm_setup_noise_layer;
        if ( (*((_QWORD *)a3 + 2751) & 0x2000000000000LL) != 0 )
          v18 = &sde_hw_lm_setup_noise_layer_v1;
      }
      *(_QWORD *)(result + 280) = v18;
    }
    v19 = result;
    sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v9, v10, v11 + v10, *(_DWORD *)(result + 16));
    return v19;
  }
  return result;
}
