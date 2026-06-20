__int64 __fastcall ucsi_qti_read_message_in(__int64 a1, void *a2, size_t a3)
{
  __int64 drvdata; // x0

  drvdata = ucsi_get_drvdata();
  return ucsi_qti_read(drvdata, 0x10u, a2, a3);
}
