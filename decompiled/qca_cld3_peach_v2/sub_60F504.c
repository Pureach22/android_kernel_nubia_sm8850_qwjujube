__int64 sub_60F504()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x6164D8);
  return ucfg_get_nan_feature_config();
}
