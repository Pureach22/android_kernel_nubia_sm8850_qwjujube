__int64 sub_171100()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return osif_cm_napi_serialize();
}
