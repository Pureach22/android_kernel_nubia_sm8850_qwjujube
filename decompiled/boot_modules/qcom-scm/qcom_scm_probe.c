unsigned __int64 __fastcall qcom_scm_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  __int64 v4; // x22
  unsigned __int64 v5; // x21
  unsigned __int64 result; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x1
  const char *v9; // x2
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x21
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  unsigned int v20; // w0
  unsigned int v21; // w0
  __int64 *v22; // x8
  unsigned __int64 v23; // x0
  __int64 *v24; // x8
  __int64 v25; // [xsp+0h] [xbp-E0h] BYREF
  __int64 v26; // [xsp+8h] [xbp-D8h]
  __int64 v27; // [xsp+10h] [xbp-D0h]
  __int64 v28; // [xsp+18h] [xbp-C8h]
  unsigned int v29; // [xsp+24h] [xbp-BCh] BYREF
  __int64 v30; // [xsp+28h] [xbp-B8h] BYREF
  __int64 v31; // [xsp+30h] [xbp-B0h]
  __int64 v32; // [xsp+38h] [xbp-A8h]
  const char *v33; // [xsp+40h] [xbp-A0h]
  _QWORD v34[8]; // [xsp+48h] [xbp-98h] BYREF
  _QWORD v35[11]; // [xsp+88h] [xbp-58h] BYREF

  v1 = a1 + 16;
  v35[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 352, 3520);
  if ( v3 )
  {
    v4 = *(_QWORD *)(a1 + 760);
    v5 = (unsigned __int64)v3;
    *v3 = v1;
    memset(v34, 0, sizeof(v34));
    v32 = 0;
    v33 = nullptr;
    v30 = 0;
    v31 = 0;
    v29 = 0;
    memset(v35, 0, 80);
    if ( !(unsigned int)_of_parse_phandle_with_args(v4, "qcom,dload-mode", 0, 0, 0, v35) && v35[0] )
    {
      result = of_address_to_resource(v35[0], 0, &v30);
      if ( (_DWORD)result )
      {
        if ( (result & 0x80000000) != 0 )
          goto LABEL_16;
      }
      else
      {
        result = of_property_read_u32_index(v4, "qcom,dload-mode", 1, &v29);
        if ( (result & 0x80000000) != 0 )
          goto LABEL_16;
        *(_QWORD *)(v5 + 336) = v30 + v29;
      }
    }
    *(_DWORD *)(v5 + 40) = 0;
    _init_swait_queue_head(v5 + 48, "&x->wait", &init_completion___key);
    _mutex_init(v5 + 280, "&scm->scm_bw_lock", &qcom_scm_probe___key);
    v7 = devm_of_icc_get(v1, 0);
    *(_QWORD *)(v5 + 32) = v7;
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      v8 = v7;
      v9 = "failed to acquire interconnect path\n";
      v10 = v1;
      goto LABEL_12;
    }
    result = devm_clk_get_optional(v1, "core");
    *(_QWORD *)(v5 + 8) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      result = devm_clk_get_optional(v1, "iface");
      *(_QWORD *)(v5 + 16) = result;
      if ( result < 0xFFFFFFFFFFFFF001LL )
      {
        result = devm_clk_get_optional(v1, "bus");
        *(_QWORD *)(v5 + 24) = result;
        if ( result < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(v5 + 72) = &qcom_scm_pas_reset_ops;
          v11 = *(_QWORD *)(a1 + 760);
          *(_DWORD *)(v5 + 160) = 1;
          *(_QWORD *)(v5 + 128) = v11;
          result = devm_reset_controller_register(v1);
          if ( !(_DWORD)result )
          {
            result = clk_set_rate(*(_QWORD *)(v5 + 8), 0x7FFFFFFF);
            if ( !(_DWORD)result )
            {
              result = dma_set_mask_and_coherent(v1);
              if ( !(_DWORD)result )
              {
                *(_QWORD *)(a1 + 168) = v5;
                atomic_store(v5, (unsigned __int64 *)&_scm);
                if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,scm-hab", 0) )
                  _qcom_scm_init();
                _get_convention();
                result = _qcom_multi_smc_init(v5, a1);
                if ( !(_DWORD)result )
                {
                  *(_QWORD *)(v5 + 168) = qcom_scm_do_restart;
                  v12 = v5 + 168;
                  *(_DWORD *)(v12 + 16) = 130;
                  register_restart_handler(v12);
                  if ( *(_QWORD *)(v12 + 168) )
                  {
                    v32 = 0;
                    v33 = "qcom-dload-mode";
                    v30 = v1;
                    v31 = 0;
                    LODWORD(v34[0]) = -1;
                    memset((char *)v34 + 4, 0, 60);
                    if ( (unsigned __int64)platform_device_register_full(&v30) >= 0xFFFFFFFFFFFFF001LL )
                      dev_err(v1, "failed to register qcom dload device\n");
                  }
                  if ( download_mode == 1 )
                    qcom_scm_set_download_mode(16, v13, v14, v15, v16, v17, v18, v19);
                  if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,sdi-enabled", 0) )
                    qcom_scm_disable_sdi();
                  v20 = of_reserved_mem_device_init_by_idx(*(_QWORD *)_scm, *(_QWORD *)(*(_QWORD *)_scm + 744LL), 0);
                  if ( v20 != -19 && (v8 = v20) != 0 )
                  {
                    v22 = (__int64 *)_scm;
                    v9 = "Failed to setup the reserved memory region for TZ mem\n";
                  }
                  else
                  {
                    v21 = qcom_tzmem_enable(*(_QWORD *)_scm, v8);
                    if ( !v21 )
                    {
                      v25 = 0;
                      v26 = 3;
                      v27 = 0;
                      v28 = 0x40000;
                      v23 = devm_qcom_tzmem_pool_new(*(_QWORD *)_scm, &v25);
                      v24 = (__int64 *)_scm;
                      *(_QWORD *)(_scm + 344) = v23;
                      if ( v23 < 0xFFFFFFFFFFFFF001LL )
                      {
                        result = qtee_shmbridge_driver_init();
                        goto LABEL_16;
                      }
                      v8 = v23;
                      v10 = *v24;
                      v9 = "Failed to create the SCM memory pool\n";
                      goto LABEL_12;
                    }
                    v22 = (__int64 *)_scm;
                    v8 = v21;
                    v9 = "Failed to enable the TrustZone memory allocator\n";
                  }
                  v10 = *v22;
LABEL_12:
                  result = dev_err_probe(v10, v8, v9);
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
