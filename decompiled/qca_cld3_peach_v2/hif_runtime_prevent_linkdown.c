__int64 __fastcall hif_runtime_prevent_linkdown(__int64 a1, char a2)
{
  __int64 v2; // x0

  v2 = a1 + 4000;
  if ( (a2 & 1) != 0 )
    return qdf_runtime_pm_prevent_suspend(v2);
  else
    return qdf_runtime_pm_allow_suspend(v2);
}
