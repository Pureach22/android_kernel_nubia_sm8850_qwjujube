__int64 __fastcall hif_pci_bus_resume(__int64 a1)
{
  __int64 result; // x0

  *(_BYTE *)(a1 + 3988) = 0;
  result = _hif_check_link_status();
  if ( !(_DWORD)result )
  {
    hif_apps_irqs_enable(a1);
    return 0;
  }
  return result;
}
