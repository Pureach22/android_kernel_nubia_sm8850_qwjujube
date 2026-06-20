__int64 __fastcall sde_encoder_update_caps_for_cont_splash(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x26
  __int64 v5; // x24
  int v6; // w5
  unsigned __int64 v7; // x20
  unsigned __int64 v9; // x27
  __int64 v10; // x28
  __int64 v11; // x8
  unsigned int v12; // w8
  __int64 v13; // x9
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x22
  int v19; // w9
  unsigned int mode_info; // w0
  __int64 v21; // x8
  char v22; // w10
  __int64 v23; // x8
  unsigned int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x5
  void *v27; // x0
  void *v28; // x0
  void *v29; // x0
  __int64 v30; // x8
  __int64 v31; // x21
  __int64 v32; // x1
  __int64 v33; // x21
  unsigned int v34; // w23
  unsigned int v35; // w8
  __int64 v36; // x21
  unsigned int v37; // w23
  unsigned int v38; // w8
  __int64 v39; // x21
  unsigned int v40; // w23
  unsigned int v41; // w8
  unsigned int v42; // w19
  void *v43; // x0
  __int64 result; // x0
  unsigned int v45; // w23
  unsigned int v46; // w8
  __int64 v47; // x21
  unsigned int v48; // w8
  __int64 v49; // x21
  __int64 v50; // x21
  __int64 v51; // x21
  void (__fastcall *v52)(__int64, __int64); // x8
  __int64 (__fastcall *v53)(_QWORD); // x8
  __int64 v54; // x21
  void (__fastcall *v55)(__int64, __int64); // x8
  __int64 (__fastcall *v56)(_QWORD); // x8
  __int64 v57; // x21
  void (__fastcall *v58)(__int64, __int64); // x8
  __int64 (__fastcall *v59)(_QWORD); // x8
  void (__fastcall *v60)(__int64, __int64); // x8
  __int64 (__fastcall *v61)(_QWORD); // x8
  __int64 v62; // [xsp+0h] [xbp-70h] BYREF
  _QWORD v63[3]; // [xsp+8h] [xbp-68h] BYREF
  _QWORD v64[3]; // [xsp+20h] [xbp-50h] BYREF
  _QWORD v65[3]; // [xsp+38h] [xbp-38h] BYREF
  _QWORD v66[4]; // [xsp+50h] [xbp-20h] BYREF

  v66[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  if ( !a1 )
  {
    v29 = &unk_23BA87;
LABEL_57:
    printk(v29, "sde_encoder_update_caps_for_cont_splash");
    goto LABEL_167;
  }
  if ( !*(_QWORD *)a1 )
  {
    v27 = &unk_26FCAB;
    goto LABEL_56;
  }
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 8)) == 0 )
  {
    v27 = &unk_234896;
LABEL_56:
    printk(v27, "sde_encoder_get_kms");
    v29 = &unk_25E374;
    goto LABEL_57;
  }
  v6 = *(_DWORD *)(v4 + 4064);
  if ( !v6 )
  {
    v28 = &unk_24922A;
    goto LABEL_166;
  }
  v7 = a3;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "enc%d num of connectors: %d\n", *(_DWORD *)(a1 + 24), v6);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "enc%d enable: %d\n", *(_DWORD *)(a1 + 24), v7 & 1);
  }
  if ( (v7 & 1) == 0 )
  {
    v12 = *(_DWORD *)(a1 + 196);
    if ( v12 )
    {
      v13 = *(_QWORD *)(a1 + 200);
      if ( v13 )
      {
        *(_BYTE *)(v13 + 2289) = 0;
        v12 = *(_DWORD *)(a1 + 196);
      }
      if ( v12 >= 2 )
      {
        v14 = *(_QWORD *)(a1 + 208);
        if ( v14 )
        {
          *(_BYTE *)(v14 + 2289) = 0;
          v12 = *(_DWORD *)(a1 + 196);
        }
        if ( v12 >= 3 )
        {
          v15 = *(_QWORD *)(a1 + 216);
          if ( v15 )
          {
            *(_BYTE *)(v15 + 2289) = 0;
            v12 = *(_DWORD *)(a1 + 196);
          }
          if ( v12 >= 4 )
          {
            v16 = *(_QWORD *)(a1 + 224);
            if ( !v16 )
              goto LABEL_36;
            *(_BYTE *)(v16 + 2289) = 0;
            goto LABEL_35;
          }
        }
      }
    }
LABEL_164:
    result = 0;
    goto LABEL_168;
  }
  if ( !a2 )
  {
    v28 = &unk_22ACD9;
    goto LABEL_166;
  }
  if ( !*(_DWORD *)(v4 + 4064) )
  {
LABEL_53:
    v28 = &unk_23F38C;
    goto LABEL_166;
  }
  v9 = 0;
  v10 = v4 + 4072;
  while ( 1 )
  {
    if ( (_drm_debug & 4) == 0 )
    {
      if ( v9 > 0xF )
        goto LABEL_37;
      goto LABEL_20;
    }
    if ( v9 > 0xF )
      break;
    _drm_dev_dbg(
      0,
      0,
      0,
      "enc%d connector id: %d\n",
      *(_DWORD *)(a1 + 24),
      *(_DWORD *)(*(_QWORD *)(v10 + 8 * v9) + 64LL));
LABEL_20:
    v7 = *(_QWORD *)(v10 + 8 * v9);
    v11 = *(_QWORD *)(v7 + 2744);
    if ( v11 )
    {
      if ( *(_DWORD *)(v11 + 24) == *(_DWORD *)(a1 + 24) )
        goto LABEL_38;
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "enc%d encoder not attached to connector\n", *(_DWORD *)(a1 + 24));
    }
    if ( ++v9 >= *(unsigned int *)(v4 + 4064) )
      goto LABEL_53;
  }
  while ( 1 )
  {
    while ( 1 )
    {
LABEL_37:
      __break(0x5512u);
LABEL_38:
      if ( !v7 )
        goto LABEL_53;
      v17 = *(_QWORD *)(v7 + 2512);
      if ( !v17 )
        goto LABEL_53;
      if ( !*(_QWORD *)(v7 + 2952) )
      {
        v28 = &unk_273800;
        goto LABEL_166;
      }
      v18 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 2008LL);
      if ( *(_BYTE *)(a2 + 74) )
        v19 = 1;
      else
        v19 = 2;
      LODWORD(v62) = v19;
      mode_info = sde_connector_get_mode_info(v7, v18 + 24, &v62, v17 + 2208);
      if ( mode_info )
      {
        v42 = mode_info;
        v43 = &unk_26C893;
LABEL_100:
        printk(v43, "sde_encoder_update_caps_for_cont_splash");
        result = v42;
        goto LABEL_168;
      }
      v21 = *(_QWORD *)(v7 + 2744);
      if ( v21 )
      {
        v22 = _drm_debug;
        *(_QWORD *)(*(_QWORD *)(v7 + 2512) + 16LL) = v21;
        if ( (v22 & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "enc%d configured cstate->best_encoder to ID = %d\n",
            *(_DWORD *)(a1 + 24),
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 2512) + 16LL) + 24LL));
      }
      else
      {
        printk(&unk_2272ED, "sde_encoder_update_caps_for_cont_splash");
      }
      v23 = *(_QWORD *)(a1 + 80);
      *(_QWORD *)(a1 + 1360) = v23;
      v24 = sde_rm_reserve(v5 + 2144, a1, *(_QWORD *)(v23 + 2008), *(_QWORD *)(v7 + 2512), 0);
      if ( v24 )
      {
        v42 = v24;
        v43 = &unk_256EF0;
        goto LABEL_100;
      }
      if ( (_drm_debug & 4) != 0 )
      {
        v25 = *(_QWORD *)(v7 + 2512);
        v26 = v25 ? *(_QWORD *)(v25 + 1376) : 0LL;
        _drm_dev_dbg(0, 0, 0, "enc%d connector topology = %llu\n", *(_DWORD *)(a1 + 24), v26);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "enc%d hdisplay = %d, vdisplay = %d\n",
            *(_DWORD *)(a1 + 24),
            *(unsigned __int16 *)(v18 + 28),
            *(unsigned __int16 *)(v18 + 38));
      }
      drm_set_preferred_mode(v7, *(unsigned __int16 *)(v18 + 28), *(unsigned __int16 *)(v18 + 38));
      v30 = *(_QWORD *)(a1 + 88);
      if ( v30 == a1 + 88 || (v31 = v30 - 120, v30 == 120) )
      {
        printk(&unk_27A14D, "sde_encoder_update_caps_for_cont_splash");
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "enc%d Bridge mapped to encoder\n", *(_DWORD *)(a1 + 24));
        drm_bridge_chain_mode_set(v31, v18 + 24, v18 + 24);
      }
      v32 = *(unsigned int *)(a1 + 24);
      memset(v66, 0, 24);
      memset(v65, 0, sizeof(v65));
      memset(v64, 0, sizeof(v64));
      memset(v63, 0, sizeof(v63));
      sde_rm_init_hw_iter(v65, v32, 7);
      *(_QWORD *)(a1 + 336) = 0;
      if ( (sde_rm_get_hw(v5 + 2144, v65) & 1) != 0 )
      {
        *(_QWORD *)(a1 + 336) = v65[0];
        *(_QWORD *)(a1 + 344) = 0;
        if ( (sde_rm_get_hw(v5 + 2144, v65) & 1) != 0 )
        {
          *(_QWORD *)(a1 + 344) = v65[0];
          *(_QWORD *)(a1 + 352) = 0;
          if ( (sde_rm_get_hw(v5 + 2144, v65) & 1) != 0 )
          {
            *(_QWORD *)(a1 + 352) = v65[0];
            *(_QWORD *)(a1 + 360) = 0;
            if ( (sde_rm_get_hw(v5 + 2144, v65) & 1) != 0 )
              *(_QWORD *)(a1 + 360) = v65[0];
          }
        }
      }
      sde_rm_init_hw_iter(v66, *(unsigned int *)(a1 + 24), 10);
      *(_QWORD *)(a1 + 368) = 0;
      if ( (sde_rm_get_hw(v5 + 2144, v66) & 1) != 0 )
      {
        *(_QWORD *)(a1 + 368) = v66[0];
        *(_QWORD *)(a1 + 376) = 0;
        if ( (sde_rm_get_hw(v5 + 2144, v66) & 1) != 0 )
        {
          *(_QWORD *)(a1 + 376) = v66[0];
          *(_QWORD *)(a1 + 384) = 0;
          if ( (sde_rm_get_hw(v5 + 2144, v66) & 1) != 0 )
          {
            *(_QWORD *)(a1 + 384) = v66[0];
            *(_QWORD *)(a1 + 392) = 0;
            if ( (sde_rm_get_hw(v5 + 2144, v66) & 1) != 0 )
              *(_QWORD *)(a1 + 392) = v66[0];
          }
        }
      }
      if ( !*(_DWORD *)(a1 + 196) )
        goto LABEL_171;
      v33 = *(_QWORD *)(a1 + 200);
      *(_QWORD *)(v33 + 416) = 0;
      sde_rm_init_hw_iter(v64, *(unsigned int *)(a1 + 24), 5);
      if ( !*(_DWORD *)(a1 + 196) )
        goto LABEL_171;
      v34 = 0;
      do
      {
        if ( (sde_rm_get_hw(v5 + 2144, v64) & 1) != 0 )
          *(_QWORD *)(v33 + 416) = v64[0];
        v35 = *(_DWORD *)(a1 + 196);
        ++v34;
      }
      while ( v34 < v35 );
      if ( v35 < 2 )
        goto LABEL_171;
      v36 = *(_QWORD *)(a1 + 208);
      *(_QWORD *)(v36 + 416) = 0;
      sde_rm_init_hw_iter(v64, *(unsigned int *)(a1 + 24), 5);
      if ( !*(_DWORD *)(a1 + 196) )
        goto LABEL_171;
      v37 = 0;
      do
      {
        if ( (sde_rm_get_hw(v5 + 2144, v64) & 1) != 0 )
          *(_QWORD *)(v36 + 416) = v64[0];
        v38 = *(_DWORD *)(a1 + 196);
        ++v37;
      }
      while ( v37 < v38 );
      if ( v38 < 3 )
        goto LABEL_171;
      v39 = *(_QWORD *)(a1 + 216);
      *(_QWORD *)(v39 + 416) = 0;
      sde_rm_init_hw_iter(v64, *(unsigned int *)(a1 + 24), 5);
      if ( !*(_DWORD *)(a1 + 196) )
        goto LABEL_171;
      v40 = 0;
      do
      {
        if ( (sde_rm_get_hw(v5 + 2144, v64) & 1) != 0 )
          *(_QWORD *)(v39 + 416) = v64[0];
        v41 = *(_DWORD *)(a1 + 196);
        ++v40;
      }
      while ( v40 < v41 );
      if ( v41 < 4 )
        goto LABEL_171;
      a2 = *(_QWORD *)(a1 + 224);
      *(_QWORD *)(a2 + 416) = 0;
      sde_rm_init_hw_iter(v64, *(unsigned int *)(a1 + 24), 5);
      if ( !*(_DWORD *)(a1 + 196) )
        goto LABEL_171;
      v45 = 0;
      do
      {
        if ( (sde_rm_get_hw(v5 + 2144, v64) & 1) != 0 )
          *(_QWORD *)(a2 + 416) = v64[0];
        v46 = *(_DWORD *)(a1 + 196);
        ++v45;
      }
      while ( v45 < v46 );
      if ( v46 <= 4 )
      {
LABEL_171:
        sde_rm_init_hw_iter(v63, *(unsigned int *)(a1 + 24), 8);
        if ( !*(_DWORD *)(a1 + 196) )
          goto LABEL_164;
        v47 = *(_QWORD *)(a1 + 200);
        *(_QWORD *)(v47 + 424) = 0;
        if ( (sde_rm_get_hw(v5 + 2144, v63) & 1) == 0 )
        {
LABEL_119:
          v48 = *(_DWORD *)(a1 + 196);
          break;
        }
        *(_QWORD *)(v47 + 424) = v63[0];
        v48 = *(_DWORD *)(a1 + 196);
        if ( v48 < 2 )
          break;
        v49 = *(_QWORD *)(a1 + 208);
        *(_QWORD *)(v49 + 424) = 0;
        if ( (sde_rm_get_hw(v5 + 2144, v63) & 1) == 0 )
          goto LABEL_119;
        *(_QWORD *)(v49 + 424) = v63[0];
        v48 = *(_DWORD *)(a1 + 196);
        if ( v48 < 3 )
          break;
        v50 = *(_QWORD *)(a1 + 216);
        *(_QWORD *)(v50 + 424) = 0;
        if ( (sde_rm_get_hw(v5 + 2144, v63) & 1) == 0 )
          goto LABEL_119;
        *(_QWORD *)(v50 + 424) = v63[0];
        v48 = *(_DWORD *)(a1 + 196);
        if ( v48 < 4 )
          break;
        a2 = *(_QWORD *)(a1 + 224);
        *(_QWORD *)(a2 + 424) = 0;
        if ( (sde_rm_get_hw(v5 + 2144, v63) & 1) == 0 )
          goto LABEL_119;
        *(_QWORD *)(a2 + 424) = v63[0];
        v48 = *(_DWORD *)(a1 + 196);
        if ( v48 <= 4 )
          break;
      }
    }
    if ( !v48 )
      goto LABEL_164;
    v51 = *(_QWORD *)(a1 + 200);
    if ( !v51 )
      break;
    *(_QWORD *)(v51 + 8) = v7;
    *(_BYTE *)(v51 + 2289) = 1;
    v52 = *(void (__fastcall **)(__int64, __int64))(v51 + 56);
    *(_QWORD *)(v51 + 496) = *(_QWORD *)(a1 + 336);
    if ( v52 )
    {
      if ( *((_DWORD *)v52 - 1) != 1476624813 )
        __break(0x8228u);
      v52(v51, v18 + 24);
    }
    v53 = *(__int64 (__fastcall **)(_QWORD))(v51 + 32);
    if ( v53 )
    {
      if ( *((_DWORD *)v53 - 1) != -1375811177 )
        __break(0x8228u);
      if ( (v53(v51) & 1) != 0 )
        *(_QWORD *)(a1 + 328) = v51;
    }
    if ( *(_DWORD *)(a1 + 196) < 2u )
      goto LABEL_164;
    v54 = *(_QWORD *)(a1 + 208);
    if ( !v54 )
      break;
    *(_QWORD *)(v54 + 8) = v7;
    *(_BYTE *)(v54 + 2289) = 1;
    v55 = *(void (__fastcall **)(__int64, __int64))(v54 + 56);
    *(_QWORD *)(v54 + 496) = *(_QWORD *)(a1 + 344);
    if ( v55 )
    {
      if ( *((_DWORD *)v55 - 1) != 1476624813 )
        __break(0x8228u);
      v55(v54, v18 + 24);
    }
    v56 = *(__int64 (__fastcall **)(_QWORD))(v54 + 32);
    if ( v56 )
    {
      if ( *((_DWORD *)v56 - 1) != -1375811177 )
        __break(0x8228u);
      if ( (v56(v54) & 1) != 0 )
        *(_QWORD *)(a1 + 328) = v54;
    }
    if ( *(_DWORD *)(a1 + 196) < 3u )
      goto LABEL_164;
    v57 = *(_QWORD *)(a1 + 216);
    if ( !v57 )
      break;
    *(_QWORD *)(v57 + 8) = v7;
    *(_BYTE *)(v57 + 2289) = 1;
    v58 = *(void (__fastcall **)(__int64, __int64))(v57 + 56);
    *(_QWORD *)(v57 + 496) = *(_QWORD *)(a1 + 352);
    if ( v58 )
    {
      if ( *((_DWORD *)v58 - 1) != 1476624813 )
        __break(0x8228u);
      v58(v57, v18 + 24);
    }
    v59 = *(__int64 (__fastcall **)(_QWORD))(v57 + 32);
    if ( v59 )
    {
      if ( *((_DWORD *)v59 - 1) != -1375811177 )
        __break(0x8228u);
      if ( (v59(v57) & 1) != 0 )
        *(_QWORD *)(a1 + 328) = v57;
    }
    if ( *(_DWORD *)(a1 + 196) < 4u )
      goto LABEL_164;
    a2 = *(_QWORD *)(a1 + 224);
    if ( !a2 )
      break;
    *(_QWORD *)(a2 + 8) = v7;
    *(_BYTE *)(a2 + 2289) = 1;
    v60 = *(void (__fastcall **)(__int64, __int64))(a2 + 56);
    *(_QWORD *)(a2 + 496) = *(_QWORD *)(a1 + 360);
    if ( v60 )
    {
      if ( *((_DWORD *)v60 - 1) != 1476624813 )
        __break(0x8228u);
      v60(a2, v18 + 24);
    }
    v61 = *(__int64 (__fastcall **)(_QWORD))(a2 + 32);
    if ( v61 )
    {
      if ( *((_DWORD *)v61 - 1) != -1375811177 )
        __break(0x8228u);
      if ( (v61(a2) & 1) != 0 )
        *(_QWORD *)(a1 + 328) = a2;
    }
LABEL_35:
    v12 = *(_DWORD *)(a1 + 196);
LABEL_36:
    if ( v12 <= 4 )
      goto LABEL_164;
  }
  v28 = &unk_219810;
LABEL_166:
  printk(v28, "sde_encoder_update_caps_for_cont_splash");
LABEL_167:
  result = 4294967274LL;
LABEL_168:
  _ReadStatusReg(SP_EL0);
  return result;
}
