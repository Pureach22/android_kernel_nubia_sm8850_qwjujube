_DWORD *__fastcall cam_smmu_is_fault_ids_valid(_DWORD *result)
{
  if ( result )
  {
    if ( result[11] == -1 || result[12] == -1 )
      return nullptr;
    else
      return (_DWORD *)(result[13] != -1);
  }
  return result;
}
