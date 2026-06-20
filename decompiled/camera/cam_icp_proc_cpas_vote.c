__int64 __fastcall cam_icp_proc_cpas_vote(unsigned int a1, __int64 a2)
{
  unsigned int v3; // w21
  unsigned int updated; // w19
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a2 )
    return (unsigned int)-22;
  if ( *(_DWORD *)(a2 + 624) )
  {
    v3 = a1;
    updated = cam_cpas_update_ahb_vote(a1, a2);
    a1 = v3;
    if ( updated )
    {
      v5 = "AHB vote update failed rc=%d";
      v6 = 147;
LABEL_8:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_proc_cpas_vote",
        v6,
        v5,
        updated);
      return updated;
    }
  }
  if ( !*(_DWORD *)(a2 + 628) )
    return 0;
  updated = cam_cpas_update_axi_vote(a1, a2 + 16);
  if ( updated )
  {
    v5 = "AXI vote update failed rc=%d";
    v6 = 155;
    goto LABEL_8;
  }
  return updated;
}
