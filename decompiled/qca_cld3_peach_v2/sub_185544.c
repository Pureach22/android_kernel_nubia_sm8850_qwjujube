__int64 sub_185544()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return osif_cm_napi_serialize();
}
