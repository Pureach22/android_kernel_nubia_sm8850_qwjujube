__int64 __fastcall cvp_create_pkt_cmd_sys_set_resource(__int64 a1, _DWORD *a2, unsigned int *a3)
{
  _DWORD *v3; // x2
  unsigned int v4; // w8
  unsigned int v5; // t1
  unsigned __int64 v6; // x19
  __int64 v7; // x22
  unsigned __int64 v8; // x4
  __int64 v9; // x25
  _DWORD *v10; // x26
  unsigned __int64 v11; // x8
  unsigned __int64 StatusReg; // x8

  if ( a1 && a2 && a3 )
  {
    *(_QWORD *)a1 = 0x110100300000014LL;
    *(_DWORD *)(a1 + 8) = a2[3] ^ a2[2];
    if ( *a2 == 1 )
    {
      *(_DWORD *)(a1 + 12) = 2;
      v5 = *a3;
      v3 = a3 + 1;
      v4 = v5;
      *(_DWORD *)(a1 + 16) = v5;
      *(_DWORD *)a1 = 8 * v5 + 20;
      if ( v5 )
      {
        v6 = 0;
        v7 = a1 + 20;
        do
        {
          v8 = *(_QWORD *)&v3[2 * v6];
          *(_QWORD *)(v7 + 8 * v6) = v8;
          if ( (msm_cvp_debug & 0x20) != 0 && !msm_cvp_debug_out )
          {
            v9 = a1;
            v10 = v3;
            printk(&unk_8B34E, &unk_96215, (unsigned int)v6, HIDWORD(v8));
            a1 = v9;
            v3 = v10;
          }
          ++v6;
        }
        while ( v6 < *(unsigned int *)(a1 + 16) );
        return 0;
      }
    }
    else
    {
      v4 = -524;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8941B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return (unsigned int)-524;
      }
    }
  }
  else
  {
    v4 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      printk(&unk_8BCFA, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
      return (unsigned int)-22;
    }
  }
  return v4;
}
