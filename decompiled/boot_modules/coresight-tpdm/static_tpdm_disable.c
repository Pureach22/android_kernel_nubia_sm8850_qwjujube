__int64 __fastcall static_tpdm_disable(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  if ( !(unsigned int)*(_QWORD *)(a1 + 968) )
    return dev_err(*(_QWORD *)(v1 + 8), "TPDM setup already disabled, Skipping disable\n");
  *(_QWORD *)(a1 + 968) = 0;
  coresight_csr_set_etr_atid(a1, *(unsigned int *)(v1 + 28), 0, 0);
  v3 = *(_QWORD *)(v1 + 8);
  *(_DWORD *)(v1 + 28) = 0;
  return dev_info(v3, "TPDM tracing disabled\n");
}
