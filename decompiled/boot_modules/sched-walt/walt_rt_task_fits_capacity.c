__int64 __fastcall walt_rt_task_fits_capacity(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w20
  __int64 v5; // x0
  unsigned int v6; // w9

  v4 = uclamp_eff_value(a1, 0);
  v5 = uclamp_eff_value(a1, 1);
  if ( a2 >= 0x20 )
  {
    __break(0x5512u);
    return walt_find_and_choose_cluster_packing_cpu(v5);
  }
  else
  {
    if ( v4 >= (unsigned int)v5 )
      v6 = v5;
    else
      v6 = v4;
    return v6 <= *(_DWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 632];
  }
}
