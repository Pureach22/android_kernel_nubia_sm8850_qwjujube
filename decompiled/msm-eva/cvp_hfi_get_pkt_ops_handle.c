__int64 (__fastcall **__fastcall cvp_hfi_get_pkt_ops_handle(int a1, __int64 a2, __int64 a3, __int64 a4))()
{
  const char *v5; // x2
  int v6; // w19

  if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
  {
    if ( a1 )
      v5 = "Unknown hfi";
    else
      v5 = "4xx packetization";
    v6 = a1;
    printk(&unk_8834D, "hfi", v5, a4);
    a1 = v6;
  }
  if ( a1 )
    return nullptr;
  else
    return hfi_default;
}
