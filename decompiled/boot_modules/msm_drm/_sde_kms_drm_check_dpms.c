__int64 __fastcall sde_kms_drm_check_dpms(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x25
  __int64 v4; // x26
  __int64 v5; // x8
  _QWORD *v6; // x28
  __int64 v7; // x20
  __int64 v8; // x27
  int v9; // w21
  __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w22
  __int64 v13; // x8
  __int64 v14; // x23
  int v15; // w8
  int v16; // w23
  int v17; // w8
  int v18; // w24
  int v20; // w20
  bool is_primary_display; // w0
  __int64 v22; // x8
  __int64 v23; // x0
  char v24; // [xsp+2Ch] [xbp-24h]
  unsigned __int64 v25; // [xsp+30h] [xbp-20h] BYREF
  __int64 v26; // [xsp+38h] [xbp-18h]
  __int64 v27; // [xsp+40h] [xbp-10h]
  __int64 v28; // [xsp+48h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(int *)(result + 40) >= 1 )
  {
    v2 = result;
    v3 = 0;
    v4 = 0;
    v26 = 0;
    v27 = 0;
    v24 = a2 & 1;
    v25 = 0;
    while ( 1 )
    {
      v5 = *(_QWORD *)(v2 + 48);
      v6 = *(_QWORD **)(v5 + v3);
      if ( !v6 )
        goto LABEL_3;
      v7 = *(_QWORD *)(v5 + v3 + 16);
      v8 = *(_QWORD *)(v6[314] + 8LL);
      if ( !v8 )
      {
        v8 = *(_QWORD *)(v7 + 8);
        if ( !v8 )
          goto LABEL_3;
      }
      result = drm_mode_vrefresh(*(_QWORD *)(v8 + 2008) + 144LL);
      v9 = result;
      if ( *(_BYTE *)(*(_QWORD *)(v8 + 2008) + 9LL) != 1 )
        goto LABEL_12;
      v10 = v6[314];
      if ( v10 )
        break;
      v12 = 2;
      v13 = *(_QWORD *)(v7 + 8);
      if ( !v13 )
      {
LABEL_19:
        v16 = 0;
        goto LABEL_20;
      }
LABEL_13:
      v14 = *(_QWORD *)(*(_QWORD *)(v2 + 32) + 56LL * *(unsigned int *)(v13 + 160) + 8);
      result = drm_mode_vrefresh(v14 + 144);
      v15 = *(unsigned __int8 *)(v14 + 9);
      v16 = result;
      if ( v15 == 1 )
      {
        if ( !v7 )
          goto LABEL_36;
        v17 = *(_DWORD *)(v7 + 1472);
        if ( (unsigned int)(v17 - 1) < 2 )
        {
          v18 = 3;
          if ( v12 != 3 )
            goto LABEL_22;
          goto LABEL_21;
        }
        if ( !v17 )
        {
LABEL_36:
          v18 = 2;
          if ( v12 != 2 )
          {
LABEL_22:
            sde_evtlog_log(sde_dbg_base_evtlog, "_sde_kms_drm_check_dpms", 1115, -1, v18, v12, v16, v9, v6[344]);
            result = v6[284];
            if ( (!result || (*(_BYTE *)(result + 772) & 1) == 0) && v6[344] )
            {
              if ( v16 != v9 && v18 == v12 )
                v20 = 4;
              else
                v20 = v12;
              is_primary_display = sde_encoder_is_primary_display(result);
              v22 = v6[344];
              v25 = __PAIR64__(v16, v20);
              v27 = v22;
              if ( is_primary_display )
                v23 = 1;
              else
                v23 = 2;
              LODWORD(v26) = v9;
              BYTE4(v26) = v24;
              result = panel_event_notification_trigger(v23, &v25);
            }
            goto LABEL_3;
          }
          goto LABEL_21;
        }
      }
LABEL_20:
      v18 = 1;
      if ( v12 != 1 )
        goto LABEL_22;
LABEL_21:
      if ( v16 != v9 )
        goto LABEL_22;
LABEL_3:
      ++v4;
      v3 += 40;
      if ( v4 >= *(int *)(v2 + 40) )
        goto LABEL_38;
    }
    v11 = *(_QWORD *)(v10 + 1472);
    if ( (unsigned int)v11 <= 2 )
    {
      v12 = dword_288DB8[v11 & 3];
      v13 = *(_QWORD *)(v7 + 8);
      if ( !v13 )
        goto LABEL_19;
      goto LABEL_13;
    }
LABEL_12:
    v12 = 1;
    v13 = *(_QWORD *)(v7 + 8);
    if ( !v13 )
      goto LABEL_19;
    goto LABEL_13;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
