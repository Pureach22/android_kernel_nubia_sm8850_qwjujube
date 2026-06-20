__int64 __fastcall check_for_higher_capacity_0(__int64 result, unsigned int a2)
{
  int v2; // w19
  _BYTE *v3; // x12

  if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask
                             + (((unsigned __int64)(unsigned int)result >> 3) & 0x1FFFFFF8)) >> result)
      & 1) != 0 )
  {
    if ( a2 >= 0x20 )
      goto LABEL_11;
    if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 8] + 32LL) == min_possible_cluster_id )
      return 0;
  }
  if ( (unsigned int)result < 0x20 )
  {
    v3 = &walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)result)];
    if ( *(_DWORD *)(*((_QWORD *)v3 + 1) + 32LL) == min_possible_cluster_id
      && ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + (((unsigned __int64)a2 >> 3) & 0x1FFFFFF8)) >> a2) & 1) != 0 )
    {
      return 0;
    }
    if ( a2 < 0x20 )
      return *((_QWORD *)v3 + 79) > *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 632];
  }
LABEL_11:
  __break(0x5512u);
  if ( (v2 & 0x100000) != 0 )
    return walt_get_mvp_task_prio();
  return result;
}
