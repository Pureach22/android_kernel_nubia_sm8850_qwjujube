__int64 __fastcall hw_fence_ipcc_get_client_virt_id(__int64 a1, unsigned int a2)
{
  if ( a1 && *(_DWORD *)(a1 + 60) > a2 )
    return *(unsigned int *)(*(_QWORD *)(a1 + 648) + 16LL * a2);
  else
    return 4294967274LL;
}
