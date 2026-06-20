__int64 __fastcall cnss_mhi_force_reset(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 result; // x0

  result = cnss_pci_check_link_status(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !(_DWORD)result )
    return mhi_force_reset(*(_QWORD *)(a1 + 344));
  return result;
}
