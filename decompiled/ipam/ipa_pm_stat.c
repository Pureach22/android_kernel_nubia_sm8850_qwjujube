__int64 __fastcall ipa_pm_stat(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w27
  __int64 v5; // x23
  int v6; // w21
  __int64 v7; // x24
  int v8; // w0
  int v9; // w21
  int v10; // w21
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x23
  __int64 v14; // x25
  __int64 max_num_pipes; // x0
  __int64 v16; // x1
  __int64 v17; // x8
  __int64 v18; // x26
  _DWORD *v19; // x9
  __int64 v20; // x10
  int v21; // w21
  unsigned __int64 v22; // x27

  v2 = -22;
  if ( !a1 || (a2 & 0x80000000) != 0 )
    return v2;
  v5 = ipa_pm_ctx;
  mutex_lock(ipa_pm_ctx + 1152);
  v6 = scnprintf(a1, a2, "\n\nCurrent threshold: [");
  if ( *(int *)(v5 + 1112) >= 1 )
  {
    v7 = 0;
    do
    {
      v8 = scnprintf(a1 + v6, (int)(a2 - v6), "%d, ", *(_DWORD *)(*(_QWORD *)(v5 + 1144) + 4 * v7++));
      v6 += v8;
    }
    while ( v7 < *(int *)(v5 + 1112) );
  }
  v9 = scnprintf(a1 + v6, (int)(a2 - v6), "\b\b]\n") + v6;
  v10 = scnprintf(
          a1 + v9,
          (int)(a2 - v9),
          "Aggregated tput: %d, Cur vote: %d",
          *(_DWORD *)(ipa_pm_ctx + 1200),
          *(_DWORD *)(v5 + 1120))
      + v9;
  v11 = scnprintf(a1 + v10, (int)(a2 - v10), "\n\nRegistered Clients:\n");
  v12 = ipa_pm_ctx;
  v2 = v10 + v11;
  v13 = 1;
  while ( 1 )
  {
    v14 = *(_QWORD *)(v12 + 8 * v13);
    if ( !v14 )
      goto LABEL_8;
    max_num_pipes = raw_spin_lock_irqsave(v14 + 100);
    v17 = *(unsigned int *)(v14 + 88);
    v18 = max_num_pipes;
    if ( (_DWORD)v17 )
    {
      if ( (unsigned int)v17 > 2 )
        goto LABEL_23;
      v19 = (_DWORD *)(ipa_pm_ctx + 4 * v17 + 1204);
    }
    else
    {
      v19 = (_DWORD *)(v14 + 96);
    }
    v20 = *(unsigned int *)(v14 + 80);
    if ( (unsigned int)v20 > 6 )
      goto LABEL_23;
    v21 = scnprintf(
            a1 + (int)v2,
            (int)(a2 - v2),
            "Client[%d]: %s State:%s\nGroup: %s Throughput: %d Pipes: ",
            v13,
            (const char *)v14,
            client_state_to_str[v20],
            ipa_pm_group_to_str[v17],
            *v19)
        + v2;
    max_num_pipes = ipa3_get_max_num_pipes();
    if ( (_DWORD)max_num_pipes )
      break;
LABEL_7:
    v2 = scnprintf(a1 + v21, (int)(a2 - v21), "\b\b\n\n") + v21;
    raw_spin_unlock_irqrestore(v14 + 100, v18);
    v12 = ipa_pm_ctx;
LABEL_8:
    if ( ++v13 == 36 )
    {
      mutex_unlock(v12 + 1152);
      return v2;
    }
  }
  v22 = 0;
  while ( v22 != 36 )
  {
    if ( *(_QWORD *)(ipa_pm_ctx + 8 * v22 + 288) == v14 )
      v21 += scnprintf(a1 + v21, (int)(a2 - v21), "%d, ", v22);
    ++v22;
    max_num_pipes = ipa3_get_max_num_pipes();
    if ( v22 >= (unsigned int)max_num_pipes )
      goto LABEL_7;
  }
LABEL_23:
  __break(0x5512u);
  __break(1u);
  return ipa_pm_exceptions_stat(max_num_pipes, v16);
}
