void *__fastcall qdf_op_callbacks_register(void *result, void *a2)
{
  _on_op_protect = result;
  _on_op_unprotect = a2;
  return result;
}
