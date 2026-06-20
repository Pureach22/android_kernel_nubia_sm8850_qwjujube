__int64 __fastcall target_if_ftm_register_tx_ops(_QWORD *a1)
{
  if ( !a1 )
    return 16;
  a1[237] = target_if_ftm_attach;
  a1[238] = target_if_ftm_detach;
  a1[239] = target_if_ftm_cmd_send;
  return 0;
}
