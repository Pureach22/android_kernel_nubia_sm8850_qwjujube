__int64 __fastcall venus_hfi_queue_msg_read(__int64 a1, void *a2)
{
  __int64 v4; // x4
  void *v5; // x0
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
    {
LABEL_9:
      result = 4294967274LL;
      goto LABEL_12;
    }
    v5 = &unk_83321;
LABEL_14:
    printk(v5, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_msg_read");
    goto LABEL_9;
  }
  if ( !core_in_valid_state(a1) )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_9;
    v5 = &unk_95D30;
    goto LABEL_14;
  }
  if ( !*(_QWORD *)(a1 + 5824) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_80A31, "err ", 0xFFFFFFFFLL, "codec", v4);
      result = 4294967235LL;
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( (unsigned int)_read_queue((int)a1 + 5808, a2) )
  {
LABEL_11:
    result = 4294967235LL;
    goto LABEL_12;
  }
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
