_QWORD *__fastcall sap_save_owe_pending_assoc_ind(__int64 a1, __int64 a2)
{
  _QWORD *result; // x0
  __int64 v5; // x21

  result = (_QWORD *)_qdf_mem_malloc(0x18u, "sap_save_owe_pending_assoc_ind", 2231);
  if ( result )
  {
    v5 = (__int64)result;
    result[2] = a2;
    if ( (unsigned int)qdf_list_insert_back((_QWORD *)(a1 + 1648), result) )
    {
      _qdf_mem_free(v5);
      return nullptr;
    }
    else
    {
      return &off_0 + 1;
    }
  }
  return result;
}
