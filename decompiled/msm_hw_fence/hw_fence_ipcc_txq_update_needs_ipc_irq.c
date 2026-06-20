__int64 __fastcall hw_fence_ipcc_txq_update_needs_ipc_irq(__int64 a1, unsigned int a2)
{
  if ( a1 && *(_DWORD *)(a1 + 60) > a2 )
    return *(_BYTE *)(*(_QWORD *)(a1 + 648) + 16LL * (int)a2 + 15) & 1;
  else
    return 0;
}
