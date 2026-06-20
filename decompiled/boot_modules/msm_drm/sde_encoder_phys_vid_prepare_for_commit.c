_BYTE *__fastcall sde_encoder_phys_vid_prepare_for_commit(_BYTE *result)
{
  if ( !*(_QWORD *)result )
    return (_BYTE *)printk(&unk_220D67, "sde_encoder_phys_vid_prepare_for_commit");
  if ( *(_BYTE *)(*(_QWORD *)result + 749LL) != 1 || (result[2289] & 1) == 0 )
    return (_BYTE *)sde_encoder_phys_vid_enact_updated_qsync_state();
  return result;
}
