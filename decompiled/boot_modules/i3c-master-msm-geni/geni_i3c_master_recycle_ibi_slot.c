__int64 __fastcall geni_i3c_master_recycle_ibi_slot(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v4; // x20
  __int64 v5; // x23
  unsigned __int64 v6; // x19
  __int64 result; // x0
  __int64 v8; // x20
  __int64 v9; // x0

  v2 = *(_QWORD *)(a1 + 16);
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(_QWORD *)(v2 + 2424);
  if ( v4 )
  {
    if ( *(_DWORD *)(v2 + 2432) )
    {
      v5 = a2;
      v6 = sched_clock(a1);
      ipc_log_string(v4, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_master_recycle_ibi_slot", v6, v6 / 0x3E8);
      a2 = v5;
    }
    else
    {
      v6 = 0;
    }
  }
  else
  {
    v6 = -22;
  }
  result = i3c_generic_ibi_recycle_slot(*(_QWORD *)(v3 + 8), a2);
  v8 = *(_QWORD *)(v2 + 2424);
  if ( v8 && v6 )
  {
    if ( *(_DWORD *)(v2 + 2432) )
    {
      v9 = sched_clock(result);
      return ipc_log_string(
               v8,
               "%s:took %llu nsec(%llu usec)\n",
               "geni_i3c_master_recycle_ibi_slot",
               v9 - v6,
               (v9 - v6) / 0x3E8);
    }
  }
  return result;
}
