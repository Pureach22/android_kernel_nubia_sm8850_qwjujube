__int64 __fastcall fastrpc_rpmsg_probe(_QWORD *a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w21
  __int64 result; // x0
  __int64 v5; // x20
  int v6; // w9
  __int64 property; // x0
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x0
  int v11; // w10
  __int64 v12; // x21
  int v13; // w0
  unsigned int v14; // w19
  __int64 v15; // x8
  unsigned int v16; // w19
  int v17; // w8
  int v18; // w8
  const char *v19; // x4
  int v20; // w8
  int v21; // w8
  const char *v22; // x1
  const char *v23; // x3
  __int64 v24; // x0
  unsigned int v25; // w4
  __int64 v26; // x8
  const char *v27; // x2
  __int64 v28; // [xsp+0h] [xbp-50h] BYREF
  __int64 v29; // [xsp+8h] [xbp-48h] BYREF
  __int64 v30; // [xsp+10h] [xbp-40h]
  __int64 v31; // [xsp+18h] [xbp-38h]
  __int64 v32; // [xsp+20h] [xbp-30h]
  __int64 v33; // [xsp+28h] [xbp-28h]
  __int64 v34; // [xsp+30h] [xbp-20h]
  __int64 v35; // [xsp+38h] [xbp-18h]
  __int64 v36; // [xsp+40h] [xbp-10h]
  __int64 v37; // [xsp+48h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v30 = 0;
  dev_info(a1, "%s started\n", "fastrpc_rpmsg_probe");
  if ( (unsigned int)of_reserved_mem_device_init_by_idx(a1, a1[93], 0) )
    goto LABEL_27;
  while ( 1 )
  {
    v2 = of_property_read_variable_u32_array(a1[93], "qcom,vmids", &v29, 0, 16);
    if ( (v2 & 0x80000000) != 0 )
    {
      v3 = 0;
    }
    else
    {
      v3 = v2;
      if ( (qcom_scm_is_available() & 1) == 0 )
      {
        result = 4294966779LL;
        goto LABEL_69;
      }
    }
    v5 = _kmalloc_large_noprof(64296, 3520);
    if ( !v5 )
    {
      result = 4294967284LL;
      goto LABEL_69;
    }
    result = fastrpc_populate_domain_from_dt((__int64)a1, &v28);
    if ( (_DWORD)result )
      goto LABEL_69;
    if ( (unsigned int)fastrpc_init_privileged_gids((__int64)a1, (__int64)"qcom,fastrpc-gids", v5 + 52728) )
    {
      dev_err(a1, "Privileged gids init failed.\n");
      if ( !v3 )
        break;
    }
    else if ( !v3 )
    {
      break;
    }
    v6 = v29;
    *(_QWORD *)(v5 + 16) = 8;
    *(_DWORD *)(v5 + 8) = v3;
    *(_DWORD *)(v5 + 32) = v6;
    *(_DWORD *)(v5 + 36) = 7;
    if ( v3 == 1 )
      break;
    *(_DWORD *)(v5 + 40) = HIDWORD(v29);
    *(_DWORD *)(v5 + 44) = 7;
    if ( v3 < 3 )
      break;
    *(_DWORD *)(v5 + 48) = v30;
    *(_DWORD *)(v5 + 52) = 7;
    if ( v3 == 3 )
      break;
    *(_DWORD *)(v5 + 56) = HIDWORD(v30);
    *(_DWORD *)(v5 + 60) = 7;
    if ( v3 < 5 )
      break;
    *(_DWORD *)(v5 + 64) = v31;
    *(_DWORD *)(v5 + 68) = 7;
    if ( v3 == 5 )
      break;
    *(_DWORD *)(v5 + 72) = HIDWORD(v31);
    *(_DWORD *)(v5 + 76) = 7;
    if ( v3 < 7 )
      break;
    *(_DWORD *)(v5 + 80) = v32;
    *(_DWORD *)(v5 + 84) = 7;
    if ( v3 == 7 )
      break;
    *(_DWORD *)(v5 + 88) = HIDWORD(v32);
    *(_DWORD *)(v5 + 92) = 7;
    if ( v3 < 9 )
      break;
    *(_DWORD *)(v5 + 96) = v33;
    *(_DWORD *)(v5 + 100) = 7;
    if ( v3 == 9 )
      break;
    *(_DWORD *)(v5 + 104) = HIDWORD(v33);
    *(_DWORD *)(v5 + 108) = 7;
    if ( v3 < 0xB )
      break;
    *(_DWORD *)(v5 + 112) = v34;
    *(_DWORD *)(v5 + 116) = 7;
    if ( v3 == 11 )
      break;
    *(_DWORD *)(v5 + 120) = HIDWORD(v34);
    *(_DWORD *)(v5 + 124) = 7;
    if ( v3 < 0xD )
      break;
    *(_DWORD *)(v5 + 128) = v35;
    *(_DWORD *)(v5 + 132) = 7;
    if ( v3 == 13 )
      break;
    *(_DWORD *)(v5 + 136) = HIDWORD(v35);
    *(_DWORD *)(v5 + 140) = 7;
    if ( v3 < 0xF )
      break;
    *(_DWORD *)(v5 + 144) = v36;
    *(_DWORD *)(v5 + 148) = 7;
    if ( v3 == 15 )
      break;
    *(_DWORD *)(v5 + 152) = HIDWORD(v36);
    *(_DWORD *)(v5 + 156) = 7;
    if ( v3 <= 0x10 )
      break;
    __break(0x5512u);
LABEL_27:
    dev_info(a1, "no reserved DMA memory for FASTRPC\n");
  }
  *(_DWORD *)(v5 + 64136) = 0;
  property = of_find_property(a1[93], "qcom,non-secure-domain", 0);
  v8 = a1[93];
  *(_BYTE *)(v5 + 64105) = property == 0;
  of_property_read_variable_u32_array(v8, "qcom,rpc-latency-us", v5 + 52700, 1, 0);
  fastrpc_lowest_capacity_corecount((__int64)a1, v5);
  if ( *(_DWORD *)(v5 + 52696) && of_find_property(a1[93], "qcom,single-core-latency-vote", 0) )
    *(_DWORD *)(v5 + 52696) = 1;
  of_property_read_variable_u32_array(a1[93], "qcom,dsp-iova-format", v5 + 64240, 1, 0);
  of_property_read_variable_u32_array(a1[93], "qcom,rootheap-buffer-size", v5 + 64256, 1, 0);
  of_property_read_variable_u32_array(a1[93], "qcom,rootheap-buffer-count", v5 + 64260, 1, 0);
  *(_DWORD *)(v5 + 51664) = 1;
  a1[19] = v5;
  a1[80] = v5 + 64112;
  if ( !(unsigned int)dma_set_mask(a1, 0xFFFFFFFFLL) )
    dma_set_coherent_mask(a1, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 51648) = v5 + 51648;
  *(_QWORD *)(v5 + 51656) = v5 + 51648;
  *(_QWORD *)(v5 + 52744) = v5 + 52744;
  *(_QWORD *)(v5 + 52752) = v5 + 52744;
  *(_QWORD *)(v5 + 64144) = v5 + 64144;
  *(_QWORD *)(v5 + 64152) = v5 + 64144;
  _mutex_init(v5 + 64056, "&data->wake_mutex", &fastrpc_rpmsg_probe___key);
  *(_QWORD *)(v5 + 51608) = 0x1000000400000000LL;
  *(_DWORD *)(v5 + 51600) = 0;
  *(_QWORD *)(v5 + 51616) = 0;
  *(_QWORD *)(v5 + 51624) = 0;
  *(_DWORD *)(v5 + 51632) = 0;
  *(_QWORD *)(v5 + 64032) = 0;
  *(_QWORD *)(v5 + 51640) = 0;
  *(_DWORD *)(v5 + 51636) = 268435461;
  *(_DWORD *)(v5 + 64184) = 0;
  _init_swait_queue_head(v5 + 64192, "&x->wait", &init_completion___key_0);
  *(_DWORD *)(v5 + 64264) = 0;
  _init_swait_queue_head(v5 + 64272, "&x->wait", &init_completion___key_0);
  _init_waitqueue_head(v5 + 64216, "&data->ssr_wait_queue", &fastrpc_rpmsg_probe___key_26);
  v9 = v28;
  v10 = a1[93];
  v11 = *(_DWORD *)(v28 + 16);
  *(_DWORD *)(v5 + 64128) = 4;
  *(_QWORD *)(v5 + 160) = a1;
  *(_QWORD *)(v5 + 24) = v9;
  *(_BYTE *)(v5 + 64106) = 0;
  *(_DWORD *)v5 = v11;
  *(_QWORD *)(v5 + 64120) = 0;
  result = of_platform_populate(v10, 0, 0, a1);
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(v28 + 60) == 1 )
    {
      *(_BYTE *)(v5 + 64106) = 1;
      *(_QWORD *)(v5 + 64120) = 1;
    }
    v12 = *(_QWORD *)(v5 + 24);
    v13 = fastrpc_device_register((__int64)a1, v5, 1, 0, (const char *)(v12 + 20));
    if ( v13 )
      goto LABEL_38;
    if ( *(_BYTE *)(v12 + 51) != 1 )
      goto LABEL_58;
    v17 = *(_DWORD *)(v12 + 60);
    switch ( v17 )
    {
      case 1:
        v20 = *(_DWORD *)(v12 + 52);
        if ( v20 )
        {
          if ( v20 != 1 )
          {
            v19 = *(const char **)(v12 + 64);
            goto LABEL_55;
          }
          v18 = 4;
          v19 = "cdsp1";
        }
        else
        {
          v18 = 3;
          v19 = "cdsp";
        }
        break;
      case 3:
        v18 = 2;
        v19 = "sdsp";
        break;
      case 2:
        v18 = 0;
        v19 = "adsp";
        break;
      default:
        v13 = -22;
        goto LABEL_38;
    }
    *(_QWORD *)(v12 + 64) = v19;
    *(_DWORD *)(v12 + 72) = v18;
LABEL_55:
    v13 = fastrpc_device_register((__int64)a1, v5, 1, 1, v19);
    if ( v13 )
      goto LABEL_38;
    if ( *(_DWORD *)(v12 + 60) == 1 )
    {
      v13 = fastrpc_device_register((__int64)a1, v5, 0, 1, *(const char **)(v12 + 64));
      if ( v13 )
        goto LABEL_38;
    }
LABEL_58:
    v21 = *(_DWORD *)(*(_QWORD *)(v5 + 24) + 60LL);
    if ( v21 == 3 )
    {
      v22 = "sensors_pdr_slpi";
      v23 = "msm/slpi/sensor_pd";
      v24 = v5;
      v25 = 0;
    }
    else
    {
      if ( v21 != 2 )
        goto LABEL_65;
      v13 = fastrpc_setup_service_locator(v5, "audio_pdr_adsp", "avs/audio", "msm/adsp/audio_pd", 0);
      if ( v13
        || (v13 = fastrpc_setup_service_locator(v5, "sensors_pdr_adsp", "tms/servreg", "msm/adsp/sensor_pd", 1u)) != 0 )
      {
LABEL_38:
        v14 = v13;
        if ( *(_QWORD *)(v5 + 64248) )
          fastrpc_channel_default_user_delete(v5);
        kfree(v5);
        result = v14;
        goto LABEL_41;
      }
      v22 = "ois_pdr_adsprpc";
      v23 = "msm/adsp/ois_pd";
      v24 = v5;
      v25 = 2;
    }
    v13 = fastrpc_setup_service_locator(v24, v22, "tms/servreg", v23, v25);
    if ( !v13 )
    {
LABEL_65:
      fastrpc_configure_wakeup_source(v5);
      v13 = fastrpc_channel_default_user_create(v5);
      if ( !v13 )
      {
        v26 = v28;
        v27 = (const char *)(v28 + 20);
        *(_BYTE *)(v28 + 50) = 1;
        *(_QWORD *)(v26 + 176) = v5;
        dev_info(a1, "Opened rpmsg channel for %s", v27);
        result = 0;
        goto LABEL_69;
      }
      goto LABEL_38;
    }
    goto LABEL_38;
  }
LABEL_41:
  v15 = *(_QWORD *)(v5 + 52704);
  if ( v15 )
  {
    v16 = result;
    misc_deregister(v15 + 8);
    result = v16;
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
