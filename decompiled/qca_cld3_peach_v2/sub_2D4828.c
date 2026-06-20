__int64 sub_2D4828()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DB7FC);
  return ucfg_mlme_get_tgt_gtx_usr_cfg();
}
