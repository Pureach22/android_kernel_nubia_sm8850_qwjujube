__int64 __fastcall cam_ife_mgr_finish_clk_bw_update(__int64 a1, __int64 a2, char a3)
{
  char v3; // w8
  int v4; // w9
  unsigned __int64 v6; // x28
  _QWORD *v7; // x22
  unsigned int *v8; // x25
  unsigned int v10; // w8
  __int64 v11; // x8
  unsigned __int64 v12; // x9
  int ***v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  int *v16; // x8
  _DWORD *v17; // x9
  __int64 v18; // x0
  int v19; // w0
  __int64 v20; // x8
  int v21; // w8
  int v22; // w9
  int *v23; // t2
  const char *v24; // x10
  __int64 result; // x0
  unsigned int v26; // w19
  int v27; // w9
  char v28; // w8
  char v29; // w19
  unsigned int v30; // w21
  int v31; // w22
  unsigned int v32; // w19
  const char *v33; // x9
  const char *v34; // x6
  const char *v35; // x7
  unsigned int v36; // w20
  _QWORD v39[2]; // [xsp+48h] [xbp-28h] BYREF
  char v40; // [xsp+58h] [xbp-18h]
  _DWORD v41[2]; // [xsp+59h] [xbp-17h]
  __int16 v42; // [xsp+64h] [xbp-Ch]
  char v43; // [xsp+66h] [xbp-Ah]
  __int64 v44; // [xsp+68h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_BYTE *)(a1 + 9464);
  v4 = *(_DWORD *)(a1 + 8716);
  v39[0] = 0;
  v43 = 0;
  v42 = 0;
  v39[1] = a2;
  *(_DWORD *)((char *)v41 + 3) = 0;
  v41[0] = v3 & 1;
  v40 = a3;
  if ( !v4 )
  {
LABEL_36:
    result = 0;
    goto LABEL_38;
  }
  v6 = 0;
  v7 = (_QWORD *)(a1 + 256);
  v8 = (unsigned int *)(a1 + 8584);
  while ( 1 )
  {
    v39[0] = 0;
    BYTE1(v41[0]) = 0;
    if ( (debug_mdl & 0x2000008) != 0 && debug_priority == 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, _DWORD, _DWORD, _DWORD, bool))cam_print_log)(
        3,
        debug_mdl & 0x2000008,
        4,
        "cam_ife_mgr_finish_clk_bw_update",
        874,
        "Clock/BW Update for ctx:%u req:%d i:%d num_vfe_out:%d num_sfe_out:%d in_rd:%d",
        *(unsigned int *)(a1 + 56),
        a2,
        v6,
        *(_DWORD *)(a1 + 8512),
        *(_DWORD *)(a1 + 8516),
        *(_QWORD *)(a1 + 256) != (_QWORD)v7);
      if ( v6 == 11 )
      {
LABEL_64:
        __break(0x5512u);
LABEL_65:
        __break(1u);
      }
    }
    else if ( v6 == 11 )
    {
      goto LABEL_64;
    }
    v10 = v8[2];
    if ( v10 == 7 )
      break;
    if ( v10 == 2 && (*(_DWORD *)(a1 + 8512) || (_QWORD *)*v7 != v7) )
    {
      v11 = *v8;
      if ( (unsigned int)v11 > 7 )
        goto LABEL_64;
      v12 = 8 * v11 + 160;
      v13 = (int ***)((char *)g_ife_hw_mgr + v12);
      goto LABEL_19;
    }
LABEL_3:
    ++v6;
    v8 += 3;
    if ( v6 >= *(unsigned int *)(a1 + 8716) )
      goto LABEL_36;
  }
  if ( !*(_DWORD *)(a1 + 8516) && (_QWORD *)*v7 == v7 )
    goto LABEL_3;
  v14 = *v8;
  if ( (unsigned int)v14 > 2 )
    goto LABEL_64;
  v15 = v14;
  v12 = (v15 * 8) | 0xE0;
  v13 = (int ***)&g_ife_hw_mgr[v15 + 28];
LABEL_19:
  if ( v12 > 0x13FD8 )
    goto LABEL_65;
  v16 = **v13;
  v39[0] = v16;
  if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
  {
    v23 = v16;
    v21 = *v16;
    v22 = v23[1];
    v24 = "N";
    if ( LOBYTE(v41[0]) )
      v24 = "Y";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000008,
      4,
      "cam_ife_mgr_finish_clk_bw_update",
      890,
      "Apply Clock/BW for ctx:%u req:%d i:%d hw_idx=%d hw_type:%d inline:%s num_vfe_out:%d num_sfe_out:%d in_rd:%d",
      *(_DWORD *)(a1 + 56),
      a2,
      v6,
      v22,
      v21,
      v24,
      *(_DWORD *)(a1 + 8512),
      *(_DWORD *)(a1 + 8516),
      *(_QWORD *)(a1 + 256) != (_QWORD)v7);
    v16 = (int *)v39[0];
  }
  v17 = *((_DWORD **)v16 + 11);
  v18 = *((_QWORD *)v16 + 14);
  if ( *(v17 - 1) != -1055839300 )
    __break(0x8229u);
  v19 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v17)(v18, 66, v39, 24);
  if ( !v19 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_finish_clk_bw_update",
        903,
        "clock_updated=%d, hw_idx=%d",
        BYTE1(v41[0]),
        *(_DWORD *)(v39[0] + 4LL));
    if ( BYTE1(v41[0]) == 1 )
    {
      v20 = *(unsigned int *)(v39[0] + 4LL);
      if ( (unsigned int)v20 <= 2 )
        *((_BYTE *)&v42 + v20) = 1;
    }
    goto LABEL_3;
  }
  v26 = v19;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x2000000,
    1,
    "cam_ife_mgr_finish_clk_bw_update",
    898,
    "Finish Clock/BW Update failed ctx:%u req:%d i:%d hw_id=%d hw_type:%d rc:%d",
    *(_DWORD *)(a1 + 56),
    a2,
    v6,
    *v8,
    v8[2],
    v19);
  result = v26;
LABEL_38:
  v27 = debug_priority;
  v28 = debug_mdl;
  if ( byte_3A88D5 != 1 )
    goto LABEL_50;
  v29 = v42;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v33 = "N";
    if ( (v42 & 1) != 0 )
      v34 = "Y";
    else
      v34 = "N";
    if ( HIBYTE(v42) )
      v35 = "Y";
    else
      v35 = "N";
    if ( v43 )
      v33 = "Y";
    v36 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, const char *, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_finish_clk_bw_update",
      914,
      "Channel switch for [0]=%s, [1]=%s, [2]=%s",
      v34,
      v35,
      v33);
    result = v36;
    if ( (v29 & 1) == 0 )
      goto LABEL_43;
LABEL_42:
    v30 = cam_soc_util_cesta_channel_switch(0, "ife_hw_mgr_update");
    v31 = 0;
    result = 0;
    if ( !v30 )
      goto LABEL_43;
LABEL_48:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_ife_mgr_finish_clk_bw_update",
      924,
      "Failed to apply power states for cesta client:%d rc:%d",
      v31,
      v30);
    result = v30;
  }
  else
  {
    if ( (v42 & 1) != 0 )
      goto LABEL_42;
LABEL_43:
    if ( HIBYTE(v42) == 1
      && (v31 = 1, result = cam_soc_util_cesta_channel_switch(1u, "ife_hw_mgr_update"), (_DWORD)result)
      || v43 == 1 && (v31 = 2, result = cam_soc_util_cesta_channel_switch(2u, "ife_hw_mgr_update"), (_DWORD)result) )
    {
      v30 = result;
      goto LABEL_48;
    }
    v28 = debug_mdl;
    v27 = debug_priority;
LABEL_50:
    if ( (v28 & 8) != 0 && !v27 )
    {
      v32 = result;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v28 & 8,
        4,
        "cam_ife_mgr_finish_clk_bw_update",
        931,
        "Clk, BW update done for Req=%lld, skip_clk_data_rst=%d",
        a2,
        a3 & 1);
      result = v32;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
