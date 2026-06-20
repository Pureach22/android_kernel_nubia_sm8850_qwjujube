__int64 pld_pcie_get_mode()
{
  __int64 result; // x0

  result = pld_get_global_context();
  if ( result )
  {
    if ( (unsigned int)*(unsigned __int8 *)(result + 36) - 3 > 6 )
      return 0;
    else
      return dword_B2D74C[(unsigned __int8)(*(_BYTE *)(result + 36) - 3)];
  }
  return result;
}
