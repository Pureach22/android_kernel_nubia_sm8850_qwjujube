__int64 __fastcall hal_get_target_type(__int64 *a1)
{
  return *(unsigned int *)(hif_get_target_info_handle(*a1) + 4);
}
