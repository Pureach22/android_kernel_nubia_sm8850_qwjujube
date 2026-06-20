__int64 __fastcall msm_dwc3_pwr_irq(int a1, __int64 a2)
{
  dev_info(*(_QWORD *)a2, "%s received %d\n", "msm_dwc3_pwr_irq", a1);
  if ( *(_DWORD *)(a2 + 832) )
  {
    *(_BYTE *)(a2 + 509) = 1;
    return 2;
  }
  else
  {
    dwc3_pwr_event_handler(a2);
    return 1;
  }
}
