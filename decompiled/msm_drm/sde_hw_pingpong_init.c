__int64 __fastcall sde_hw_pingpong_init(int a1, __int64 a2, int *a3)
{
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x20
  int v10; // w8
  int v11; // w9
  int v12; // w10
  int v13; // w8
  unsigned __int64 v14; // x8
  int v15; // w24
  __int64 v16; // x25
  unsigned __int64 v17; // x23
  int v18; // w8
  __int64 v19; // x8
  unsigned __int64 v21; // x1
  unsigned int v22; // w2
  int v23; // w8
  int v24; // w9
  __int64 v25; // x10
  __int64 v26; // x9
  __int64 (__fastcall *v27)(); // x9
  __int64 v28; // x10
  __int64 (__fastcall *v29)(); // x9
  __int64 v30; // x19
  __int64 v31; // x8
  int v32; // w10
  int v33; // w9
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v38; // x23
  __int64 (__fastcall *v39)(_QWORD); // x0

  v6 = _kmalloc_cache_noprof(msleep, 3520, 472);
  if ( !v6 )
    return -12;
  while ( 1 )
  {
    v7 = a3[2404];
    if ( !v7 )
    {
LABEL_15:
      kfree(v6);
      return -22;
    }
    if ( a3[2410] == a1 )
    {
      v8 = 2406;
LABEL_5:
      v9 = (unsigned __int64)&a3[v8];
      goto LABEL_6;
    }
    if ( v7 == 1 )
      goto LABEL_15;
    if ( a3[2426] == a1 )
    {
      v8 = 2422;
      goto LABEL_5;
    }
    if ( v7 == 2 )
      goto LABEL_15;
    if ( a3[2442] == a1 )
    {
      v8 = 2438;
      goto LABEL_5;
    }
    if ( v7 == 3 )
      goto LABEL_15;
    if ( a3[2458] == a1 )
    {
      v8 = 2454;
      goto LABEL_5;
    }
    if ( v7 == 4 )
      goto LABEL_15;
    if ( a3[2474] == a1 )
    {
      v8 = 2470;
      goto LABEL_5;
    }
    if ( v7 == 5 )
      goto LABEL_15;
    if ( a3[2490] == a1 )
    {
      v8 = 2486;
      goto LABEL_5;
    }
    if ( v7 == 6 )
      goto LABEL_15;
    if ( a3[2506] == a1 )
    {
      v8 = 2502;
      goto LABEL_5;
    }
    if ( v7 == 7 )
      goto LABEL_15;
    if ( a3[2522] == a1 )
    {
      v34 = 2518;
    }
    else
    {
      if ( v7 == 8 )
        goto LABEL_15;
      if ( a3[2538] == a1 )
      {
        v34 = 2534;
      }
      else
      {
        if ( v7 == 9 )
          goto LABEL_15;
        if ( a3[2554] == a1 )
        {
          v34 = 2550;
        }
        else
        {
          if ( v7 == 10 )
            goto LABEL_15;
          if ( a3[2570] == a1 )
          {
            v34 = 2566;
          }
          else
          {
            if ( v7 == 11 )
              goto LABEL_15;
            if ( a3[2586] != a1 )
            {
              if ( v7 == 12 )
                goto LABEL_15;
              goto LABEL_110;
            }
            v34 = 2582;
          }
        }
      }
    }
    v9 = (unsigned __int64)&a3[v34];
LABEL_6:
    v10 = *(_DWORD *)(v9 + 20);
    v11 = *(_DWORD *)(v9 + 24);
    v12 = *a3;
    *(_QWORD *)v6 = a2;
    *(_DWORD *)(v6 + 8) = v10;
    *(_DWORD *)(v6 + 12) = v11;
    *(_DWORD *)(v6 + 20) = v12;
    *(_DWORD *)(v6 + 24) = 64;
    if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_15;
    v13 = *(_DWORD *)(v9 + 60);
    *(_DWORD *)(v6 + 32) = a1;
    *(_QWORD *)(v6 + 40) = v9;
    *(_DWORD *)(v6 + 48) = v13;
    v14 = v9;
    if ( (*(_QWORD *)(v9 + 32) & 0x100) == 0 )
      goto LABEL_65;
    v15 = *(_DWORD *)(v9 + 56);
    if ( !v15 )
    {
      *(_QWORD *)(v6 + 56) = 0;
      v14 = v9;
      goto LABEL_65;
    }
    v16 = v6;
    v17 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
    v6 = v16;
    if ( !v17 )
    {
      v36 = -12;
LABEL_113:
      *(_QWORD *)(v6 + 56) = v36;
      goto LABEL_114;
    }
    v18 = a3[4676];
    if ( !v18 )
      goto LABEL_105;
    if ( a3[4682] == v15 )
    {
      v19 = 4678;
LABEL_58:
      v21 = (unsigned __int64)&a3[v19];
      goto LABEL_59;
    }
    if ( v18 == 1 )
      goto LABEL_105;
    if ( a3[4694] == v15 )
    {
      v19 = 4690;
      goto LABEL_58;
    }
    if ( v18 == 2 )
      goto LABEL_105;
    if ( a3[4706] == v15 )
    {
      v19 = 4702;
      goto LABEL_58;
    }
    if ( v18 == 3 )
      goto LABEL_105;
    if ( a3[4718] == v15 )
    {
      v19 = 4714;
      goto LABEL_58;
    }
    if ( v18 == 4 )
      goto LABEL_105;
    if ( a3[4730] == v15 )
    {
      v19 = 4726;
      goto LABEL_58;
    }
    if ( v18 == 5 )
      goto LABEL_105;
    if ( a3[4742] == v15 )
    {
      v19 = 4738;
      goto LABEL_58;
    }
    if ( v18 == 6 )
      goto LABEL_105;
    if ( a3[4754] == v15 )
    {
      v19 = 4750;
      goto LABEL_58;
    }
    if ( v18 == 7 )
      goto LABEL_105;
    if ( a3[4766] == v15 )
    {
      v19 = 4762;
      goto LABEL_58;
    }
    if ( v18 == 8 )
      goto LABEL_105;
    if ( a3[4778] == v15 )
    {
      v19 = 4774;
      goto LABEL_58;
    }
    if ( v18 == 9 )
      goto LABEL_105;
    if ( a3[4790] == v15 )
      break;
    if ( v18 == 10 )
      goto LABEL_105;
    if ( a3[4802] == v15 )
    {
      v35 = 4798;
      goto LABEL_97;
    }
    if ( v18 == 11 )
      goto LABEL_105;
    if ( a3[4814] == v15 )
    {
      v35 = 4810;
      goto LABEL_97;
    }
    if ( v18 == 12 )
      goto LABEL_105;
LABEL_110:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v38 = *(_QWORD *)(StatusReg + 80);
    v39 = msleep;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_pingpong_init__alloc_tag;
    v6 = _kmalloc_cache_noprof(v39, 3520, 472);
    *(_QWORD *)(StatusReg + 80) = v38;
    if ( !v6 )
      return -12;
  }
  v35 = 4786;
LABEL_97:
  v21 = (unsigned __int64)&a3[v35];
  v6 = v16;
LABEL_59:
  v22 = *(_DWORD *)(v21 + 20);
  v23 = *(_DWORD *)(v21 + 24);
  v24 = *a3;
  *(_QWORD *)v17 = a2;
  *(_DWORD *)(v17 + 8) = v22;
  *(_DWORD *)(v17 + 12) = v23;
  *(_DWORD *)(v17 + 20) = v24;
  *(_DWORD *)(v17 + 24) = 64;
  if ( !v21 || v21 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_105:
    printk(&unk_21E77E, "_sde_pp_merge_3d_init");
    kfree(v17);
    v6 = v16;
    v36 = -22;
    goto LABEL_113;
  }
  *(_DWORD *)(v17 + 32) = v15;
  v25 = (unsigned int)sde_pp_merge_3d_init_merge3d_init_mask;
  *(_QWORD *)(v17 + 40) = v21;
  *(_QWORD *)(v17 + 48) = sde_hw_merge_3d_setup_blend_mode;
  *(_QWORD *)(v17 + 72) = sde_hw_merge_3d_reset_blend_mode;
  if ( ((1LL << v15) & v25) == 0 )
  {
    sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v21, v22, v23 + v22, *(_DWORD *)(v17 + 16));
    v6 = v16;
    sde_pp_merge_3d_init_merge3d_init_mask |= 1LL << v15;
  }
  *(_QWORD *)(v6 + 56) = v17;
  if ( v17 > 0xFFFFFFFFFFFFF000LL )
  {
LABEL_114:
    printk(&unk_239395, "sde_hw_pingpong_init");
    return -12;
  }
  v14 = *(_QWORD *)(v6 + 40);
LABEL_65:
  *(_QWORD *)(v6 + 424) = sde_hw_pp_get_caps;
  v26 = *(_QWORD *)(v14 + 32);
  if ( (v26 & 2) != 0 )
  {
    v28 = 288;
    *(_QWORD *)(v6 + 64) = sde_hw_pp_setup_te_config;
    *(_QWORD *)(v6 + 88) = sde_hw_pp_enable_te;
    *(_QWORD *)(v6 + 112) = sde_hw_pp_update_te;
    *(_QWORD *)(v6 + 136) = sde_hw_pp_connect_external_te;
    *(_QWORD *)(v6 + 160) = sde_hw_pp_get_vsync_info;
    *(_QWORD *)(v6 + 184) = sde_hw_pp_setup_autorefresh_config;
    *(_QWORD *)(v6 + 208) = sde_hw_pp_get_autorefresh_config;
    *(_QWORD *)(v6 + 232) = sde_hw_pp_poll_timeout_wr_ptr;
    v27 = sde_hw_pp_get_line_count;
LABEL_69:
    *(_QWORD *)(v6 + 64 + v28) = v27;
    v26 = *(_QWORD *)(v14 + 32);
  }
  else if ( (v26 & 0x800) != 0 )
  {
    v27 = sde_hw_pp_set_ppb_fifo_size;
    v28 = 384;
    goto LABEL_69;
  }
  if ( (v26 & 0x20) != 0 )
  {
    *(_QWORD *)(v6 + 256) = sde_hw_pp_setup_dsc;
    *(_QWORD *)(v6 + 280) = sde_hw_pp_dsc_enable;
    *(_QWORD *)(v6 + 304) = sde_hw_pp_dsc_disable;
  }
  if ( (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v14 + 48) + 142LL) - 1 > 2 )
    v29 = nullptr;
  else
    v29 = off_28C020[(unsigned __int16)(*(_WORD *)(*(_QWORD *)(v14 + 48) + 142LL) - 1)];
  *(_QWORD *)(v6 + 328) = v29;
  if ( (*(_QWORD *)(v14 + 32) & 0x100) != 0 )
  {
    *(_QWORD *)(v6 + 376) = sde_hw_pp_setup_3d_merge_mode;
    *(_QWORD *)(v6 + 400) = sde_hw_pp_reset_3d_merge_mode;
  }
  v30 = v6;
  sde_dbg_reg_register_dump_range(
    (__int64)"sde",
    (const char *)v9,
    *(_DWORD *)(v6 + 8),
    *(_DWORD *)(v6 + 12) + *(_DWORD *)(v6 + 8),
    *(_DWORD *)(v6 + 16));
  v31 = *(_QWORD *)(v9 + 48);
  v32 = *(_DWORD *)(v31 + 128);
  if ( v32 )
  {
    v33 = *(_DWORD *)(v31 + 132);
    if ( v33 )
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        (const char *)(v31 + 108),
        *(_DWORD *)(v30 + 8) + v32,
        *(_DWORD *)(v30 + 8) + v32 + v33,
        *(_DWORD *)(v30 + 16));
  }
  return v30;
}
