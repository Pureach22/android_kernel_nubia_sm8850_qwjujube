__int64 __fastcall sde_connector_set_msm_mode(__int64 a1, __int64 a2)
{
  if ( a1 && a2 )
  {
    *(_QWORD *)(a1 + 3232) = a2;
    return 0;
  }
  else
  {
    printk(&unk_22124F, "sde_connector_set_msm_mode");
    return 4294967274LL;
  }
}
