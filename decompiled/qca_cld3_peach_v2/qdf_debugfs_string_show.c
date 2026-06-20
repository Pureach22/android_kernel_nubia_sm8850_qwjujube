__int64 __fastcall qdf_debugfs_string_show(__int64 a1)
{
  _seq_puts();
  seq_putc(a1, 10);
  return 0;
}
