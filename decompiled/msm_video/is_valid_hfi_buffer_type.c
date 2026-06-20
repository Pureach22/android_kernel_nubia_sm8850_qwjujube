bool __fastcall is_valid_hfi_buffer_type(__int64 a1, unsigned int a2, __int64 a3)
{
  _BOOL4 v6; // w19

  v6 = a2 - 6 < 3 || (a2 & 0xFFFFFFF7) - 1 < 3 || (a2 & 0xFFFFFFFE) == 12 || a2 == 5;
  if ( a1 && !v6 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_94891, "err ", a1 + 340, a3, a2);
  return v6;
}
