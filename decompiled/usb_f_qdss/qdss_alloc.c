_QWORD *__fastcall qdss_alloc(__int64 a1)
{
  _QWORD *result; // x0

  result = *(_QWORD **)(a1 + 176);
  *result = "usb_qdss";
  result[1] = &qdss_strings;
  result[9] = qdss_bind;
  result[10] = qdss_unbind;
  result[13] = qdss_set_alt;
  result[11] = qdss_free_func;
  result[15] = qdss_disable;
  result[16] = 0;
  return result;
}
