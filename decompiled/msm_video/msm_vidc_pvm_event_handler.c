__int64 __fastcall msm_vidc_pvm_event_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( *(_BYTE *)(a1 + 4769) != 1 || (msm_vidc_debug & 1) == 0 )
    return 0;
  printk(&unk_916C1, "err ", 0xFFFFFFFFLL, "codec", a5);
  return 0;
}
