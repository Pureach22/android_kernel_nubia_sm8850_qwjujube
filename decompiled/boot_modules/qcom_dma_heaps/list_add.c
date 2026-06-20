_UNKNOWN **__fastcall list_add(_UNKNOWN **result)
{
  void *v1; // x2

  v1 = secure_heaps;
  if ( *((_UNKNOWN ***)secure_heaps + 1) != &secure_heaps
    || result == &secure_heaps
    || secure_heaps == (_UNKNOWN *)result )
  {
    return (_UNKNOWN **)_list_add_valid_or_report(result);
  }
  *((_QWORD *)secure_heaps + 1) = result;
  *result = v1;
  result[1] = &secure_heaps;
  secure_heaps = result;
  return result;
}
