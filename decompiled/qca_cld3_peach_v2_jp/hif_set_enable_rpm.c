__int64 __fastcall hif_set_enable_rpm(__int64 result)
{
  *(_BYTE *)gp_hif_rtpm_ctx = *(_BYTE *)(result + 1) != 0;
  return result;
}
