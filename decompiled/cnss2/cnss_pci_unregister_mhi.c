__int64 __fastcall cnss_pci_unregister_mhi(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  if ( *(_DWORD *)(result + 24) != 62 )
  {
    v1 = *(_QWORD *)(result + 344);
    v2 = result;
    mhi_unregister_controller(v1);
    kfree(*(_QWORD *)(v1 + 200));
    *(_QWORD *)(v1 + 200) = 0;
    result = mhi_free_controller(v1);
    *(_QWORD *)(v2 + 344) = 0;
  }
  return result;
}
