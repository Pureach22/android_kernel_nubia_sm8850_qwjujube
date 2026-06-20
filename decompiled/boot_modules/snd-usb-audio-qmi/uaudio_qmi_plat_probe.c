__int64 __fastcall uaudio_qmi_plat_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  _QWORD *v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w0
  _QWORD *v7; // x8
  unsigned int v8; // w0
  __int64 *v10; // x21
  __int64 v11; // x0
  unsigned int v12; // w0
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w19
  const char *v16; // x1
  unsigned int v17; // w2
  __int64 v18; // x0

  v1 = *(_QWORD *)(a1 + 760);
  if ( uaudio_svc )
  {
LABEL_2:
    v3 = a1 + 16;
    v4 = (_QWORD *)devm_kmalloc(a1 + 16, 112, 3520);
    uaudio_qdev = (__int64)v4;
    if ( v4 )
    {
      *v4 = v3;
      if ( (of_property_read_variable_u32_array(v1, "qcom,usb-audio-stream-id", v4 + 1, 1, 0) & 0x80000000) != 0 )
      {
        v16 = "failed to read sid.\n";
      }
      else if ( (of_property_read_variable_u32_array(v1, "qcom,usb-audio-intr-num", uaudio_qdev + 12, 1, 0) & 0x80000000) != 0 )
      {
        v16 = "failed to read intr num.\n";
      }
      else
      {
        v5 = iommu_domain_alloc(*(_QWORD *)(a1 + 144));
        *(_QWORD *)(uaudio_qdev + 24) = v5;
        if ( v5 )
        {
          v6 = iommu_attach_device(v5, a1 + 16);
          if ( v6 )
          {
            v17 = v6;
            v18 = a1 + 16;
            v15 = v17;
            dev_err(v18, "failed to attach device ret = %d\n", v17);
          }
          else
          {
            v7 = (_QWORD *)uaudio_qdev;
            *(_QWORD *)(uaudio_qdev + 32) = uaudio_qdev + 32;
            v7[5] = v7 + 4;
            v7[6] = 4190208;
            v7[7] = 139264;
            v7[8] = v7 + 8;
            v7[9] = v7 + 8;
            v7[10] = 4290625536LL;
            v7[11] = 4333568;
            v8 = snd_usb_register_platform_ops(offload_ops);
            if ( (v8 & 0x80000000) == 0 )
              return 0;
            v15 = v8;
            iommu_detach_device(*(_QWORD *)(uaudio_qdev + 24), v3);
          }
          iommu_domain_free(*(_QWORD *)(uaudio_qdev + 24));
          return v15;
        }
        v16 = "failed to allocate iommu domain\n";
      }
      dev_err(a1 + 16, v16);
      return 4294967277LL;
    }
    return 4294967284LL;
  }
  v10 = (__int64 *)_kmalloc_cache_noprof(iommu_detach_device, 3520, 32);
  if ( !v10 )
    return 4294967284LL;
  v11 = _kmalloc_cache_noprof(snd_usb_unregister_platform_ops, 3520, 304);
  *v10 = v11;
  if ( v11 )
  {
    v12 = qmi_handle_init(v11, 46, &uaudio_svc_ops_options, &uaudio_stream_req_handlers);
    if ( (v12 & 0x80000000) != 0 )
    {
      v15 = v12;
      printk(&unk_B2EB, "uaudio_qmi_svc_init");
    }
    else
    {
      v13 = *v10;
      uaudio_svc = (__int64)v10;
      v14 = qmi_add_server(v13, 1053, 1, 0);
      if ( (v14 & 0x80000000) == 0 )
      {
        v10[3] = ipc_log_context_create(10, "usb_audio", 0);
        goto LABEL_2;
      }
      v15 = v14;
      printk(&unk_B7C4, "uaudio_qmi_svc_init");
      qmi_handle_release(*v10);
      uaudio_svc = 0;
    }
    kfree(*v10);
  }
  else
  {
    v15 = -12;
  }
  kfree(v10);
  return v15;
}
