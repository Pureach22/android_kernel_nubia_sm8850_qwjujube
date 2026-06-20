__int64 sub_188B1C()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qdf_is_drv_connected();
}
