__int64 __fastcall sde_crtc_set_qos_dirty(
        int *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v9; // x9
  __int64 *v10; // x8
  int v11; // w5
  __int64 v12; // x11
  int v13; // w4
  __int64 v14; // x8
  __int64 *v15; // x22
  int v16; // w20
  int v17; // w22
  unsigned int v18; // w23
  int v19; // w21
  unsigned int v20; // w8
  int v21; // w20
  int v22; // w0
  int v23; // w24
  char v24; // w0
  __int64 result; // x0
  char v26; // [xsp+0h] [xbp-30h]
  unsigned int v27; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)a1;
  v10 = *(__int64 **)(*(_QWORD *)a1 + 840LL);
  if ( v10 == (__int64 *)(*(_QWORD *)a1 + 840LL) )
  {
    v11 = 0;
  }
  else
  {
    v11 = 0;
    do
    {
      if ( ((*(_DWORD *)(*((_QWORD *)a1 + 251) + 12LL) >> *((_DWORD *)v10 + 437)) & 1) != 0 )
      {
        v12 = v10[220];
        if ( v12 )
        {
          *(_DWORD *)(v12 + 1772) |= 0x200u;
          v9 = *(_QWORD *)a1;
          v11 |= 1 << *((_DWORD *)v10 + 437);
        }
      }
      v10 = (__int64 *)*v10;
    }
    while ( v10 != (__int64 *)(v9 + 840) );
  }
  if ( a1 )
    v13 = a1[28];
  else
    v13 = -1;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_set_qos_dirty", 8082, -1, v13, v11, -1059143953, a8, v26);
  v14 = *(_QWORD *)a1;
  v27 = 0;
  v15 = *(__int64 **)(v14 + 816);
  if ( v15 == (__int64 *)(v14 + 816) )
    goto LABEL_19;
  do
  {
    if ( ((*(_DWORD *)(*((_QWORD *)a1 + 251) + 20LL) >> *((_DWORD *)v15 + 15)) & 1) != 0
      && (sde_encoder_check_curr_mode(v15 - 1, 2) & 1) != 0 )
    {
      sde_encoder_get_transfer_time(v15 - 1, &v27);
    }
    v15 = (__int64 *)*v15;
  }
  while ( v15 != (__int64 *)(*(_QWORD *)a1 + 816LL) );
  v16 = v27;
  if ( !v27 )
  {
LABEL_19:
    v21 = drm_mode_vrefresh(a1 + 44) * *((unsigned __int16 *)a1 + 98) + 999999999;
    v22 = drm_mode_vrefresh(a1 + 44);
    v19 = *((unsigned __int16 *)a1 + 98);
    v17 = *((unsigned __int16 *)a1 + 95);
    v18 = 0;
    v20 = v21 / (v22 * v19);
    v16 = v27;
  }
  else
  {
    v17 = *((unsigned __int16 *)a1 + 95);
    v18 = (v27 + 999999) / v27;
    v19 = *((unsigned __int16 *)a1 + 98);
    v20 = (v18 * v17 + 999999999) / (v18 * v17);
  }
  v23 = sde_dbg_base_evtlog;
  a1[1969] = v20;
  v24 = drm_mode_vrefresh(a1 + 44);
  result = sde_evtlog_log(v23, "sde_crtc_update_line_time", 8062, -1, v16, v18, v17, v19, v24);
  _ReadStatusReg(SP_EL0);
  return result;
}
