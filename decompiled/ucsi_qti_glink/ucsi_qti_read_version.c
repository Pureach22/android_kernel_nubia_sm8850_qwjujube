__int64 __fastcall ucsi_qti_read_version(__int64 a1, void *a2)
{
  __int64 drvdata; // x0

  drvdata = ucsi_get_drvdata();
  return ucsi_qti_read(drvdata, 0, a2, 2u);
}
