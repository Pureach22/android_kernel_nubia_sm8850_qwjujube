__int64 __fastcall ucfg_tdls_is_vdev_allowed_to_tx(__int64 a1)
{
  return tdls_is_vdev_allowed_to_tx(a1) & 1;
}
