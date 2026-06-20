__int64 __fastcall check_for_higher_capacity(__int64 a1, __int64 a2)
{
  _BYTE *v3; // x12

  if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + (((unsigned __int64)(unsigned int)a1 >> 3) & 0x1FFFFFF8)) >> a1)
      & 1) != 0 )
  {
    if ( (unsigned int)a2 >= 0x20 )
      goto LABEL_11;
    if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a2) + 8] + 32LL) == min_possible_cluster_id )
      return 0;
  }
  if ( (unsigned int)a1 < 0x20 )
  {
    v3 = &walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a1)];
    if ( *(_DWORD *)(*((_QWORD *)v3 + 1) + 32LL) == min_possible_cluster_id
      && ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask
                               + (((unsigned __int64)(unsigned int)a2 >> 3) & 0x1FFFFFF8)) >> a2)
        & 1) != 0 )
    {
      return 0;
    }
    if ( (unsigned int)a2 < 0x20 )
      return *((_QWORD *)v3 + 79) > *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a2) + 632];
  }
LABEL_11:
  __break(0x5512u);
  return task_fits_max_0(a1, a2);
}
