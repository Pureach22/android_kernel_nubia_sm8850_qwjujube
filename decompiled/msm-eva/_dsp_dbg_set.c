__int64 __fastcall dsp_dbg_set(__int64 a1, int a2)
{
  dword_6C66C = a2;
  cvp_dsp_send_debug_mask();
  return 0;
}
