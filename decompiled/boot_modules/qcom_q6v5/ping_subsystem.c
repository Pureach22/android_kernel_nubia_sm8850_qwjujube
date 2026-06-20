__int64 __fastcall ping_subsystem(_QWORD *a1)
{
  _QWORD *v2; // x21
  unsigned int updated; // w0
  unsigned int v4; // w20
  unsigned int v5; // w0

  *((_DWORD *)a1 + 60) = 0;
  v2 = a1 + 30;
  updated = qcom_smem_state_update_bits(a1[3], 0xFFFFFFFFLL, 1LL << *((_DWORD *)a1 + 15));
  if ( updated )
  {
    v4 = updated;
    dev_err(*a1, "Failed to update ping bits\n");
  }
  else
  {
    if ( (unsigned int)wait_for_completion_timeout(v2, 250) )
    {
      v4 = 0;
    }
    else
    {
      dev_err(*a1, "Failed to get back pong\n");
      v4 = -110;
    }
    v5 = qcom_smem_state_update_bits(a1[3], 1LL << *((_DWORD *)a1 + 15), 0);
    if ( v5 )
    {
      v4 = v5;
      printk(&unk_7477);
    }
  }
  return v4;
}
