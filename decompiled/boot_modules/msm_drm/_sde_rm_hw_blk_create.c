__int64 __fastcall sde_rm_hw_blk_create(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v8; // x9
  __int64 v9; // x19
  __int64 v10; // x3
  unsigned __int64 v11; // x0
  __int64 v12; // x23
  __int64 v13; // x0
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x2
  __int64 *v17; // x1
  __int64 v18; // x8
  __int64 result; // x0
  __int64 v20; // [xsp+8h] [xbp-28h] BYREF
  __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)a1 && (v8 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
    v9 = *(_QWORD *)(v8 + 8);
  else
    v9 = 0;
  v10 = *(_QWORD *)(a1 + 264);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  if ( a4 > 7 )
  {
    if ( a4 > 10 )
    {
      switch ( a4 )
      {
        case 11:
          v11 = sde_hw_vdc_init(a5, a3, a2, v10);
          goto LABEL_30;
        case 13:
          v11 = sde_hw_qdss_init(a5, a3, a2, v10);
          goto LABEL_30;
        case 14:
          v11 = sde_hw_dnsc_blur_init(a5, a3, a2, v10);
          goto LABEL_30;
      }
      goto LABEL_46;
    }
    if ( a4 == 8 )
    {
      v11 = sde_hw_intf_init(a5, a3, a2, v10);
    }
    else if ( a4 == 9 )
    {
      v11 = sde_hw_wb_init(a5, a3, a2, v10, &v20);
    }
    else
    {
      v11 = sde_hw_dsc_init(a5, a3, a2, v10);
    }
  }
  else
  {
    if ( a4 <= 4 )
    {
      switch ( a4 )
      {
        case 2:
          v11 = sde_hw_lm_init(a5, a3, a2, v10);
          goto LABEL_30;
        case 3:
          v11 = sde_hw_dspp_init(a5, a3, a2, v9);
          goto LABEL_30;
        case 4:
          v11 = sde_hw_ds_init(a5, a3, a2, v10);
          goto LABEL_30;
      }
LABEL_46:
      printk(&unk_246378, "_sde_rm_hw_blk_create");
      result = 4294967274LL;
      goto LABEL_49;
    }
    if ( a4 == 5 )
    {
      v11 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, _QWORD, __int64))sde_hw_ctl_init)(
              a5,
              a3,
              a2,
              **(unsigned int **)(*(_QWORD *)(v9 + 136) + 64LL),
              v9 + 3544);
    }
    else if ( a4 == 6 )
    {
      v11 = sde_hw_cdm_init(a5, a3, a2, v10, *(unsigned int *)(a1 + 376));
    }
    else
    {
      v11 = sde_hw_pingpong_init(a5, a3, a2, v10);
    }
  }
LABEL_30:
  v12 = v11;
  if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_253B1E, "_sde_rm_hw_blk_create");
    goto LABEL_45;
  }
  v13 = _kmalloc_cache_noprof(_drm_debug, 3520, 48);
  v14 = v13;
  if ( !v13 )
  {
    sde_rm_hw_destroy(a4, v12);
    result = 4294967284LL;
    goto LABEL_49;
  }
  v15 = a1 + 16LL * (unsigned int)a4;
  *(_DWORD *)(v13 + 32) = a4;
  *(_DWORD *)(v13 + 36) = a5;
  *(_QWORD *)(v13 + 40) = v12;
  v16 = v15 + 24;
  v17 = *(__int64 **)(v15 + 32);
  if ( v13 == v15 + 24 || v17 == (__int64 *)v13 || *v17 != v16 )
  {
    _list_add_valid_or_report(v13, v17);
  }
  else
  {
    *(_QWORD *)(v15 + 32) = v13;
    *(_QWORD *)v13 = v16;
    *(_QWORD *)(v13 + 8) = v17;
    *v17 = v13;
  }
  sde_rm_inc_resource_info(a1, a1 + 336, v14);
  if ( v9
    && (v18 = *(_QWORD *)(v9 + 152)) != 0
    && (*(_QWORD *)(v18 + 22008) & 0x8000000000LL) != 0
    && (unsigned int)(v21 - 1) <= 0x12 )
  {
    result = sde_vbif_clk_register(v9, &v20);
    if ( (_DWORD)result )
    {
      printk(&unk_26CAE5, "_sde_rm_hw_blk_create");
LABEL_45:
      result = 4294967282LL;
    }
  }
  else
  {
    result = 0;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
