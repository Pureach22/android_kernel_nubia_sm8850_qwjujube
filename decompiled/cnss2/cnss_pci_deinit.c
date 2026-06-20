__int64 cnss_pci_deinit()
{
  __int64 result; // x0

  if ( cnss_driver_registered == 1 )
  {
    result = pci_unregister_driver(&cnss_pci_driver);
    cnss_driver_registered = 0;
  }
  return result;
}
