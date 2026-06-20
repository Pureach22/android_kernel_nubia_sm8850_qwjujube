__int64 sub_307EBC()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cds_is_log_report_in_progress();
}
