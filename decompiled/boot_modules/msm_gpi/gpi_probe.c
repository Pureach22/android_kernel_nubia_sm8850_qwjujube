__int64 __fastcall gpi_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 resource_byname; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  int variable_u32_array; // w0
  int v11; // w0
  __int64 v12; // x0
  int v13; // w0
  __int64 result; // x0
  __int64 v15; // x8
  const char *v16; // x1
  unsigned int v17; // w19
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  const char *v21; // x1
  __int64 v22; // x0
  unsigned int v23; // w19
  __int64 v24; // x0
  __int64 property; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  int v28; // w27
  unsigned int v29; // w24
  __int64 v30; // x26
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x28
  __int64 v37; // x23
  __int64 v38; // x8
  __int64 v39; // x25
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x8
  __int64 v43; // x8
  unsigned int v44; // w20
  unsigned int v45; // w20
  unsigned int v46; // w20
  unsigned int v47; // w20
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  unsigned int v52; // w19
  unsigned int v53; // w20
  unsigned int v54; // w20
  unsigned int v55; // w20
  unsigned __int64 v61; // x9
  unsigned int v62; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+18h] [xbp-8h]

  v2 = a1 + 16;
  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  v4 = devm_kmalloc(a1 + 16, 576, 3520);
  if ( !v4 )
    goto LABEL_93;
  v5 = (unsigned int)arr_idx;
  if ( (unsigned int)arr_idx++ >= 5 )
  {
    __break(0x5512u);
    goto LABEL_110;
  }
  v1 = v4;
  gpi_dev_dbg[v5] = v4;
  *(_QWORD *)(v4 + 392) = v2;
  *(_DWORD *)(v4 + 484) = 1;
  resource_byname = platform_get_resource_byname(a1, 512, "gpi-top");
  *(_QWORD *)(v1 + 400) = resource_byname;
  if ( !resource_byname )
  {
    if ( *(_DWORD *)(v1 + 484) >= 2u )
    {
      dev_err(*(_QWORD *)(v1 + 392), "%s: missing 'reg' DT node\n", "gpi_probe");
      v18 = *(_QWORD *)(v1 + 472);
      if ( !v18 )
        goto LABEL_68;
    }
    else
    {
      v18 = *(_QWORD *)(v1 + 472);
      if ( !v18 )
        goto LABEL_68;
    }
    if ( *(_DWORD *)(v1 + 480) >= 2u )
    {
      ipc_log_string(v18, "%s: missing 'reg' DT node\n", "gpi_probe");
      result = 4294967274LL;
      goto LABEL_94;
    }
LABEL_68:
    result = 4294967274LL;
    goto LABEL_94;
  }
  v8 = devm_ioremap(*(_QWORD *)(v1 + 392));
  *(_QWORD *)(v1 + 408) = v8;
  if ( !v8 )
  {
    if ( *(_DWORD *)(v1 + 484) >= 2u )
    {
      dev_err(*(_QWORD *)(v1 + 392), "%s: IO remap failed\n", "gpi_probe");
      v19 = *(_QWORD *)(v1 + 472);
      if ( !v19 )
        goto LABEL_70;
    }
    else
    {
      v19 = *(_QWORD *)(v1 + 472);
      if ( !v19 )
        goto LABEL_70;
    }
    if ( *(_DWORD *)(v1 + 480) >= 2u )
    {
      ipc_log_string(v19, "%s: IO remap failed\n", "gpi_probe");
      result = 4294967282LL;
      goto LABEL_94;
    }
LABEL_70:
    result = 4294967282LL;
    goto LABEL_94;
  }
  v9 = *(_QWORD *)(v1 + 392);
  *(_QWORD *)(v1 + 416) = v8;
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v9 + 744), "qcom,max-num-gpii", v1 + 424, 1, 0);
  if ( variable_u32_array < 0 )
  {
    result = variable_u32_array & (unsigned int)(variable_u32_array >> 31);
    if ( *(_DWORD *)(v1 + 484) >= 2u )
    {
      v44 = result;
      dev_err(*(_QWORD *)(v1 + 392), "%s: missing 'max-no-gpii' DT node\n", "gpi_probe");
      result = v44;
      v20 = *(_QWORD *)(v1 + 472);
      if ( !v20 )
        goto LABEL_94;
    }
    else
    {
      v20 = *(_QWORD *)(v1 + 472);
      if ( !v20 )
        goto LABEL_94;
    }
    if ( *(_DWORD *)(v1 + 480) < 2u )
      goto LABEL_94;
    v21 = "%s: missing 'max-no-gpii' DT node\n";
LABEL_43:
    v23 = result;
    ipc_log_string(v20, v21, "gpi_probe");
    result = v23;
    goto LABEL_94;
  }
  v11 = of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(v1 + 392) + 744LL),
          "qcom,gpii-mask",
          v1 + 428,
          1,
          0);
  if ( v11 < 0 )
  {
    result = v11 & (unsigned int)(v11 >> 31);
    if ( *(_DWORD *)(v1 + 484) >= 2u )
    {
      v45 = result;
      dev_err(*(_QWORD *)(v1 + 392), "%s: missing 'gpii-mask' DT node\n", "gpi_probe");
      result = v45;
      v20 = *(_QWORD *)(v1 + 472);
      if ( !v20 )
        goto LABEL_94;
    }
    else
    {
      v20 = *(_QWORD *)(v1 + 472);
      if ( !v20 )
        goto LABEL_94;
    }
    if ( *(_DWORD *)(v1 + 480) < 2u )
      goto LABEL_94;
    v21 = "%s: missing 'gpii-mask' DT node\n";
    goto LABEL_43;
  }
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(v1 + 392) + 744LL),
          "qcom,static-gpii-mask",
          v1 + 432,
          1,
          0)
      & 0x80000000) == 0 )
  {
    v12 = *(_QWORD *)(v1 + 472);
    if ( v12 )
    {
      if ( *(_DWORD *)(v1 + 480) )
        ipc_log_string(v12, "%s: static GPII usecase\n", "gpi_probe");
    }
  }
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(v1 + 392) + 744LL),
          "qcom,gpi-ee-offset",
          &v62,
          1,
          0)
      & 0x80000000) != 0 )
  {
    v22 = *(_QWORD *)(v1 + 472);
    if ( v22 && *(_DWORD *)(v1 + 480) )
      ipc_log_string(v22, "%s: No variable ee offset present\n", "gpi_probe");
  }
  else
  {
    *(_QWORD *)(v1 + 416) -= v62;
  }
  v13 = of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(v1 + 392) + 744LL),
          "qcom,ev-factor",
          v1 + 436,
          1,
          0);
  if ( v13 < 0 )
  {
    result = v13 & (unsigned int)(v13 >> 31);
    if ( *(_DWORD *)(v1 + 484) >= 2u )
    {
      v47 = result;
      dev_err(*(_QWORD *)(v1 + 392), "%s: missing 'qcom,ev-factor' DT node\n", "gpi_probe");
      result = v47;
      v20 = *(_QWORD *)(v1 + 472);
      if ( !v20 )
        goto LABEL_94;
    }
    else
    {
      v20 = *(_QWORD *)(v1 + 472);
      if ( !v20 )
        goto LABEL_94;
    }
    if ( *(_DWORD *)(v1 + 480) < 2u )
      goto LABEL_94;
    v21 = "%s: missing 'qcom,ev-factor' DT node\n";
    goto LABEL_43;
  }
  result = dma_set_mask(*(_QWORD *)(v1 + 392), -1);
  if ( (_DWORD)result )
  {
    if ( *(_DWORD *)(v1 + 484) >= 2u )
    {
      v46 = result;
      dev_err(*(_QWORD *)(v1 + 392), "%s: Error setting dma_mask to 64, ret:%d\n", "gpi_probe", result);
      result = v46;
      v15 = *(_QWORD *)(v1 + 472);
      if ( !v15 )
        goto LABEL_94;
    }
    else
    {
      v15 = *(_QWORD *)(v1 + 472);
      if ( !v15 )
        goto LABEL_94;
    }
    if ( *(_DWORD *)(v1 + 480) < 2u )
      goto LABEL_94;
    v16 = "%s: Error setting dma_mask to 64, ret:%d\n";
    goto LABEL_19;
  }
  v24 = devm_kmalloc(*(_QWORD *)(v1 + 392), 1480LL * *(unsigned int *)(v1 + 424), 3520);
  *(_QWORD *)(v1 + 464) = v24;
  if ( !v24 )
  {
LABEL_93:
    result = 4294967284LL;
    goto LABEL_94;
  }
  _mutex_init(v1 + 528, "&gpi_dev->qup_se_lock", &gpi_probe___key);
  property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,le-vm", 0);
  *(_BYTE *)(v1 + 496) = property != 0;
  if ( property )
  {
    v26 = *(_QWORD *)(v1 + 472);
    if ( v26 )
    {
      if ( *(_DWORD *)(v1 + 480) )
        ipc_log_string(v26, "%s: LE-VM usecase\n", "gpi_probe");
    }
  }
  v27 = of_find_property(*(_QWORD *)(*(_QWORD *)(v1 + 392) + 744LL), "qcom,use-smem", 0);
  *(_BYTE *)(v1 + 497) = v27 != 0;
  if ( v27 )
  {
    result = gpi_alloc_smem_region(v1);
    if ( (_DWORD)result )
      goto LABEL_94;
  }
  *(_QWORD *)(v1 + 16) = v1 + 16;
  *(_QWORD *)(v1 + 24) = v1 + 16;
  if ( !*(_DWORD *)(v1 + 424) )
  {
LABEL_61:
    *(_QWORD *)(a1 + 168) = v1;
    *(_QWORD *)(v1 + 72) = 0;
LABEL_110:
    _X8 = (unsigned __int64 *)(v1 + 72);
    __asm { PRFM            #0x11, [X8] }
    do
      v61 = __ldxr(_X8);
    while ( __stxr(v61 | 0x400, _X8) );
    *(_DWORD *)(v1 + 152) = 6;
    *(_QWORD *)(v1 + 176) = gpi_alloc_chan_resources;
    *(_QWORD *)(v1 + 144) = 0x800000008LL;
    *(_QWORD *)(v1 + 192) = gpi_free_chan_resources;
    *(_QWORD *)(v1 + 352) = dma_cookie_status;
    *(_QWORD *)(v1 + 360) = gpi_issue_pending;
    v43 = *(_QWORD *)(v1 + 392);
    *(_DWORD *)(v1 + 172) = 0;
    *(_QWORD *)(v1 + 272) = gpi_prep_slave_sg;
    *(_QWORD *)(v1 + 112) = v43;
    *(_QWORD *)(v1 + 312) = gpi_config;
    *(_QWORD *)(v1 + 320) = gpi_pause;
    *(_QWORD *)(v1 + 328) = gpi_resume;
    *(_QWORD *)(v1 + 336) = gpi_terminate_all;
    result = dma_async_device_register(v1);
    if ( (_DWORD)result )
    {
      if ( *(_DWORD *)(v1 + 484) >= 2u )
      {
        v53 = result;
        dev_err(*(_QWORD *)(v1 + 392), "%s: async_device_register failed ret:%d", "gpi_probe", result);
        result = v53;
        v15 = *(_QWORD *)(v1 + 472);
        if ( !v15 )
          goto LABEL_94;
      }
      else
      {
        v15 = *(_QWORD *)(v1 + 472);
        if ( !v15 )
          goto LABEL_94;
      }
      if ( *(_DWORD *)(v1 + 480) < 2u )
        goto LABEL_94;
      v16 = "%s: async_device_register failed ret:%d";
    }
    else
    {
      result = of_dma_controller_register(*(_QWORD *)(*(_QWORD *)(v1 + 392) + 744LL), gpi_of_dma_xlate, v1);
      if ( !(_DWORD)result )
      {
        gpi_setup_debug(v1);
        result = *(_QWORD *)(v1 + 472);
        if ( result )
        {
          if ( *(_DWORD *)(v1 + 480) )
            ipc_log_string(result, "%s: %s: probe success\n", "gpi_probe", "gpi_probe");
          result = 0;
        }
        goto LABEL_94;
      }
      if ( *(_DWORD *)(v1 + 484) >= 2u )
      {
        v54 = result;
        dev_err(*(_QWORD *)(v1 + 392), "%s: of_dma_controller_reg failed ret:%d", "gpi_probe", result);
        result = v54;
        v15 = *(_QWORD *)(v1 + 472);
        if ( !v15 )
          goto LABEL_94;
      }
      else
      {
        v15 = *(_QWORD *)(v1 + 472);
        if ( !v15 )
          goto LABEL_94;
      }
      if ( *(_DWORD *)(v1 + 480) < 2u )
        goto LABEL_94;
      v16 = "%s: of_dma_controller_reg failed ret:%d";
    }
LABEL_19:
    v17 = result;
    ipc_log_string(v15, v16, "gpi_probe", (unsigned int)result);
    result = v17;
    goto LABEL_94;
  }
  v28 = 0;
  v29 = 0;
  while ( 1 )
  {
    v30 = *(_QWORD *)(v1 + 464) + 1480LL * (int)v29;
    *(_BYTE *)(v30 + 1474) = 1;
    v31 = dmam_alloc_attrs(*(_QWORD *)(v1 + 392), 72, v30 + 368, 3264, 0);
    *(_QWORD *)(v30 + 360) = v31;
    if ( !v31 )
    {
      v48 = *(_QWORD *)(v1 + 472);
      if ( v48 && *(_DWORD *)(v1 + 480) )
        ipc_log_string(v48, "%s: could not allocate for gpii->gpii_chan[0].ch_ring\n", "gpi_probe");
      goto LABEL_93;
    }
    v32 = dmam_alloc_attrs(*(_QWORD *)(v1 + 392), 72, v30 + 760, 3264, 0);
    *(_QWORD *)(v30 + 752) = v32;
    if ( !v32 )
    {
      v49 = *(_QWORD *)(v1 + 472);
      if ( v49 && *(_DWORD *)(v1 + 480) )
        ipc_log_string(v49, "%s: could not allocate for gpii->gpii_chan[1].ch_ring\n", "gpi_probe");
      goto LABEL_93;
    }
    v33 = dmam_alloc_attrs(*(_QWORD *)(v1 + 392), 72, v30 + 968, 3264, 0);
    *(_QWORD *)(v30 + 960) = v33;
    if ( !v33 )
    {
      v50 = *(_QWORD *)(v1 + 472);
      if ( v50 && *(_DWORD *)(v1 + 480) )
        ipc_log_string(v50, "%s: could not allocate for gpii->ev_ring\n", "gpi_probe");
      goto LABEL_93;
    }
    if ( (*(_DWORD *)(v1 + 428) & (1 << v29)) != 0 || (*(_DWORD *)(v1 + 432) & (1 << v29)) != 0 )
      break;
LABEL_60:
    ++v29;
    v28 += 0x4000;
    if ( v29 >= *(_DWORD *)(v1 + 424) )
      goto LABEL_61;
  }
  v34 = *(_QWORD *)(v1 + 416) + v28 + 135168;
  *(_QWORD *)(v30 + 824) = v34;
  v35 = *(_QWORD *)(v1 + 416);
  *(_QWORD *)(v30 + 840) = v34 + 8;
  *(_QWORD *)(v30 + 848) = v34 + 16;
  *(_QWORD *)(v30 + 856) = v34 + 24;
  *(_QWORD *)(v30 + 832) = v35 + v28 + 139520;
  *(_QWORD *)(v30 + 864) = *(_QWORD *)(v1 + 416) + v28 + 143376;
  *(_QWORD *)(v30 + 872) = *(_QWORD *)(v1 + 416) + v28 + 143536;
  *(_QWORD *)(v30 + 880) = *(_QWORD *)(v1 + 416) + v28 + 143552;
  result = platform_get_irq(a1, v29);
  if ( (result & 0x80000000) == 0 )
  {
    *(_DWORD *)(v30 + 808) = result;
    v36 = v28 + 0x20000;
    v37 = v28 + 139264;
    v38 = *(_QWORD *)(v1 + 416) + v36;
    *(_QWORD *)(v30 + 304) = v38;
    *(_QWORD *)(v30 + 312) = *(_QWORD *)(v1 + 416) + v37;
    *(_QWORD *)(v30 + 320) = v38 + 8;
    *(_QWORD *)(v30 + 328) = v38 + 16;
    *(_QWORD *)(v30 + 336) = v38 + 24;
    v39 = v28 + 143368;
    *(_QWORD *)(v30 + 344) = *(_QWORD *)(v1 + 416) + v39;
    vchan_init(v30 + 8, v1);
    *(_DWORD *)(v30 + 264) = 0;
    *(_QWORD *)(v30 + 160) = gpi_desc_free;
    *(_QWORD *)(v30 + 288) = v30;
    *(_DWORD *)(v30 + 356) = 1;
    v40 = *(_QWORD *)(v1 + 416) + v36;
    *(_QWORD *)(v30 + 696) = v40 + 128;
    v41 = *(_QWORD *)(v1 + 416);
    *(_QWORD *)(v30 + 712) = v40 + 136;
    *(_QWORD *)(v30 + 720) = v40 + 144;
    *(_QWORD *)(v30 + 728) = v40 + 152;
    *(_QWORD *)(v30 + 704) = v41 + v37 + 8;
    *(_QWORD *)(v30 + 736) = *(_QWORD *)(v1 + 416) + v39;
    vchan_init(v30 + 400, v1);
    *(_QWORD *)(v30 + 552) = gpi_desc_free;
    *(_DWORD *)(v30 + 656) = 1;
    *(_QWORD *)(v30 + 680) = v30;
    *(_DWORD *)(v30 + 748) = 0;
    _mutex_init(v30 + 888, "&gpii->ctrl_lock", &gpi_probe___key_273);
    *(_QWORD *)(v30 + 948) = 0;
    tasklet_init(v30 + 976, gpi_ev_tasklet, v30);
    *(_DWORD *)(v30 + 1016) = 0;
    _init_swait_queue_head(v30 + 1024, "&x->wait", &init_completion___key);
    *(_DWORD *)v30 = v29;
    v42 = *(_QWORD *)(v1 + 416);
    *(_QWORD *)(v30 + 792) = v1;
    *(_QWORD *)(v30 + 816) = v42;
    *(_DWORD *)(v30 + 1072) = 0;
    goto LABEL_60;
  }
  if ( *(_DWORD *)(v1 + 484) >= 2u )
  {
    v55 = result;
    dev_err(*(_QWORD *)(v1 + 392), "%s: could not req. irq for gpii%d ret:%d", "gpi_probe", v29, result);
    result = v55;
    v51 = *(_QWORD *)(v1 + 472);
    if ( !v51 )
      goto LABEL_94;
  }
  else
  {
    v51 = *(_QWORD *)(v1 + 472);
    if ( !v51 )
      goto LABEL_94;
  }
  if ( *(_DWORD *)(v1 + 480) >= 2u )
  {
    v52 = result;
    ipc_log_string(v51, "%s: could not req. irq for gpii%d ret:%d", "gpi_probe", v29, result);
    result = v52;
  }
LABEL_94:
  _ReadStatusReg(SP_EL0);
  return result;
}
