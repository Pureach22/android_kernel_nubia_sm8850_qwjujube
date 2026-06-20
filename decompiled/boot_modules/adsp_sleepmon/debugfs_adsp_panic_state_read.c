__int64 __fastcall debugfs_adsp_panic_state_read(__int64 a1, __int64 *a2)
{
  *a2 = (unsigned __int8)byte_A632
      | (2LL * (unsigned __int8)byte_A633)
      | (4LL * (unsigned __int8)byte_A634)
      | (8LL * (unsigned __int8)byte_A635);
  return 0;
}
