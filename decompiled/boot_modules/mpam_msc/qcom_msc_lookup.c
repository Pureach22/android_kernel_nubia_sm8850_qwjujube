_UNKNOWN **__fastcall qcom_msc_lookup(int a1)
{
  _UNKNOWN **v1; // x9

  v1 = &qcom_mpam_list;
  while ( 1 )
  {
    v1 = (_UNKNOWN **)*v1;
    if ( v1 == &qcom_mpam_list )
      break;
    if ( *((_DWORD *)v1 - 18) == a1 )
      return v1 - 9;
  }
  return nullptr;
}
