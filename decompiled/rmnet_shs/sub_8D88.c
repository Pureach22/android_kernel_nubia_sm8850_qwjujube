__int64 sub_8D88()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return rmnet_shs_get_online_mask();
}
