__int64 __fastcall cvp_fastrpc_callback(__int64 a1)
{
  __int64 v2; // x19

  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
  {
    v2 = a1;
    printk(&unk_82B42, "dsp", "cvp_fastrpc_callback", *(unsigned int *)(a1 + 928));
    a1 = v2;
  }
  ((void (__fastcall *)(_QWORD, __int64))eva_fastrpc_driver_unregister)(*(unsigned int *)(a1 + 928), 1);
  return 0;
}
