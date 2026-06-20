__int64 __fastcall list_add_tail(__int64 result)
{
  __int64 *v1; // x1

  v1 = (__int64 *)off_158;
  if ( (_UNKNOWN **)result == &csr_list || off_158 == (_UNKNOWN *)result || *(_UNKNOWN ***)off_158 != &csr_list )
    return _list_add_valid_or_report(result, off_158);
  off_158 = (_UNKNOWN *)result;
  *(_QWORD *)result = &csr_list;
  *(_QWORD *)(result + 8) = v1;
  *v1 = result;
  return result;
}
