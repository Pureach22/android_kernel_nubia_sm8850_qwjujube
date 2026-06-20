__int64 __fastcall dwc_dpdm_cb(__int64 a1, __int64 a2)
{
  if ( a2 != 128 || *(_DWORD *)(a1 - 472) )
    return 1;
  queue_work_on(32, *(_QWORD *)(a1 - 520), a1 - 512);
  return 1;
}
