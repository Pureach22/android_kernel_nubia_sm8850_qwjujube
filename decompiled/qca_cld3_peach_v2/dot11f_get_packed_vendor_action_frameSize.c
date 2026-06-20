__int64 __fastcall dot11f_get_packed_vendor_action_frameSize(__int64 a1, __int64 a2, int *a3)
{
  *a3 = 5;
  return get_packed_size_core(a1, a2, a3, IES_vendor_action_frame);
}
