__int64 __fastcall qcom_ddump_to_shm(__int64 a1, int *a2)
{
  __int64 v3; // x0
  int v4; // w2
  __int64 result; // x0
  size_t v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 8);
  v4 = *a2;
  v6[0] = 0;
  dev_warn(v3, "detail->reason = %d\n", v4);
  kmsg_dump_rewind(a1 + 32);
  memset(*(void **)(a1 + 144), 0, *(_QWORD *)(a1 + 152));
  kmsg_dump_get_buffer(a1 + 32, 0, *(_QWORD *)(a1 + 144), *(_QWORD *)(a1 + 152), v6);
  result = dev_warn(*(_QWORD *)(a1 - 8), "size of dmesg logbuf logged = %zu\n", v6[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
