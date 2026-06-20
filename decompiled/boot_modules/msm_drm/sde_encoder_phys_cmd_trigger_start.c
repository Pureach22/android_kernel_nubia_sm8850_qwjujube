__int64 __fastcall sde_encoder_phys_cmd_trigger_start(__int64 result)
{
  __int64 v1; // x8
  unsigned int *v2; // x19
  __int64 v3; // x8
  unsigned int v4; // w20
  int v5; // w4
  unsigned int v12; // w9
  _QWORD v13[3]; // [xsp+48h] [xbp-78h] BYREF
  __int64 v14; // [xsp+60h] [xbp-60h]
  __int64 v15; // [xsp+68h] [xbp-58h]
  __int64 v16; // [xsp+70h] [xbp-50h]
  __int64 v17; // [xsp+78h] [xbp-48h]
  __int64 v18; // [xsp+80h] [xbp-40h]
  __int64 v19; // [xsp+88h] [xbp-38h]
  __int64 v20; // [xsp+90h] [xbp-30h]
  __int64 v21; // [xsp+98h] [xbp-28h]
  __int64 v22; // [xsp+A0h] [xbp-20h]
  __int64 v23; // [xsp+A8h] [xbp-18h]
  __int64 v24; // [xsp+B0h] [xbp-10h]
  __int64 v25; // [xsp+B8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 0;
  memset(v13, 0, sizeof(v13));
  if ( result )
  {
    v1 = *(_QWORD *)(result + 8);
    v2 = (unsigned int *)result;
    if ( v1 && (v3 = *(_QWORD *)(v1 + 2512)) != 0 && (v4 = *(_DWORD *)(v3 + 1440)) != 0 )
    {
      sde_encoder_phys_cmd_config_autorefresh(result, v4);
      _X8 = v2 + 674;
      __asm { PRFM            #0x11, [X8] }
      do
        v12 = __ldxr(_X8);
      while ( __stxr(v12 + 1, _X8) );
    }
    else
    {
      ((void (__fastcall *)(__int64))sde_encoder_helper_trigger_start)(result);
      v4 = 0;
    }
    ((void (__fastcall *)(_QWORD, _QWORD *))sde_encoder_helper_get_pp_line_count)(*(_QWORD *)v2, v13);
    if ( *(_QWORD *)v2 )
      v5 = *(_DWORD *)(*(_QWORD *)v2 + 24LL);
    else
      v5 = -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_phys_cmd_trigger_start",
               2538,
               -1,
               v5,
               v4,
               v13[0],
               SHIDWORD(v13[0]),
               v14);
    *((_BYTE *)v2 + 2760) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
