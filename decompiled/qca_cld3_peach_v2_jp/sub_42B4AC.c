__int64 sub_42B4AC()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return sme_change_mcc_beacon_interval();
}
