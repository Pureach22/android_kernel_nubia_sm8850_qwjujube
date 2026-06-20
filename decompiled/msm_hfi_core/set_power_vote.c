__int64 __fastcall set_power_vote(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v5; // x21
  int v6; // w8

  v5 = *(_QWORD **)(a1 + 728);
  v6 = msm_hfi_core_debug_level;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( *v5 )
      goto LABEL_5;
  }
  else
  {
    printk(&unk_1E83A, "set_power_vote", 103, a4, a5);
    v6 = msm_hfi_core_debug_level;
    if ( *v5 )
      goto LABEL_5;
  }
  if ( (v6 & 0x10004) == 0x10004 )
  {
    printk(&unk_1A699, "set_power_vote", 106, a4, a5);
    v6 = msm_hfi_core_debug_level;
  }
LABEL_5:
  if ( (~v6 & 0x10001) == 0 )
    printk(&unk_1C28B, "set_power_vote", 117, a4, a5);
  return 0;
}
