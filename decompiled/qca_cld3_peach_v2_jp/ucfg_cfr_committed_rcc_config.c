__int64 __fastcall ucfg_cfr_committed_rcc_config(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 v20; // x22
  __int64 v21; // x21
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w20
  __int64 v32; // x0
  __int64 (**v33)(void); // x8
  __int64 (*v34)(void); // x8
  __int64 v35; // x0
  __int64 v36; // x22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  __int64 v46; // x8
  void (*v47)(void); // x8
  __int64 (**v48)(void); // x8
  __int64 (*v49)(void); // x8
  __int64 v50; // x22
  __int64 v51; // x0
  __int64 v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int128 v77; // [xsp+0h] [xbp-30h]
  __int64 v78; // [xsp+18h] [xbp-18h] BYREF
  __int64 v79[2]; // [xsp+20h] [xbp-10h] BYREF

  v79[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v79[0] = 0;
  v78 = 0;
  v77 = 0u;
  result = dev_sanity_check(a1, &v78, v79, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    v19 = v78;
    v20 = *(__int64 *)((char *)&qword_50 + v78);
    if ( !v20 )
    {
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: psoc is null!",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "ucfg_cfr_committed_rcc_config");
      v31 = 29;
LABEL_60:
      wlan_objmgr_pdev_release_ref(v19, 0x30u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      result = v31;
      goto LABEL_61;
    }
    v21 = v79[0];
    *((_BYTE *)&dword_98 + v79[0] + 1) = *(_BYTE *)(a1 + 104);
    if ( a1 )
      wlan_vdev_mlme_get_cmpt_obj(a1, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( (*((_BYTE *)&word_B0 + v21) & 0x3F) == 0 )
    {
      v32 = *(_QWORD *)(v20 + 2808);
      if ( v32 && *(_QWORD *)v32 )
      {
        v33 = *(__int64 (***)(void))(*(_QWORD *)v32 + 168LL);
        if ( v33 )
        {
          v34 = *v33;
          if ( v34 )
          {
            if ( *((_DWORD *)v34 - 1) != -1653155309 )
              __break(0x8228u);
            if ( (v34() & 1) != 0 )
              tgt_cfr_stop_lut_age_timer(v19, v11, v12, v13, v14, v15, v16, v17, v18);
          }
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_get_cfr_rcc", 0);
      }
      v36 = *(__int64 *)((char *)&qword_50 + v19);
      qdf_trace_msg(
        0x6Au,
        4u,
        "%s: pdev_id=%d\n",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "cfr_set_filter",
        *((unsigned __int8 *)&qword_28 + v19),
        (_QWORD)v77);
      if ( v36 )
      {
        v45 = *(_QWORD *)(v36 + 2808);
        if ( v45 )
        {
          if ( *(_QWORD *)v45 )
          {
            v46 = *(_QWORD *)(*(_QWORD *)v45 + 24LL);
            if ( v46 )
            {
              v47 = *(void (**)(void))(v46 + 88);
              if ( v47 )
                goto LABEL_52;
            }
            goto LABEL_56;
          }
        }
      }
LABEL_55:
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v37, v38, v39, v40, v41, v42, v43, v44, "cdp_cfr_filter");
      goto LABEL_56;
    }
    if ( *((_BYTE *)&qword_8 + v21 + 1) )
    {
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: Not allowed: Periodic capture is enabled.\n",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "ucfg_cfr_committed_rcc_config");
      v31 = 11;
      goto LABEL_60;
    }
    if ( (*((_BYTE *)&word_B0 + v21) & 2) != 0 )
    {
      LODWORD(v77) = 536870915;
      WORD4(v77) = 0x2000;
      if ( (*((_BYTE *)&word_B0 + v21) & 8) == 0 )
      {
LABEL_19:
        if ( (*((_BYTE *)&word_B0 + v21) & 0x20) == 0 )
          goto LABEL_20;
        goto LABEL_34;
      }
    }
    else if ( (*((_BYTE *)&word_B0 + v21) & 8) == 0 )
    {
      goto LABEL_19;
    }
    LOWORD(v77) = v77 | 3;
    WORD2(v77) = 32;
    WORD5(v77) = 32;
    if ( (*((_BYTE *)&word_B0 + v21) & 0x20) == 0 )
    {
LABEL_20:
      if ( (*((_BYTE *)&word_B0 + v21) & 0x10) == 0 )
        goto LABEL_21;
      goto LABEL_35;
    }
LABEL_34:
    *(_QWORD *)((char *)&v77 + 2) = -1;
    *(_DWORD *)((char *)&v77 + 10) = -1;
    LOWORD(v77) = v77 | 3;
    if ( (*((_BYTE *)&word_B0 + v21) & 0x10) == 0 )
    {
LABEL_21:
      if ( (*((_BYTE *)&word_B0 + v21) & 1) == 0 )
        goto LABEL_22;
      goto LABEL_36;
    }
LABEL_35:
    *(_QWORD *)((char *)&v77 + 2) = -1;
    *(_DWORD *)((char *)&v77 + 10) = -1;
    LOWORD(v77) = v77 | 3;
    if ( (*((_BYTE *)&word_B0 + v21) & 1) == 0 )
    {
LABEL_22:
      if ( (*((_BYTE *)&word_B0 + v21) & 4) == 0 )
        goto LABEL_23;
      goto LABEL_37;
    }
LABEL_36:
    LODWORD(v77) = v77 | 0x20000001;
    if ( (*((_BYTE *)&word_B0 + v21) & 4) == 0 )
    {
LABEL_23:
      v35 = *(_QWORD *)(v20 + 2808);
      if ( !v35 )
        goto LABEL_45;
LABEL_38:
      if ( *(_QWORD *)v35 )
      {
        v48 = *(__int64 (***)(void))(*(_QWORD *)v35 + 168LL);
        if ( v48 )
        {
          v49 = *v48;
          if ( v49 )
          {
            if ( *((_DWORD *)v49 - 1) != -1653155309 )
              __break(0x8228u);
            if ( (v49() & 1) != 0 )
            {
LABEL_47:
              v50 = *(__int64 *)((char *)&qword_50 + v19);
              qdf_trace_msg(
                0x6Au,
                4u,
                "%s: pdev_id=%d\n",
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                "cfr_set_filter",
                *((unsigned __int8 *)&qword_28 + v19),
                (_QWORD)v77);
              if ( v50 )
              {
                v51 = *(_QWORD *)(v50 + 2808);
                if ( v51 )
                {
                  if ( *(_QWORD *)v51 )
                  {
                    v52 = *(_QWORD *)(*(_QWORD *)v51 + 24LL);
                    if ( v52 )
                    {
                      v47 = *(void (**)(void))(v52 + 88);
                      if ( v47 )
                      {
LABEL_52:
                        if ( *((_DWORD *)v47 - 1) != 1469199883 )
                          __break(0x8228u);
                        v47();
                      }
                    }
LABEL_56:
                    v31 = tgt_cfr_config_rcc(v19, v21 + 152, v37, v38, v39, v40, v41, v42, v43, v44);
                    if ( v31 )
                    {
                      qdf_trace_msg(
                        0x6Au,
                        2u,
                        "%s: CFR commit failed",
                        v53,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        "ucfg_cfr_committed_rcc_config");
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x6Au,
                        4u,
                        "%s: CFR commit done\n",
                        v53,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        "ucfg_cfr_committed_rcc_config");
                      tgt_cfr_update_global_cfg(v19, v61, v62, v63, v64, v65, v66, v67, v68);
                      tgt_cfr_default_ta_ra_cfg(v19, v21 + 152, 0, 0xFFFFu, v69, v70, v71, v72, v73, v74, v75, v76);
                    }
                    *((_BYTE *)&word_B0 + v21 + 1) = 0;
                    *(__int64 *)((char *)&qword_2E8 + v21) = 0;
                    goto LABEL_60;
                  }
                }
              }
              goto LABEL_55;
            }
          }
        }
LABEL_46:
        tgt_cfr_start_lut_age_timer(v19, v11, v12, v13, v14, v15, v16, v17, v18);
        goto LABEL_47;
      }
LABEL_45:
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_get_cfr_rcc", v77, 0);
      goto LABEL_46;
    }
LABEL_37:
    LOWORD(v77) = v77 | 1;
    WORD2(v77) |= 0x20u;
    v35 = *(_QWORD *)(v20 + 2808);
    if ( !v35 )
      goto LABEL_45;
    goto LABEL_38;
  }
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
