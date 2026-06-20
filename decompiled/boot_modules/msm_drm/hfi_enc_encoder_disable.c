__int64 __fastcall hfi_enc_encoder_disable(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w0
  unsigned int v4; // w8
  __int64 result; // x0
  unsigned int v6; // w19
  void *v7; // x0

  if ( !a1 )
  {
    printk(&unk_22A7AB, "hfi_enc_encoder_disable");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 4976);
  if ( !v1 )
  {
    v6 = -22;
LABEL_9:
    v7 = &unk_220650;
LABEL_11:
    printk(v7, "hfi_enc_encoder_disable");
    return v6;
  }
  v3 = hfi_enc_hw_event_set_buff(a1, 2, 0);
  if ( v3 )
  {
    v6 = v3;
    printk(&unk_2734D0, "hfi_enc_enable_hw_event");
    goto LABEL_9;
  }
  *(_QWORD *)(v1 + 52) = 0;
  v4 = hfi_enc_set_panic_events(a1, 0);
  result = 0;
  if ( v4 )
  {
    v7 = &unk_23B5A2;
    v6 = v4;
    goto LABEL_11;
  }
  return result;
}
