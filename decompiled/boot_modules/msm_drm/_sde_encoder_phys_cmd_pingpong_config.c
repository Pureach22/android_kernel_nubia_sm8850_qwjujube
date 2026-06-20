__int64 __fastcall sde_encoder_phys_cmd_pingpong_config(__int64 a1)
{
  __int64 v1; // x8
  int v3; // w4
  __int64 v4; // x8
  __int64 v5; // x8
  unsigned int disp_op; // w0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned __int16 *v10; // x4
  __int64 v11; // x8
  void (__fastcall *v12)(__int64, __int64 *); // x9
  int v13; // w12
  int v14; // w13
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x12
  int v18; // w10
  unsigned int v19; // w11
  __int64 v20; // x12
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x20
  __int64 v24; // x8
  unsigned int v25; // w21
  int v26; // w25
  int v27; // w4
  __int64 v28; // x26
  __int64 v29; // x8
  __int64 v30; // x8
  int v31; // w4
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x22
  int v36; // w21
  int v37; // w22
  int v38; // w8
  unsigned int v39; // w9
  char v40; // w11
  int v41; // w4
  int v42; // w4
  int v43; // w4
  int v44; // w4
  int v45; // w4
  void (*v46)(void); // x8
  __int64 (*v47)(void); // x8
  void (*v48)(void); // x8
  __int64 (*v49)(void); // x8
  int v50; // [xsp+44h] [xbp-3Ch] BYREF
  __int64 v51; // [xsp+48h] [xbp-38h] BYREF
  __int64 v52; // [xsp+50h] [xbp-30h] BYREF
  unsigned __int64 v53; // [xsp+58h] [xbp-28h]
  __int64 v54; // [xsp+60h] [xbp-20h]
  __int64 v55; // [xsp+68h] [xbp-18h]
  __int64 v56; // [xsp+70h] [xbp-10h]
  __int64 v57; // [xsp+78h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 416) || (v1 = *(_QWORD *)(a1 + 496)) == 0 )
  {
    result = printk(&unk_273C25, "_sde_encoder_phys_cmd_pingpong_config");
    goto LABEL_119;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
      v3 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v3 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "enc%d intf%d pp %d, enabling mode:\n",
      v3,
      *(_DWORD *)(a1 + 672) - 1,
      *(_DWORD *)(v1 + 32) - 1);
  }
  drm_mode_debug_printmodeline(a1 + 520);
  v4 = *(_QWORD *)(a1 + 8);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 2512)) == 0 || *(_DWORD *)(v5 + 1376) != 10 || *(_DWORD *)(a1 + 664) != 3 )
  {
    disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
    v11 = *(_QWORD *)(a1 + 416);
    if ( v11 )
    {
      if ( disp_op >= 3 )
        goto LABEL_120;
      v12 = *(void (__fastcall **)(__int64, __int64 *))(v11 + 8LL * disp_op + 808);
      if ( v12 )
      {
        v13 = *(_DWORD *)(a1 + 2680);
        v14 = *(_DWORD *)(a1 + 832);
        v52 = *(unsigned int *)(a1 + 672);
        HIDWORD(v53) = 1;
        LODWORD(v54) = v13;
        if ( v14 )
        {
          v15 = *(_QWORD *)(a1 + 8);
          if ( !v15 )
          {
LABEL_39:
            LODWORD(v53) = v15;
            if ( *((_DWORD *)v12 - 1) != -1201655407 )
              __break(0x8229u);
            v12(v11, &v52);
            goto LABEL_42;
          }
          v16 = *(_QWORD *)(v15 + 2512);
          if ( v16 )
          {
            v17 = *(_QWORD *)(a1 + 424);
            v18 = *(_DWORD *)(v16 + 2244);
            v19 = *(_DWORD *)(v16 + 2248);
            if ( !v17 || (*(_BYTE *)(v17 + 77) & 1) == 0 )
            {
              if ( *(_DWORD *)(a1 + 664) )
              {
                v20 = *(_QWORD *)a1;
                if ( *(_QWORD *)a1 )
                {
                  if ( *(_DWORD *)(v20 + 196) == 1 )
                  {
                    LODWORD(v20) = *(unsigned __int8 *)(v20 + 4936);
                    if ( (_DWORD)v20 == 1 && v18 == 2 && v19 < 2 )
                      goto LABEL_37;
                  }
                  else
                  {
                    LOBYTE(v20) = 0;
                  }
                }
                if ( (v20 & 1) == 0 && v18 == 4 && v19 < 4 )
                {
LABEL_37:
                  LODWORD(v15) = 2;
                  goto LABEL_39;
                }
              }
              else if ( v18 == 2 && v19 < 2 )
              {
                goto LABEL_37;
              }
            }
          }
        }
        LODWORD(v15) = 0;
        goto LABEL_39;
      }
      if ( (*(_QWORD *)(*(_QWORD *)(v11 + 72) + 32LL) & 0x10) != 0 )
        sde_encoder_helper_update_intf_cfg((__int64 **)a1, v7, v8, v9, v10);
    }
  }
LABEL_42:
  v22 = *(_QWORD *)(a1 + 496);
  v23 = *(_QWORD *)a1;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v52 = 0;
  if ( !v22 || !*(_QWORD *)(a1 + 424) || !*(_QWORD *)(a1 + 8) )
  {
    result = printk(&unk_26FCAB, "sde_encoder_phys_cmd_tearcheck_config");
    goto LABEL_119;
  }
  result = sde_encoder_get_disp_op(v23);
  v24 = *(_QWORD *)(a1 + 8);
  v25 = result;
  if ( v24 )
    v26 = *(_DWORD *)(v24 + 4676);
  else
    v26 = 0;
  v51 = 0;
  v50 = 0;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
      v27 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v27 = -1;
    result = _drm_dev_dbg(
               0,
               0,
               0,
               "enc%d intf%d pp %d, intf %d\n",
               v27,
               *(_DWORD *)(a1 + 672) - 1,
               *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
               *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1);
  }
  v28 = v25;
  if ( *(_BYTE *)(a1 + 2288) == 1 )
  {
    if ( v25 < 3 )
    {
      v29 = *(_QWORD *)(a1 + 424) + 8LL * v25;
      if ( !*(_QWORD *)(v29 + 464) || !*(_QWORD *)(v29 + 488) )
      {
        if ( !v25 && (_drm_debug & 4) != 0 )
        {
          v30 = *(_QWORD *)a1;
          if ( *(_QWORD *)a1 )
          {
LABEL_61:
            v31 = *(_DWORD *)(v30 + 24);
LABEL_78:
            result = _drm_dev_dbg(0, 0, 0, "enc%d intf%d tearcheck not supported\n", v31, *(_DWORD *)(a1 + 672) - 1);
            goto LABEL_119;
          }
LABEL_77:
          v31 = -1;
          goto LABEL_78;
        }
        goto LABEL_119;
      }
LABEL_65:
      v33 = *(_QWORD *)(a1 + 512);
      if ( !v33 || (v34 = *(_QWORD *)(v33 + 136)) == 0 || (v35 = *(_QWORD *)(v34 + 56)) == 0 )
      {
        result = printk(&unk_231B33, "sde_encoder_phys_cmd_tearcheck_config");
        goto LABEL_119;
      }
      v36 = drm_mode_vrefresh(a1 + 520);
      result = sde_power_clk_get_rate((int)v35 + 16, "vsync_clk");
      v37 = result;
      if ( !(_DWORD)result || (v38 = *(unsigned __int16 *)(a1 + 540), !*(_WORD *)(a1 + 540)) || !v36 )
      {
        if ( (_drm_debug & 4) != 0 )
        {
          if ( *(_QWORD *)a1 )
            v42 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
          else
            v42 = -1;
          result = _drm_dev_dbg(
                     0,
                     0,
                     0,
                     "enc%d intf%d invalid params - vsync_hz %u vtot %u vrefresh %u\n",
                     v42,
                     *(_DWORD *)(a1 + 672) - 1,
                     result,
                     *(unsigned __int16 *)(a1 + 540),
                     v36);
        }
        goto LABEL_119;
      }
      LOBYTE(v56) = 0;
      LODWORD(v52) = (unsigned int)result / (v36 * v38);
      get_tearcheck_cfg(a1, (unsigned int *)&v51 + 1, (int *)&v51, &v50);
      v39 = *(unsigned __int16 *)(a1 + 534);
      HIDWORD(v52) = v51;
      v53 = __PAIR64__(HIDWORD(v51), v39);
      LODWORD(v54) = 4;
      HIDWORD(v54) = v50;
      LODWORD(v55) = v39 + 1;
      v40 = _drm_debug;
      HIDWORD(v55) = 1;
      HIDWORD(v56) = v39 + 20;
      *(_DWORD *)(a1 + 2904) = HIDWORD(v51);
      if ( (v40 & 4) != 0 )
      {
        v41 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
        _drm_dev_dbg(
          0,
          0,
          0,
          "enc%d intf%d tc %d intf %d vsync_clk_speed_hz %u vtotal %u vrefresh %u\n",
          v41,
          *(_DWORD *)(a1 + 672) - 1,
          *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
          *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
          v37,
          *(unsigned __int16 *)(a1 + 540),
          v36);
        if ( (_drm_debug & 4) != 0 )
        {
          v43 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
          _drm_dev_dbg(
            0,
            0,
            0,
            "enc%d intf%d tc %d intf %d enable %u start_pos %u rd_ptr_irq %u wr_ptr_irq %u\n",
            v43,
            *(_DWORD *)(a1 + 672) - 1,
            *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
            *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
            1,
            HIDWORD(v54),
            v55,
            HIDWORD(v55));
          if ( (_drm_debug & 4) != 0 )
          {
            v44 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
            _drm_dev_dbg(
              0,
              0,
              0,
              "enc%d intf%d tc %d intf %d hw_vsync_mode %u vsync_count %u vsync_init_val %u\n",
              v44,
              *(_DWORD *)(a1 + 672) - 1,
              *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
              *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
              (unsigned __int8)v56,
              v52,
              v53);
            if ( (_drm_debug & 4) != 0 )
            {
              if ( *(_QWORD *)a1 )
                v45 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
              else
                v45 = -1;
              _drm_dev_dbg(
                0,
                0,
                0,
                "enc%d intf%d tc %d intf %d cfgheight %u thresh_start %u thresh_cont %u\n",
                v45,
                *(_DWORD *)(a1 + 672) - 1,
                *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
                *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
                HIDWORD(v52),
                HIDWORD(v53),
                v54);
            }
          }
        }
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_cmd_tearcheck_config",
        1582,
        -1,
        *(_DWORD *)(*(_QWORD *)(a1 + 496) + 32LL) - 1,
        *(_DWORD *)(*(_QWORD *)(a1 + 424) + 32LL) - 1,
        v37,
        *(unsigned __int16 *)(a1 + 540),
        v36);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_cmd_tearcheck_config",
        1586,
        -1,
        1,
        SHIDWORD(v54),
        v55,
        SHIDWORD(v55),
        v56);
      if ( *(_BYTE *)(a1 + 2288) == 1 )
      {
        result = *(_QWORD *)(a1 + 424);
        v46 = *(void (**)(void))(result + 8 * v28 + 464);
        if ( v46 )
        {
          if ( *((_DWORD *)v46 - 1) != 707899111 )
            __break(0x8228u);
          v46();
          result = *(_QWORD *)(a1 + 424);
        }
        v47 = *(__int64 (**)(void))(result + 8 * v28 + 488);
        if ( !v47 )
          goto LABEL_113;
        if ( *((_DWORD *)v47 - 1) != 467537577 )
          __break(0x8228u);
      }
      else
      {
        v48 = *(void (**)(void))(*(_QWORD *)(a1 + 496) + 8 * v28 + 64);
        if ( *((_DWORD *)v48 - 1) != -1833914660 )
          __break(0x8228u);
        v48();
        v47 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 496) + 8 * v28 + 88);
        if ( *((_DWORD *)v47 - 1) != 683511807 )
          __break(0x8228u);
      }
      result = v47();
LABEL_113:
      if ( v26 )
      {
        result = *(_QWORD *)(a1 + 424);
        v49 = *(__int64 (**)(void))(result + 8 * v28 + 800);
        if ( v49 )
        {
          if ( (*(_BYTE *)(v23 + 700) & 1) == 0 )
          {
            if ( *((_DWORD *)v49 - 1) != -1839426449 )
              __break(0x8228u);
            result = v49();
          }
        }
      }
      goto LABEL_119;
    }
LABEL_120:
    __break(0x5512u);
  }
  if ( v25 > 2 )
    goto LABEL_120;
  v32 = *(_QWORD *)(a1 + 496) + 8LL * v25;
  if ( *(_QWORD *)(v32 + 64) && *(_QWORD *)(v32 + 88) )
    goto LABEL_65;
  if ( !v25 && (_drm_debug & 4) != 0 )
  {
    v30 = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 )
      goto LABEL_61;
    goto LABEL_77;
  }
LABEL_119:
  _ReadStatusReg(SP_EL0);
  return result;
}
