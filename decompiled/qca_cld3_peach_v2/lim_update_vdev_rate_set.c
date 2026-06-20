__int64 __fastcall lim_update_vdev_rate_set(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  unsigned __int64 v33; // x2
  __int64 result; // x0
  _BYTE *v35; // x9
  _BYTE *v36; // x9
  _BYTE *v37; // x9
  _QWORD v38[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a2;
  v38[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 7);
  if ( !v5 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: vdev not found for id: %d",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "lim_update_vdev_rate_set",
               v4);
    goto LABEL_22;
  }
  v14 = v5;
  if ( *(_BYTE *)(a3 + 2284) && *(_BYTE *)(a3 + 6) )
    mlme_set_opr_rate(v5, (const void *)(a3 + 7), *(unsigned __int8 *)(a3 + 6), v6, v7, v8, v9, v10, v11, v12, v13);
  if ( !*(_BYTE *)(a3 + 2285) || !*(_BYTE *)(a3 + 19) )
  {
    mlme_clear_ext_opr_rate(v14, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( !*(_BYTE *)(a3 + 244) )
      goto LABEL_8;
LABEL_10:
    v32 = *(_DWORD *)(a3 + 248);
    v33 = 0;
    v38[0] = 0;
    if ( (v32 & 1) != 0 )
    {
      v33 = 1;
      LOBYTE(v38[0]) = 0;
      if ( (v32 & 2) == 0 )
      {
LABEL_12:
        if ( (v32 & 4) == 0 )
          goto LABEL_13;
        goto LABEL_25;
      }
    }
    else if ( (v32 & 2) == 0 )
    {
      goto LABEL_12;
    }
    v35 = (_BYTE *)((unsigned __int64)v38 | v33++);
    *v35 = 1;
    if ( (v32 & 4) == 0 )
    {
LABEL_13:
      if ( (v32 & 8) == 0 )
        goto LABEL_14;
      goto LABEL_26;
    }
LABEL_25:
    v36 = (_BYTE *)((unsigned __int64)v38 | v33++);
    *v36 = 2;
    if ( (v32 & 8) == 0 )
    {
LABEL_14:
      if ( (v32 & 0x10) == 0 )
        goto LABEL_15;
      goto LABEL_27;
    }
LABEL_26:
    v37 = (_BYTE *)((unsigned __int64)v38 | v33++);
    *v37 = 3;
    if ( (v32 & 0x10) == 0 )
    {
LABEL_15:
      if ( (v32 & 0x20) == 0 )
        goto LABEL_16;
      goto LABEL_28;
    }
LABEL_27:
    *((_BYTE *)v38 + v33++) = 4;
    if ( (v32 & 0x20) == 0 )
    {
LABEL_16:
      if ( (v32 & 0x40) == 0 )
        goto LABEL_17;
      goto LABEL_29;
    }
LABEL_28:
    *((_BYTE *)v38 + v33++) = 5;
    if ( (v32 & 0x40) == 0 )
    {
LABEL_17:
      if ( (v32 & 0x80) == 0 )
      {
LABEL_19:
        mlme_set_mcs_rate(v14, v38, v33, v15, v16, v17, v18, v19, v20, v21, v22);
        goto LABEL_20;
      }
LABEL_18:
      *((_BYTE *)v38 + v33++) = 7;
      goto LABEL_19;
    }
LABEL_29:
    *((_BYTE *)v38 + v33++) = 6;
    if ( (v32 & 0x80) == 0 )
      goto LABEL_19;
    goto LABEL_18;
  }
  mlme_set_ext_opr_rate(v14, (const void *)(a3 + 20), *(unsigned __int8 *)(a3 + 19), v6, v7, v8, v9, v10, v11, v12, v13);
  if ( *(_BYTE *)(a3 + 244) )
    goto LABEL_10;
LABEL_8:
  mlme_clear_mcs_rate(v14, v15, v16, v17, v18, v19, v20, v21, v22);
LABEL_20:
  result = wlan_objmgr_vdev_release_ref(v14, 7u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
