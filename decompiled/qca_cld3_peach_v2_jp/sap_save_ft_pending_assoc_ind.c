_QWORD *__fastcall sap_save_ft_pending_assoc_ind(__int64 a1, __int64 a2)
{
  _QWORD *result; // x0
  __int64 v5; // x21
  __int64 v6; // x1

  result = (_QWORD *)_qdf_mem_malloc(0x18u, "sap_save_ft_pending_assoc_ind", 2251);
  if ( result )
  {
    v5 = (__int64)result;
    result[2] = a2;
    if ( (unsigned int)qdf_list_insert_back((_QWORD *)(a1 + 1656), result) )
    {
      _qdf_mem_free(v5);
      return nullptr;
    }
    else
    {
      qdf_event_set(a1 + 1680, v6);
      return &off_0 + 1;
    }
  }
  return result;
}
