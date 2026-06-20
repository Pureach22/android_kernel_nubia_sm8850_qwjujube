__int64 __fastcall msm_vidc_component_master_bind(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  unsigned int v3; // w19
  __int64 v4; // x4
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned int v7; // w0
  __int64 v8; // x4
  unsigned int v9; // w21
  unsigned int v10; // w0
  __int64 v11; // x4
  unsigned int v12; // w0
  unsigned int v13; // w19
  void *v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4

  v1 = *(_QWORD *)(a1 + 152);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_96554, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_component_master_bind");
  result = component_bind_all();
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v3 = result;
      printk(&unk_9008F, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_component_master_bind");
      return v3;
    }
    return result;
  }
  if ( !(unsigned int)v4l2_device_register(*(_QWORD *)v1 + 16LL, v1 + 2712) )
  {
    v5 = *(_QWORD *)v1 + 16LL;
    strcpy((char *)(v1 + 2848), "msm_vidc_media");
    *(_QWORD *)(v1 + 2832) = v5;
    media_device_init(v1 + 2832);
    v6 = *(_QWORD *)(v1 + 6576);
    *(_QWORD *)(v1 + 2720) = v1 + 2832;
    *(_QWORD *)(v1 + 3464) = v6;
    v7 = msm_vidc_register_video_device(v1, 2, 32);
    if ( v7 )
    {
      v9 = v7;
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_87814, "err ", 0xFFFFFFFFLL, "codec", v8);
      goto LABEL_24;
    }
    v10 = msm_vidc_register_video_device(v1, 1, 33);
    if ( v10 )
    {
      v9 = v10;
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8E80D, "err ", 0xFFFFFFFFLL, "codec", v11);
      goto LABEL_21;
    }
    v12 = _media_device_register(v1 + 2832, &_this_module);
    if ( v12 )
    {
      v9 = v12;
      if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_927BA, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_initialize_media");
        if ( (msm_vidc_debug & 2) == 0 )
          goto LABEL_20;
      }
      else if ( (msm_vidc_debug & 2) == 0 )
      {
LABEL_20:
        v4l2_m2m_unregister_media_controller(*(_QWORD *)(v1 + 2704));
        v4l2_m2m_release(*(_QWORD *)(v1 + 2704));
        *(_QWORD *)(v1 + 1704) = 0;
        video_unregister_device(v1 + 1368);
LABEL_21:
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_9181F, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_unregister_video_device");
        v4l2_m2m_unregister_media_controller(*(_QWORD *)(v1 + 1352));
        v4l2_m2m_release(*(_QWORD *)(v1 + 1352));
        *(_QWORD *)(v1 + 352) = 0;
        video_unregister_device(v1 + 16);
LABEL_24:
        media_device_cleanup(v1 + 2832);
        v4l2_device_unregister(v1 + 2712);
        result = v9;
        if ( (msm_vidc_debug & 1) == 0 )
          return result;
LABEL_26:
        v13 = result;
        printk(&unk_8449C, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_component_master_bind");
        return v13;
      }
      printk(&unk_9181F, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_unregister_video_device");
      goto LABEL_20;
    }
    if ( (unsigned int)venus_hfi_queue_init(v1) )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v14 = &unk_8F2B7;
LABEL_39:
        printk(v14, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_component_master_bind");
      }
    }
    else
    {
      if ( !(unsigned int)msm_vidc_core_init(v1) )
      {
        printk(&unk_93E3B, v15, v16, v17, v18);
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_838C0, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_component_master_bind");
        return 0;
      }
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v14 = &unk_8944E;
        goto LABEL_39;
      }
    }
    venus_hfi_queue_deinit(v1);
    return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_877D9, "err ", 0xFFFFFFFFLL, "codec", v4);
  result = 4294967274LL;
  if ( (msm_vidc_debug & 1) != 0 )
    goto LABEL_26;
  return result;
}
