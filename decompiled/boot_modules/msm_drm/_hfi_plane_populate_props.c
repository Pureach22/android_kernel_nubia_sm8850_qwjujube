__int64 __fastcall hfi_plane_populate_props(__int64 a1, int a2, _QWORD *a3, __int64 a4)
{
  unsigned int **v4; // x26
  int *v9; // x23
  __int64 v10; // x25
  unsigned int v11; // w10
  unsigned int v12; // w11
  int *v13; // x28
  int v14; // w8
  int v15; // w9
  int v16; // w10
  int v17; // w9
  int v18; // w10
  int v19; // t1
  __int64 v20; // x1
  __int64 v21; // x2
  int hfi_format; // w0
  int v23; // w2
  int v24; // w6
  int v25; // w4
  int *v26; // x0
  __int64 v27; // x8
  int v28; // w2
  __int64 v29; // x8
  int v30; // w8
  int v31; // w2
  __int64 v32; // x4
  __int64 v33; // x8
  int v34; // w2
  int *v35; // x0
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x4
  int v39; // w2
  int *v40; // x0
  __int64 v41; // x8
  int v42; // w8
  int v43; // w2
  __int64 result; // x0
  unsigned int v45; // w19
  _DWORD *payload_addr; // x22
  unsigned int size; // w0
  unsigned int v48; // w0
  int v49; // w4
  __int64 v50; // x2
  void *v51; // x0
  __int64 v52; // x0
  __int64 v53; // x1
  __int64 v54; // x2
  __int64 v55; // x3
  char v56[8]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v57; // [xsp+8h] [xbp-38h]
  __int64 v58; // [xsp+10h] [xbp-30h] BYREF
  int v59; // [xsp+18h] [xbp-28h]
  int v60; // [xsp+1Ch] [xbp-24h]
  unsigned __int64 src; // [xsp+20h] [xbp-20h] BYREF
  int v62; // [xsp+28h] [xbp-18h]
  int v63; // [xsp+2Ch] [xbp-14h]
  _QWORD v64[2]; // [xsp+30h] [xbp-10h] BYREF

  v64[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    printk(&unk_226FC0, "_hfi_plane_populate_props");
    result = 4294967274LL;
LABEL_50:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v4 = (unsigned int **)a3[534];
  if ( !a4 )
  {
    printk(&unk_226FC0, "_hfi_plane_set_props_base");
    v45 = -22;
LABEL_54:
    v51 = &unk_21586A;
    goto LABEL_55;
  }
  mutex_lock(v4 + 2);
  hfi_util_u32_prop_helper_reset(v4[8]);
  v9 = (int *)v4[8];
  *(_QWORD *)v56 = 0;
  if ( !v9 )
  {
    printk(&unk_2194BA, "_hfi_plane_set_props_base");
    v45 = -22;
LABEL_53:
    mutex_unlock(v4 + 2);
    goto LABEL_54;
  }
  v10 = *(_QWORD *)(a4 + 16);
  v11 = *(unsigned __int16 *)(a4 + 50);
  v12 = *(unsigned __int16 *)(a4 + 54);
  v13 = (int *)a3[534];
  v14 = **(_DWORD **)(v10 + 72);
  v57 = *(_QWORD *)(v10 + 120);
  v15 = *(unsigned __int16 *)(a4 + 62);
  src = __PAIR64__(v12, v11);
  v16 = *(unsigned __int16 *)(a4 + 58);
  *(_DWORD *)v56 = v14;
  v62 = v15;
  v63 = v16;
  v17 = *(_DWORD *)(a4 + 44);
  v59 = *(_DWORD *)(a4 + 40);
  v60 = v17;
  v18 = *(_DWORD *)(a4 + 36);
  v19 = v13[2];
  LODWORD(v58) = *(_DWORD *)(a4 + 32);
  HIDWORD(v58) = v18;
  hfi_util_u32_prop_helper_add_prop_by_obj(v9, 196613, v19, 2, &src, 0x10u);
  hfi_util_u32_prop_helper_add_prop_by_obj(v9, 196614, v13[2], 2, &v58, 0x10u);
  hfi_util_u32_prop_helper_add_prop(v9, 131096, 0, (_QWORD *)v13 + 1, 4u);
  sde_plane_get_scanout_info(a3, a4, v10, a3 + 277);
  hfi_util_u32_prop_helper_add_prop_by_obj(v9, 196618, v13[2], 2, a3 + 280, 0x10u);
  hfi_util_u32_prop_helper_add_prop_by_obj(v9, 196620, v13[2], 2, a3 + 284, 0x10u);
  hfi_format = hfi_catalog_get_hfi_format((unsigned int *)v56, v20, v21);
  v23 = v13[2];
  HIDWORD(v64[0]) = hfi_format;
  hfi_util_u32_prop_helper_add_prop_by_obj(v9, 196619, v23, 2, (_QWORD *)((char *)v64 + 4), 4u);
  v24 = v13[2];
  LODWORD(v64[0]) = *(_DWORD *)(a4 + 2740) & 0x3F;
  sde_evtlog_log(sde_dbg_base_evtlog, "_hfi_plane_add_drm_props", 182, -1, 196630, v64[0], v24, -1059143953, v56[0]);
  hfi_util_u32_prop_helper_add_prop_by_obj(v9, 196630, v13[2], 2, v64, 4u);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v13 )
      v25 = *(_DWORD *)(*(_QWORD *)v13 + 104LL);
    else
      v25 = -1;
    _drm_dev_dbg(0, 0, 0, "plane%d done adding drm props\n", v25);
  }
  v26 = (int *)v4[8];
  if ( v26 )
  {
    v27 = a3[221];
    if ( !v27
      || (v28 = *(_DWORD *)(a3[534] + 8LL),
          LODWORD(src) = *(_QWORD *)(v27 + 752),
          hfi_util_u32_prop_helper_add_prop_by_obj(v26, 196612, v28, 0, &src, 4u),
          (v26 = (int *)v4[8]) != nullptr) )
    {
      v29 = a3[221];
      if ( v29 )
      {
        v30 = *(_DWORD *)(v29 + 784);
        v31 = *(_DWORD *)(a3[534] + 8LL);
        if ( (*(_QWORD *)(a3[301] + 22008LL) & 0x400000000000LL) == 0 )
          v30 <<= 8;
        LODWORD(src) = v30;
        hfi_util_u32_prop_helper_add_prop_by_obj(v26, 196611, v31, 0, &src, 4u);
        v26 = (int *)v4[8];
        if ( !v26 )
          goto LABEL_41;
      }
      if ( a3[221] )
      {
        v32 = *(_QWORD *)(a4 + 1456);
        v33 = a3[534];
        LODWORD(src) = v32;
        if ( (unsigned int)v32 >= 6 )
        {
          printk(&unk_212015, "_sde_hfi_add_base_prop_helper");
          v35 = (int *)v4[8];
          if ( v35 )
            goto LABEL_21;
LABEL_41:
          v40 = nullptr;
          goto LABEL_42;
        }
        if ( (unsigned int)v32 > 5uLL )
          goto LABEL_58;
        v34 = *(_DWORD *)(v33 + 8);
        LODWORD(src) = hfi_plane_blend_ops_map[(unsigned int)v32];
        hfi_util_u32_prop_helper_add_prop_by_obj(v26, 196610, v34, 0, &src, 4u);
      }
    }
  }
  v35 = (int *)v4[8];
  if ( !v35 )
    goto LABEL_41;
LABEL_21:
  v36 = a3[221];
  if ( v36 )
  {
    hfi_util_u32_prop_helper_add_prop_by_obj(v35, 196616, *(_DWORD *)(a3[534] + 8LL), 0, (_QWORD *)(v36 + 2926), 4u);
    v35 = (int *)v4[8];
    if ( !v35 )
      goto LABEL_41;
  }
  v37 = a3[221];
  if ( v37 )
  {
    hfi_util_u32_prop_helper_add_prop_by_obj(v35, 196617, *(_DWORD *)(a3[534] + 8LL), 0, (_QWORD *)(v37 + 2924), 4u);
    v35 = (int *)v4[8];
    if ( !v35 )
      goto LABEL_41;
  }
  if ( !a3[221] || (v38 = *(_QWORD *)(a4 + 1552), !(_DWORD)v38) )
  {
LABEL_30:
    v40 = (int *)v4[8];
    if ( v40 )
      goto LABEL_31;
    goto LABEL_42;
  }
  if ( (unsigned int)v38 >= 3 )
  {
    printk(&unk_212015, "_sde_hfi_add_base_prop_helper");
    v40 = (int *)v4[8];
    if ( v40 )
    {
LABEL_31:
      v41 = a3[221];
      if ( v41 )
      {
        v42 = *(_DWORD *)(v41 + 1392);
        v43 = *(_DWORD *)(a3[534] + 8LL);
        if ( (*(_QWORD *)(a3[301] + 22008LL) & 0x400000000000LL) == 0 )
          v42 <<= 8;
        LODWORD(src) = v42;
        hfi_util_u32_prop_helper_add_prop_by_obj(v40, 196622, v43, 0, &src, 4u);
        v40 = (int *)v4[8];
      }
    }
LABEL_42:
    if ( !(unsigned int)hfi_util_u32_prop_helper_prop_count((__int64)v40) )
    {
LABEL_49:
      mutex_unlock(v4 + 2);
      result = hfi_plane_populate_custom_kv_setter_props((__int64)a3, a2, v50, a1);
      if ( !(_DWORD)result )
        goto LABEL_50;
      v45 = result;
      v51 = &unk_2349FC;
LABEL_55:
      printk(v51, "_hfi_plane_populate_props");
      result = v45;
      goto LABEL_50;
    }
    payload_addr = hfi_util_u32_prop_helper_get_payload_addr(v4[8]);
    size = hfi_util_u32_prop_helper_get_size((__int64)v4[8]);
    v48 = hfi_adapter_add_set_property(a1, 33554433, a2, 2u, (__int64)payload_addr, size, 4);
    if ( !v48 )
    {
      if ( (_drm_debug & 4) != 0 )
      {
        if ( v4 )
          v49 = (*v4)[26];
        else
          v49 = -1;
        _drm_dev_dbg(0, 0, 0, "plane%d done adding all base props\n", v49);
      }
      goto LABEL_49;
    }
    v45 = v48;
    printk(&unk_24FA34, "_hfi_plane_set_props_base");
    goto LABEL_53;
  }
  if ( (*(_QWORD *)(a4 + 1552) & 3LL) != 3 )
  {
    v39 = *(_DWORD *)(a3[534] + 8LL);
    LODWORD(src) = hfi_plane_multirect_mode_map[*(_QWORD *)(a4 + 1552) & 3LL];
    hfi_util_u32_prop_helper_add_prop_by_obj(v35, 196621, v39, 0, &src, 4u);
    goto LABEL_30;
  }
LABEL_58:
  __break(1u);
  v52 = MEMORY[0x7D6FAC4]();
  return hfi_plane_disable(v52, v53, v54, v55);
}
