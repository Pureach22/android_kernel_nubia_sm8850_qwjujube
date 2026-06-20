__int64 __fastcall sde_hw_vdc_init(int a1, __int64 a2, int *a3)
{
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x1
  unsigned int v10; // w2
  int v11; // w8
  int v12; // w9
  int v13; // w4
  __int64 v14; // x20
  __int64 result; // x0
  __int64 v16; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v18; // x23
  double (*v19)(_QWORD, _QWORD, _QWORD, const char *, ...); // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  *(_QWORD *)s = 0;
  v21 = 0;
  v6 = _kmalloc_cache_noprof(_drm_dev_dbg, 3520, 120);
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = a3[2792];
      if ( !v7 )
        break;
      if ( a3[2798] == a1 )
      {
        v8 = 2794;
LABEL_5:
        v9 = (unsigned __int64)&a3[v8];
        goto LABEL_6;
      }
      if ( v7 == 1 )
        break;
      if ( a3[2812] == a1 )
      {
        v8 = 2808;
        goto LABEL_5;
      }
      if ( v7 == 2 )
        break;
      if ( a3[2826] == a1 )
      {
        v8 = 2822;
        goto LABEL_5;
      }
      if ( v7 == 3 )
        break;
      if ( a3[2840] == a1 )
      {
        v8 = 2836;
        goto LABEL_5;
      }
      if ( v7 == 4 )
        break;
      if ( a3[2854] == a1 )
      {
        v8 = 2850;
        goto LABEL_5;
      }
      if ( v7 == 5 )
        break;
      if ( a3[2868] == a1 )
      {
        v8 = 2864;
        goto LABEL_5;
      }
      if ( v7 == 6 )
        break;
      if ( a3[2882] == a1 )
      {
        v8 = 2878;
        goto LABEL_5;
      }
      if ( v7 == 7 )
        break;
      if ( a3[2896] == a1 )
      {
        v16 = 2892;
        goto LABEL_31;
      }
      if ( v7 == 8 )
        break;
      if ( a3[2910] == a1 )
      {
        v16 = 2906;
        goto LABEL_31;
      }
      if ( v7 == 9 )
        break;
      if ( a3[2924] == a1 )
      {
        v16 = 2920;
        goto LABEL_31;
      }
      if ( v7 == 10 )
        break;
      if ( a3[2938] == a1 )
      {
        v16 = 2934;
        goto LABEL_31;
      }
      if ( v7 == 11 )
        break;
      if ( a3[2952] == a1 )
      {
        v16 = 2948;
LABEL_31:
        v9 = (unsigned __int64)&a3[v16];
LABEL_6:
        v10 = *(_DWORD *)(v9 + 20);
        v11 = *(_DWORD *)(v9 + 24);
        v12 = *a3;
        *(_QWORD *)v6 = a2;
        *(_DWORD *)(v6 + 8) = v10;
        *(_DWORD *)(v6 + 12) = v11;
        *(_DWORD *)(v6 + 20) = v12;
        *(_DWORD *)(v6 + 24) = 0x20000;
        if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_DWORD *)(v6 + 32) = a1;
          *(_QWORD *)(v6 + 40) = v9;
          *(_QWORD *)(v6 + 48) = sde_hw_vdc_disable;
          *(_QWORD *)(v6 + 72) = sde_hw_vdc_config;
          v13 = *(_DWORD *)(v6 + 16);
          *(_QWORD *)(v6 + 96) = sde_hw_vdc_bind_pingpong_blk;
          v14 = v6;
          sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v9, v10, v11 + v10, v13);
          snprintf(s, 0x20u, "vdc_enc_%u", *(_DWORD *)(v14 + 32) - 1);
          sde_dbg_reg_register_dump_range(
            (__int64)"sde",
            s,
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 40) + 48LL) + 20LL) + *(_DWORD *)(v14 + 8),
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 40) + 48LL) + 20LL)
          + *(_DWORD *)(v14 + 8)
          + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 40) + 48LL) + 24LL),
            *(_DWORD *)(v14 + 16));
          snprintf(s, 0x20u, "vdc_ctl_%u", *(_DWORD *)(v14 + 32) - 1);
          sde_dbg_reg_register_dump_range(
            (__int64)"sde",
            s,
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 40) + 48LL) + 48LL) + *(_DWORD *)(v14 + 8),
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 40) + 48LL) + 48LL)
          + *(_DWORD *)(v14 + 8)
          + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 40) + 48LL) + 52LL),
            *(_DWORD *)(v14 + 16));
          result = v14;
          goto LABEL_47;
        }
        break;
      }
      if ( v7 == 12 )
        break;
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = *(_QWORD *)(StatusReg + 80);
      v19 = _drm_dev_dbg;
      *(_QWORD *)(StatusReg + 80) = &sde_hw_vdc_init__alloc_tag;
      v6 = _kmalloc_cache_noprof(v19, 3520, 120);
      *(_QWORD *)(StatusReg + 80) = v18;
      if ( !v6 )
        goto LABEL_46;
    }
    kfree(v6);
    result = -22;
  }
  else
  {
LABEL_46:
    result = -12;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
