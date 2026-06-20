__int64 __fastcall cvp_create_pkt_cmd_sys_release_resource(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // w19
  unsigned __int64 v3; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x19

  if ( a1 && a2 )
  {
    *(_QWORD *)a1 = 0x110100400000010LL;
    *(_DWORD *)(a1 + 12) = a2[3] ^ a2[2];
    if ( *a2 == 1 )
    {
      v2 = 0;
      *(_DWORD *)(a1 + 8) = 2;
    }
    else
    {
      v2 = -524;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v6 = a1;
        printk(&unk_8941B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        a1 = v6;
        v2 = -524;
      }
    }
    if ( (msm_cvp_debug & 0x20) != 0 && !msm_cvp_debug_out )
      printk(&unk_8BD45, &unk_96215, *(unsigned int *)(a1 + 4), *(unsigned int *)(a1 + 8));
  }
  else
  {
    v2 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v3 = _ReadStatusReg(SP_EL0);
      printk(&unk_8D0A6, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
    }
  }
  return v2;
}
