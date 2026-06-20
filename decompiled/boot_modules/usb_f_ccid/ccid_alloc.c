__int64 __fastcall ccid_alloc(__int64 a1)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(a1 + 176);
  *v1 = "ccid";
  v1[9] = ccid_function_bind;
  v1[10] = ccid_function_unbind;
  v1[13] = ccid_function_set_alt;
  v1[15] = ccid_function_disable;
  v1[16] = ccid_function_setup;
  v1[11] = ccid_free_func;
  return *(_QWORD *)(a1 + 176);
}
