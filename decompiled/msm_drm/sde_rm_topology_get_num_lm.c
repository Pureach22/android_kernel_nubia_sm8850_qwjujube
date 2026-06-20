__int64 __fastcall sde_rm_topology_get_num_lm(__int64 a1, unsigned int a2)
{
  if ( a1 && a2 < 0x11 )
    return *(unsigned int *)(*(_QWORD *)(a1 + 328) + 28LL * a2 + 4);
  printk(&unk_22E16F, "sde_rm_topology_get_num_lm");
  return 4294967274LL;
}
