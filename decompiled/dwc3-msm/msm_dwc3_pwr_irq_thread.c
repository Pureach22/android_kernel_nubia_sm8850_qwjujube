__int64 __fastcall msm_dwc3_pwr_irq_thread(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 832) )
    dwc3_resume_work(a2 + 568);
  else
    dwc3_pwr_event_handler(a2);
  dwc3_dbg_print(*(_QWORD *)(a2 + 1256), 0xFFu, "PWR IRQ", *(_DWORD *)(a2 + 832), (const char *)&unk_16A05);
  return 1;
}
