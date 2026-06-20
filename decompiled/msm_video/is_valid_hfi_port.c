bool __fastcall is_valid_hfi_port(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w19

  v4 = a2 - 1;
  if ( a1 && v4 >= 2 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8F76A, "err ", a1 + 340, a4, a2);
  return v4 < 2;
}
