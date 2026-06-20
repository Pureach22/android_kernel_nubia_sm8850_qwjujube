_UNKNOWN **__fastcall list_add(_UNKNOWN **result)
{
  void *v1; // x2

  v1 = ect_net;
  if ( *((_UNKNOWN ***)ect_net + 1) != &ect_net || result == &ect_net || ect_net == (_UNKNOWN *)result )
    return (_UNKNOWN **)_list_add_valid_or_report(result, &ect_net);
  *((_QWORD *)ect_net + 1) = result;
  *result = v1;
  result[1] = &ect_net;
  ect_net = result;
  return result;
}
