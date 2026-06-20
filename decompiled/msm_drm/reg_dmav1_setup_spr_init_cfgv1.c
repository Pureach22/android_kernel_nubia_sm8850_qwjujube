__int64 __fastcall reg_dmav1_setup_spr_init_cfgv1(int *a1, char **a2)
{
  __int64 result; // x0
  char *v5; // x21
  __int64 (__fastcall *v6)(_QWORD); // x8
  int v7; // w0
  _BYTE v8[4]; // [xsp+10h] [xbp-60h] BYREF
  int v9; // [xsp+14h] [xbp-5Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-58h] BYREF
  __int64 v11; // [xsp+20h] [xbp-50h] BYREF
  unsigned __int64 v12; // [xsp+28h] [xbp-48h] BYREF
  int v13; // [xsp+30h] [xbp-40h]
  __int64 v14; // [xsp+34h] [xbp-3Ch]
  int v15; // [xsp+3Ch] [xbp-34h]
  __int64 v16; // [xsp+40h] [xbp-30h]
  __int64 v17; // [xsp+48h] [xbp-28h]
  __int64 v18; // [xsp+50h] [xbp-20h]
  __int64 v19; // [xsp+58h] [xbp-18h]
  __int64 v20; // [xsp+60h] [xbp-10h]
  __int64 v21; // [xsp+68h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11 = 0;
  v9 = 0;
  v8[0] = 0;
  result = ((__int64 (__fastcall *)(int *, char **, __int64 *, int *, __int64 *, _BYTE *))reg_dmav1_get_spr_target)(
             a1,
             a2,
             &v11,
             &v9,
             &v10,
             v8);
  if ( !(_DWORD)result )
  {
    if ( v8[0] == 1 )
    {
      sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_spr_init_cfgv1", 6992, -1, a1[16], a1[374], a1[7], 0, 239);
      result = reg_dmav1_disable_spr((__int64)a1, (__int64)a2);
    }
    else
    {
      v19 = 0;
      v20 = 0;
      v5 = *a2;
      v13 = 12;
      v15 = 0;
      v14 = 0;
      v16 = v10;
      v17 = 0;
      v18 = 0;
      v6 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      v12 = 0x8000000000000000LL;
      if ( *((_DWORD *)v6 - 1) != -1839634494 )
        __break(0x8228u);
      v7 = v6(&v12);
      if ( v7 )
      {
        result = _drm_err("spr write decode select failed ret %d\n", v7);
      }
      else if ( (*v5 & 1) != 0
             || (result = reg_dmav1_setup_spr_init_common((__int64)a1, (__int64)v5, (__int64)&v12, v11), !(_DWORD)result) )
      {
        result = reg_dmav1_setup_spr_init_kickoff(a1[374], 1, v9, v11, (__int64)a2, v5, (__int64)&v12);
        if ( !(_DWORD)result )
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "reg_dmav1_setup_spr_init_cfgv1",
                     7013,
                     -1,
                     a1[16],
                     a1[374],
                     a1[7],
                     1,
                     239);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
