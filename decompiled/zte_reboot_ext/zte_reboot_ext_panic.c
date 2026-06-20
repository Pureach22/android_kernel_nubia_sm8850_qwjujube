__int64 __fastcall zte_reboot_ext_panic(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x1
  __int64 v3; // x2

  v1 = (_QWORD *)(a1 - 104);
  saved_nvmem_buf[0] = get_ss_panic_buf_byte();
  save_panic_buf_data_to_nvmem(v1, v2, v3);
  return 1;
}
