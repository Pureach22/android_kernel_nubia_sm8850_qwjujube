__int64 __fastcall hfi_encoder_init(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x0
  _QWORD *v4; // x20
  __int64 result; // x0

  v3 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
  v4 = (_QWORD *)v3;
  if ( v3 )
  {
    a2[654] = hfi_enc_kickoff;
    a2[642] = hfi_enc_encoder_enable;
    a2[645] = hfi_enc_encoder_disable;
    a2[657] = hfi_enc_wait_for_event;
    a2[660] = hfi_enc_enable_hw_event;
    a2[663] = hfi_enc_debugfs_misr_setup;
    a2[666] = hfi_enc_debugfs_misr_read;
    a2[669] = hfi_enc_debugfs_dump_status;
    a2[672] = hfi_enc_get_vblank_count;
    a2[675] = hfi_enc_get_vblank_timestamp;
    *(_QWORD *)(v3 + 112) = hfi_enc_hfi_prop_handler;
    _init_waitqueue_head(v3 + 88, "&hfi_enc->pending_kickoff_wq", &hfi_encoder_init___key);
    result = 0;
    a2[622] = v4;
    *v4 = a2;
  }
  else
  {
    printk(&unk_22DDA5, "hfi_encoder_init");
    return 4294967284LL;
  }
  return result;
}
