__int64 sub_2A2AFC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A9AD0);
  return ucfg_mlme_get_tgt_gtx_usr_cfg();
}
