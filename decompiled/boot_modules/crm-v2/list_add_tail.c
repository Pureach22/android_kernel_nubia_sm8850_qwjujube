__int64 __fastcall list_add_tail(__int64 result)
{
  __int64 *v1; // x1

  v1 = (__int64 *)off_550;
  if ( (_UNKNOWN **)result == &crm_dev_list || off_550 == (_UNKNOWN *)result || *(_UNKNOWN ***)off_550 != &crm_dev_list )
    return _list_add_valid_or_report(result, off_550);
  off_550 = (_UNKNOWN *)result;
  *(_QWORD *)result = &crm_dev_list;
  *(_QWORD *)(result + 8) = v1;
  *v1 = result;
  return result;
}
