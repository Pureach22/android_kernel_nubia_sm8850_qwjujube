__int64 __fastcall geni_i3c_master_free_ibi(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x22
  __int64 v3; // x20
  unsigned __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x0

  v1 = *(_QWORD *)(result + 16);
  v2 = *(_QWORD *)(result + 24);
  v3 = *(_QWORD *)(v1 + 2424);
  if ( !v3 )
  {
    v4 = -22;
    if ( (*(_BYTE *)(v1 + 21208) & 1) != 0 )
      goto LABEL_9;
    goto LABEL_8;
  }
  if ( *(_DWORD *)(v1 + 2432) )
  {
    v4 = sched_clock(result);
    result = ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_free_ibi", v4, v4 / 0x3E8);
    if ( (*(_BYTE *)(v1 + 21208) & 1) != 0 )
      goto LABEL_9;
LABEL_8:
    if ( *(_BYTE *)(v1 + 21209) != 1 )
      return result;
    goto LABEL_9;
  }
  v4 = 0;
  if ( (*(_BYTE *)(v1 + 21208) & 1) == 0 )
    goto LABEL_8;
LABEL_9:
  qcom_geni_i3c_ibi_unconf(v1 - 112);
  v5 = raw_spin_lock_irqsave(v1 + 21240);
  *(_QWORD *)(*(_QWORD *)(v1 + 21232) + 8LL * *(__int16 *)(v2 + 2)) = 0;
  *(_WORD *)(v2 + 2) = -1;
  raw_spin_unlock_irqrestore(v1 + 21240, v5);
  result = i3c_generic_ibi_free_pool(*(_QWORD *)(v2 + 8));
  v6 = *(_QWORD *)(v1 + 2424);
  if ( v6 && v4 )
  {
    if ( *(_DWORD *)(v1 + 2432) )
    {
      v7 = sched_clock(result);
      return ipc_log_string(
               v6,
               "%s:took %llu nsec(%llu usec)\n",
               "geni_i3c_master_free_ibi",
               v7 - v4,
               (v7 - v4) / 0x3E8);
    }
  }
  return result;
}
