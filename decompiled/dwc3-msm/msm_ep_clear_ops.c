__int64 __fastcall msm_ep_clear_ops(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x22
  __int64 v4; // x0
  unsigned __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x10
  __int64 v8; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v1 + 368) + 96LL) + 152LL);
  v4 = raw_spin_lock_irqsave(v1 + 312);
  v5 = *(unsigned __int8 *)(a1 + 170);
  if ( v5 >= 0x20 )
  {
    __break(0x5512u);
    return msm_ep_update_ops(v4);
  }
  else
  {
    v6 = v4;
    v7 = v3[v5 + 7];
    if ( v7 )
    {
      v8 = *(_QWORD *)(a1 + 16);
      *(_QWORD *)(a1 + 16) = v7;
      v3[v5 + 7] = 0;
      kfree(v8);
      raw_spin_unlock_irqrestore(v1 + 312, v6);
      return 0;
    }
    else
    {
      raw_spin_unlock_irqrestore(v1 + 312, v4);
      dev_err(
        *v3,
        "ep [%s,%d] was not configured as msm endpoint\n",
        *(const char **)(a1 + 8),
        *(unsigned __int8 *)(a1 + 170));
      return 4294967274LL;
    }
  }
}
