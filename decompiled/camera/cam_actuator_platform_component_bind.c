__int64 __fastcall cam_actuator_platform_component_bind(__int64 a1)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  int v5; // w9
  __int64 v6; // x0
  unsigned int v7; // w22
  __int64 v8; // x0
  __int64 v9; // x0
  _QWORD *v10; // x21
  int v11; // w8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  _QWORD *v15; // x9
  unsigned int v16; // w0
  unsigned int v17; // w0
  int v18; // w8
  unsigned int v19; // w0
  const char *v20; // x3
  const char *v21; // x5
  __int64 v22; // x4
  _QWORD *v23; // x0
  __int16 v24; // w8
  unsigned int v25; // w8
  char *v26; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v28; // x22
  __int64 v29; // x0
  _QWORD *v30; // x0
  _QWORD v32[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v33[3]; // [xsp+18h] [xbp-18h] BYREF

  v33[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v33[1] = 0;
  v32[0] = 0;
  v32[1] = 0;
  ktime_get_real_ts64(v33);
  v3 = devm_kmalloc(v2, a1, 4832, 3520);
  if ( v3 )
  {
    v4 = v3;
    v5 = (unsigned __int8)mem_trace_en;
    v3[15] = *(_QWORD *)(a1 - 16);
    v3[467] = a1 - 16;
    v3[12] = a1 - 16;
    v3[13] = a1;
    *((_DWORD *)v3 + 8) = 1;
    if ( v5 == 1 )
    {
      v6 = cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_actuator_platform_component_bind", 0x1C2u);
      v4[6] = v6;
      if ( v6 )
        goto LABEL_7;
    }
    else
    {
      v8 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
      v4[6] = v8;
      if ( v8 )
      {
        while ( 1 )
        {
LABEL_7:
          if ( mem_trace_en == 1 )
            v9 = cam_mem_trace_alloc(96, 0xCC0u, 0, "cam_actuator_platform_component_bind", 0x1C9u);
          else
            v9 = _kvmalloc_node_noprof(96, 0, 3520, 0xFFFFFFFFLL);
          v10 = (_QWORD *)v9;
          if ( !v9 )
          {
            v7 = -12;
            goto LABEL_39;
          }
          v11 = (unsigned __int8)mem_trace_en;
          v4[424] = v9;
          *(_QWORD *)(v9 + 8) = a1;
          if ( v11 == 1 )
          {
            v12 = cam_mem_trace_alloc(1536, 0xCC0u, 0, "cam_actuator_platform_component_bind", 0x1D3u);
            v4[556] = v12;
            if ( !v12 )
              goto LABEL_35;
          }
          else
          {
            v13 = _kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
            v4[556] = v13;
            if ( !v13 )
            {
LABEL_35:
              v7 = -12;
              goto LABEL_36;
            }
          }
          ((void (__fastcall *)(_QWORD *, _QWORD))cam_sensor_module_add_i2c_device)(v4, 0);
          v14 = 0;
          v4[526] = v4 + 526;
          v4[527] = v4 + 526;
          v4[532] = v4 + 532;
          v4[533] = v4 + 532;
          do
          {
            v15 = (_QWORD *)(v4[556] + v14);
            v14 += 48;
            *v15 = v15;
            v15[1] = v15;
          }
          while ( v14 != 1536 );
          _mutex_init(v4 + 585, "&a_ctrl->actuator_park_mutex", &cam_actuator_platform_component_bind___key);
          *((_DWORD *)v4 + 1184) = 0;
          _init_swait_queue_head(v4 + 593, "&x->wait", &init_completion___key_17);
          v16 = cam_req_mgr_workq_create("cam_actuator_worker", 1u, v4 + 584, 0, 0, (__int64)cam_actuator_process_workq);
          if ( (v16 & 0x80000000) != 0 )
          {
            v7 = v16;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x2000,
              1,
              "cam_actuator_platform_component_bind",
              489,
              "Unable to create worker");
            goto LABEL_24;
          }
          v17 = cam_actuator_parse_dt(v4, a1);
          if ( (v17 & 0x80000000) != 0 )
            break;
          v18 = *((_DWORD *)v4 + 29);
          v4[517] = &cam_actuator_internal_ops;
          *(_DWORD *)(a1 - 8) = v18;
          v4[516] = &cam_actuator_subdev_ops;
          v4[518] = v4;
          v4[520] = v4;
          strcpy((char *)v4, "cam-actuator-driver");
          *((_DWORD *)v4 + 1038) = 12;
          *((_DWORD *)v4 + 1042) = 65545;
          *((_DWORD *)v4 + 1050) = 1;
          v19 = cam_register_subdev((__int64)(v4 + 467));
          if ( v19 )
          {
            v7 = v19;
            v20 = "cam_actuator_init_subdev";
            v21 = "Fail with cam_register_subdev rc: %d";
            v22 = 177;
            goto LABEL_23;
          }
          *(_QWORD *)(a1 + 152) = v4;
          *((_DWORD *)v4 + 1146) = -1;
          *((_DWORD *)v4 + 1148) = -1;
          v4[575] = cam_actuator_publish_dev_info;
          v4[576] = cam_actuator_establish_link;
          v4[577] = cam_actuator_apply_request;
          v4[579] = cam_actuator_flush_request;
          v24 = debug_mdl;
          *((_DWORD *)v4 + 1166) = 0;
          *((_DWORD *)v4 + 932) = 0;
          if ( (v24 & 0x2000) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v24 & 0x2000,
              4,
              "cam_actuator_platform_component_bind",
              521,
              "Component bound successfully %d",
              *((_DWORD *)v4 + 29));
          v25 = *((_DWORD *)v4 + 29);
          if ( v25 < 0x10 )
          {
            v26 = (char *)&g_i3c_actuator_data + 40 * v25;
            *(_QWORD *)v26 = v4;
            *((_DWORD *)v26 + 2) = 0;
            _init_swait_queue_head(v26 + 16, "&x->wait", &init_completion___key_17);
            ktime_get_real_ts64(v32);
            cam_record_bind_latency();
            v7 = 0;
            goto LABEL_43;
          }
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v28 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &cam_actuator_platform_component_bind__alloc_tag;
          v29 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(StatusReg + 80) = v28;
          v4[6] = v29;
          if ( !v29 )
            goto LABEL_33;
        }
        v7 = v17;
        v20 = "cam_actuator_platform_component_bind";
        v21 = "Paring actuator dt failed rc %d";
        v22 = 495;
LABEL_23:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x2000,
          1,
          v20,
          v22,
          v21,
          v7);
        cam_req_mgr_workq_destroy(v4 + 584);
LABEL_24:
        v23 = (_QWORD *)v4[556];
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v23, 0);
        else
          kvfree(v23);
LABEL_36:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v10, 0);
        else
          kvfree(v10);
LABEL_39:
        v30 = (_QWORD *)v4[6];
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v30, 0);
        else
          kvfree(v30);
        goto LABEL_42;
      }
    }
LABEL_33:
    v7 = -12;
LABEL_42:
    devm_kfree(a1);
    goto LABEL_43;
  }
  v7 = -12;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v7;
}
