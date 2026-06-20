__int64 __fastcall btfmcodec_wq_prepare_bearer(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20

  v1 = a1 - 432;
  v2 = btfmcodec_dequeue_transport(a1 - 432);
  printk(&unk_C1D3, "btfmcodec_wq_prepare_bearer");
  if ( v2 == 255 )
    return printk(&unk_DB1F, "btfmcodec_wq_prepare_bearer");
  else
    return ((__int64 (__fastcall *)(__int64, _QWORD))btfmcodec_prepare_bearer)(v1, v2);
}
