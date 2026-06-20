__int64 __fastcall cvp_create_pkt_ssr_cmd(int a1, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w8
  unsigned __int64 StatusReg; // x9
  int v6; // w19
  __int64 v7; // x20
  unsigned __int64 v8; // x8

  if ( a2 )
  {
    v2 = a1 - 1;
    *(_QWORD *)a2 = 0x11011010000000CLL;
    if ( (unsigned int)(a1 - 1) < 8 && ((0xB7u >> v2) & 1) != 0 )
    {
      a1 = dword_9771C[v2];
    }
    else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = a1;
      v7 = a2;
      printk(&unk_8836A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      a1 = v6;
      a2 = v7;
    }
    v3 = 0;
    *(_DWORD *)(a2 + 8) = a1;
  }
  else
  {
    v3 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_9020D, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
      return (unsigned int)-22;
    }
  }
  return v3;
}
