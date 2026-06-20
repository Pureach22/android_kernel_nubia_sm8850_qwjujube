__int64 __fastcall dp_display_mst_get_fixed_topology_port(__int64 a1, unsigned int a2, _DWORD *a3)
{
  int v3; // w8
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( a1 )
  {
    if ( a2 >= 2 )
    {
      if ( !g_dp_display || (v6 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v6 = 0;
      ipc_log_string(v6, "[e][%-4d]invalid stream id:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2);
      printk(&unk_26EFE9, "dp_display_mst_get_fixed_topology_port");
      return 4294967274LL;
    }
    else
    {
      v3 = *(_DWORD *)(*(_QWORD *)(a1 - 1032) + 4LL * a2 + 744);
      if ( (unsigned int)(v3 - 256) >= 0xFFFFFF01 )
      {
        result = 0;
        if ( a3 )
          *a3 = v3;
      }
      else
      {
        return 4294967294LL;
      }
    }
  }
  else
  {
    if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v5 = 0;
    ipc_log_string(v5, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_display_mst_get_fixed_topology_port");
    return 4294967274LL;
  }
  return result;
}
