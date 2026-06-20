__int64 __fastcall ipa_uc_offload_reg_rdyCB(__int64 a1)
{
  __int64 result; // x0
  bool v3; // w8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 )
  {
    if ( (*(_DWORD *)(a1 + 24) & 0xFFFFFFFE) == 2 )
      LODWORD(result) = ipa3_ntn_uc_reg_rdyCB(*(_QWORD *)(a1 + 16), *(_QWORD *)(a1 + 8));
    else
      LODWORD(result) = 0;
    v3 = (_DWORD)result == -17;
    if ( (_DWORD)result == -17 )
      result = 0;
    else
      result = (unsigned int)result;
    *(_BYTE *)a1 = v3;
  }
  else
  {
    printk(&unk_3DCF11, "ipa_uc_offload_reg_rdyCB");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_uc_offload %s:%d Invalid input\n", "ipa_uc_offload_reg_rdyCB", 688);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_uc_offload %s:%d Invalid input\n", "ipa_uc_offload_reg_rdyCB", 688);
    }
    return 4294967274LL;
  }
  return result;
}
