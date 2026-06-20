__int64 __fastcall qcom_smd_edge_intr(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x23
  int v4; // w22
  int free_space; // w0

  raw_spin_lock(a2 + 1040);
  v3 = *(_QWORD **)(a2 + 1024);
  if ( v3 == (_QWORD *)(a2 + 1024) )
  {
    LOBYTE(v4) = 0;
  }
  else
  {
    v4 = 0;
    do
    {
      raw_spin_lock(v3 - 2);
      v4 |= qcom_smd_channel_intr(v3 - 20);
      raw_spin_unlock(v3 - 2);
      v3 = (_QWORD *)*v3;
    }
    while ( v3 != (_QWORD *)(a2 + 1024) );
  }
  raw_spin_unlock(a2 + 1040);
  free_space = qcom_smem_get_free_space(*(unsigned int *)(a2 + 932));
  if ( free_space != *(_DWORD *)(a2 + 1064) )
  {
    *(_DWORD *)(a2 + 1064) = free_space;
    queue_work_on(32, system_wq, a2 + 1096);
  }
  if ( (v4 & 1) != 0 )
    queue_work_on(32, system_wq, a2 + 1128);
  return 1;
}
