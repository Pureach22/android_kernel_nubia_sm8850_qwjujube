__int64 __fastcall rmnet_shs_genl_set_flow_ll(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x20
  int v7; // w1

  if ( !a2 )
    return 0xFFFFFFFFLL;
  v3 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 40LL);
  if ( v3
    && (v4 = _kmalloc_cache_noprof(_rcu_read_lock, 2336, 120), (v5 = v4) != 0)
    && (int)nla_memcpy(v4 + 32, v3, 84) >= 1 )
  {
    if ( *(_BYTE *)(v5 + 72) && !*(_DWORD *)(v5 + 96) )
    {
      *(_QWORD *)(v5 + 96) = -1;
      *(_QWORD *)(v5 + 104) = -1;
    }
    if ( *(_BYTE *)(v5 + 73) && !*(_DWORD *)(v5 + 80) )
    {
      *(_QWORD *)(v5 + 80) = -1;
      *(_QWORD *)(v5 + 88) = -1;
    }
    if ( *(_WORD *)(v5 + 66) && !*(_WORD *)(v5 + 112) )
      *(_WORD *)(v5 + 112) = *(_WORD *)(v5 + 64);
    if ( *(_WORD *)(v5 + 70) && !*(_WORD *)(v5 + 114) )
      *(_WORD *)(v5 + 114) = *(_WORD *)(v5 + 68);
    if ( *(_BYTE *)(v5 + 79) )
    {
      if ( *(_BYTE *)(v5 + 79) == 1 )
        rmnet_shs_add_llflow(v5);
    }
    else
    {
      rmnet_shs_remove_llflow(v5);
    }
    v7 = 929;
  }
  else
  {
    v7 = 920;
  }
  rmnet_shs_genl_send_int_to_userspace(a2, v7);
  return 0;
}
