__int64 __fastcall ipahal_get_offset_flt_rt_v4_5(unsigned __int8 *a1, __int64 a2)
{
  __int16 v2; // w8
  __int16 v3; // w9

  *(_DWORD *)a2 = 16 * *a1 - 16;
  v2 = a1[1];
  v3 = *a1;
  *(_WORD *)(a2 + 4) = 16 * (v2 - v3) + 16;
  return 0;
}
