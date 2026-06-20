__int64 __fastcall hfi_enc_encoder_enable(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int v5; // w19
  void *v6; // x0

  if ( !a1 )
  {
    printk(&unk_22A7AB, "hfi_enc_encoder_enable");
    return 4294967274LL;
  }
  v2 = hfi_enc_set_panic_events(a1, 1);
  if ( v2 )
  {
    v5 = v2;
    v6 = &unk_23B5A2;
LABEL_12:
    printk(v6, "hfi_enc_encoder_enable");
    return v5;
  }
  v3 = *(_QWORD *)(a1 + 4976);
  if ( !v3 )
  {
    v5 = -22;
LABEL_11:
    v6 = &unk_220650;
    goto LABEL_12;
  }
  result = hfi_enc_hw_event_set_buff(a1, 2, 1);
  if ( (_DWORD)result )
  {
    v5 = result;
    printk(&unk_2734D0, "hfi_enc_enable_hw_event");
    goto LABEL_11;
  }
  *(_QWORD *)(v3 + 52) = 1;
  return result;
}
