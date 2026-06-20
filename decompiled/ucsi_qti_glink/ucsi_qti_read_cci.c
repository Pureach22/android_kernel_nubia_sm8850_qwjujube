__int64 __fastcall ucsi_qti_read_cci(__int64 a1, void *a2)
{
  __int64 drvdata; // x0

  drvdata = ucsi_get_drvdata();
  return ucsi_qti_read(drvdata, 4u, a2, 4u);
}
