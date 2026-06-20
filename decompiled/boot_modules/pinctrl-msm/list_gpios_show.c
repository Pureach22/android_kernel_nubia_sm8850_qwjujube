__int64 __fastcall list_gpios_show(__int64 a1)
{
  msm_dump_gpios(a1, 0, 0);
  return 0;
}
