__int64 __fastcall qcom_smp2p_remove(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x19
  _QWORD *v3; // x22
  _QWORD *v4; // x19
  _QWORD *v5; // x22
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 168);
  dev_pm_clear_wake_irq(a1 + 16);
  v2 = (_QWORD *)v1[18];
  if ( v2 != v1 + 18 )
  {
    do
    {
      v3 = (_QWORD *)*v2;
      irq_domain_remove(v2[6]);
      kfree(v2);
      v2 = v3;
    }
    while ( v3 != v1 + 18 );
  }
  v4 = (_QWORD *)v1[20];
  if ( v4 != v1 + 20 )
  {
    do
    {
      v5 = (_QWORD *)*v4;
      qcom_smem_state_unregister(v4[11]);
      kfree(v4);
      v4 = v5;
    }
    while ( v5 != v1 + 20 );
  }
  mbox_free_channel(v1[17]);
  result = kfree(v1[5]);
  *(_WORD *)(v1[2] + 14LL) = 0;
  return result;
}
