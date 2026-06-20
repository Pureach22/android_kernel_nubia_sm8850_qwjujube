__int64 __fastcall reg_dmav1_setup_spr_init_cfgv2(int *a1, __int64 a2)
{
  __int64 v2; // d14
  __int64 result; // x0
  __int64 v6; // x15
  __int64 v7; // d3
  __int64 v8; // x8
  int v9; // w8
  bool v10; // zf
  char *v11; // x21
  __int64 (__fastcall *v12)(_QWORD); // x8
  int v13; // w0
  _BYTE v14[4]; // [xsp+10h] [xbp-60h] BYREF
  int v15; // [xsp+14h] [xbp-5Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-58h] BYREF
  __int64 v17; // [xsp+20h] [xbp-50h] BYREF
  unsigned __int64 v18; // [xsp+28h] [xbp-48h] BYREF
  int v19; // [xsp+30h] [xbp-40h]
  __int64 v20; // [xsp+34h] [xbp-3Ch]
  int v21; // [xsp+3Ch] [xbp-34h]
  __int64 v22; // [xsp+40h] [xbp-30h]
  __int64 v23; // [xsp+48h] [xbp-28h]
  __int64 v24; // [xsp+50h] [xbp-20h]
  __int64 v25; // [xsp+58h] [xbp-18h]
  __int64 v26; // [xsp+60h] [xbp-10h]
  __int64 v27; // [xsp+68h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v14[0] = 0;
  result = ((__int64 (__fastcall *)(int *, __int64, __int64 *, int *, __int64 *, _BYTE *))reg_dmav1_get_spr_target)(
             a1,
             a2,
             &v17,
             &v15,
             &v16,
             v14);
  if ( (_DWORD)result )
    goto LABEL_10;
  v8 = *(unsigned int *)(a2 + 176);
  *(_DWORD *)(a2 + 160) = *(_DWORD *)(a2 + 160) & 0xFF0F0FFF | 0x2000;
  if ( (unsigned int)v8 < 5 )
  {
    v9 = hfi_dspp_idx_map[v8];
    v10 = v14[0] == 1;
    *(_DWORD *)(a2 + 168) = v9;
    if ( v10 )
    {
      sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_spr_init_cfgv2", 7038, -1, a1[16], a1[374], a1[7], 0, 239);
      result = reg_dmav1_disable_spr((__int64)a1, a2);
    }
    else
    {
      v25 = 0;
      v26 = 0;
      *(_DWORD *)(a2 + 168) = v9 | 1;
      v11 = *(char **)a2;
      v19 = 12;
      v21 = 0;
      v20 = 0;
      v22 = v16;
      v23 = 0;
      v24 = 0;
      v12 = *(__int64 (__fastcall **)(_QWORD))(v17 + 8);
      v18 = 0x8000000000000000LL;
      if ( *((_DWORD *)v12 - 1) != -1839634494 )
        __break(0x8228u);
      v13 = v12(&v18);
      if ( v13 )
      {
        result = _drm_err("spr write decode select failed ret %d\n", v13);
      }
      else
      {
        if ( (*v11 & 1) != 0 )
        {
          a1[21] = 0;
        }
        else
        {
          result = reg_dmav1_setup_spr_init_common((__int64)a1, (__int64)v11, (__int64)&v18, v17);
          if ( (_DWORD)result )
            goto LABEL_10;
          result = reg_dmav1_setup_spr_cfg5_params((__int64)a1, (__int64)v11, (__int64)&v18, v17);
          if ( (_DWORD)result )
            goto LABEL_10;
        }
        result = reg_dmav1_setup_spr_init_kickoff(a1[374], 2, v15, v17, a2, v11, (__int64)&v18);
        if ( !(_DWORD)result )
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "reg_dmav1_setup_spr_init_cfgv2",
                     7065,
                     -1,
                     a1[16],
                     a1[374],
                     a1[7],
                     1,
                     239);
      }
    }
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  *(_QWORD *)(v6 - 24) = v2;
  *(_QWORD *)(v6 - 16) = v7;
  return reg_dmav1_setup_spr_udc_cfgv2();
}
