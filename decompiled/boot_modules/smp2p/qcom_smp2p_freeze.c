__int64 __fastcall qcom_smp2p_freeze(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v2; // x19
  _QWORD *v3; // x21
  _QWORD *v4; // x23
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  __int64 *v7; // x9
  __int64 *v8; // x10

  v1 = *(_QWORD *)(a1 + 152);
  irq_set_irq_wake(*(unsigned int *)(v1 + 56), 0);
  v3 = (_QWORD *)(v1 + 160);
  v2 = *(_QWORD **)(v1 + 160);
  if ( v2 != (_QWORD *)(v1 + 160) )
  {
    do
    {
      v4 = (_QWORD *)*v2;
      qcom_smem_state_unregister(v2[11]);
      v5 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v5 == v2 && (v6 = (_QWORD *)*v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        v6[1] = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      kfree(v2);
      v2 = v4;
    }
    while ( v4 != v3 );
  }
  v7 = *(__int64 **)(v1 + 144);
  *(_QWORD *)(v1 + 160) = v1 + 160;
  *(_QWORD *)(v1 + 168) = v3;
  if ( v7 != (__int64 *)(v1 + 144) )
  {
    do
    {
      v8 = (__int64 *)*v7;
      *((_DWORD *)v7 + 10) = 0;
      v7 = v8;
    }
    while ( v8 != (__int64 *)(v1 + 144) );
  }
  *(_QWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 32) = 0;
  return 0;
}
