__int64 __fastcall interrupt_init_iris2_kaanapali(__int64 a1)
{
  int v2; // w20
  int v3; // w20
  __int64 result; // x0

  v2 = _read_register(a1, 0xB0010u);
  _write_register(a1, 0xB0010u, v2 & 0xFFFFFF9B);
  if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
    printk(&unk_834FB, &unk_8425A, 720912, v2 & 0xFFFFFF9B);
  v3 = _read_register(a1, 4u);
  result = _write_register(a1, 4u, v3 & 0xFFFFFEFF);
  if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
    return printk(&unk_854A9, &unk_8425A, 4, v3 & 0xFFFFFEFF);
  return result;
}
