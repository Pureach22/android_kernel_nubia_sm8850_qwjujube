void __fastcall walt_rt_find_lowest_rq(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, unsigned int a5, _DWORD *a6)
{
  _DWORD *v10; // x23
  unsigned int v11; // w0
  unsigned __int64 v12; // x3
  unsigned __int64 v13; // x14
  __int64 v14; // x15
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  if ( (walt_disabled & 1) == 0 )
  {
    if ( (_UNKNOWN *)a2 == &init_task )
      v10 = &vendor_data_pad;
    else
      v10 = (_DWORD *)(a2 + 5184);
    v11 = walt_find_and_choose_cluster_packing_cpu(a2);
    if ( v11 > 7 )
    {
LABEL_14:
      v15[0] = (unsigned int)(*a4 & v10[92]);
      if ( LODWORD(v15[0]) )
        walt_rt_energy_aware_wake_cpu(a2, v15, a5, a6);
      if ( *a6 == -1 )
      {
        walt_rt_energy_aware_wake_cpu(a2, a4, a5, a6);
        if ( *a6 == -1 )
          *(_QWORD *)a4 = *a4 & (unsigned int)~LODWORD(_cpu_halt_mask[0]);
      }
    }
    else
    {
      v12 = v11;
      while ( 1 )
      {
        v13 = v12 >> 6;
        v14 = 1LL << v12;
        if ( (*(_QWORD *)&v10[2 * (v12 >> 6) + 92] & (1LL << v12)) != 0
          && (*(_QWORD *)(*(_QWORD *)(a2 + 1376) + 8 * v13) & v14) != 0
          && (*((_QWORD *)&_cpu_active_mask + v13) & v14) != 0
          && (_cpu_halt_mask[v13] & v14) == 0
          && *(_DWORD *)((char *)&runqueues + *((_QWORD *)&_per_cpu_offset + v12) + 2640) < 3u )
        {
          break;
        }
        if ( ++v12 == 8 )
          goto LABEL_14;
      }
      *a6 = v12;
    }
  }
  _ReadStatusReg(SP_EL0);
}
