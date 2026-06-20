__int64 __fastcall gpr_send_pkt(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x9
  __int64 *v3; // x21
  int v4; // w9
  void *v5; // x0
  __int64 v9; // x0
  unsigned int v10; // w9
  unsigned int v11; // w20
  __int64 v12; // x8
  __int64 v13; // x21
  unsigned int v14; // w19

  if ( !q6 )
  {
    if ( (unsigned int)__ratelimit(&gpr_send_pkt__rs, "gpr_send_pkt") )
      printk(&unk_74A8, "gpr_send_pkt");
    return 4294967274LL;
  }
  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&gpr_send_pkt__rs_3, "gpr_send_pkt") )
      return 4294967274LL;
    v5 = &unk_74C0;
LABEL_18:
    printk(v5, "gpr_send_pkt");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(a1 + 96);
  if ( !v2 )
  {
    if ( !(unsigned int)__ratelimit(&gpr_send_pkt__rs_5, "gpr_send_pkt") )
      return 4294967274LL;
    v5 = &unk_73F3;
    goto LABEL_18;
  }
  v3 = *(__int64 **)(v2 + 152);
  if ( !v3 )
  {
    if ( (unsigned int)__ratelimit(&gpr_send_pkt__rs_7, "gpr_send_pkt") )
    {
      v5 = &unk_7520;
      goto LABEL_18;
    }
    return 4294967274LL;
  }
  v4 = *(unsigned __int16 *)(a1 + 914);
  if ( v4 == 1 )
  {
    if ( !dword_7174 )
    {
      if ( (unsigned int)__ratelimit(&gpr_send_pkt__rs_11, "gpr_send_pkt") )
      {
        dev_err(v3[1], "%s: Still Modem is not Up\n", "gpr_send_pkt");
        return 4294967194LL;
      }
      return 4294967194LL;
    }
  }
  else if ( v4 == 2 && q6 != 2 )
  {
    if ( (unsigned int)__ratelimit(&gpr_send_pkt__rs_9, "gpr_send_pkt") )
    {
      dev_err(v3[1], "%s: Still Dsp is not Up\n", "gpr_send_pkt");
      return 4294967194LL;
    }
    return 4294967194LL;
  }
  v9 = raw_spin_lock_irqsave(a1 + 952);
  v10 = *a2;
  *((_BYTE *)a2 + 4) = *(_BYTE *)(a1 + 914);
  v11 = v10 >> 8;
  v12 = *v3;
  v13 = v9;
  v14 = rpmsg_trysend(v12, a2, v10 >> 8);
  raw_spin_unlock_irqrestore(a1 + 952, v13);
  if ( v14 )
    return v14;
  else
    return v11;
}
