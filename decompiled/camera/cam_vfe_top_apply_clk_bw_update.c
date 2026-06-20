__int64 __fastcall cam_vfe_top_apply_clk_bw_update(__int64 a1, __int64 *a2, int a3)
{
  __int64 v3; // x24
  char v4; // w8
  __int64 result; // x0
  unsigned int v6; // w20
  __int64 v7; // x19
  __int64 v8; // x20
  __int64 v10; // x19
  unsigned int v11; // w0
  __int64 v12; // x6
  const char *v13; // x5
  __int64 v14; // x4
  unsigned int v15; // w0
  __int64 v16; // x23
  int v17; // w9
  int v18; // w11
  int v19; // w9
  __int64 v20; // x21
  __int64 v21; // x22
  unsigned int v22; // w0
  __int64 v23; // x6
  unsigned int v24; // w8
  const char *v25; // x8
  __int64 v26; // x21
  unsigned int v27; // w0
  __int64 v28; // x6
  unsigned int v29; // w8
  const char *v30; // x8
  unsigned int v31; // w0
  unsigned int v32; // w8
  const char *v33; // x8
  const char *v34; // x8
  const char *v35; // x7
  unsigned int v36; // w0
  unsigned int v37; // w8
  const char *v38; // x8
  const char *v39; // x7
  const char *v40; // x8
  unsigned int v41; // w9
  const char *v42; // x9
  unsigned int v43; // w9
  const char *v44; // x9
  const char *v45; // x10
  __int64 v46; // x4
  const char *v47; // x10
  __int64 v48; // x4
  __int64 v49; // x20
  unsigned int v50; // w0
  unsigned int v51; // w8
  const char *v52; // x8
  unsigned int v53; // w0
  unsigned int v54; // w8
  const char *v55; // x8
  unsigned int v56; // w10
  const char *v57; // x9
  const char *v58; // x10
  unsigned int v59; // w9
  unsigned int v60; // w21
  unsigned int v61; // w9
  const char *v62; // x9
  const char *v63; // x10
  unsigned int v64; // w9
  const char *v65; // x9
  const char *v66; // x10
  unsigned int v67; // w8
  const char *v68; // x8
  unsigned int v69; // w9
  const char *v70; // x9
  const char *v71; // x10
  const char *v72; // [xsp+8h] [xbp-48h]
  const char *v73; // [xsp+10h] [xbp-40h]
  const char *v74; // [xsp+18h] [xbp-38h]
  __int64 v75; // [xsp+28h] [xbp-28h] BYREF
  __int64 v76; // [xsp+30h] [xbp-20h] BYREF
  __int64 v77; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v78[2]; // [xsp+40h] [xbp-10h] BYREF

  v78[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  v78[0] = 0;
  v76 = 0;
  v75 = 0;
  if ( a3 != 24 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_apply_clk_bw_update",
      580,
      "Invalid arg size: %u",
      a3);
    result = 4294967274LL;
    goto LABEL_21;
  }
  v3 = *a2;
  if ( !*a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_vfe_top_apply_clk_bw_update",
      588,
      "Invalid hw_intf");
    result = 4294967274LL;
    goto LABEL_21;
  }
  if ( *(_DWORD *)(*(_QWORD *)(v3 + 112) + 92LL) != 1 )
  {
    v6 = 0;
    if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
    {
      v7 = a1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 0x2000008,
        4,
        "cam_vfe_top_apply_clk_bw_update",
        596,
        "VFE:%d Not ready to set clocks yet :%d",
        *(unsigned int *)(v3 + 4));
      a1 = v7;
      v6 = 0;
    }
    goto LABEL_20;
  }
  if ( *((_BYTE *)a2 + 16) != 1 )
  {
    v8 = a2[1];
    v10 = a1;
    v11 = cam_vfe_top_calc_hw_clk_rate(a1, 0, &v77, v8);
    if ( v11 )
    {
      v12 = *(unsigned int *)(v3 + 4);
      v13 = "VFE:%d Failed in calculating clock rate rc=%d";
      v6 = v11;
      v14 = 610;
LABEL_18:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_clk_bw_update",
        v14,
        v13,
        v12,
        v6);
LABEL_19:
      a1 = v10;
LABEL_20:
      *(_QWORD *)(a1 + 10368) = 0;
      result = v6;
      goto LABEL_21;
    }
    v15 = cam_vfe_top_calc_axi_bw_vote(v10, 0, v78, &v76, &v75, v8);
    if ( v15 )
    {
      v12 = *(unsigned int *)(v3 + 4);
      v13 = "VFE:%d Failed in calculating bw vote rc=%d";
      v6 = v15;
      v14 = 619;
      goto LABEL_18;
    }
    v16 = v78[0];
    a1 = v10;
    if ( v78[0] || (v17 = *(_DWORD *)(v10 + 10372), v17 == 1) )
    {
      if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
      {
        v67 = *(_DWORD *)(v10 + 10368) - 1;
        if ( v67 > 2 )
          v68 = "Invalid State";
        else
          v68 = off_44EBB0[v67];
        v69 = *(_DWORD *)(v10 + 10372) - 1;
        if ( v69 > 2 )
          v70 = "Invalid State";
        else
          v70 = off_44EBB0[v69];
        v71 = "Y";
        if ( !*((_BYTE *)a2 + 17) )
          v71 = "N";
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, const char *, const char *, const char *))cam_print_log)(
          3,
          debug_mdl & 0x2000008,
          4,
          "cam_vfe_top_apply_clk_bw_update",
          635,
          "VFE:%d APPLY CLK/BW req_id:%ld clk_state:%s bw_state:%s is_drv_config_en:%s",
          *(unsigned int *)(v3 + 4),
          v8,
          v68,
          v70,
          v71);
        a1 = v10;
      }
      v18 = *(_DWORD *)(a1 + 10368);
      v19 = *(_DWORD *)(a1 + 10372);
      if ( v18 == 1 )
      {
        if ( v19 == 1 )
        {
LABEL_79:
          v6 = 0;
          goto LABEL_20;
        }
        v20 = v76;
        v21 = v75;
        v22 = cam_vfe_top_set_axi_bw_vote(a1, v16, v76, v75, 0, v8);
        if ( v22 )
        {
          v23 = *(unsigned int *)(v3 + 4);
          v24 = *(_DWORD *)(v10 + 10368) - 1;
          if ( v24 > 2 )
            v25 = "Invalid State";
          else
            v25 = off_44EBB0[v24];
          v6 = v22;
          v41 = *(_DWORD *)(v10 + 10372) - 1;
          if ( v41 > 2 )
            v42 = "Invalid State";
          else
            v42 = off_44EBB0[v41];
          v45 = "Y";
          if ( !*((_BYTE *)a2 + 17) )
            v45 = "N";
          v46 = 650;
          v73 = v42;
          v74 = v45;
          v72 = v25;
LABEL_110:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, const char *, const char *, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_top_apply_clk_bw_update",
            v46,
            "VFE:%d Failed in voting final bw camnoc:%llu mnoc:%llu clk_state:%s bw_state:%s is_drv_config_en:%s",
            v23,
            v20,
            v21,
            v72,
            v73,
            v74);
          goto LABEL_19;
        }
LABEL_78:
        a1 = v10;
        if ( *(_DWORD *)(v10 + 10368) != 1 )
        {
          v6 = 0;
          *((_BYTE *)a2 + 18) = 1;
          goto LABEL_20;
        }
        goto LABEL_79;
      }
      if ( v19 == 1 )
      {
        v26 = v77;
        v27 = cam_vfe_top_set_hw_clk_rate(a1, v77, 0, v8);
        if ( !v27 )
          goto LABEL_78;
        v28 = *(unsigned int *)(v3 + 4);
        v29 = *(_DWORD *)(v10 + 10368) - 1;
        if ( v29 > 2 )
          v30 = "Invalid State";
        else
          v30 = off_44EBB0[v29];
        v6 = v27;
        v43 = *(_DWORD *)(v10 + 10372) - 1;
        if ( v43 > 2 )
          v44 = "Invalid State";
        else
          v44 = off_44EBB0[v43];
        v47 = "Y";
        if ( !*((_BYTE *)a2 + 17) )
          v47 = "N";
        v48 = 662;
LABEL_95:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, const char *, const char *, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_top_apply_clk_bw_update",
          v48,
          "VFE:%d Failed in voting final clk:%lu clk_state:%s bw_state:%s is_drv_config_en:%s",
          v28,
          v26,
          v30,
          v44,
          v47);
        goto LABEL_19;
      }
      if ( v18 == 3 )
      {
        v26 = v77;
        v36 = ((__int64 (*)(void))cam_vfe_top_set_hw_clk_rate)();
        if ( !v36 )
        {
          v20 = v76;
          v21 = v75;
          v53 = cam_vfe_top_set_axi_bw_vote(v10, v16, v76, v75, 0, v8);
          if ( v53 )
          {
            v23 = *(unsigned int *)(v3 + 4);
            v54 = *(_DWORD *)(v10 + 10368) - 1;
            if ( v54 > 2 )
              v55 = "Invalid State";
            else
              v55 = off_44EBB0[v54];
            v6 = v53;
            v64 = *(_DWORD *)(v10 + 10372) - 1;
            if ( v64 > 2 )
              v65 = "Invalid State";
            else
              v65 = off_44EBB0[v64];
            v66 = "Y";
            v72 = v55;
            if ( !*((_BYTE *)a2 + 17) )
              v66 = "N";
            v73 = v65;
            v74 = v66;
            v46 = 712;
            goto LABEL_110;
          }
          goto LABEL_78;
        }
        v28 = *(unsigned int *)(v3 + 4);
        v37 = *(_DWORD *)(v10 + 10368) - 1;
        if ( v37 > 2 )
          v30 = "Invalid State";
        else
          v30 = off_44EBB0[v37];
        v6 = v36;
        v59 = *(_DWORD *)(v10 + 10372) - 1;
        if ( v59 > 2 )
          v44 = "Invalid State";
        else
          v44 = off_44EBB0[v59];
        v47 = "Y";
        if ( !*((_BYTE *)a2 + 17) )
          v47 = "N";
        v48 = 700;
        goto LABEL_95;
      }
      if ( v18 == 2 )
      {
        v20 = v76;
        v21 = v75;
        v31 = cam_vfe_top_set_axi_bw_vote(a1, v16, v76, v75, 0, v8);
        if ( v31 )
        {
          v23 = *(unsigned int *)(v3 + 4);
          v32 = *(_DWORD *)(v10 + 10368) - 1;
          if ( v32 > 2 )
            v33 = "Invalid State";
          else
            v33 = off_44EBB0[v32];
          v6 = v31;
          v56 = *(_DWORD *)(v10 + 10372) - 1;
          if ( v56 > 2 )
            v57 = "Invalid State";
          else
            v57 = off_44EBB0[v56];
          v58 = "Y";
          v72 = v33;
          if ( !*((_BYTE *)a2 + 17) )
            v58 = "N";
          v73 = v57;
          v74 = v58;
          v46 = 675;
          goto LABEL_110;
        }
        v49 = v77;
        v50 = cam_vfe_top_set_hw_clk_rate(v10, v77, 0, 0);
        if ( v50 )
        {
          v51 = *(_DWORD *)(v10 + 10368) - 1;
          if ( v51 > 2 )
            v52 = "Invalid State";
          else
            v52 = off_44EBB0[v51];
          v60 = v50;
          v61 = *(_DWORD *)(v10 + 10372) - 1;
          if ( v61 > 2 )
            v62 = "Invalid State";
          else
            v62 = off_44EBB0[v61];
          v63 = "Y";
          if ( !*((_BYTE *)a2 + 17) )
            v63 = "N";
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, const char *, const char *, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_top_apply_clk_bw_update",
            687,
            "VFE:%d Failed in voting final clk:%lu clk_state:%s bw_state:%s is_drv_config_en:%s",
            *(unsigned int *)(v3 + 4),
            v49,
            v52,
            v62,
            v63);
          a1 = v10;
          v6 = v60;
          goto LABEL_20;
        }
        goto LABEL_78;
      }
      v38 = "INCREASE";
      if ( v19 != 2 )
        v38 = "Invalid State";
      if ( v19 == 3 )
        v39 = "DECREASE";
      else
        v39 = v38;
      v40 = "N";
      if ( *((_BYTE *)a2 + 17) )
        v40 = "Y";
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_clk_bw_update",
        720,
        "Invalid state to apply CLK/BW clk_state:%s bw_state:%s is_drv_config_en:%s",
        "Invalid State",
        v39,
        v40);
    }
    else
    {
      v34 = "Invalid State";
      if ( v17 == 2 )
        v34 = "INCREASE";
      if ( v17 == 3 )
        v35 = "DECREASE";
      else
        v35 = v34;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_vfe_top_apply_clk_bw_update",
        625,
        "VFE:%d Invalid BW vote for state:%s",
        *(_DWORD *)(v3 + 4),
        v35);
    }
    a1 = v10;
    v6 = -22;
    goto LABEL_20;
  }
  v4 = debug_mdl;
  *(_BYTE *)(a1 + 10480) = 1;
  if ( (v4 & 8) != 0 )
  {
    result = 0;
    if ( !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v4 & 8,
        4,
        "cam_vfe_top_apply_clk_bw_update",
        602,
        "VFE:%u requested to avoid clk data rst",
        *(_DWORD *)(v3 + 4));
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
